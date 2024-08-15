#pragma once

#include "AudioEngine/AudioGenerator.hpp"

#include "AudioEngine/StereoSample.hpp"


namespace sc 
{

const double DEFAULT_FREQUENCY = 440.0; // Frequency of the sine wave (Hz)
const double DEFAULT_AMPLITUDE = 0.5;

//struct StereoSample;

class SineGenerator_Example : public AudioGenerator 
{
public:
    SineGenerator_Example(
        double frequency        = DEFAULT_FREQUENCY,
        double amplitude        = DEFAULT_AMPLITUDE,
        unsigned int sampleRate = DEFAULT_SAMPLE_RATE,
        unsigned int bufferSize = DEFAULT_BUFFER_SIZE
    );

protected:
    virtual StereoSample GetNextSample();

private:
    double m_frequency;
    double m_amplitude;
};
}
