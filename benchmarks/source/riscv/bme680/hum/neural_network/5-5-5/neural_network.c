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
dense_4 (Dense)              (None, 1)                 3         
_________________________________________________________________
dense_5 (Dense)              (None, 5)                 10        
_________________________________________________________________
dense_6 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_7 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_8 (Dense)              (None, 1)                 6         
=================================================================
Total params: 79
Trainable params: 79
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[1][2] = {
{2.349729, 0.31564656, },
};
const float layer_0_biases[1] = {-0.25942042, };
float layer_0_output[1];

const float layer_1_weights[5][1] = {
{1.4065248, },
{-0.0800395, },
{0.004546265, },
{-0.21480465, },
{-0.49361348, },
};
const float layer_1_biases[5] = {-0.005034468, 0.0, -0.18300463, 0.0, 0.0, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.96397823, -0.08629125, -0.61525345, -0.17514348, -0.12680006, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{-0.006056046, 0.42830908, -0.14939728, -0.2670191, 0.20532304, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.38235137, 0.491691, 0.6512296, -0.21045804, -0.03804189, },
};
const float layer_2_biases[5] = {-0.0019938499, 0.0, -0.15389484, 0.0, 0.0, };
float layer_2_output[5];

const float layer_3_weights[5][5] = {
{0.6919697, -0.08629125, -0.6406563, -0.17514348, -0.12680006, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.5665721, 0.42830908, 0.13080412, -0.2670191, 0.20532304, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.38235137, 0.491691, 0.6512296, -0.21045804, -0.03804189, },
};
const float layer_3_biases[5] = {0.0019256187, 0.0, -0.85878587, 0.0, 0.0, };
float layer_3_output[5];

const float output_neuron_weights[5] = {0.4394885, -0.0800395, 0.14897057, -0.21480465, -0.49361348, };
const float output_neuron_bias = 0.013857458718121052;


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

	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_1_output[neuron_index] = neuron(layer_1_weights[neuron_index], layer_1_biases[neuron_index], layer_0_output, 1);
	}

	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_2_output[neuron_index] = neuron(layer_2_weights[neuron_index], layer_2_biases[neuron_index], layer_1_output, 5);
	}

	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_3_output[neuron_index] = neuron(layer_3_weights[neuron_index], layer_3_biases[neuron_index], layer_2_output, 5);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_3_output, 5);
	return (output - -0.010179742927756977)/0.01020346946349399;
}

int main()
{
	float input[2] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 2.438728094100952);
	return 0;
}
