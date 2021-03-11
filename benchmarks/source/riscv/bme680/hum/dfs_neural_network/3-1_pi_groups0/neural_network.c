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
dense_1 (Dense)              (None, 3)                 12        
_________________________________________________________________
dense_2 (Dense)              (None, 1)                 4         
=================================================================
Total params: 16
Trainable params: 16
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][3] = {
{0.31271783, 1.3116152, -0.6671378, },
{0.26735452, -1.4793289, 0.8489237, },
{0.013627186, -0.14722455, -1.0700442, },
};
const float layer_0_biases[3] = {-0.31906885, 0.18469656, -0.18551625, };
float layer_0_output[3];

const float output_neuron_weights[3] = {1.5921552, -1.1108032, 0.08626993, };
const float output_neuron_bias = 0.5193408131599426;


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
float input_0[3] = {input[1], input[0]/input[1], 1/input[1]};
input_0[0] = input_0[0]*2.4983011552144543e-06 + -0.7340108726066276;
input_0[1] = input_0[1]*11.819142211288188 + -0.21709761474494596;
input_0[2] = input_0[2]*509459.3304153176 + -0.7340108726066276;
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
