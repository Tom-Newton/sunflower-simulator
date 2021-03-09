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
dense (Dense)                (None, 3)                 6         
_________________________________________________________________
dense_1 (Dense)              (None, 1)                 4         
=================================================================
Total params: 10
Trainable params: 10
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][1] = {
{0.9791635, },
{-0.098027945, },
{0.2711197, },
};
const float layer_0_biases[3] = {7.743534e-05, 0.0, 5.7834386e-05, };
float layer_0_output[3];

const float output_neuron_weights[3] = {0.9618799, -0.098027945, 0.21466942, };
const float output_neuron_bias = -0.00022435019491240382;


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

float evaluate_network(float input[1])
{
	input[0]=input[0]*2.4983011552144543e-06 + -0.7340108726066276;
	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 1);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_0_output, 3);
	return (output - 0.32000005950859406)/0.007999998663355634;
}

int main()
{
	float input[1] = {293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", -40.0000114440918);
	return 0;
}
