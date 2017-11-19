
#include "CompressorComponent.h"


CompressorComponent::CompressorComponent(AudioProcessorValueTreeState& valueTreeState)
{
    
    m_textFont = Font(Typeface::createSystemTypefaceFor (BinaryData::SHPinscherRegular_otf, BinaryData::SHPinscherRegular_otfSize));
    
    
    m_autoMakeupButton.setButtonText("AUTOGAIN");
    m_autoMakeupButton.setToggleState(false, dontSendNotification);
    m_autoMakeupButton.setLookAndFeel(&m_customLAF);
    m_autoGainButtonAttachment = new juce::AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "compressorAutoGain",m_autoMakeupButton);
    addAndMakeVisible(&m_autoMakeupButton);
    
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
    
    m_ratioLabel.setText("Ratio", dontSendNotification);
    m_ratioLabel.setFont(m_labelFontSize);
    m_ratioLabel.setFont(m_textFont);
    m_ratioLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_ratioLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_ratioLabel);
    
    m_makeupGainLabel.setText("Makeup Gain", dontSendNotification);
    m_makeupGainLabel.setFont(m_labelFontSize);
    m_makeupGainLabel.setFont(m_textFont);
    m_makeupGainLabel.setColour(Label::ColourIds::textColourId, Colours::black);
    m_makeupGainLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&m_makeupGainLabel);
    
    addAndMakeVisible(&m_attackSlider);
    m_attackSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_attackSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_attackSlider.setTextValueSuffix(" ms");
    m_attackSlider.setPopupDisplayEnabled(true, this);
    m_attackSlider.setLookAndFeel(&m_customLAF);
    m_attackSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compressorAttack",m_attackSlider);
    
    addAndMakeVisible(&m_releaseSlider);
    m_releaseSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_releaseSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_releaseSlider.setTextValueSuffix(" ms");
    m_releaseSlider.setPopupDisplayEnabled(true, this);
    m_releaseSlider.setLookAndFeel(&m_customLAF);
    m_releaseSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compressorRelease",m_releaseSlider);
    
    addAndMakeVisible(&m_thresholdSlider);
    m_thresholdSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_thresholdSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_thresholdSlider.setTextValueSuffix(" dB");
    m_thresholdSlider.setPopupDisplayEnabled(true, this);
    m_thresholdSlider.setLookAndFeel(&m_customLAF);
    m_thresholdSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compressorThreshold",m_thresholdSlider);
    
    addAndMakeVisible(&m_ratioSlider);
    m_ratioSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_ratioSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_ratioSlider.setTextValueSuffix(" : 1");
    m_ratioSlider.setPopupDisplayEnabled(true, this);
    m_ratioSlider.setLookAndFeel(&m_customLAF);
    m_ratioSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compressorRatio", m_ratioSlider);
    
    addAndMakeVisible(&m_makeupGainSlider);
    m_makeupGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    m_makeupGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    m_makeupGainSlider.setTextValueSuffix(" dB");
    m_makeupGainSlider.setPopupDisplayEnabled(true, this);
    m_makeupGainSlider.setLookAndFeel(&m_customLAF);
    m_makeupGainSliderAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compressorGain",m_makeupGainSlider);
}


CompressorComponent::~CompressorComponent()
{
    
}


void CompressorComponent::sliderValueChanged(juce::Slider *slider)
{
    
}

void CompressorComponent::resized()
{
    float width = getWidth();
    
    float titleHeight = 30;
    float labelHeight = m_labelFontSize + 3.f;
    m_titleArea = juce::Rectangle<int>(5, 5, width, titleHeight);
    
    float horizontalOffset = 10.f;
    //float knobSize = jmin(0.33f * (width - 2 * horizontalOffset), 0.5f * getHeight() - titleHeight - labelHeight);
    float knobSize = 65.f;
    float xPos = horizontalOffset;
    float yPos = m_titleArea.getBottom() + 2;
    
    m_attackLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_attackSlider.setBounds(xPos, yPos, knobSize, knobSize);
    
    xPos += knobSize;
    yPos -= labelHeight;
    m_releaseLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_releaseSlider.setBounds(xPos, yPos, knobSize, knobSize);
    
    xPos = 10.f;
    yPos += knobSize;
    m_thresholdLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_thresholdSlider.setBounds(xPos, yPos, knobSize, knobSize);

    xPos += knobSize;
    yPos -= labelHeight;
    m_ratioLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_ratioSlider.setBounds(xPos, yPos, knobSize, knobSize);
    
    
    
    xPos += knobSize + 2 * horizontalOffset;
    yPos = m_attackSlider.getY() + 0.25 * knobSize;
    m_autoMakeupButton.setBounds(xPos, yPos, knobSize, 0.5 * knobSize);
    
    //xPos = getWidth() - horizontalOffset - knobSize;
    yPos = m_ratioLabel.getY();
    m_makeupGainLabel.setBounds(xPos, yPos, knobSize, labelHeight);
    yPos += labelHeight;
    m_makeupGainSlider.setBounds(xPos, yPos, knobSize, knobSize);
}

void CompressorComponent::paint(juce::Graphics &g)
{
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 10.f, 1.f);
    
    g.setFont(m_textFont);
    g.setFont(20.f);
    g.drawFittedText("Compressor", m_titleArea, Justification::centredLeft, 1);
}

