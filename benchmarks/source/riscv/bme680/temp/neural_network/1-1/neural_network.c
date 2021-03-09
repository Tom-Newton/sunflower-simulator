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
_________________________________________________________________
dense_1 (Dense)              (None, 1)                 2         
=================================================================
Total params: 4
Trainable params: 4
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[1][1] = {
{1.0134239, },
};
const float layer_0_biases[1] = {-0.00013950569, };
float layer_0_output[1];

const float output_neuron_weights[1] = {0.98679197, };
const float output_neuron_bias = -3.031586004453857e-08;


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
	input[0]=input[0]*2.4983011552144543e-06 + -0.7340108726066276;
	for (int neuron_index = 0; neuron_index < 1; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 1);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_0_output, 1);
	return (output - 0.32000005950859406)/0.007999998663355634;
}

int main()
{
	float input[1] = {293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", -40.0000114440918);
	return 0;
}
