/*
  ==============================================================================

    LinearSmoother.cpp
    Created: 26 Nov 2017 8:28:25pm
    Author:  F.GK

  ==============================================================================
*/

#include "LinearSmoother.h"


LinearSmoother::LinearSmoother()
{
}

void LinearSmoother::reset (double sampleRate, double fadeLengthSeconds)
{
    jassert (sampleRate > 0 && fadeLengthSeconds >= 0);
    m_stepsToTarget = (int) std::floor (fadeLengthSeconds * sampleRate);
    m_currentValue = m_target;
    m_countdown = 0;
}

void LinearSmoother::reset()
{
    m_currentValue = m_target;
    m_countdown = 0;
}

int LinearSmoother::getStepsToTarget()
{
    return m_stepsToTarget;
}

void LinearSmoother::setValue (float newValue)
{
    if (m_target != newValue)
    {
        m_target = newValue;
        m_countdown = m_stepsToTarget;
        
        if (m_countdown <= 0)
        {
            m_currentValue = m_target;
        }
        else
        {
            m_step = (m_target - m_currentValue) / (float) m_countdown;
        }
    }
    
}

float LinearSmoother::getNextValue()
{
    if (m_countdown <= 0)
    {
        return m_target;
    }
    
    --m_countdown;
    
    m_currentValue += m_step;
    
    return m_currentValue;
}

float LinearSmoother::getCurrentValue()
{
    if (m_countdown <= 0)
    {
        return m_target;
    }
    
    
    return m_currentValue;
}

float LinearSmoother::getTarget() 
{
    return m_target;
}