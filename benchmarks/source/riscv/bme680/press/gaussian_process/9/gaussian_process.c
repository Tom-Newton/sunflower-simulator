#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define number_training_points 9


float gaussian_kernel(float x[2], float y[2])
{
	return expf(12.937089037573198) * expf(12.937089037573198) *
		   expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) /
				(2 * expf(14.679445794794997) * expf(14.679445794794997)));
}

void evaluate_cross_kernel(float input[2], float (*cross_kernel)[number_training_points])
{
	static float train_input_points[number_training_points][2] = {
		{738541.0, 293804.0},
		{758979.0, 492409.0},
		{776224.0, 694076.0},
		{478920.0, 293804.0},
		{523927.0, 492409.0},
		{562362.0, 694076.0},
		{221477.0, 293804.0},
		{290846.0, 492409.0},
		{350295.0, 694076.0}};

	for (int i = 0; i < number_training_points; i++)
	{
		(*cross_kernel)[i] = gaussian_kernel(input, train_input_points[i]);
	}
}

float mean(float input[2])
{
	static float parameter_mean[number_training_points] = {
		0.00096469070550853075,
		-0.00290255013698725861,
		0.00210706214568645578,
		-0.00382518281193711118,
		0.01025932145469710122,
		-0.00685207828732359303,
		0.00292185735953154335,
		-0.00748053889917343895,
		0.00480860352554302040};

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
	printf("expected_result = %f\n", 30000.082103848457);

	return 0;
}
