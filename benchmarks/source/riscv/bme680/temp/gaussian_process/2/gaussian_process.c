#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define number_training_points 2

float gaussian_kernel(float x, float y)
{
	return expf(7.968736260676217) * expf(7.968736260676217) *
		   expf(-((x - y) * (x - y)) /
				(2 * expf(16.275061443536504) * expf(16.275061443536504)));
}

void evaluate_cross_kernel(float input, float (*cross_kernel)[number_training_points])
{
	static float train_input_points[number_training_points] = {
		293804,
		694076};

	for (int i = 0; i < number_training_points; i++)
	{
		(*cross_kernel)[i] = gaussian_kernel(input, train_input_points[i]);
	}
}

float mean(float input)
{
	static float parameter_mean[number_training_points] = {
		-0.01278032969667357993,
		0.01278302590217098543};

	float cross_kernel[number_training_points];
	evaluate_cross_kernel(input, &cross_kernel);

	float mean = 0;
	for (int i = 0; i < number_training_points; i++)
	{
		mean += cross_kernel[i] * parameter_mean[i];
	}
	return mean;
}

int main(void)
{
	float input = 293804;

	LOGMARK(0);
	float temp = mean(input);
	LOGMARK(1);

	printf("Converted temp = %f\n", temp);
	printf("expected_result = %f\n", -39.92505161387089);

	return 0;
}
