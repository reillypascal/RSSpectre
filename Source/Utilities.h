/*
  ==============================================================================

    Utilities.h
    Created: 5 Jul 2024 1:28:05pm
    Author:  Reilly Spitzfaden

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

inline float scale(float input, float inLow, float inHi, float outLow, float outHi)
{
    float scaleFactor = (outHi - outLow)/(inHi - inLow);
    float offset = outLow - inLow;
    return (input * scaleFactor) + offset;
}

inline int wrapInt(int a, int b)
{
    int c = a % b;
    return (c < 0) ? c + b : c;
}

struct FFTProcessorParameters
{
    FFTProcessorParameters() {}
    
    FFTProcessorParameters& operator=(const FFTProcessorParameters& params)
    {
        if (this != &params)
        {
            fftSize = params.fftSize;
            fftOverlap = params.fftOverlap;
        }
        return *this;
    }
    
    bool operator==(const FFTProcessorParameters& params)
    {
        if (fftSize == params.fftSize &&
            fftOverlap == params.fftOverlap)
            return true;
        
        return false;
    }
    
    int fftSize { 2048 };
    int fftOverlap { 4 };
};
