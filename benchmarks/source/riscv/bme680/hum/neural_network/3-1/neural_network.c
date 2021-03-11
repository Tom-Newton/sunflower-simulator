#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"

/* Model Summary:
Model: "sequential_2"
_________________________________________________________________
Layer (type)                 Output Shape              Param #   
=================================================================
dense_4 (Dense)              (None, 3)                 9         
_________________________________________________________________
dense_5 (Dense)              (None, 1)                 4         
=================================================================
Total params: 13
Trainable params: 13
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][2] = {
{0.949912, 0.061576176, },
{-0.08767891, -0.5407265, },
{0.5216674, 0.22855234, },
};
const float layer_0_biases[3] = {-0.032200843, 0.0, -0.36726508, };
float layer_0_output[3];

const float output_neuron_weights[3] = {0.9703822, -0.098027945, 0.61876696, };
const float output_neuron_bias = -0.01812700182199478;


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
input[0] = input[0]*5.7123272021021365e-05 + -0.7282645949960014;
input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;
	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 2);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_0_output, 3);
output = (output - -0.010179742927756977)/0.01020346946349399;
return output;
}

int main()
{
	float input[2] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 0.9976746599946321);
	return 0;
}
