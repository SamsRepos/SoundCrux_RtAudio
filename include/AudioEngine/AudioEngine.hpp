#pragma once

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

    static void InitInstance(std::shared_ptr<AudioGenerator> generator);

    //static const AudioEngine& GetInstance();

    static void StopAndCloseStream();

private:
    static AudioEngine m_instance;

    AudioEngine();
    ~AudioEngine();

    static int audioCallback(
        void* outputBuffer, 
        void* inputBuffer, 
        unsigned int nBufferFrames,
        double streamTime, 
        RtAudioStreamStatus status,
        void* userData
    );
    
    bool m_initialised = false;

    RtAudio m_dac;

    std::shared_ptr<AudioGenerator> m_generator;
};

}
