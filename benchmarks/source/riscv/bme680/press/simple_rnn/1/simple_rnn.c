#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define state_size 1
#define input_dimension 2

float predict(float input[2])
{
	input[0] = input[0]*2.059456509427162e-06 + -0.5627197182663495;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	float output = tanhf(1.13868212699890136719 + -1.29711759090423583984*input[0] + 0.19344264268875122070*input[1] + state[0]*-0.01480337511748075485);
	
	state[0] = output;

	output = (output - -0.37499996968700844)/1.2499994367320406e-05;
	return output;
}

int main(void)
{
	float input[2] = {622901, 694076};

	LOGMARK(0);
	float press = predict(input);
	LOGMARK(1);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 60262.175494);

	return 0;
}
