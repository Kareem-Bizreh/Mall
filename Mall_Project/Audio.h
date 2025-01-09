#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <fstream>
#include <mutex>
#include <memory>

class Audio {
public:
    Audio();
    ~Audio();

    void playAudio();
    void stopAudio();
    bool isPlaying();
    void setVolume(float volume);
    void loopAudio(bool loop);
    void cleanupOpenAL();
    void loadAudio(const std::string& filePath);
    void initializeOpenAL();

private:
    ALuint source;
    ALuint buffer;
    ALCdevice* device;
    ALCcontext* context;
    std::mutex audioMutex; 
    std::string currentFile; 

    void logError(const std::string& message);
    void checkOpenALError(const std::string& context);
    void loadWavFile(const std::string& filename, ALuint& buffer);
};
template <typename T>
T clamp(const T& value, const T& min, const T& max) {
    return (value < min) ? min : (value > max) ? max : value;
};
