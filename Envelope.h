#pragma once
class Envelope
{
	float attack;
	float release;
	int samplerate;

	float const_attack;
	float const_release;

	float initsample;
public:
	Envelope();
	void init(float attack, float release, int samplerate);
	void changeAttack(float attack);
	void changeRelease(float release);
	void changeSamplerate(int samplerate);
	void update();
	void updateParams(float attack, float release, int samplerate);
	void process(const float *in, float *out, int size, bool reset = false);
	float getAttack() const;
	float getRelease() const;
	int getSamplerate() const;
};

