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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KompresorAudioProcessorEditor  : public AudioProcessorEditor,
                                       public Slider::Listener,
                                       public Button::Listener
{
public:
    //==============================================================================
    KompresorAudioProcessorEditor (KompresorAudioProcessor& p);
    ~KompresorAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    KompresorAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> low_thresh;
    std::unique_ptr<Slider> mid_thresh;
    std::unique_ptr<Slider> high_thresh;
    std::unique_ptr<Slider> ratio_low;
    std::unique_ptr<Label> label;
    std::unique_ptr<Slider> attack_low;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> release_low;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> frequency_1;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Slider> frequency_2;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Slider> ratio_mid;
    std::unique_ptr<Label> label7;
    std::unique_ptr<Slider> attack_mid;
    std::unique_ptr<Label> label8;
    std::unique_ptr<Slider> release_mid;
    std::unique_ptr<Label> label9;
    std::unique_ptr<Slider> ratio_high;
    std::unique_ptr<Label> label10;
    std::unique_ptr<Slider> attack_high;
    std::unique_ptr<Label> label11;
    std::unique_ptr<Slider> release_high;
    std::unique_ptr<Label> label12;
    std::unique_ptr<ToggleButton> mute_low;
    std::unique_ptr<ToggleButton> mute_mid;
    std::unique_ptr<ToggleButton> mute_high;
    std::unique_ptr<Slider> knee;
    std::unique_ptr<Slider> gain;
    std::unique_ptr<Label> label13;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KompresorAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
