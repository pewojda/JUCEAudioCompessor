/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KompresorAudioProcessorEditor::KompresorAudioProcessorEditor (KompresorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    low_thresh.reset (new Slider ("low_thresh"));
    addAndMakeVisible (low_thresh.get());
    low_thresh->setRange (-60, 0, 0.1);
    low_thresh->setSliderStyle (Slider::LinearBarVertical);
    low_thresh->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    low_thresh->addListener (this);

    low_thresh->setBounds (128, 80, 40, 200);

    mid_thresh.reset (new Slider ("mid_thresh"));
    addAndMakeVisible (mid_thresh.get());
    mid_thresh->setRange (-60, 0, 0.1);
    mid_thresh->setSliderStyle (Slider::LinearBarVertical);
    mid_thresh->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mid_thresh->addListener (this);

    mid_thresh->setBounds (328, 80, 40, 200);

    high_thresh.reset (new Slider ("high_thresh"));
    addAndMakeVisible (high_thresh.get());
    high_thresh->setRange (-60, 0, 0.1);
    high_thresh->setSliderStyle (Slider::LinearBarVertical);
    high_thresh->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    high_thresh->addListener (this);

    high_thresh->setBounds (544, 80, 40, 200);

    ratio_low.reset (new Slider ("ratio_low"));
    addAndMakeVisible (ratio_low.get());
    ratio_low->setRange (-8, 12, 0.5);
    ratio_low->setSliderStyle (Slider::LinearBar);
    ratio_low->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    ratio_low->addListener (this);

    ratio_low->setBounds (40, 136, 72, 24);

    label.reset (new Label ("new label",
                            TRANS("Ratio\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredTop);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (41, 112, 71, 16);

    attack_low.reset (new Slider ("attack_low"));
    addAndMakeVisible (attack_low.get());
    attack_low->setRange (0, 500, 0.1);
    attack_low->setSliderStyle (Slider::LinearBar);
    attack_low->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    attack_low->addListener (this);

    attack_low->setBounds (40, 192, 72, 24);

    label2.reset (new Label ("new label",
                             TRANS("Attack\n")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredTop);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (41, 168, 71, 16);

    release_low.reset (new Slider ("release_low"));
    addAndMakeVisible (release_low.get());
    release_low->setRange (1, 2000, 0.1);
    release_low->setSliderStyle (Slider::LinearBar);
    release_low->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    release_low->addListener (this);

    release_low->setBounds (40, 253, 72, 24);

    label3.reset (new Label ("new label",
                             TRANS("Release\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredTop);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (41, 229, 71, 16);

    frequency_1.reset (new Slider ("frequency_1"));
    addAndMakeVisible (frequency_1.get());
    frequency_1->setRange (20, 2000, 1);
    frequency_1->setSliderStyle (Slider::LinearBar);
    frequency_1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    frequency_1->addListener (this);

    frequency_1->setBounds (120, 32, 112, 24);

    label4.reset (new Label ("new label",
                             TRANS("Frequency Low")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredTop);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (120, 8, 112, 16);

    frequency_2.reset (new Slider ("frequency_2"));
    addAndMakeVisible (frequency_2.get());
    frequency_2->setRange (2000, 10000, 1);
    frequency_2->setSliderStyle (Slider::LinearBar);
    frequency_2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    frequency_2->addListener (this);

    frequency_2->setBounds (240, 32, 115, 24);

    label5.reset (new Label ("new label",
                             TRANS("Frequency High\n")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredTop);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (240, 8, 112, 16);

    label6.reset (new Label ("new label",
                             TRANS("Knee\n")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredTop);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (360, 8, 112, 16);

    ratio_mid.reset (new Slider ("ratio_mid"));
    addAndMakeVisible (ratio_mid.get());
    ratio_mid->setRange (-8, 12, 0.5);
    ratio_mid->setSliderStyle (Slider::LinearBar);
    ratio_mid->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    ratio_mid->addListener (this);

    ratio_mid->setBounds (237, 138, 72, 24);

    label7.reset (new Label ("new label",
                             TRANS("Ratio\n")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredTop);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (238, 114, 71, 16);

    attack_mid.reset (new Slider ("attack_mid"));
    addAndMakeVisible (attack_mid.get());
    attack_mid->setRange (0, 500, 0.1);
    attack_mid->setSliderStyle (Slider::LinearBar);
    attack_mid->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    attack_mid->addListener (this);

    attack_mid->setBounds (237, 194, 72, 24);

    label8.reset (new Label ("new label",
                             TRANS("Attack\n")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredTop);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (238, 170, 71, 16);

    release_mid.reset (new Slider ("release_mid"));
    addAndMakeVisible (release_mid.get());
    release_mid->setRange (1, 2000, 0.1);
    release_mid->setSliderStyle (Slider::LinearBar);
    release_mid->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    release_mid->addListener (this);

    release_mid->setBounds (237, 255, 72, 24);

    label9.reset (new Label ("new label",
                             TRANS("Release\n")));
    addAndMakeVisible (label9.get());
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredTop);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label9->setBounds (238, 231, 71, 16);

    ratio_high.reset (new Slider ("ratio_high"));
    addAndMakeVisible (ratio_high.get());
    ratio_high->setRange (-8, 12, 0.5);
    ratio_high->setSliderStyle (Slider::LinearBar);
    ratio_high->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    ratio_high->addListener (this);

    ratio_high->setBounds (450, 139, 72, 24);

    label10.reset (new Label ("new label",
                              TRANS("Ratio\n")));
    addAndMakeVisible (label10.get());
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centredTop);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label10->setBounds (451, 115, 71, 16);

    attack_high.reset (new Slider ("attack_high"));
    addAndMakeVisible (attack_high.get());
    attack_high->setRange (0, 500, 0.1);
    attack_high->setSliderStyle (Slider::LinearBar);
    attack_high->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    attack_high->addListener (this);

    attack_high->setBounds (450, 195, 72, 24);

    label11.reset (new Label ("new label",
                              TRANS("Attack\n")));
    addAndMakeVisible (label11.get());
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredTop);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label11->setBounds (451, 171, 71, 16);

    release_high.reset (new Slider ("release_high"));
    addAndMakeVisible (release_high.get());
    release_high->setRange (1, 2000, 0.1);
    release_high->setSliderStyle (Slider::LinearBar);
    release_high->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    release_high->addListener (this);

    release_high->setBounds (450, 256, 72, 24);

    label12.reset (new Label ("new label",
                              TRANS("Release\n")));
    addAndMakeVisible (label12.get());
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centredTop);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label12->setBounds (451, 232, 71, 16);

    mute_low.reset (new ToggleButton ("mute_low"));
    addAndMakeVisible (mute_low.get());
    mute_low->setButtonText (TRANS("Mute"));
    mute_low->addListener (this);

    mute_low->setBounds (40, 80, 72, 24);

    mute_mid.reset (new ToggleButton ("mute_mid"));
    addAndMakeVisible (mute_mid.get());
    mute_mid->setButtonText (TRANS("Mute"));
    mute_mid->addListener (this);

    mute_mid->setBounds (240, 80, 72, 24);

    mute_high.reset (new ToggleButton ("mute_high"));
    addAndMakeVisible (mute_high.get());
    mute_high->setButtonText (TRANS("Mute"));
    mute_high->addListener (this);

    mute_high->setBounds (448, 80, 72, 24);

    knee.reset (new Slider ("knee"));
    addAndMakeVisible (knee.get());
    knee->setRange (0, 1, 0.01);
    knee->setSliderStyle (Slider::LinearBar);
    knee->setTextBoxStyle (Slider::TextBoxLeft, true, 80, 20);
    knee->addListener (this);

    knee->setBounds (368, 32, 96, 24);

    gain.reset (new Slider ("gain"));
    addAndMakeVisible (gain.get());
    gain->setRange (-10, 30, 0.1);
    gain->setSliderStyle (Slider::LinearBar);
    gain->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    gain->addListener (this);

    gain->setBounds (208, 312, 184, 24);

    label13.reset (new Label ("new label",
                              TRANS("Gain")));
    addAndMakeVisible (label13.get());
    label13->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label13->setBounds (152, 312, 48, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 350);


    //[Constructor] You can add your own custom stuff here..
	frequency_1->setValue(200.0, dontSendNotification);
	frequency_2->setValue(6000.0, dontSendNotification);
	knee->setValue(0.0, dontSendNotification);
	ratio_low->setValue(2.0, dontSendNotification);
	ratio_mid->setValue(2.0, dontSendNotification);
	ratio_high->setValue(2.0, dontSendNotification);
	attack_low->setValue(5.0, dontSendNotification);
	attack_mid->setValue(5.0, dontSendNotification);
	attack_high->setValue(5.0, dontSendNotification);
	release_low->setValue(200.0, dontSendNotification);
	release_mid->setValue(200.0, dontSendNotification);
	release_high->setValue(200.0, dontSendNotification);
	gain->setValue(0.0, dontSendNotification);

	if (p.getParameters()->state.getPropertyPointer("frequency_1") == nullptr) {
		p.getParameters()->state.setProperty("frequency_1", frequency_1->getValue(), nullptr);
	}
	else {
		frequency_1->setValue(p.getParameters()->state.getProperty("frequency_1"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("frequency_2") == nullptr) {
		p.getParameters()->state.setProperty("frequency_2", frequency_2->getValue(), nullptr);
	}
	else {
		frequency_2->setValue(p.getParameters()->state.getProperty("frequency_2"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("knee") == nullptr) {
		p.getParameters()->state.setProperty("knee", knee->getValue(), nullptr);
	}
	else {
		knee->setValue(p.getParameters()->state.getProperty("knee"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("ratio_low") == nullptr) {
		p.getParameters()->state.setProperty("ratio_low", ratio_low->getValue(), nullptr);
	}
	else {
		ratio_low->setValue(p.getParameters()->state.getProperty("ratio_low"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("ratio_mid") == nullptr) {
		p.getParameters()->state.setProperty("ratio_mid", ratio_mid->getValue(), nullptr);
	}
	else {
		ratio_mid->setValue(p.getParameters()->state.getProperty("ratio_mid"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("ratio_high") == nullptr) {
		p.getParameters()->state.setProperty("ratio_high", ratio_high->getValue(), nullptr);
	}
	else {
		ratio_high->setValue(p.getParameters()->state.getProperty("ratio_high"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("attack_low") == nullptr) {
		p.getParameters()->state.setProperty("attack_low", attack_low->getValue(), nullptr);
	}
	else {
		attack_low->setValue(p.getParameters()->state.getProperty("attack_low"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("attack_mid") == nullptr) {
		p.getParameters()->state.setProperty("attack_mid", attack_mid->getValue(), nullptr);
	}
	else {
		attack_mid->setValue(p.getParameters()->state.getProperty("attack_mid"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("attack_high") == nullptr) {
		p.getParameters()->state.setProperty("attack_high", attack_high->getValue(), nullptr);
	}
	else {
		attack_high->setValue(p.getParameters()->state.getProperty("attack_high"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("release_low") == nullptr) {
		p.getParameters()->state.setProperty("release_low", release_low->getValue(), nullptr);
	}
	else {
		release_low->setValue(p.getParameters()->state.getProperty("release_low"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("release_mid") == nullptr) {
		p.getParameters()->state.setProperty("release_mid", release_mid->getValue(), nullptr);
	}
	else {
		release_mid->setValue(p.getParameters()->state.getProperty("release_mid"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("release_high") == nullptr) {
		p.getParameters()->state.setProperty("release_high", release_high->getValue(), nullptr);
	}
	else {
		release_high->setValue(p.getParameters()->state.getProperty("release_high"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("mute_low") == nullptr) {
		p.getParameters()->state.setProperty("mute_low", mute_low->getToggleState(), nullptr);
	}
	else {
		mute_low->setToggleState(p.getParameters()->state.getProperty("mute_low"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("mute_mid") == nullptr) {
		p.getParameters()->state.setProperty("mute_mid", mute_mid->getToggleState(), nullptr);
	}
	else {
		mute_mid->setToggleState(p.getParameters()->state.getProperty("mute_mid"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("mute_high") == nullptr) {
		p.getParameters()->state.setProperty("mute_high", mute_high->getToggleState(), nullptr);
	}
	else {
		mute_high->setToggleState(p.getParameters()->state.getProperty("mute_high"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("low_thresh") == nullptr) {
		p.getParameters()->state.setProperty("low_thresh", low_thresh->getValue(), nullptr);
	}
	else {
		low_thresh->setValue(p.getParameters()->state.getProperty("low_thresh"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("mid_thresh") == nullptr) {
		p.getParameters()->state.setProperty("mid_thresh", mid_thresh->getValue(), nullptr);
	}
	else {
		mid_thresh->setValue(p.getParameters()->state.getProperty("mid_thresh"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("high_thresh") == nullptr) {
		p.getParameters()->state.setProperty("high_thresh", high_thresh->getValue(), nullptr);
	}
	else {
		high_thresh->setValue(p.getParameters()->state.getProperty("high_thresh"), dontSendNotification);
	}

	if (p.getParameters()->state.getPropertyPointer("gain") == nullptr) {
		p.getParameters()->state.setProperty("gain", gain->getValue(), nullptr);
	}
	else {
		gain->setValue(p.getParameters()->state.getProperty("gain"), dontSendNotification);
	}
    //[/Constructor]
}

KompresorAudioProcessorEditor::~KompresorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    low_thresh = nullptr;
    mid_thresh = nullptr;
    high_thresh = nullptr;
    ratio_low = nullptr;
    label = nullptr;
    attack_low = nullptr;
    label2 = nullptr;
    release_low = nullptr;
    label3 = nullptr;
    frequency_1 = nullptr;
    label4 = nullptr;
    frequency_2 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    ratio_mid = nullptr;
    label7 = nullptr;
    attack_mid = nullptr;
    label8 = nullptr;
    release_mid = nullptr;
    label9 = nullptr;
    ratio_high = nullptr;
    label10 = nullptr;
    attack_high = nullptr;
    label11 = nullptr;
    release_high = nullptr;
    label12 = nullptr;
    mute_low = nullptr;
    mute_mid = nullptr;
    mute_high = nullptr;
    knee = nullptr;
    gain = nullptr;
    label13 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KompresorAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 0, y = 64, width = 200, height = 236;
        Colour strokeColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = 200, y = 64, width = 200, height = 236;
        Colour strokeColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = 400, y = 64, width = 200, height = 236;
        Colour strokeColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    //[UserPaint] Add your own custom painting code here..
	if (processor.getParameters()->state.getPropertyPointer("frequency_1") == nullptr) {
		processor.getParameters()->state.setProperty("frequency_1", frequency_1->getValue(), nullptr);
	}
	else {
		frequency_1->setValue(processor.getParameters()->state.getProperty("frequency_1"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("frequency_2") == nullptr) {
		processor.getParameters()->state.setProperty("frequency_2", frequency_2->getValue(), nullptr);
	}
	else {
		frequency_2->setValue(processor.getParameters()->state.getProperty("frequency_2"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("knee") == nullptr) {
		processor.getParameters()->state.setProperty("knee", knee->getValue(), nullptr);
	}
	else {
		knee->setValue(processor.getParameters()->state.getProperty("knee"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("ratio_low") == nullptr) {
		processor.getParameters()->state.setProperty("ratio_low", ratio_low->getValue(), nullptr);
	}
	else {
		ratio_low->setValue(processor.getParameters()->state.getProperty("ratio_low"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("ratio_mid") == nullptr) {
		processor.getParameters()->state.setProperty("ratio_mid", ratio_mid->getValue(), nullptr);
	}
	else {
		ratio_mid->setValue(processor.getParameters()->state.getProperty("ratio_mid"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("ratio_high") == nullptr) {
		processor.getParameters()->state.setProperty("ratio_high", ratio_high->getValue(), nullptr);
	}
	else {
		ratio_high->setValue(processor.getParameters()->state.getProperty("ratio_high"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("attack_low") == nullptr) {
		processor.getParameters()->state.setProperty("attack_low", attack_low->getValue(), nullptr);
	}
	else {
		attack_low->setValue(processor.getParameters()->state.getProperty("attack_low"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("attack_mid") == nullptr) {
		processor.getParameters()->state.setProperty("attack_mid", attack_mid->getValue(), nullptr);
	}
	else {
		attack_mid->setValue(processor.getParameters()->state.getProperty("attack_mid"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("attack_high") == nullptr) {
		processor.getParameters()->state.setProperty("attack_high", attack_high->getValue(), nullptr);
	}
	else {
		attack_high->setValue(processor.getParameters()->state.getProperty("attack_high"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("release_low") == nullptr) {
		processor.getParameters()->state.setProperty("release_low", release_low->getValue(), nullptr);
	}
	else {
		release_low->setValue(processor.getParameters()->state.getProperty("release_low"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("release_mid") == nullptr) {
		processor.getParameters()->state.setProperty("release_mid", release_mid->getValue(), nullptr);
	}
	else {
		release_mid->setValue(processor.getParameters()->state.getProperty("release_mid"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("release_high") == nullptr) {
		processor.getParameters()->state.setProperty("release_high", release_high->getValue(), nullptr);
	}
	else {
		release_high->setValue(processor.getParameters()->state.getProperty("release_high"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("mute_low") == nullptr) {
		processor.getParameters()->state.setProperty("mute_low", mute_low->getToggleState(), nullptr);
	}
	else {
		mute_low->setToggleState(processor.getParameters()->state.getProperty("mute_low"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("mute_mid") == nullptr) {
		processor.getParameters()->state.setProperty("mute_mid", mute_mid->getToggleState(), nullptr);
	}
	else {
		mute_mid->setToggleState(processor.getParameters()->state.getProperty("mute_mid"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("mute_high") == nullptr) {
		processor.getParameters()->state.setProperty("mute_high", mute_high->getToggleState(), nullptr);
	}
	else {
		mute_high->setToggleState(processor.getParameters()->state.getProperty("mute_high"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("low_thresh") == nullptr) {
		processor.getParameters()->state.setProperty("low_thresh", low_thresh->getValue(), nullptr);
	}
	else {
		low_thresh->setValue(processor.getParameters()->state.getProperty("low_thresh"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("mid_thresh") == nullptr) {
		processor.getParameters()->state.setProperty("mid_thresh", mid_thresh->getValue(), nullptr);
	}
	else {
		mid_thresh->setValue(processor.getParameters()->state.getProperty("mid_thresh"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("high_thresh") == nullptr) {
		processor.getParameters()->state.setProperty("high_thresh", high_thresh->getValue(), nullptr);
	}
	else {
		high_thresh->setValue(processor.getParameters()->state.getProperty("high_thresh"), dontSendNotification);
	}

	if (processor.getParameters()->state.getPropertyPointer("gain") == nullptr) {
		processor.getParameters()->state.setProperty("gain", gain->getValue(), nullptr);
	}
	else {
		gain->setValue(processor.getParameters()->state.getProperty("gain"), dontSendNotification);
	}
    //[/UserPaint]
}

void KompresorAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void KompresorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	processor.getParameters()->state.setProperty(sliderThatWasMoved->getName(), sliderThatWasMoved->getValue(), nullptr);
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == low_thresh.get())
    {
        //[UserSliderCode_low_thresh] -- add your slider handling code here..
        //[/UserSliderCode_low_thresh]
    }
    else if (sliderThatWasMoved == mid_thresh.get())
    {
        //[UserSliderCode_mid_thresh] -- add your slider handling code here..
        //[/UserSliderCode_mid_thresh]
    }
    else if (sliderThatWasMoved == high_thresh.get())
    {
        //[UserSliderCode_high_thresh] -- add your slider handling code here..
        //[/UserSliderCode_high_thresh]
    }
    else if (sliderThatWasMoved == ratio_low.get())
    {
        //[UserSliderCode_ratio_low] -- add your slider handling code here..
        //[/UserSliderCode_ratio_low]
    }
    else if (sliderThatWasMoved == attack_low.get())
    {
        //[UserSliderCode_attack_low] -- add your slider handling code here..
        //[/UserSliderCode_attack_low]
    }
    else if (sliderThatWasMoved == release_low.get())
    {
        //[UserSliderCode_release_low] -- add your slider handling code here..
        //[/UserSliderCode_release_low]
    }
    else if (sliderThatWasMoved == frequency_1.get())
    {
        //[UserSliderCode_frequency_1] -- add your slider handling code here..
        //[/UserSliderCode_frequency_1]
    }
    else if (sliderThatWasMoved == frequency_2.get())
    {
        //[UserSliderCode_frequency_2] -- add your slider handling code here..
        //[/UserSliderCode_frequency_2]
    }
    else if (sliderThatWasMoved == ratio_mid.get())
    {
        //[UserSliderCode_ratio_mid] -- add your slider handling code here..
        //[/UserSliderCode_ratio_mid]
    }
    else if (sliderThatWasMoved == attack_mid.get())
    {
        //[UserSliderCode_attack_mid] -- add your slider handling code here..
        //[/UserSliderCode_attack_mid]
    }
    else if (sliderThatWasMoved == release_mid.get())
    {
        //[UserSliderCode_release_mid] -- add your slider handling code here..
        //[/UserSliderCode_release_mid]
    }
    else if (sliderThatWasMoved == ratio_high.get())
    {
        //[UserSliderCode_ratio_high] -- add your slider handling code here..
        //[/UserSliderCode_ratio_high]
    }
    else if (sliderThatWasMoved == attack_high.get())
    {
        //[UserSliderCode_attack_high] -- add your slider handling code here..
        //[/UserSliderCode_attack_high]
    }
    else if (sliderThatWasMoved == release_high.get())
    {
        //[UserSliderCode_release_high] -- add your slider handling code here..
        //[/UserSliderCode_release_high]
    }
    else if (sliderThatWasMoved == knee.get())
    {
        //[UserSliderCode_knee] -- add your slider handling code here..
        //[/UserSliderCode_knee]
    }
    else if (sliderThatWasMoved == gain.get())
    {
        //[UserSliderCode_gain] -- add your slider handling code here..
        //[/UserSliderCode_gain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void KompresorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	processor.getParameters()->state.setProperty(buttonThatWasClicked->getName(), buttonThatWasClicked->getToggleState(), nullptr);
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == mute_low.get())
    {
        //[UserButtonCode_mute_low] -- add your button handler code here..
        //[/UserButtonCode_mute_low]
    }
    else if (buttonThatWasClicked == mute_mid.get())
    {
        //[UserButtonCode_mute_mid] -- add your button handler code here..
        //[/UserButtonCode_mute_mid]
    }
    else if (buttonThatWasClicked == mute_high.get())
    {
        //[UserButtonCode_mute_high] -- add your button handler code here..
        //[/UserButtonCode_mute_high]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KompresorAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="KompresorAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="350">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 64 200 236" fill="solid: 782aa5" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff000000"/>
    <RECT pos="200 64 200 236" fill="solid: 782aa5" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff000000"/>
    <RECT pos="400 64 200 236" fill="solid: 782aa5" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <SLIDER name="low_thresh" id="20d1648ed586940a" memberName="low_thresh"
          virtualName="" explicitFocusOrder="0" pos="128 80 40 200" min="-60.00000000000000000000"
          max="0.00000000000000000000" int="0.10000000000000000555" style="LinearBarVertical"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="mid_thresh" id="c890fad2b76e9437" memberName="mid_thresh"
          virtualName="" explicitFocusOrder="0" pos="328 80 40 200" min="-60.00000000000000000000"
          max="0.00000000000000000000" int="0.10000000000000000555" style="LinearBarVertical"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="high_thresh" id="d8510c760f6fb6f" memberName="high_thresh"
          virtualName="" explicitFocusOrder="0" pos="544 80 40 200" min="-60.00000000000000000000"
          max="0.00000000000000000000" int="0.10000000000000000555" style="LinearBarVertical"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="ratio_low" id="b372fe97c6cae12b" memberName="ratio_low"
          virtualName="" explicitFocusOrder="0" pos="40 136 72 24" min="-8.00000000000000000000"
          max="12.00000000000000000000" int="0.50000000000000000000" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="a9a5bfa6af70900d" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="41 112 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Ratio&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="12"/>
  <SLIDER name="attack_low" id="a87817fd12e10b6f" memberName="attack_low"
          virtualName="" explicitFocusOrder="0" pos="40 192 72 24" min="0.00000000000000000000"
          max="500.00000000000000000000" int="0.10000000000000000555" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="fbd9b858a2cca2a1" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="41 168 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <SLIDER name="release_low" id="528cc76e0a929e12" memberName="release_low"
          virtualName="" explicitFocusOrder="0" pos="40 253 72 24" min="1.00000000000000000000"
          max="2000.00000000000000000000" int="0.10000000000000000555"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="d9d79091003d2d20" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="41 229 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Release&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <SLIDER name="frequency_1" id="87c5f5e65515f4a6" memberName="frequency_1"
          virtualName="" explicitFocusOrder="0" pos="120 32 112 24" min="20.00000000000000000000"
          max="2000.00000000000000000000" int="1.00000000000000000000"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="d2c8712437c724f0" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="120 8 112 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency Low" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <SLIDER name="frequency_2" id="48f21656b3a1d966" memberName="frequency_2"
          virtualName="" explicitFocusOrder="0" pos="240 32 115 24" min="2000.00000000000000000000"
          max="10000.00000000000000000000" int="1.00000000000000000000"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="d25941e564d5b976" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="240 8 112 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency High&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <LABEL name="new label" id="50342f59fe4f5ce4" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="360 8 112 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Knee&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="12"/>
  <SLIDER name="ratio_mid" id="ebd3714a1022195b" memberName="ratio_mid"
          virtualName="" explicitFocusOrder="0" pos="237 138 72 24" min="-8.00000000000000000000"
          max="12.00000000000000000000" int="0.50000000000000000000" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="6591dc097dc735aa" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="238 114 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Ratio&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="12"/>
  <SLIDER name="attack_mid" id="dc3437101de139f9" memberName="attack_mid"
          virtualName="" explicitFocusOrder="0" pos="237 194 72 24" min="0.00000000000000000000"
          max="500.00000000000000000000" int="0.10000000000000000555" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="dc56cf0d24eac016" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="238 170 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <SLIDER name="release_mid" id="2d58ae8ff68dd5b2" memberName="release_mid"
          virtualName="" explicitFocusOrder="0" pos="237 255 72 24" min="1.00000000000000000000"
          max="2000.00000000000000000000" int="0.10000000000000000555"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="16aadd63bf636ec1" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="238 231 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Release&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <SLIDER name="ratio_high" id="9d5fa69a608570b9" memberName="ratio_high"
          virtualName="" explicitFocusOrder="0" pos="450 139 72 24" min="-8.00000000000000000000"
          max="12.00000000000000000000" int="0.50000000000000000000" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="cf998346c62a6d40" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="451 115 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Ratio&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="12"/>
  <SLIDER name="attack_high" id="d79d48e587f225c2" memberName="attack_high"
          virtualName="" explicitFocusOrder="0" pos="450 195 72 24" min="0.00000000000000000000"
          max="500.00000000000000000000" int="0.10000000000000000555" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="56ad4fe47d992c57" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="451 171 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <SLIDER name="release_high" id="4cc95c556291cb7a" memberName="release_high"
          virtualName="" explicitFocusOrder="0" pos="450 256 72 24" min="1.00000000000000000000"
          max="2000.00000000000000000000" int="0.10000000000000000555"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="12523072f8a05052" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="451 232 71 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Release&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="12"/>
  <TOGGLEBUTTON name="mute_low" id="8df4a9e39b0c76e0" memberName="mute_low" virtualName=""
                explicitFocusOrder="0" pos="40 80 72 24" buttonText="Mute" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="mute_mid" id="6f8830cb6482affb" memberName="mute_mid" virtualName=""
                explicitFocusOrder="0" pos="240 80 72 24" buttonText="Mute" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="mute_high" id="9cd273d1f9a95fd7" memberName="mute_high"
                virtualName="" explicitFocusOrder="0" pos="448 80 72 24" buttonText="Mute"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="knee" id="86a06375c8fc210" memberName="knee" virtualName=""
          explicitFocusOrder="0" pos="368 32 96 24" min="0.00000000000000000000"
          max="1.00000000000000000000" int="0.01000000000000000021" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="gain" id="6905d73063900bbe" memberName="gain" virtualName=""
          explicitFocusOrder="0" pos="208 312 184 24" min="-10.00000000000000000000"
          max="30.00000000000000000000" int="0.10000000000000000555" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="856e6be1f445536" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="152 312 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
