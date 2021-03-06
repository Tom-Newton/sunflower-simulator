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
dense_1 (Dense)              (None, 1)                 4         
=================================================================
Total params: 13
Trainable params: 13
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][2] = {
{-1.5289671, 0.2330866, },
{-0.08767891, -0.5407265, },
{0.056268226, -0.26313642, },
};
const float layer_0_biases[3] = {1.3604863, 0.0, -0.16932335, };
float layer_0_output[3];

const float output_neuron_weights[3] = {0.77355057, -0.098027945, 0.106656805, };
const float output_neuron_bias = -0.0005162704037502408;


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

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_0_output, 3);
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
