#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"

/* Model Summary:
Model: "sequential_1"
_________________________________________________________________
Layer (type)                 Output Shape              Param #   
=================================================================
dense_2 (Dense)              (None, 1)                 3         
_________________________________________________________________
dense_3 (Dense)              (None, 1)                 2         
=================================================================
Total params: 5
Trainable params: 5
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[1][2] = {
{1.8136615, 0.23755074, },
};
const float layer_0_biases[1] = {-0.29430538, };
float layer_0_output[1];

const float output_neuron_weights[1] = {0.6194541, };
const float output_neuron_bias = 0.030897827818989754;


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

float evaluate_network(float input[2])
{
	input[0]=input[0]*5.7123272021021365e-05 + -0.7282645949960014;
	input[1]=input[1]*2.4983011552144543e-06 + -0.7340108726066276;
	for (int neuron_index = 0; neuron_index < 1; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 2);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_0_output, 1);
	return (output - -0.010179742927756977)/0.01020346946349399;
}

int main()
{
	float input[2] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 4.025843143463135);
	return 0;
}
