#include "AudioEngine/AudioEngine.hpp"

#include "AudioEngine/AudioGenerators/Base/StereoSample.hpp"
#include "AudioEngine/AudioGenerators/Base/AudioGenerator.hpp"

namespace sc 
{

const int NUM_CHANNELS = 2;

const RtAudioFormat RT_AUDIO_FORMAT = RTAUDIO_FLOAT64;

AudioEngine AudioEngine::m_instance;

void AudioEngine::initInstance(std::shared_ptr<AudioGenerator> generator)
{
    m_instance.m_generator  = generator;

    if (m_instance.m_dac.getDeviceCount() < 1) {
        throw "No audio devices found!";
    }

    RtAudio::StreamParameters parameters;
    parameters.deviceId = m_instance.m_dac.getDefaultOutputDevice();
    parameters.nChannels = NUM_CHANNELS;

    m_instance.m_dac.openStream(
        &parameters,
        nullptr,
        RT_AUDIO_FORMAT,
        generator->m_sampleRate,
        &(unsigned int(generator->m_bufferSize)),
        &audioCallback
    );

    m_instance.m_dac.startStream();

    m_instance.m_initialised = true;
}

const AudioEngine& AudioEngine::getInstance(
)
{
    if(!m_instance.m_initialised) {
        throw std::runtime_error("AudioEngine instance not initialized.");
    }

    return m_instance;
}

AudioEngine::AudioEngine() = default;

AudioEngine::~AudioEngine() {
    m_dac.stopStream();
    if (m_dac.isStreamOpen()) 
    {
        m_dac.closeStream();
    }
}

int AudioEngine::audioCallback(
    void *outputBuffer,
    void *inputBuffer,
    unsigned int nBufferFrames,
    double streamTime,
    RtAudioStreamStatus status,
    void *userData
)
{
    Sample* buffer = static_cast<Sample*>(outputBuffer);

    for(unsigned int i = 0; i < nBufferFrames; ++i) {
        StereoSample stereoSample = m_instance.m_generator->GetNextSample();
        buffer[2 * i]       = stereoSample.left;
        buffer[(2 * i) + 1] = stereoSample.right;
    }

    return 0;
}

}
