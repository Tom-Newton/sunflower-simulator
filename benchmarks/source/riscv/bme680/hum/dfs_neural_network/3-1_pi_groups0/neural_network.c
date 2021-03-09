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
dense (Dense)                (None, 3)                 12        
_________________________________________________________________
dense_1 (Dense)              (None, 1)                 4         
=================================================================
Total params: 16
Trainable params: 16
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][3] = {
{0.31268337, 1.3114979, -0.66710377, },
{0.26738065, -1.4791635, 0.8489015, },
{0.0136272125, -0.14722458, -1.0700442, },
};
const float layer_0_biases[3] = {-0.3190966, 0.18468875, -0.18551625, };
float layer_0_output[3];

const float output_neuron_weights[3] = {1.592285, -1.1109515, 0.086269915, };
const float output_neuron_bias = 0.5193156599998474;


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

float evaluate_network(float input[3])
{
float input_0[3] = {input[1]*1009, input[0]/input[1], 785/input[1]};
input_0[0] = input_0[0]*2.476017002194702e-09 + -0.7340108726066275;
input_0[1] = input_0[1]*11.819142211288188 + -0.21709761474494596;
input_0[2] = input_0[2]*648.9927775991307 + -0.7340108726066276;
	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input_0, 3);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_0_output, 3);
output = (output - -0.010179742927756977)/0.01020346946349399;
return output;
}

int main()
{
	float input[3] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 0.9976746599946321);
	return 0;
}
