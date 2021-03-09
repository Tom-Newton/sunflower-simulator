#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"

/* Model Summary:
Model: "sequential"
_________________________________________________________________
Layer (type)                 Output Shape              Param #   
=================================================================
dense (Dense)                (None, 1)                 2         
=================================================================
Total params: 2
Trainable params: 2
Non-trainable params: 0
_________________________________________________________________
*/

const float output_neuron_weights[1] = {1.0000386, };
const float output_neuron_bias = -0.00013767625205218792;


float relu(float x)
{
    if (x < 0)
    {
        return 0;
    }
    return x;
}

float neuron(const float *neuron_weights, const float neuron_bias, float *inputVector, int inputVectorSize)
{
    float sum = neuron_bias;
    for (int i = 0; i < inputVectorSize; i++)
    {
        sum += neuron_weights[i] * inputVector[i];
    }
    return relu(sum);
}

float evaluate_network(float input[1])
{
float input_0[1] = {26372/input[0]};
input_0[0] = input_0[0]*0.06588519806531559 + -0.7340108726066276;
	float output = neuron(output_neuron_weights, output_neuron_bias, input_0, 1);
output = (output - 0.32000005950859406)/5563858.142387389;
output = output*(26372*26372);
return output;
}

int main()
{
	float input[1] = {293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", -40.00001412179845);
	return 0;
}
