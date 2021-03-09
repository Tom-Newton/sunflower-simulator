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

	float output_gate[state_size] = {softsign(input[0] * 0.01486274134367704391 + input[1] * -0.33787736296653747559 + state[0] * 0.31161791086196899414 + -0.03404971957206726074)};
	float forget_gate[state_size] = {softsign(input[0] * 0.65421354770660400391 + input[1] * -0.60573476552963256836 + state[0] * 0.61782228946685791016 + -0.64351636171340942383)};

	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   relu(input[0] * -0.88944488763809204102 + input[1] * 0.06379368901252746582 + forget_gate[0] * state[0] * -0.60755926370620727539 + 0.85812616348266601562);
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
	printf("expected_result = %f\n", 58487.463086);

	return 0;
}