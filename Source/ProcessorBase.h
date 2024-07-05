/*
  ==============================================================================

    ProcessorBase.h
    Created: 5 Jul 2024 2:01:33pm
    Author:  Reilly Spitzfaden

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "Utilities.h"

class FFTProcessorBase
{
public:
    FFTProcessorBase() {}
    
    virtual ~FFTProcessorBase() {}
    
    virtual void prepare(const juce::dsp::ProcessSpec& spec) = 0;
    
    virtual void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) = 0;
    
    virtual void reset() = 0;
    
    virtual FFTProcessorParameters& getParameters() = 0;
    
    virtual void setParameters(const FFTProcessorParameters& params) = 0;
};
