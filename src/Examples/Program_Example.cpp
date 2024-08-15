#include "Examples/Program_Example.hpp"

#include <memory>
#include <iostream>

#include <SoundCrux.hpp>
#include "Examples/SineGenerator_Example.hpp"

namespace sc
{

void Program_Example()
{
    std::shared_ptr<SineGenerator_Example> generator = std::make_shared<SineGenerator_Example>();


    AudioEngine::initInstance(generator);

    const AudioEngine& audioEngine = AudioEngine::getInstance();

    std::cout << "Playing sine wave now" << std::endl;
    std::cout << "Press Enter to stop the program..." << std::endl;
  

    std::cin.get();
}

}