#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define ar_state_size 2
#define ma_state_size 1
#define input_dimension 2

float predict(float input[2], bool reset_states, float initial_label)
{
	input[0] = input[0]*2.059456509427162e-06 + -0.5627197182663495;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float ma_state[ma_state_size][input_dimension] = {{0, 0}};
	static float ar_state[ar_state_size] = {0, 0};

	if (reset_states)
	{
		float transformed_initial_label = initial_label*1.2499994367320406e-05 + -0.37499996968700844;
		ar_state[0] = transformed_initial_label;
		ar_state[1] = transformed_initial_label;
		ma_state[0][0] = 0;
		ma_state[0][1] = 0;
	}

	float output = 0.69102334976196289062 + 0.02721103839576244354 +
				   (-0.62211757898330688477 + -0.16098716855049133301) * input[0] +
				   (-0.01151726208627223969 + 0.13621032238006591797) * input[1] +
				   0.42129915952682495117 * ar_state[0] + -0.17284591495990753174 * ar_state[1] +
				   -0.04121445491909980774 * ma_state[0][0] + 0.04895013570785522461 * ma_state[0][1];
	output = (output - -0.37499996968700844)/1.2499994367320406e-05;
	return output;
}

int main(void)
{
	float input[2] = {622901, 694076};
	float initial_label = 58656.926994;

	LOGMARK(0);
	float press = predict(input, true, initial_label);
	LOGMARK(1);
	float press2 = predict(input, false, initial_label);
	LOGMARK(2);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 59439.907592);

	return 0;
}
