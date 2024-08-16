#pragma once

#include "Examples/Oscillators/Base/Oscillator_Example.hpp"

namespace sc 
{

class SawtoothOsc_Example : public Oscillator_Example
{
public:
    SawtoothOsc_Example(
        double frequency        = DEFAULT_FREQUENCY,
        double amplitude        = DEFAULT_AMPLITUDE,
        unsigned int sampleRate = DEFAULT_SAMPLE_RATE,
        unsigned int bufferSize = DEFAULT_BUFFER_SIZE
    );

protected:
    virtual StereoSample GetNextSample();

private:

};

}
