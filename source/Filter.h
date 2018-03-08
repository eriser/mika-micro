#pragma once

#include "Util.h"

class Filter
{
public:
	void SetSampleRate(double sr) { dt = 44100.0 / sr; }

	void SetRes(double r) { res = r; }

	bool IsSilent() { return low == 0.0; }

	void ResetF() { reset = true; }
	double Process(double input, double targetF);

private:
	double FastAtan(double x) { return x / (1.0 + .28 * (x * x)); }

	double dt = 0.0;

	double res = 1.0;

	bool reset = false;
	double f = 1.0;
	double low = 0.0;
	double band = 0.0;
};

