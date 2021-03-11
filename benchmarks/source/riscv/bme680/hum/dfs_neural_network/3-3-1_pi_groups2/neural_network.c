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
dense (Dense)                (None, 3)                 9         
_________________________________________________________________
dense_1 (Dense)              (None, 3)                 12        
_________________________________________________________________
dense_2 (Dense)              (None, 1)                 4         
=================================================================
Total params: 25
Trainable params: 25
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][2] = {
{1.0543451, -0.2264969, },
{-0.08767891, -0.5407265, },
{0.08499137, -0.25086996, },
};
const float layer_0_biases[3] = {0.0059448774, 0.0, -0.13209313, };
float layer_0_output[3];

const float layer_1_weights[3][3] = {
{0.93034697, -0.21480465, -0.20217209, },
{-0.14396878, -0.49361348, 0.48930782, },
{0.5545353, -0.11140156, -0.78730136, },
};
const float layer_1_biases[3] = {-0.00082566065, -0.06303163, -0.23909557, };
float layer_1_output[3];

const float output_neuron_weights[3] = {1.0504619, -0.03775547, 0.5436086, };
const float output_neuron_bias = -0.00017363479128107429;


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
input[1] = input[0]/input[1];
input[0] = input[0]*5.7123272021021365e-05 + -0.7282645949960014;
input[1] = input[1]*11.819142211288188 + -0.21709761474494596;
	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 2);
	}

	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_1_output[neuron_index] = neuron(layer_1_weights[neuron_index], layer_1_biases[neuron_index], layer_0_output, 3);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_1_output, 3);
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
