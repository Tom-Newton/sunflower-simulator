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
	input[0] = input[0]*5.969792848188168e-05 + -0.7649692555668318;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	float output_gate[state_size] = {softsign(input[0] * -0.34350404143333435059 + input[1] * -0.24216914176940917969 + state[0] * 0.89821761846542358398 + 0.40869048237800598145)};
	float forget_gate[state_size] = {softsign(input[0] * 2.22800683975219726562 + input[1] * 0.67036342620849609375 + state[0] * -1.48134899139404296875 + -0.99654877185821533203)};


	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   relu(input[0] * 0.98161798715591430664 + input[1] * 0.04331209138035774231 + forget_gate[0] * state[0] * 0.73424404859542846680 + -0.02623031474649906158);
	state[0] = output;
	
	output = (output - -0.010188503536061447)/0.010203688679615065;
	return output;
}

int main(void)
{
	float input[input_dimension] = {16347, 543639};

	LOGMARK(0);
	float hum = predict(input);
	LOGMARK(1);

	printf("Converted hum = %f\n", hum);
	printf("expected_result = %f\n", 18.186292);

	return 0;
}
