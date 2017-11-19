/*
  ==============================================================================

    TransientShaperComponent.cpp
    Created: 3 Sep 2017 3:18:47pm
    Author:  F.GK

  ==============================================================================
*/

#include "TransientShaperComponent.h"


TransientShaperComponent::TransientShaperComponent(AudioProcessorValueTreeState& valueTreeState)
{
    
    m_textFont = Font(Typeface::createSystemTypefaceFor (BinaryData::SHPinscherRegular_otf, BinaryData::SHPinscherRegular_otfSize));
    
    
    
    m_attackLabel.setText("Attack Amount", dontSendNotification);
    m_attackLabel.setFont(m_labelFontSize);
    m_attackLabel.setFont(m_textFont);
    m_attackLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_attackLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_attackLabel);
    
    m_releaseLabel.setText("Release Amount", dontSendNotification);
    m_releaseLabel.setFont(m_labelFontSize);
    m_releaseLabel.setFont(m_textFont);
    m_releaseLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_releaseLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_releaseLabel);
    
    m_makeupGainLabel.setText("Makeup Gain", dontSendNotification);
    m_makeupGainLabel.setFont(m_labelFontSize);
    m_makeupGainLabel.setFont(m_textFont);
    m_makeupGainLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_makeupGainLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_makeupGainLabel);
    
    addAndMakeVisible(&m_attackSlider);
    m_attackSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_attackSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_attackSlider.setTextValueSuffix(" %");
    m_attackSlider.setPopupDisplayEnabled(true, this);
    m_attackSlider.setLookAndFeel(&m_customLAF);
    m_attackSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "transientShaperAttack",m_attackSlider);
    
    addAndMakeVisible(&m_releaseSlider);
    m_releaseSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_releaseSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_releaseSlider.setTextValueSuffix(" %");
    m_releaseSlider.setPopupDisplayEnabled(true, this);
    m_releaseSlider.setLookAndFeel(&m_customLAF);
    m_releaseSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "transientShaperRelease",m_releaseSlider);
    
    addAndMakeVisible(&m_makeupGainSlider);
    m_makeupGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_makeupGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_makeupGainSlider.setTextValueSuffix(" dB");
    m_makeupGainSlider.setPopupDisplayEnabled(true, this);
    m_makeupGainSlider.setLookAndFeel(&m_customLAF);
    m_makeupGainSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "transientShaperGain",m_makeupGainSlider);
}


TransientShaperComponent::~TransientShaperComponent()
{
    
}


void TransientShaperComponent::sliderValueChanged(juce::Slider *slider)
{
    
}

void TransientShaperComponent::resized()
{
    float width = getWidth();
    
    m_titleArea = juce::Rectangle<int>(5, 5, width, 30);

    float horizontalOffset = 10.f;
    float knobSize = 0.33f * (width - 2 * horizontalOffset);
    float xPos = 10.f;
    float yPos = m_titleArea.getBottom() + 2;
    
    float labelHeight = m_labelFontSize + 3.f;
    
    m_attackLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_attackSlider.setBounds(xPos, yPos, knobSize, knobSize);
    
    xPos += knobSize;
    yPos -= labelHeight;
    m_releaseLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_releaseSlider.setBounds(xPos, yPos, knobSize, knobSize);
    
    xPos += knobSize;
    yPos -= labelHeight;
    m_makeupGainLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_makeupGainSlider.setBounds(xPos, yPos, knobSize, knobSize);
}

void TransientShaperComponent::paint(juce::Graphics &g)
{
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 10.f, 1.f);
    
    g.setFont(m_textFont);
    g.setFont(20.f);
    g.drawFittedText("Transient Shaper", m_titleArea, Justification::centredLeft, 1);
}

