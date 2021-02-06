#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../../../../superh/port/logmarkers.h"

#define ar_state_size 2
#define ma_state_size 1
#define input_dimension 2

float predict(float input[input_dimension], bool reset_states, float initial_label)
{
	input[0] = input[0] * 5.969792848188168e-05 + -0.7649692555668318;
	input[1] = input[1] * 2.4983011552144543e-06 + -0.7340108726066276;

	static float ma_state[ma_state_size][input_dimension] = {{0, 0}};
	static float ar_state[ar_state_size] = {0, 0};

	if (reset_states)
	{
		float transformed_initial_label = initial_label * 0.010203688679615065 + -0.010188503536061447;
		ar_state[0] = transformed_initial_label;
		ar_state[1] = transformed_initial_label;
		ma_state[0][0] = 0;
		ma_state[0][1] = 0;
	}

	float output = 0.09243402630090713501 + -0.27642777562141418457 +
				   (0.51061952114105224609 + 0.31642121076583862305) * input[0] +
				   (-0.07335481792688369751 + 0.22794730961322784424) * input[1] +
				   0.53241693973541259766 * ar_state[0] + -0.23956160247325897217 * ar_state[1] +
				   -0.00136420398484915495 * ma_state[0][0] + 0.01269345171749591827 * ma_state[0][1];

	ar_state[1] = ar_state[0];
	ar_state[0] = output;

	ma_state[0][0] = input[0];
	ma_state[0][1] = input[1];

	output = (output - -0.010188503536061447) / 0.010203688679615065;
	return output;
}

int main(void)
{
	float input[input_dimension] = {16347, 543639};
	float initial_label = 17.999593;

	LOGMARK(0);
	float hum = predict(input, true, initial_label);
	LOGMARK(1);
	float hum2 = predict(input, false, initial_label);
	LOGMARK(2);

	printf("Converted hum = %f\n", hum);
	printf("expected_result = %f\n", 14.4969);

	return 0;
}
