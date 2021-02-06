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
		state[1] = transformed_initial_label;
	}

	float output_gate[state_size] = {sigmoid(input[0] * -0.85940176248550415039 + input[1] * -0.23951263725757598877 + state[0] * -0.06910761445760726929 + 0.10083637386560440063 + 0.10083637386560440063)};
	float forget_gate[state_size] = {sigmoid(input[0] * 0.63198220729827880859 + input[1] * -0.06936411559581756592 + state[0] * -0.67112284898757934570 + -0.09291975945234298706 + -0.09291975945234298706)};

	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   tanhf(input[0] * 0.94886767864227294922 + input[1] * -0.31985044479370117188 + forget_gate[0] * state[0] * 0.70614594221115112305 + -0.01456232741475105286 + -0.01612281613051891327);
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
	printf("expected_result = %f\n", 62686.876847);

	return 0;
}
