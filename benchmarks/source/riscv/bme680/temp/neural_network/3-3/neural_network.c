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
dense_1 (Dense)              (None, 3)                 12        
_________________________________________________________________
dense_2 (Dense)              (None, 1)                 4         
=================================================================
Total params: 22
Trainable params: 22
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][1] = {
{1.0591784, },
{-0.098027945, },
{0.08555021, },
};
const float layer_0_biases[3] = {0.0006796912, 0.0, -0.13282704, };
float layer_0_output[3];

const float layer_1_weights[3][3] = {
{0.8766467, -0.21480465, -0.18283328, },
{-0.1631769, -0.49361348, 0.4708526, },
{0.2557779, -0.11140156, -0.79114676, },
};
const float layer_1_biases[3] = {0.00038701692, -0.08201893, -0.001757736, };
float layer_1_output[3];

const float output_neuron_weights[3] = {1.0280775, -0.024780441, 0.18092035, };
const float output_neuron_bias = 0.001808250555768609;


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

	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_1_output[neuron_index] = neuron(layer_1_weights[neuron_index], layer_1_biases[neuron_index], layer_0_output, 3);
	}

	float output = neuron(output_neuron_weights, output_neuron_bias, layer_1_output, 3);
	return (output - 0.32000005950859406)/0.007999998663355634;
}

int main()
{
	float input[1] = {293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", -39.647674560546875);
	return 0;
}
