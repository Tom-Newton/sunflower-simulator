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
	input[0] = input[0]*5.969792848188168e-05 + -0.7649692555668318;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float ma_state[ma_state_size][input_dimension] = {{0, 0}};
	static float ar_state[ar_state_size] = {0, 0};

	float output = 0.00029661590815521777 + -0.14594134688377380371 +
				   (-0.00050068146083503962 + 1.03888499736785888672) * input[0] +
				   (-0.00002736092028499115 + 0.13752995431423187256) * input[1] +
				   -1.46985054016113281250 * ar_state[0] + -0.95989215373992919922 * ar_state[1] +
				   0.00032785304938443005 * ma_state[0][0] + -0.00022125121904537082 * ma_state[0][1];
	
	ar_state[1] = ar_state[0];
	ar_state[0] = output;

	ma_state[0][0] = input[0];
	ma_state[0][1] = input[1];

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
	printf("expected_result = %f\n", 16.599521);

	return 0;
}
