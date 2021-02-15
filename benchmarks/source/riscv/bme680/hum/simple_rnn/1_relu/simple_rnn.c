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
	input[0] = input[0]*5.969792848188168e-05 + -0.7649692555668318;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	float output = relu(-0.15149357914924621582 + 1.04587256908416748047 * input[0] + 0.14043632149696350098 * input[1] + state[0] * 0.00022849392553325742);

	state[0] = output;

	output = (output - -0.010188503536061447)/0.010203688679615065;
	return output;
}

int main(void)
{
	float input[2] = {16347, 543639};

	LOGMARK(0);
	float result = predict(input);
	LOGMARK(1);

	printf("Converted result = %f\n", result);
	printf("expected_result = %f\n", 16.360553);

	return 0;
}
