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
{1.2597396, -0.016778648, },
{-0.07410216, -0.29086787, },
{0.80441403, 0.6269153, },
{-0.19887048, -0.8422644, },
{-1.2364545, 0.34430557, },
};
const float layer_0_biases[5] = {-0.11834701, 0.0, -0.76616186, 0.0, 1.1283147, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.5754438, -0.08629125, 0.0304733, -0.17514348, 0.88854367, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{-0.24010263, 0.42830908, -0.42894575, -0.2670191, -0.19800322, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.7715526, 0.491691, -0.26916954, -0.21045804, 1.0626845, },
};
const float layer_1_biases[5] = {-0.8958003, 0.0, -0.40759835, 0.0, 0.82228404, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.6084675, -0.08629125, -0.35269204, -0.17514348, 0.6650864, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.024036897, 0.42830908, 0.40416887, -0.2670191, 0.697624, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.4669451, 0.491691, 0.5639527, -0.21045804, -0.11710162, },
};
const float layer_2_biases[5] = {-0.0009371348, 0.0, -0.001509382, 0.0, -0.08776387, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.40179944, -0.0800395, 0.30030364, -0.21480465, -0.41516912, };
const float output_neuron_bias = 0.00020339968614280224;


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
	printf("expected_result = %f\n", 30242.072265625);
	return 0;
}
