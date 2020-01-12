#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"
#include <vector>

class Compressor {
	float threshold;
	float threshold_lin;
	float ratio;
	float knee;
	float attack;
	float release;
	int samplerate;
	int channels;
	std::vector<Envelope> envelopes;

public:
	Compressor();
	void init(float threshold, float ratio, float knee, float attack, float release, int samplerate, int channels);
	void update();
	void changeThreshold(float threshold);
	void changeRatio(float ratio);
	void changeKnee(float knee);
	void changeAttack(float attack);
	void changeRelease(float release);
	void changeSamplerate(int samplerate);
	void process(AudioBuffer<float> &buffer);
	void updateParams(float threshold, float ratio, float knee, float attack, float release, int samplerate);
	float getThreshold() const;
	float getRatio() const;
	float getKnee() const;
	float getAttack() const;
	float getRelease() const;
	int getSamplerate() const;
	int getChannels() const;
};