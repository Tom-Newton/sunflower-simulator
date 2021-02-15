#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define state_size 1
#define input_dimension 2

float relu(float x)
{
	if (x < 0)
	{
		return 0;
	}
	return x;
}

float predict(float input[2])
{
	input[0] = input[0] * 2.059456509427162e-06 + -0.5627197182663495;
	input[1] = input[1] * 2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	float output = relu(0.94724708795547485352 + -1.02806663513183593750 * input[0] + 0.16640673577785491943 * input[1] + state[0] * -0.00002362415762036107);

	state[0] = output;

	output = (output - -0.37499996968700844) / 1.2499994367320406e-05;
	return output;
}

int main(void)
{
	float input[2] = {622901, 694076};

	LOGMARK(0);
	float result = predict(input);
	LOGMARK(1);

	printf("Converted result = %f\n", result);
	printf("expected_result = %f\n", 59866.0047);

	return 0;
}
