/*
  ==============================================================================

    NoiseGateComponent.h
    Created: 3 Sep 2017 3:18:37pm
    Author:  F.GK

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DynamicProcessorLAF.h"

class NoiseGateComponent
:
public Component,
public Slider::Listener
{
public:
    NoiseGateComponent(AudioProcessorValueTreeState& valueTreeState);
    ~NoiseGateComponent();
    
    void sliderValueChanged(Slider* slider) override;
    
    void resized() override;
    void paint(Graphics& g) override;
    
private:
    
    Slider m_attackSlider;
    Slider m_releaseSlider;
    Slider m_thresholdSlider;
    
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_attackSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_releaseSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_thresholdSliderAttachment;
    
    Label m_attackLabel;
    Label m_releaseLabel;
    Label m_thresholdLabel;
    
    juce::Rectangle<int> m_titleArea;
    
    Font m_textFont;
    int m_labelFontSize { 14 };
    DynamicProcessorLAF m_customLAF;
};