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
dense (Dense)                (None, 1)                 4         
=================================================================
Total params: 4
Trainable params: 4
Non-trainable params: 0
_________________________________________________________________
*/

const float output_neuron_weights[3] = {-0.09492128, 2.538827, -1.6278006, };
const float output_neuron_bias = 0.2526736557483673;


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
	float output = neuron(output_neuron_weights, output_neuron_bias, input_0, 3);
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
