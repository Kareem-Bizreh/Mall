#include "Audio.h"
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

#define M_PI 3.14159265358979323846

Audio::Audio() : source(0), buffer(0), device(nullptr), context(nullptr) {
    initializeOpenAL();
}

Audio::~Audio() {
    cleanupOpenAL();
}

void Audio::initializeOpenAL() {
    device = alcOpenDevice(nullptr);  // Open default device
    if (!device) {
        logError("Failed to open OpenAL device.");
        return;
    }

    context = alcCreateContext(device, nullptr);  // Create context
    if (!context) {
        logError("Failed to create OpenAL context.");
        alcCloseDevice(device);
        return;
    }

    alcMakeContextCurrent(context);
    checkOpenALError("Making context current");

    std::cout << "OpenAL initialized successfully." << std::endl;
}

void Audio::cleanupOpenAL() {
    if (source != 0) {
        alDeleteSources(1, &source);
        checkOpenALError("Deleting source");
    }

    if (buffer != 0) {
        alDeleteBuffers(1, &buffer);
        checkOpenALError("Deleting buffer");
    }

    if (context) {
        alcMakeContextCurrent(nullptr);
        alcDestroyContext(context);
    }

    if (device) {
        alcCloseDevice(device);
    }

    std::cout << "OpenAL cleaned up." << std::endl;
}

void Audio::logError(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}

void Audio::checkOpenALError(const std::string& context) {
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        logError("OpenAL error in " + context + ": " + std::string(alGetString(error)));
    }
}

void Audio::playAudio() {
    std::lock_guard<std::mutex> lock(audioMutex);

    if (!source) {
        logError("Audio source not initialized.");
        return;
    }

    if (isPlaying()) {
        std::cout << "Audio is already playing." << std::endl;
        return;
    }

    alSourcePlay(source);
    checkOpenALError("Playing audio");
    std::cout << "Audio playback started." << std::endl;
}

void Audio::stopAudio() {
    std::lock_guard<std::mutex> lock(audioMutex);

    if (!source) {
        logError("Audio source not initialized.");
        return;
    }

    alSourceStop(source);
    checkOpenALError("Stopping audio");
    std::cout << "Audio playback stopped." << std::endl;
}

bool Audio::isPlaying() {
    ALint state = 0;

    if (source) {
        alGetSourcei(source, AL_SOURCE_STATE, &state);
        checkOpenALError("Checking source state");
    }

    return state == AL_PLAYING;
}

void Audio::setVolume(float volume) {
    volume = clamp(volume, 0.0f, 1.0f); // Clamp volume between 0 and 1

    if (source) {
        alSourcef(source, AL_GAIN, volume);
        checkOpenALError("Setting volume");
    }
}

void Audio::loopAudio(bool loop) {
    if (source) {
        alSourcei(source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
        checkOpenALError("Setting looping");
    }
}

void Audio::loadAudio(const std::string& filePath) {
    std::lock_guard<std::mutex> lock(audioMutex);

    if (currentFile == filePath && buffer) {
        std::cout << "Audio file already loaded: " << filePath << std::endl;
        return;
    }

    currentFile = filePath;

    if (!buffer) {
        alGenBuffers(1, &buffer);
        checkOpenALError("Generating buffer");
    }

    loadWavFile(filePath, buffer);

    if (!source) {
        alGenSources(1, &source);
        checkOpenALError("Generating source");
    }

    alSourcei(source, AL_BUFFER, buffer);
    checkOpenALError("Attaching buffer to source");
    std::cout << "Audio file loaded successfully: " << filePath << std::endl;
}

void Audio::loadWavFile(const std::string& filename, ALuint& buffer) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        logError("Failed to open WAV file: " + filename);
        return;
    }

    // Read WAV header
    char header[44];
    file.read(header, 44);
    if (file.gcount() != 44) {
        logError("Invalid WAV header in file: " + filename);
        return;
    }

    // Parse WAV header
    int16_t audioFormat = *reinterpret_cast<int16_t*>(&header[20]);
    int16_t numChannels = *reinterpret_cast<int16_t*>(&header[22]);
    int32_t sampleRate = *reinterpret_cast<int32_t*>(&header[24]);
    int16_t bitsPerSample = *reinterpret_cast<int16_t*>(&header[34]);

    std::cout << "Audio Format: " << audioFormat << "\n";
    std::cout << "Channels: " << numChannels << "\n";
    std::cout << "Sample Rate: " << sampleRate << "\n";
    std::cout << "Bits Per Sample: " << bitsPerSample << "\n";

    if (audioFormat != 1) {
        logError("Unsupported audio format in file: " + filename);
        return;
    }

    ALenum format;
    if (numChannels == 1 && bitsPerSample == 16) {
        format = AL_FORMAT_MONO16;
    }
    else if (numChannels == 2 && bitsPerSample == 16) {
        format = AL_FORMAT_STEREO16;
    }
    else {
        logError("Unsupported channel/bit depth configuration in file: " + filename);
        return;
    }

    // Read WAV data
    std::vector<char> audioData(std::istreambuf_iterator<char>(file), {});
    std::cout << "Audio Data Size: " << audioData.size() << " bytes\n";

    if (audioData.empty()) {
        logError("Failed to read audio data from file: " + filename);
        return;
    }

    size_t maxDataSize = 5 * 48000 * numChannels * (bitsPerSample / 8); // 5 minutes max
    if (audioData.size() > maxDataSize) {
        std::cout << "Audio exceeds 5 minutes. Truncating data.\n";
        audioData.resize(maxDataSize);
    }

    alBufferData(buffer, format, audioData.data(), static_cast<ALsizei>(audioData.size()), sampleRate);
    if (alGetError() != AL_NO_ERROR) {
        logError("Failed to buffer audio data for file: " + filename);
        return;
    }

    std::cout << "WAV file loaded successfully.\n";
}