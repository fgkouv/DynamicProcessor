/*
  ==============================================================================

    NoiseGate.h
    Created: 3 Sep 2017 3:19:16pm
    Author:  F.GK

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "LinearSmoother.h"

#include <vector>
#include <numeric>

class NoiseGate
{
public:
    NoiseGate();
    
    void prepareToPlay(double sampleRate, int numSamples);
    void processBlock(juce::AudioSampleBuffer& audioBuffer);
    void processBlock(juce::AudioSampleBuffer& audioBuffer, juce::AudioSampleBuffer& sidechainBuffer);
    
    void setSidechainGain(float newSidechainGain);
    void setSidechainAmount(float newSidechainAmount);
    void setThreshold(float newThresholdIndB);
    void setAttackTime(float newAttackTimeInMs);
    void setReleaseTime(float newReleaseTimeInMs);

private:
    
    float calculateRms(float sample);
    float calculateGain(float envelope, float threshold);

    
    const float thresholdInitIndB              { -90.0f };
    const float attackTimeInitInMs             { 10.0f };
    const float releaseTimeInitInMs            { 200.0f };
    
    const float envelopAttackTimeInMs          { 1.0f };
    const float envelopReleaseTimeInMs         { 1.0f };
    
    static const int m_squaredSampleBufferSize { 512 };

    float m_threshold           { -30.0f };
    float m_attackTimeMs        { 10.0f  };
    float m_releaseTimeMs       { 200.0f };
    
    
    double m_sampleRate         { 44100.0 };
    
    float m_attackCoef          { 0.0f };
    float m_releaseCoef         { 0.0f };
    
    float m_attackTimeInSample  { 0.0f };
    float m_releaseTimeInSample { 0.0f };
    
    enum attackReleaseHysteresisState
    {
        attack,
        transitionFromAttackToRelease,
        release,
        transitionFromReleaseToAttack
    };
    
    attackReleaseHysteresisState currentAttackReleaseState { release };
    
    int   m_attackTimeCounter  { 0 };
    int   m_releaseTimeCounter { 0 };
    
    int   m_squaredSampleBufferIndex { 0 };
    float m_squaredSampleBuffer[m_squaredSampleBufferSize];
    
    LinearSmoother m_smoothedGain;
    
    bool m_sidechainIsOn    { false };
    
    float dB2Amp(float db)
    {
        return ( powf(10.0f, db / 20.0f) );
    }
    

    const float m_minimumAttackReleaseTimeInMs { 1.f };
    
    
};