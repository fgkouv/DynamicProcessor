/*
  ==============================================================================

    NoiseGate.cpp
    Created: 3 Sep 2017 3:19:16pm
    Author:  F.GK

  ==============================================================================
*/

#include "NoiseGate.h"


NoiseGate::NoiseGate()
{

    setThreshold(thresholdInitIndB);
    setAttackTime(attackTimeInitInMs);
    setReleaseTime(releaseTimeInitInMs);
    
    for (int i = 0; i < m_squaredSampleBufferSize; i++)
    {
        m_squaredSampleBuffer[i] = 0.0f;
    }
}

void NoiseGate::prepareToPlay(double newSampleRate, int /*numSamples*/)
{
    m_sampleRate = newSampleRate;
    
    m_attackTimeInSample  = m_attackTimeMs  * m_sampleRate * 0.001f;
    m_releaseTimeInSample = m_releaseTimeMs * m_sampleRate * 0.001f;
    
    switch (currentAttackReleaseState)
    {
        case attack:
        case transitionFromAttackToRelease:
            m_smoothedGain.reset(newSampleRate, m_attackTimeMs * 0.001);
            break;
            
        case release:
        case transitionFromReleaseToAttack:
            m_smoothedGain.reset(newSampleRate, m_releaseTimeMs * 0.001);
            break;
    }
}

void NoiseGate::processBlock(AudioSampleBuffer& audioBuffer)
{
    processBlock(audioBuffer, audioBuffer);
}


void NoiseGate::processBlock(AudioSampleBuffer& audioBuffer, AudioSampleBuffer& sidechainBuffer)
{
    int numberOfSamples  = audioBuffer.getNumSamples();
    int numberOfChannels = audioBuffer.getNumChannels();
    
    for (int i = 0; i < numberOfSamples; i++)
    {
        float meanSample = 0.0f;
        
        for (int channel = 0; channel < sidechainBuffer.getNumChannels(); channel++)
        {
            meanSample += fabs(sidechainBuffer.getWritePointer(channel)[i]);
        }
        
        meanSample /= static_cast<float> (sidechainBuffer.getNumChannels());
        
        float rms = calculateRms(meanSample);
        float gain = calculateGain(rms, m_threshold);
        
        for (int channel = 0; channel < numberOfChannels; channel++)
        {
            audioBuffer.getWritePointer(channel)[i] *= gain;
        }
    }
}


float NoiseGate::calculateRms(float sample)
{
    float squaredSample = sample * sample;
    
    m_squaredSampleBuffer[m_squaredSampleBufferIndex] = squaredSample;
    
    float squaredSampleSum = std::accumulate(m_squaredSampleBuffer, m_squaredSampleBuffer + m_squaredSampleBufferSize, 0.0f);
    
    float rms = sqrt(squaredSampleSum / m_squaredSampleBufferSize);
    
    m_squaredSampleBufferIndex++;
    
    if (m_squaredSampleBufferIndex >= m_squaredSampleBufferSize)
    {
        m_squaredSampleBufferIndex = 0;
    }
    
    return rms;
}



float NoiseGate::calculateGain(float envelope, float threshold)
{
    switch (currentAttackReleaseState)
    {
        case attack:
        {
            m_releaseTimeCounter = 0;
            
            m_smoothedGain.setValue(1.0);
            m_smoothedGain.reset(m_sampleRate, m_releaseTimeMs * 0.001);
            
            if (envelope < threshold)
            {
                currentAttackReleaseState = transitionFromAttackToRelease;
                
                m_smoothedGain.setValue(0.0);
            }
            
            break;
        }
        case transitionFromAttackToRelease:
        {
            m_releaseTimeCounter++;
            m_attackTimeCounter = 0;
            
            if (envelope < threshold && m_releaseTimeCounter > m_releaseTimeInSample)
            {
                currentAttackReleaseState = release;
            }
            else if (envelope > threshold)
            {
                currentAttackReleaseState = attack;
            }
            
            break;
        }
        case release:
        {
            m_attackTimeCounter = 0;
            
            m_smoothedGain.setValue(0.0);
            m_smoothedGain.reset(m_sampleRate, m_attackTimeMs * 0.001);
            
            if (envelope > threshold)
            {
                currentAttackReleaseState = transitionFromReleaseToAttack;
                
                m_smoothedGain.setValue(1.0);
            }
            
            break;
        }
        case transitionFromReleaseToAttack:
        {
            m_attackTimeCounter++;
            m_releaseTimeCounter = 0;
            
            if (envelope > threshold && m_attackTimeCounter > m_attackTimeInSample)
            {
                currentAttackReleaseState = attack;
            }
            else if (envelope < threshold)
            {
                currentAttackReleaseState = release;
            }
            break;
        }
    }
    
    float gain = m_smoothedGain.getNextValue();
    
    return gain;
}


void NoiseGate::setThreshold(float newThresholdIndB)
{
    m_threshold = pow(10.0, newThresholdIndB / 20.0);
}

void NoiseGate::setAttackTime(float newAttackTimeInMs)
{
    m_attackTimeMs = std::max(newAttackTimeInMs, m_minimumAttackReleaseTimeInMs);
    m_attackTimeInSample = m_attackTimeMs  * m_sampleRate * 0.001f;
}

void NoiseGate::setReleaseTime(float newReleaseTimeInMs)
{
    m_releaseTimeMs = std::max(newReleaseTimeInMs, m_minimumAttackReleaseTimeInMs);
    m_releaseTimeInSample = m_releaseTimeMs * m_sampleRate * 0.001f;
}

