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

float predict(float input[2], bool reset_states, float initial_label)
{
	input[0] = input[0]*2.059456509427162e-06 + -0.5627197182663495;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	if (reset_states)
	{
		float transformed_initial_label = initial_label * 1.2499994367320406e-05 + -0.37499996968700844;
		state[0] = transformed_initial_label;
	}

	float output_gate[state_size] = {sigmoid(input[0] * 0.47724983096122741699 + input[1] * -0.31615862250328063965 + state[0] * -0.80062437057495117188 + 0.27962753176689147949)};
	float forget_gate[state_size] = {sigmoid(input[0] * 7.10969924926757812500 + input[1] * -3.01183509826660156250 + state[0] * 0.08229340612888336182 + 0.79827982187271118164)};


	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   tanhf(input[0] * -2.51875472068786621094 + input[1] * 0.35096794366836547852 + forget_gate[0] * state[0] * -1.40747070312500000000 + 2.34080910682678222656);
	state[0] = output;
	
	output = (output - -0.37499996968700844) / 1.2499994367320406e-05;
	return output;
}

int main(void)
{
	float input[input_dimension] = {622901, 694076};
	float initial_label = 58656.926994;

	LOGMARK(0);
	float press = predict(input, true, initial_label);
	LOGMARK(1);
	float press2 = predict(input, false, initial_label);
	LOGMARK(2);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 59491.243903);

	return 0;
}
