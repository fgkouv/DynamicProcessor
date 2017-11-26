/*
  ==============================================================================

    LinearSmoother.h
    Created: 26 Nov 2017 8:28:25pm
    Author:  F.GK

  ==============================================================================
*/

#pragma once


#include "../JuceLibraryCode/JuceHeader.h"


class LinearSmoother
{
public:
    LinearSmoother();
    
    void reset (double sampleRate, double fadeLengthSeconds);
    
    void reset();
    
    int getStepsToTarget() ;
    
    void setValue (float newValue);
    
    float getNextValue();
    
    float getCurrentValue();
    
    float getTarget() ;
    
    
private:
    float m_currentValue { 0.f };
    float m_target { 0.f };
    float m_step { 0.f };
    
    int m_countdown { 0 };
    int m_stepsToTarget { 0 };
    
    JUCE_DECLARE_NON_COPYABLE (LinearSmoother)
};

