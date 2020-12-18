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
dense_3 (Dense)              (None, 3)                 9         
_________________________________________________________________
dense_4 (Dense)              (None, 3)                 12        
_________________________________________________________________
dense_5 (Dense)              (None, 1)                 4         
=================================================================
Total params: 25
Trainable params: 25
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][2] = {
{1.925793, 0.25492004, },
{-0.08767891, -0.5407265, },
{0.10773916, -0.23489985, },
};
const float layer_0_biases[3] = {-0.20881517, 0.0, -0.10846725, };
float layer_0_output[3];

const float layer_1_weights[3][3] = {
{0.9564484, -0.21480465, -0.20084654, },
{-0.1503629, -0.49361348, 0.48309687, },
{0.80640805, -0.11140156, -0.78963935, },
};
const float layer_1_biases[3] = {-0.0027160367, -0.06799506, -0.73998904, };
float layer_1_output[3];

const float output_neuron_weights[3] = {0.5242437, -0.03416225, 0.18121205, };
const float output_neuron_bias = 0.011859674006700516;


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
	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 2);
	}

	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_1_output[neuron_index] = neuron(layer_1_weights[neuron_index], layer_1_biases[neuron_index], layer_0_output, 3);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_1_output, 3);
	return (output - -0.010179742927756977)/0.01020346946349399;
}

int main()
{
	float input[2] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 2.1599924564361572);
	return 0;
}
