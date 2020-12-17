#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../superh/port/logmarkers.h"

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
{0.550133, 0.6289439, },
{0.4117484, 0.18359625, },
{-0.8239893, -0.61251974, },
};
const float layer_0_biases[3] = {0.0, 0.0, 0.0, };
float layer_0_output[3];

const float layer_1_weights[3][3] = {
{0.116461515, 0.5877342, -0.324121, },
{-0.59323573, 0.36768246, 0.9524884, },
{-0.82047105, -0.065820694, 0.5682764, },
};
const float layer_1_biases[3] = {0.0, 0.0, 0.0, };
float layer_1_output[3];

const float output_neuron_weights[3] = {-0.8269653, -0.098255396, -0.5508415, };
const float output_neuron_bias = 0.0;


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
	input[0]=input[0]*1.8026235382976384e-06 + -0.39923965339154605;
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
	return (output - -0.37499857438644063)/1.2499979050552e-05;
}

int main()
{
	float input[2] = {738541.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 29999.935546875);
	return 0;
}
