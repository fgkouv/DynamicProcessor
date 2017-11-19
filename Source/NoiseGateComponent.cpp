

#include "NoiseGateComponent.h"




NoiseGateComponent::NoiseGateComponent(AudioProcessorValueTreeState& valueTreeState)
{
    
    m_textFont = Font(Typeface::createSystemTypefaceFor (BinaryData::SHPinscherRegular_otf, BinaryData::SHPinscherRegular_otfSize));

    m_attackLabel.setText("Attack", dontSendNotification);
    m_attackLabel.setFont(m_labelFontSize);
    m_attackLabel.setFont(m_textFont);
    m_attackLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_attackLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_attackLabel);
    
    m_releaseLabel.setText("Release", dontSendNotification);
    m_releaseLabel.setFont(m_labelFontSize);
    m_releaseLabel.setFont(m_textFont);
    m_releaseLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_releaseLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_releaseLabel);
    
    m_thresholdLabel.setText("Threshold", dontSendNotification);
    m_thresholdLabel.setFont(m_labelFontSize);
    m_thresholdLabel.setFont(m_textFont);
    m_thresholdLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_thresholdLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_thresholdLabel);
    
    addAndMakeVisible(&m_attackSlider);
    m_attackSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_attackSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_attackSlider.setTextValueSuffix(" ms");
    m_attackSlider.setPopupDisplayEnabled(true, this);
    m_attackSlider.setLookAndFeel(&m_customLAF);
    m_attackSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "noiseGateAttack", m_attackSlider);
    
    addAndMakeVisible(&m_releaseSlider);
    m_releaseSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_releaseSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_releaseSlider.setTextValueSuffix(" ms");
    m_releaseSlider.setPopupDisplayEnabled(true, this);
    m_releaseSlider.setLookAndFeel(&m_customLAF);
    m_releaseSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "noiseGateRelease",m_releaseSlider);
    
    addAndMakeVisible(&m_thresholdSlider);
    m_thresholdSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_thresholdSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_thresholdSlider.setTextValueSuffix(" dB");
    m_thresholdSlider.setPopupDisplayEnabled(true, this);
    m_thresholdSlider.setLookAndFeel(&m_customLAF);
    m_thresholdSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "noiseGateThreshold",m_thresholdSlider);
}


NoiseGateComponent::~NoiseGateComponent()
{
    
}


void NoiseGateComponent::sliderValueChanged(juce::Slider *slider)
{
    
}

void NoiseGateComponent::resized()
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
    m_thresholdLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_thresholdSlider.setBounds(xPos, yPos, knobSize, knobSize);
}

void NoiseGateComponent::paint(juce::Graphics &g)
{
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 10.f, 1.f);
    
    g.setFont(m_textFont);
    g.setFont(20.f);
    g.drawFittedText("Noise Gate", m_titleArea, Justification::centredLeft, 1);
}

