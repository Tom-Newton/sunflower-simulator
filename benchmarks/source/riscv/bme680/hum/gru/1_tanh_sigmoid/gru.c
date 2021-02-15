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
	input[0] = input[0]*5.969792848188168e-05 + -0.7649692555668318;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	float output_gate[state_size] = {sigmoid(input[0] * -4.54780149459838867188 + input[1] * -0.61354088783264160156 + state[0] * 3.48991179466247558594 + 2.83082127571105957031)};
	float forget_gate[state_size] = {sigmoid(input[0] * -7.19928693771362304688 + input[1] * -2.04525446891784667969 + state[0] * 3.83244895935058593750 + 4.91294765472412109375)};


	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   tanhf(input[0] * 7.09004259109497070312 + input[1] * 0.50249993801116943359 + forget_gate[0] * state[0] * -7.93172788619995117188 + -0.31117677688598632812);
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
	printf("expected_result = %f\n", 17.324345);

	return 0;
}
