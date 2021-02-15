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

	float output_gate[state_size] = {sigmoid(input[0] * -0.51209306716918945312 + input[1] * -0.35485029220581054688 + state[0] * 0.75328582525253295898 + 0.89761650562286376953)};
	float forget_gate[state_size] = {sigmoid(input[0] * -5.22200775146484375000 + input[1] * -1.80016767978668212891 + state[0] * 3.09795022010803222656 + 3.27204632759094238281)};


	float output = output_gate[0] * state[0] + (1 - output_gate[0]) *
												   relu(input[0] * 2.296919584274291992192 + input[1] * 0.11030149459838867188 + forget_gate[0] * state[0] * -2.12639331817626953125 + -0.07310368865728378296);
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
	printf("expected_result = %f\n", 18.018914);

	return 0;
}
