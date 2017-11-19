
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "DynamicProcessorLAF.h"
#include "TransientShaperComponent.h"
#include "NoiseGateComponent.h"
#include "CompressorComponent.h"

class DynamicProcessorAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    DynamicProcessorAudioProcessorEditor (DynamicProcessorAudioProcessor& processor, AudioProcessorValueTreeState& vts);
    ~DynamicProcessorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:

    DynamicProcessorAudioProcessor& processor;
    
    TransientShaperComponent m_transientShaperUI;
    NoiseGateComponent m_noiseGateUI;
    CompressorComponent m_compressorUI;
    
    DynamicProcessorLAF m_dynamicProcessorLAF;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DynamicProcessorAudioProcessorEditor)
};
