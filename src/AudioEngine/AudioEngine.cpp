#include "AudioEngine/AudioEngine.hpp"

#include <cmath>

namespace sc 
{

const double PI = 3.14159265358979323846;

const int NUM_CHANNELS = 2;

AudioEngine AudioEngine::m_instance;

void AudioEngine::initInstance(
    unsigned int sampleRate,
    unsigned int bufferSize
)
{
    m_instance.m_sampleRate = sampleRate;
    m_instance.m_bufferSize = bufferSize;

    if (m_instance.m_dac.getDeviceCount() < 1) {
        throw "No audio devices found!";
    }

    RtAudio::StreamParameters parameters;
    parameters.deviceId = m_instance.m_dac.getDefaultOutputDevice();
    parameters.nChannels = NUM_CHANNELS;

    m_instance.m_dac.openStream(
        &parameters,
        nullptr,
        RTAUDIO_FLOAT64,
        m_instance.m_sampleRate,
        &m_instance.m_bufferSize,
        &audioCallback
    );

    m_instance.m_dac.startStream();

    m_instance.m_initialised = true;
}

AudioEngine& AudioEngine::getInstance(
)
{
    if(!m_instance.m_initialised) {
        throw;
    }

    return m_instance;
}


void AudioEngine::addGenerator(std::shared_ptr<AudioGenerator> generator)
{
    m_generators.push_back(generator);
}

AudioEngine::AudioEngine() = default;

AudioEngine::~AudioEngine() {
    m_dac.stopStream();
    if (m_dac.isStreamOpen()) 
    {
        m_dac.closeStream();
    }
}

const unsigned int BUFFER_SIZE = 256;
const double FREQUENCY = 440.0; // Frequency of the sine wave (Hz)

int AudioEngine::audioCallback(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
                         double streamTime, RtAudioStreamStatus status, void *userData) {
    double *buffer = static_cast<double*>(outputBuffer);
    static double phase = 0.0;
    const double increment = 2.0 * PI * FREQUENCY / AudioEngine::getInstance().m_sampleRate;

    for (unsigned int i = 0; i < nBufferFrames; ++i) {
        auto val = 0.5 * sin(phase); // Sine wave with amplitude 0.5
        buffer[2 * i] = buffer[(2 * i) + 1] = val;
        phase += increment;
        if (phase >= 2.0 * PI) phase -= 2.0 * PI;
    }

    return 0;
}

}