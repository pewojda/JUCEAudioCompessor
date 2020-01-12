#include "Envelope.h"
#include <cmath>


Envelope::Envelope()
{
	Envelope::attack = 0;
	Envelope::release = 0;
	Envelope::samplerate = 0;
	Envelope::initsample = 0;
	update();
}

void Envelope::init(float attack, float release, int samplerate) {
	Envelope::attack = attack;
	Envelope::release = release;
	Envelope::samplerate = samplerate;
	Envelope::initsample = 0;
	update();
}

void Envelope::changeAttack(float attack) {
	Envelope::attack = attack;
	update();
}

void Envelope::changeRelease(float release) {
	Envelope::release = release;
	update();
}

void Envelope::changeSamplerate(int samplerate) {
	Envelope::samplerate = samplerate;
	update();
}

void Envelope::update() {
	const_attack = exp(-1 / (samplerate*attack));
	const_release = exp(-1 / (samplerate*release));
}

void Envelope::updateParams(float attack, float release, int samplerate)
{
	Envelope::attack = attack;
	Envelope::release = release;
	Envelope::samplerate = samplerate;
	update();
}

void Envelope::process(const float *in, float *out, int size, bool reset) {
	if (reset) initsample = 0;

	for (int i = 0; i < size; ++i) {
		float abs_in = abs(in[i]);

		if (initsample < abs_in) {
			initsample *= const_attack;
			initsample += (1 - const_attack)*abs_in;
		}

		if (initsample > abs_in) {
			initsample *= const_release;
			initsample += (1 - const_release)*abs_in;
		}
		out[i] = initsample;
	}
}

float Envelope::getAttack() const
{
	return attack;
}

float Envelope::getRelease() const
{
	return release;
}

int Envelope::getSamplerate() const
{
	return samplerate;
}
