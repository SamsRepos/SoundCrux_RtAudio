#pragma once

#include <vector>
#include <memory>

#include <RtAudio.h>

namespace sc 
{

class AudioGenerator;

class AudioEngine
{
public:
    AudioEngine(const AudioEngine&) = delete;
    AudioEngine& operator=(const AudioEngine&) = delete;

    static void initInstance(
        unsigned int sampleRate,
        unsigned int bufferSize
    );

    static AudioEngine& getInstance();

    void addGenerator(std::shared_ptr<AudioGenerator> generator);

private:
    static AudioEngine m_instance;

    AudioEngine();
    ~AudioEngine();

    static int audioCallback(
        void *outputBuffer, 
        void *inputBuffer, 
        unsigned int 
        nBufferFrames,
        double streamTime, 
        RtAudioStreamStatus status,
        void *userData
    );
    
    bool m_initialised = false;

    RtAudio m_dac;

    unsigned int m_sampleRate;
    unsigned int m_bufferSize;

    std::vector<std::shared_ptr<AudioGenerator>> m_generators;
};

}