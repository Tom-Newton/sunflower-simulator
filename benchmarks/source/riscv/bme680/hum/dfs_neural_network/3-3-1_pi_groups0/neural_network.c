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
dense (Dense)                (None, 3)                 12        
_________________________________________________________________
dense_1 (Dense)              (None, 3)                 12        
_________________________________________________________________
dense_2 (Dense)              (None, 1)                 4         
=================================================================
Total params: 28
Trainable params: 28
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][3] = {
{0.739323, 0.47564116, -0.0093633225, },
{0.046442818, -1.0535619, 0.6514833, },
{0.09724912, -0.9507764, 0.40036762, },
};
const float layer_0_biases[3] = {-0.09916884, 0.46786025, 0.29914105, };
float layer_0_output[3];

const float layer_1_weights[3][3] = {
{0.677613, -0.94497603, -0.34696242, },
{0.3939647, 0.4437438, 1.1787297, },
{0.4984848, -0.64411247, -0.8723024, },
};
const float layer_1_biases[3] = {0.08191981, -0.5649706, 0.4675497, };
float layer_1_output[3];

const float output_neuron_weights[3] = {0.88152695, -0.7303256, 0.9477378, };
const float output_neuron_bias = 0.20965911448001862;


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
float input_0[3] = {input[1]*1009, input[0]/input[1], 785/input[1]};
input_0[0] = input_0[0]*2.476017002194702e-09 + -0.7340108726066275;
input_0[1] = input_0[1]*11.819142211288188 + -0.21709761474494596;
input_0[2] = input_0[2]*648.9927775991307 + -0.7340108726066276;
	for (int neuron_index = 0; neuron_index < 3; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input_0, 3);
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
	float input[3] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 0.9976746599946321);
	return 0;
}
