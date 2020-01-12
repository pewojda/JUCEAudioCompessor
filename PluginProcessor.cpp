/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Compressor.h"

//==============================================================================
KompresorAudioProcessor::KompresorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), parameters(*this, nullptr)
#endif
{
	parameters.state = ValueTree(Identifier("Kompresor"));

	low_comp.init(0, 0, 0, 0, 0, getSampleRate(), getTotalNumInputChannels());
	mid_comp.init(0, 0, 0, 0, 0, getSampleRate(), getTotalNumInputChannels());
	high_comp.init(0, 0, 0, 0, 0, getSampleRate(), getTotalNumInputChannels());
}

KompresorAudioProcessor::~KompresorAudioProcessor()
{
}

//==============================================================================
const String KompresorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool KompresorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KompresorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KompresorAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double KompresorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KompresorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int KompresorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KompresorAudioProcessor::setCurrentProgram (int index)
{
}

const String KompresorAudioProcessor::getProgramName (int index)
{
    return {};
}

void KompresorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void KompresorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

	spec.maximumBlockSize = samplesPerBlock;
	spec.numChannels = getTotalNumOutputChannels();
	spec.sampleRate = sampleRate;

	low_filt.prepare(spec);
	mid_filt.prepare(spec);
	high_filt.prepare(spec);
}

void KompresorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.

	low_filt.reset();
	mid_filt.reset();
	high_filt.reset();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool KompresorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void KompresorAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }

	*low_filt.get<0>().state = *dsp::IIR::Coefficients<float>::makeFirstOrderLowPass(getSampleRate(), parameters.state.getProperty("frequency_1"));
	*low_filt.get<1>().state = *dsp::IIR::Coefficients<float>::makeFirstOrderAllPass(getSampleRate(), parameters.state.getProperty("frequency_2"));

	*mid_filt.get<0>().state = *dsp::IIR::Coefficients<float>::makeFirstOrderLowPass(getSampleRate(), parameters.state.getProperty("frequency_2"));
	*mid_filt.get<1>().state = *dsp::IIR::Coefficients<float>::makeFirstOrderHighPass(getSampleRate(), parameters.state.getProperty("frequency_1"));

	*high_filt.get<0>().state = *dsp::IIR::Coefficients<float>::makeFirstOrderHighPass(getSampleRate(), parameters.state.getProperty("frequency_1"));
	*high_filt.get<1>().state = *dsp::IIR::Coefficients<float>::makeFirstOrderHighPass(getSampleRate(), parameters.state.getProperty("frequency_2"));

	AudioBuffer<float> buffer_in;
	buffer_in.makeCopyOf(buffer);
	dsp::AudioBlock<float> block_in(buffer_in);

	dsp::AudioBlock<float> block_out(buffer);

	AudioBuffer<float> low_buffer;
	low_buffer.makeCopyOf(buffer_in);
	dsp::AudioBlock<float> low(low_buffer);
	AudioBuffer<float> mid_buffer;
	mid_buffer.makeCopyOf(buffer_in);
	dsp::AudioBlock<float> mid(mid_buffer);
	AudioBuffer<float> high_buffer;
	high_buffer.makeCopyOf(buffer_in);
	dsp::AudioBlock<float> high(high_buffer);

	dsp::ProcessContextNonReplacing<float> main_context(block_in, block_out);

	dsp::ProcessContextReplacing<float> low_context(low);
	dsp::ProcessContextReplacing<float> mid_context(mid);
	dsp::ProcessContextReplacing<float> high_context(high);

	low_filt.process(low_context);
	mid_filt.process(mid_context);
	high_filt.process(high_context);

	mid.multiply(-1);

	low_comp.updateParams(parameters.state.getProperty("low_thresh"), parameters.state.getProperty("ratio_low"), parameters.state.getProperty("knee"), (float)parameters.state.getProperty("attack_low") * pow(10, -3), (float)parameters.state.getProperty("release_low") * pow(10, -3), getSampleRate());
	mid_comp.updateParams(parameters.state.getProperty("mid_thresh"), parameters.state.getProperty("ratio_mid"), parameters.state.getProperty("knee"), (float)parameters.state.getProperty("attack_mid") * pow(10, -3), (float)parameters.state.getProperty("release_mid") * pow(10, -3), getSampleRate());
	high_comp.updateParams(parameters.state.getProperty("high_thresh"), parameters.state.getProperty("ratio_high"), parameters.state.getProperty("knee"), (float)parameters.state.getProperty("attack_high") * pow(10, -3), (float)parameters.state.getProperty("release_high") * pow(10, -3), getSampleRate());

	low_comp.process(low_buffer);
	mid_comp.process(mid_buffer);
	high_comp.process(high_buffer);

	low.multiply(!parameters.state.getProperty("mute_low"));
	mid.multiply(!parameters.state.getProperty("mute_mid"));
	high.multiply(!parameters.state.getProperty("mute_high"));

	main_context.getOutputBlock().clear();
	main_context.getOutputBlock() += low;
	main_context.getOutputBlock() += mid;
	main_context.getOutputBlock() += high;

	buffer.applyGain(pow(10.0 ,(float)parameters.state.getProperty("gain") / 20.0));
}

//==============================================================================
bool KompresorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* KompresorAudioProcessor::createEditor()
{
    return new KompresorAudioProcessorEditor (*this);
}

//==============================================================================
void KompresorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	auto state = parameters.copyState();
	std::unique_ptr<XmlElement> xml(state.createXml());
	copyXmlToBinary(*xml, destData);
}

void KompresorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
	if (xmlState.get() != nullptr)
		if (xmlState->hasTagName(parameters.state.getType()))
			parameters.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KompresorAudioProcessor();
}

AudioProcessorValueTreeState* KompresorAudioProcessor::getParameters() {
	return &parameters;
}
