#include "AudioEngine/AudioGenerators/SineGenerator.hpp"

#include <cmath>

//#include "AudioEngine/AudioGenerators/Base/StereoSample.hpp"

namespace sc
{

const double PI = 3.14159265358979323846;

SineGenerator::SineGenerator(
    unsigned int sampleRate,
    unsigned int bufferSize,
    double frequency,
    double amplitude
)
:
AudioGenerator(sampleRate, bufferSize),
m_frequency(frequency),
m_amplitude(amplitude)
{

}

StereoSample SineGenerator::GetNextSample()
{
    static double phase = 0.0;
    const double increment = 2.0 * PI * m_frequency / m_sampleRate;

    StereoSample stereoSample = m_amplitude * sin(phase);

    phase += increment;
    if (phase >= 2.0 * PI) phase -= 2.0 * PI;

    return stereoSample;
}


}