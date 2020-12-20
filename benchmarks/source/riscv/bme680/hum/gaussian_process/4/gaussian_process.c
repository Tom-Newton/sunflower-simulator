#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define number_training_points 4

float gaussian_kernel(float x[2], float y[2])
{
	return expf(4.5551530550530925) * expf(4.5551530550530925) *
		   expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) /
				(2 * expf(15.27860381595202) * expf(15.27860381595202))) *
		   expf(4.5551530550530925) * expf(4.5551530550530925) *
		   expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) /
				(2 * expf(12.880708856351463) * expf(12.880708856351463)));
}

void evaluate_cross_kernel(float input[2], float (*cross_kernel)[number_training_points])
{
	static float train_input_points[number_training_points][2] = {
		{12840, 293804},
		{12749, 694076},
		{30255, 293804},
		{27476, 694076}};

	for (int i = 0; i < number_training_points; i++)
	{
		(*cross_kernel)[i] = gaussian_kernel(input, train_input_points[i]);
	}
}

float mean(float input[2])
{
	static float parameter_mean[number_training_points] = {
		-0.00027868685483879154,
		-0.00064882217522352077,
		0.00027896428735629082,
		0.00064929583146771991};

	float cross_kernel[number_training_points];
	evaluate_cross_kernel(input, &cross_kernel);

	float mean = 0;
	for (int i = 0; i < 9; i++)
	{
		mean += cross_kernel[i] * parameter_mean[i];
	}
	return mean;
}

int main(void)
{
	float input[2] = {12840, 293804};

	LOGMARK(0);
	float hum = mean(input);
	LOGMARK(1);

	printf("Converted hum = %f\n", hum);
	printf("expected_result = %f\n", 1.001303720913711);

	return 0;
}
