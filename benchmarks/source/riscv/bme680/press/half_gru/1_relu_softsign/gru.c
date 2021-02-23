#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define state_size 1
#define input_dimension 2

float softsign(float x)
{
	return x/(1 + fabsf(x));
}
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

	float forget_gate[state_size] = {softsign(input[0] * 0.13461300730705261230 + input[1] * 0.30388662219047546387 + state[0] * 0.16369985044002532959 + -0.29480984807014465332)};

	float output = relu(input[0] * -1.02577900886535644531 + input[1] * 0.12748387455940246582 + forget_gate[0] * state[0] * 0.32136216759681701660 + 0.96438956260681152344);
	state[0] = output;

	output = (output - -0.37499996968700844) / 1.2499994367320406e-05;
	return output;
}

int main(void)
{
	float input[input_dimension] = {622901, 694076};

	LOGMARK(0);
	float result = predict(input);
	LOGMARK(1);

	printf("Converted result = %f\n", result);
	printf("expected_result = %f\n", 58255.362494);

	return 0;
}
