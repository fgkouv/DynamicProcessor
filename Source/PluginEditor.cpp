

#include "PluginProcessor.h"
#include "PluginEditor.h"

DynamicProcessorAudioProcessorEditor::DynamicProcessorAudioProcessorEditor(DynamicProcessorAudioProcessor& p, AudioProcessorValueTreeState& vts)
:
AudioProcessorEditor (&p),
processor (p),
m_transientShaperUI(vts),
m_noiseGateUI(vts),
m_compressorUI(vts)
{
    setSize (500, 800);
    
    addAndMakeVisible(&m_transientShaperUI);
    addAndMakeVisible(&m_noiseGateUI);
    addAndMakeVisible(&m_compressorUI);
    
}

DynamicProcessorAudioProcessorEditor::~DynamicProcessorAudioProcessorEditor()
{
    
}

void DynamicProcessorAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    float width = getWidth();
    float height = getHeight();
    
    juce::Rectangle<int> logoArea = juce::Rectangle<int>(0.7 * width, 0.65 * height, 0.2 * width, 0.2 * height);
    
    Font logoFont = Font(Typeface::createSystemTypefaceFor (BinaryData::Lombok_otf, BinaryData::Lombok_otfSize));
    
    g.setFont(logoFont);
    g.setFont(30.f);
    g.drawFittedText("QUA.REJ", logoArea, juce::Justification::centredBottom, 1);
}

void DynamicProcessorAudioProcessorEditor::resized()
{
    int offset = 5;
    m_transientShaperUI.setBounds(offset, offset, 0.5f * getWidth(), 0.2f * getHeight());
    m_noiseGateUI.setBounds(offset, 0.2f * getHeight() + 2 * offset, 0.5f * getWidth(), 0.2f * getHeight());
    m_compressorUI.setBounds(offset, 0.4f * getHeight() + 3 * offset, 0.5f * getWidth(), 0.25f * getHeight());
}
