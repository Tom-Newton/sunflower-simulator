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
dense_8 (Dense)              (None, 5)                 15        
_________________________________________________________________
dense_9 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_10 (Dense)             (None, 5)                 30        
_________________________________________________________________
dense_11 (Dense)             (None, 1)                 6         
=================================================================
Total params: 81
Trainable params: 81
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[5][2] = {
{1.1689041, 0.083643965, },
{-0.07410216, -0.29086787, },
{-0.22786818, 0.21696934, },
{-0.19887048, -0.8422644, },
{0.38523656, 0.66967106, },
};
const float layer_0_biases[5] = {-0.053943373, 0.0, -0.09142746, 0.0, -0.5355272, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.9527655, -0.08629125, -0.45574152, -0.17514348, 0.21858507, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.0055904645, 0.42830908, -0.14496526, -0.2670191, 0.093800254, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.39024597, 0.491691, 0.6823273, -0.21045804, -0.11559101, },
};
const float layer_1_biases[5] = {-0.0010182776, 0.0, -0.14608689, 0.0, -0.06658583, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.86606526, -0.08629125, -0.6374115, -0.17514348, -0.05155729, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.5783333, 0.42830908, 0.11748277, -0.2670191, 0.30868873, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.46563375, 0.491691, 0.56261784, -0.21045804, -0.11593288, },
};
const float layer_2_biases[5] = {-0.0004058432, 0.0, -0.31648722, 0.0, -0.08954501, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.9198907, -0.0800395, 0.45832884, -0.21480465, -0.4160233, };
const float output_neuron_bias = -5.1718663598876446e-05;


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
	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 2);
	}

	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_1_output[neuron_index] = neuron(layer_1_weights[neuron_index], layer_1_biases[neuron_index], layer_0_output, 5);
	}

	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_2_output[neuron_index] = neuron(layer_2_weights[neuron_index], layer_2_biases[neuron_index], layer_1_output, 5);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_2_output, 5);
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
