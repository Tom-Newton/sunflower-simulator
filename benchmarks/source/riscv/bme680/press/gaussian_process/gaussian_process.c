#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../../superh/port/logmarkers.h"

float gaussian_kernel(float x[2], float y[2])
{
	return 172.55812E9 * expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) / 11.25731E12);
}

void evaluate_cross_kernel(float x_star[2], float (*cross_kernel)[9])
{
	static float train_input_points[9][2] = {
		{738541.0, 293804.0},
		{758979.0, 492409.0},
		{776224.0, 694076.0},
		{478920.0, 293804.0},
		{523927.0, 492409.0},
		{562362.0, 694076.0},
		{221477.0, 293804.0},
		{290846.0, 492409.0},
		{350295.0, 694076.0}};

	for (int i = 0; i < 9; i++)
	{
		(*cross_kernel)[i] = gaussian_kernel(x_star, train_input_points[i]);
	}
}

float mean(float x_star[2])
{
	static float parameter_mean[9] = {
		0.00096469,
		-0.00290255,
		0.00210706,
		-0.00382518,
		0.01025932,
		-0.00685208,
		0.00292186,
		-0.00748054,
		0.0048086};

	float cross_kernel[9];
	evaluate_cross_kernel(x_star, &cross_kernel);

	float mean = 0;
	for (int i = 0; i < 9; i++)
	{
		mean += cross_kernel[i] * parameter_mean[i];
	}
	return mean;
}

int main(void)
{
	float x_star[2] = {738541, 293804};

	LOGMARK(0);
	float press = mean(x_star);
	LOGMARK(1);

	printf_("Converted press = %f\n", press);

	return 0;
}
