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

	float forget_gate[state_size] = {softsign(input[0] * 2.24184703826904296875 + input[1] * 1.73561024665832519531 + state[0] * 0.81404781341552734375 + -2.87958765029907226562)};

	float output = relu(input[0] * 0.98688334226608276367 + input[1] * 0.10040589421987533569 + forget_gate[0] * state[0] * 0.10416917502880096436 + -0.09280458837747573853);
	state[0] = output;

	output = (output - -0.010188503536061447)/0.010203688679615065;
	return output;
}

int main(void)
{
	float input[input_dimension] = {16347, 543639};

	LOGMARK(0);
	float result = predict(input);
	LOGMARK(1);

	printf("Converted result = %f\n", result);
	printf("expected_result = %f\n", 18.4443);

	return 0;
}
