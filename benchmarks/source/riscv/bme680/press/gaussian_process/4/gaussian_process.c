#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define number_training_points 4

float gaussian_kernel(float x[2], float y[2])
{
	return expf(12.937089037573198) * expf(12.937089037573198) *
		   expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) /
				(2 * expf(14.679445794794997) * expf(14.679445794794997)));
}

void evaluate_cross_kernel(float input[2], float (*cross_kernel)[number_training_points])
{
	static float train_input_points[number_training_points][2] = {
		{738541, 293804},
		{776224, 694076},
		{221477, 293804},
		{350295, 694076}};

	for (int i = 0; i < number_training_points; i++)
	{
		(*cross_kernel)[i] = gaussian_kernel(input, train_input_points[i]);
	}
}

float mean(float input[2])
{
	static float parameter_mean[number_training_points] = {
		0.00005876170547401140,
		-0.00008542129990529571,
		-0.00006161199882486618,
		0.00008818416234338824};

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
	float input[2] = {738541, 293804};

	LOGMARK(0);
	float press = mean(input);
	LOGMARK(1);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 30000.073067557067);

	return 0;
}
