#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define ar_state_size 2
#define ma_state_size 1
#define input_dimension 2

float predict(float input[2])
{
	input[0] = input[0]*2.059456509427162e-06 + -0.5627197182663495;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float ma_state[ma_state_size][input_dimension] = {{0, 0}};
	static float ar_state[ar_state_size] = {0, 0};

	float output = 0.23239611089229583740 + 0.61854439973831176758 +
				   (-0.17492766678333282471 + -0.74483805894851684570) * input[0] +
				   (-0.30142074823379516602 + 0.53025776147842407227) * input[1] +
				   0.54591494798660278320 * ar_state[0] + -0.25370252132415771484 * ar_state[1] +
				   -0.03924603015184402466 * ma_state[0][0] + 0.06837829947471618652 * ma_state[0][1];
	
	ar_state[1] = ar_state[0];
	ar_state[0] = output;

	ma_state[0][0] = input[0];
	ma_state[0][1] = input[1];

	output = (output - -0.37499996968700844)/1.2499994367320406e-05;
	return output;
}

int main(void)
{
	float input[2] = {622901, 694076};

	LOGMARK(0);
	float press = predict(input);
	LOGMARK(1);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 63395.054256);

	return 0;
}
