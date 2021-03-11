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
dense_2 (Dense)              (None, 3)                 12        
_________________________________________________________________
dense_3 (Dense)              (None, 1)                 4         
=================================================================
Total params: 28
Trainable params: 28
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[3][3] = {
{0.7389955, 0.47479048, -0.0106101185, },
{0.046829533, -1.0529724, 0.65158165, },
{0.09812839, -0.9500589, 0.40132245, },
};
const float layer_0_biases[3] = {-0.09948941, 0.4683905, 0.2994018, };
float layer_0_output[3];

const float layer_1_weights[3][3] = {
{0.67731315, -0.94504815, -0.34806365, },
{0.39411047, 0.44419214, 1.1797895, },
{0.49761778, -0.64482445, -0.8720548, },
};
const float layer_1_biases[3] = {0.08112769, -0.5638356, 0.46740067, };
float layer_1_output[3];

const float output_neuron_weights[3] = {0.8810319, -0.7289738, 0.9474442, };
const float output_neuron_bias = 0.2091701328754425;


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
