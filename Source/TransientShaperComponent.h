/*
  ==============================================================================

    TransientShaperComponent.h
    Created: 3 Sep 2017 3:18:47pm
    Author:  F.GK

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "DynamicProcessorLAF.h"

class TransientShaperComponent
:
public Component,
public Slider::Listener
{
public:
    TransientShaperComponent(AudioProcessorValueTreeState& valueTreeState);
    ~TransientShaperComponent();
    
    void sliderValueChanged(Slider* slider) override;
    
    void resized() override;
    void paint(Graphics& g) override;
    
private:
    
    Slider m_attackSlider;
    Slider m_releaseSlider;
    Slider m_makeupGainSlider;
    
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_attackSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_releaseSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_makeupGainSliderAttachment;

    Label m_attackLabel;
    Label m_releaseLabel;
    Label m_makeupGainLabel;
    
    juce::Rectangle<int> m_titleArea;
    
    Font m_textFont;
    int m_labelFontSize { 14 };
    DynamicProcessorLAF m_customLAF;
};