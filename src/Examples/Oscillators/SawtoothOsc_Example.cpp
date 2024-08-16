#include "Examples/Oscillators/SawtoothOsc_Example.hpp"

namespace sc
{

SawtoothOsc_Example::SawtoothOsc_Example(
    double frequency,
    double amplitude,
    unsigned int sampleRate,
    unsigned int bufferSize
)
:
Oscillator_Example(frequency, amplitude, sampleRate, bufferSize)
{

}

StereoSample SawtoothOsc_Example::GetNextSample()
{
    static sc::Sample sample = m_amplitude;

    sample -= (2 * m_amplitude) / (m_sampleRate / m_frequency);

    if(sample <= -m_amplitude) 
    {
        sample = m_amplitude;
    }

    return sc::StereoSample(sample);
}


}