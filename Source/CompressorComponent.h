/*
  ==============================================================================

    CompressorComponent.h
    Created: 3 Sep 2017 3:18:29pm
    Author:  F.GK

  ==============================================================================
*/

#pragma once


#include "../JuceLibraryCode/JuceHeader.h"
#include "DynamicProcessorLAF.h"

class CompressorComponent
:
public Component,
public Slider::Listener
{
public:
    CompressorComponent(AudioProcessorValueTreeState& valueTreeState);
    ~CompressorComponent();
    
    void sliderValueChanged(Slider* slider) override;
    
    void resized() override;
    void paint(Graphics& g) override;
    
private:
    
    Slider m_attackSlider;
    Slider m_releaseSlider;
    Slider m_thresholdSlider;
    Slider m_ratioSlider;
    Slider m_makeupGainSlider;
    
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_attackSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_releaseSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_thresholdSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_ratioSliderAttachment;
    ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> m_makeupGainSliderAttachment;
    
    Label m_attackLabel;
    Label m_releaseLabel;
    Label m_thresholdLabel;
    Label m_ratioLabel;
    Label m_makeupGainLabel;
    
    ToggleButton m_autoMakeupButton;
    ScopedPointer<juce::AudioProcessorValueTreeState::ButtonAttachment> m_autoGainButtonAttachment;
    
    juce::Rectangle<int> m_titleArea;
    
    Font m_textFont;
    int m_labelFontSize { 14 };
    DynamicProcessorLAF m_customLAF;
};