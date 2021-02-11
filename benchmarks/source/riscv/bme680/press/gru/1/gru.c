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

float predict(float input[2])
{
	input[0] = input[0]*2.059456509427162e-06 + -0.5627197182663495;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	float output_gate[state_size] = {sigmoid(input[0] * 4.26657676696777343750 + input[1] * -0.70207417011260986328 + state[0] * 3.00414919853210449219 + -1.86521255970001220703)};
	float forget_gate[state_size] = {sigmoid(input[0] * 15.65465545654296875000 + input[1] * -5.16762113571166992188 + state[0] * 10.71361255645751953125 + -7.26974058151245117188)};


	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   tanhf(input[0] * -6.95799350738525390625 + input[1] * 0.94798463582992553711 + forget_gate[0] * state[0] * -5.89046096801757812500 + 6.52127170562744140625);
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
	printf("expected_result = %f\n", 59669.03987);

	return 0;
}
