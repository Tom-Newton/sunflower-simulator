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
	input[0] = input[0]*5.969792848188168e-05 + -0.7649692555668318;
	input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;

	static float state[state_size] = {0};

	if (reset_states)
	{
		float transformed_initial_label = initial_label * 0.010203688679615065 + -0.010188503536061447;
		state[0] = transformed_initial_label;
	}

	float output_gate[state_size] = {sigmoid(input[0] * 1.12700080871582031250 + input[1] * 0.15924258530139923096 + state[0] * -2.02423167228698730469 + 1.17723178863525390625)};
	float forget_gate[state_size] = {sigmoid(input[0] * -7.35302066802978515625 + input[1] * -1.95884263515472412109 + state[0] * 3.03914761543273925781 + 5.22411394119262695312)};


	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   tanhf(input[0] * 3.36223196983337402344 + input[1] * 0.27866742014884948730 + forget_gate[0] * state[0] * -3.15807557106018066406 + -0.16372995078563690186);
	state[0] = output;
	
	output = (output - -0.010188503536061447)/0.010203688679615065;
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
	printf("expected_result = %f\n", 18.513212);

	return 0;
}
