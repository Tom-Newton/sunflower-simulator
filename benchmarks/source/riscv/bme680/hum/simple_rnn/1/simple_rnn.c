#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define state_size 1
#define input_dimension 2

float predict(float input[2])
{
	input[0] = input[0]*5.969792848188168e-05 + -0.7649692555668318;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	float output = tanhf(-0.25576296448707580566 + 1.35969877243041992188*input[0] + 0.15631349384784698486*input[1] + state[0]*-0.03033968247473239899);
	
	state[0] = output;

	output = (output - -0.010188503536061447)/0.010203688679615065;
	return output;
}

int main(void)
{
	float input[2] = {16347, 543639};

	LOGMARK(0);
	float hum = predict(input);
	LOGMARK(1);

	printf("Converted hum = %f\n", hum);
	printf("expected_result = %f\n", 13.530848);

	return 0;
}
