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
dense (Dense)                (None, 5)                 15        
_________________________________________________________________
dense_1 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_2 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_3 (Dense)              (None, 1)                 6         
=================================================================
Total params: 81
Trainable params: 81
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[5][2] = {
{1.1875465, 0.0007028949, },
{-0.07410216, -0.29086787, },
{0.80694765, 0.6343939, },
{-0.19887048, -0.8422644, },
{-1.2745552, 0.32210854, },
};
const float layer_0_biases[5] = {-0.15469718, 0.0, -0.7546756, 0.0, 1.16302, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.63898784, -0.08629125, 0.027140126, -0.17514348, 0.90249205, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{-0.2272436, 0.42830908, -0.4228529, -0.2670191, -0.17606379, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.72059095, 0.491691, -0.26586562, -0.21045804, 1.1832368, },
};
const float layer_1_biases[5] = {-0.8920534, 0.0, -0.3963699, 0.0, 0.69521916, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.6327752, -0.08629125, -0.3624965, -0.17514348, 0.69766, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{-0.06405818, 0.42830908, 0.41121605, -0.2670191, 0.6286763, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.46266872, 0.491691, 0.5644752, -0.21045804, -0.11651504, },
};
const float layer_2_biases[5] = {-0.0019810717, 0.0, -0.0038378958, 0.0, -0.086746186, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.436494, -0.0800395, 0.25768095, -0.21480465, -0.41834825, };
const float output_neuron_bias = 0.00013068178668618202;


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
	return (output - -0.37499857438644063)/1.2499979050552e-05;
}

int main()
{
	float input[2] = {738541.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 30201.19921875);
	return 0;
}
