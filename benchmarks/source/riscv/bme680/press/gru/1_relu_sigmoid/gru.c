#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define state_size 1
#define input_dimension 2

float sigmoid(float x)
{
	return 1 / (1 + expf(-x));
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

	float output_gate[state_size] = {sigmoid(input[0] * 0.04032552242279052734 + input[1] * -0.89646327495574951172 + state[0] * 0.73928999900817871094 + -0.77644789218902587891)};
	float forget_gate[state_size] = {sigmoid(input[0] * 1.29749298095703125000 + input[1] * -1.38655710220336914062 + state[0] * 1.21555590629577636719 + -1.85895407199859619141)};

	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   relu(input[0] * -1.34482216835021972656 + input[1] * 0.09562864154577255249 + forget_gate[0] * state[0] * -1.37637460231781005859 + 1.29807424545288085938);
	state[0] = output;

	output = (output - -0.37499996968700844) / 1.2499994367320406e-05;
	return output;
}

int main(void)
{
	float input[input_dimension] = {622901, 694076};

	LOGMARK(0);
	float press = predict(input);
	LOGMARK(1);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 58512.368302);

	return 0;
}
