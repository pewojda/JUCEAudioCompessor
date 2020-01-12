#include "Compressor.h"
#include "Envelope.h"
#include "PluginProcessor.h"
#include <cmath>

Compressor::Compressor()
{
	Compressor::threshold = 0;
	Compressor::threshold_lin = 0;
	Compressor::ratio = 0;
	Compressor::knee = 0;
	Compressor::attack = 0;
	Compressor::release = 0;
	Compressor::samplerate = 0;
	Compressor::channels = 0;
}

void Compressor::init(float threshold, float ratio, float knee, float attack, float release, int samplerate, int channels)
{
	Compressor::threshold = threshold;
	Compressor::threshold_lin = pow(10, threshold / 20);
	Compressor::ratio = ratio;
	Compressor::knee = knee;
	Compressor::attack = attack;
	Compressor::release = release;
	Compressor::samplerate = samplerate;
	Compressor::channels = channels;

	envelopes.clear();

	for (int i = 0; i < channels; ++i) {
		envelopes.emplace_back();
		envelopes[i].init(attack, release, samplerate);
	}
}

void Compressor::update()
{
	for (int i = 0; i < channels; ++i) {
		envelopes[i].changeAttack(attack);
		envelopes[i].changeRelease(release);
		envelopes[i].changeSamplerate(samplerate);
		envelopes[i].update();
	}
}

void Compressor::changeThreshold(float threshold)
{
	Compressor::threshold = pow(10, threshold / 20);
	update();
}

void Compressor::changeRatio(float ratio)
{
	Compressor::ratio = ratio;
	update();
}

void Compressor::changeKnee(float knee)
{
	Compressor::knee = knee;
	update();
}

void Compressor::changeAttack(float attack)
{
	Compressor::attack = attack;
	update();
}

void Compressor::changeRelease(float release)
{
	Compressor::release = release;
	update();
}

void Compressor::changeSamplerate(int samplerate)
{
	Compressor::samplerate = samplerate;
	update();
}

void Compressor::process(AudioBuffer<float>& buffer)
{
	for (int i = 0; i < channels; ++i) {

		auto* in = buffer.getReadPointer(i);
		auto* out = buffer.getWritePointer(i);

		std::vector<float> env(buffer.getNumSamples());

		envelopes[i].process(in, env.data(), buffer.getNumSamples());

		std::vector<float> gain(buffer.getNumSamples());

		for (int i = 0; i < buffer.getNumSamples(); ++i) {

			auto to_db = [](float lin) {return 20 * log10(lin); };
			auto to_lin = [](float db) {return pow(10, db / 20); };

			float kneeWidth = threshold * knee * -1.0;
			float lowerKneeBound = threshold - (kneeWidth / 2.0);
			float upperKneeBound = threshold + (kneeWidth / 2.0);

			float slope = 1.0 - (1.0 / ratio);

			if (kneeWidth > 0.0 && env[i] > lowerKneeBound && env[i] < upperKneeBound) {
				slope *= ((env[i] - lowerKneeBound) / kneeWidth) * 0.5;
				gain[i] = slope * (lowerKneeBound - env[i]);
			}
			else {
				gain[i] = slope * (threshold - to_db(env[i]));
				gain[i] = std::min((float)0.0, gain[i]);
			}
			
			gain[i] = to_lin(gain[i]);

			out[i] = in[i] * gain[i];

		}
	}
}

void Compressor::updateParams(float threshold, float ratio, float knee, float attack, float release, int samplerate)
{
	Compressor::threshold = threshold;
	Compressor::threshold_lin = pow(10, threshold / 20);
	Compressor::ratio = ratio;
	Compressor::knee = knee;
	Compressor::attack = attack;
	Compressor::release = release;
	Compressor::samplerate = samplerate;

	update();
}

float Compressor::getThreshold() const
{
	return threshold;
}

float Compressor::getRatio() const
{
	return ratio;
}

float Compressor::getKnee() const
{
	return knee;
}

float Compressor::getAttack() const
{
	return attack;
}

float Compressor::getRelease() const
{
	return release;
}

int Compressor::getSamplerate() const
{
	return samplerate;
}

int Compressor::getChannels() const {
	return channels;
}
