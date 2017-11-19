/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
DynamicProcessorAudioProcessor::DynamicProcessorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
, m_parameters (*this, nullptr)
{
    m_parameters.createAndAddParameter ("transientShaperAttack",                        // parameter ID
                                        "Transient Shaper Attack",                      // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (-100.f, 100.f, 1.f),  // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    m_parameters.createAndAddParameter ("transientShaperRelease",                       // parameter ID
                                        "Transient Shaper Release",                     // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (-100.f, 100.f, 1.f),  // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    
    m_parameters.createAndAddParameter ("transientShaperGain",                          // parameter ID
                                        "Transient Shaper Makeup Gain",                 // parameter name
                                        "dB",                                           // parameter label (suffix)
                                        NormalisableRange<float> (-6.f, 6.0f, 1.f),     // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    m_parameters.createAndAddParameter ("noiseGateAttack",                        // parameter ID
                                        "Noise Gate Attack",                      // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (100.f, 2000.f, 1.f),  // range
                                        200.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    
    m_parameters.createAndAddParameter ("noiseGateRelease",                       // parameter ID
                                        "Noise Gate Release",                     // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (100.f, 2000.f, 1.f),  // range
                                        1.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    
    m_parameters.createAndAddParameter ("noiseGateThreshold",                          // parameter ID
                                        "Noise Gate Threshold",                 // parameter name
                                        "dB",                                           // parameter label (suffix)
                                        NormalisableRange<float> (-60.f, 0.0f, 1.f),     // range
                                        -10.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    
    m_parameters.createAndAddParameter ("compressorAttack",                        // parameter ID
                                        "Compressor Attack",                      // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (100.f, 2000.f, 1.f),  // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    m_parameters.createAndAddParameter ("compressorRelease",                        // parameter ID
                                        "Compressor Release",                      // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (100.f, 2000.f, 1.f),  // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    
    m_parameters.createAndAddParameter ("compressorThreshold",                        // parameter ID
                                        "Compressor Threshold",                      // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (-60.f, 0.f, 1.f),  // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    m_parameters.createAndAddParameter ("compressorRatio",                        // parameter ID
                                        "Compressor Ratio",                      // parameter name
                                        "ms",                                           // parameter label (suffix)
                                        NormalisableRange<float> (1.f, 200.f, 1.f, 0.25f),  // range
                                        1.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    m_parameters.createAndAddParameter ("compressorGain",                          // parameter ID
                                        "Compressor Makeup Gain",                 // parameter name
                                        "dB",                                           // parameter label (suffix)
                                        NormalisableRange<float> (-6.f, 6.0f, 1.f),     // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    m_parameters.createAndAddParameter ("compressorAutoGain",                          // parameter ID
                                        "Compressor Auto Makeup Gain",                 // parameter name
                                        " ",                                           // parameter label (suffix)
                                        NormalisableRange<float> (0.f, 1.f, 1.f),     // range
                                        0.f,                                            // default value
                                        nullptr,
                                        nullptr);
    
    
    
    
    m_parameters.state = ValueTree (Identifier ("DynamicProcessor"));

}

DynamicProcessorAudioProcessor::~DynamicProcessorAudioProcessor()
{

}

const String DynamicProcessorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DynamicProcessorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DynamicProcessorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double DynamicProcessorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DynamicProcessorAudioProcessor::getNumPrograms()
{
    return 1;
}

int DynamicProcessorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DynamicProcessorAudioProcessor::setCurrentProgram (int index)
{
}

const String DynamicProcessorAudioProcessor::getProgramName (int index)
{
    return {};
}

void DynamicProcessorAudioProcessor::changeProgramName (int index, const String& newName)
{
}


void DynamicProcessorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

}

void DynamicProcessorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DynamicProcessorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DynamicProcessorAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const float attack = *m_parameters.getRawParameterValue ("transientShaperAttack");
}


bool DynamicProcessorAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* DynamicProcessorAudioProcessor::createEditor()
{
    return new DynamicProcessorAudioProcessorEditor (*this, m_parameters);
}


void DynamicProcessorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    ScopedPointer<XmlElement> xml (m_parameters.state.createXml());
    copyXmlToBinary (*xml, destData);
}

void DynamicProcessorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    
    if (xmlState != nullptr)
    {
        if (xmlState->hasTagName (m_parameters.state.getType()))
        {
            m_parameters.state = ValueTree::fromXml (*xmlState);
        }
    }
}


// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DynamicProcessorAudioProcessor();
}
