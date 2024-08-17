#include "Examples/Program_Example.hpp"

#include <memory>
#include <iostream>

#include <SoundCrux.hpp>
//#include "Examples/Oscillators/SineOsc_Example.hpp"
#include "Examples/Oscillators/SawtoothOsc_Example.hpp"

namespace sc
{

void Program_Example()
{
    //std::shared_ptr<SineOsc_Example> generator = std::make_shared<SineOsc_Example>();

    std::shared_ptr<SawtoothOsc_Example> generator = std::make_shared<SawtoothOsc_Example>();

    AudioEngine::InitInstance(generator);

    //const AudioEngine& audioEngine = AudioEngine::GetInstance();

    std::cout << "Playing sawtooth oscillator now" << std::endl;
    std::cout << "Press Enter to stop the program..." << std::endl;
  

    std::cin.get();
}

}