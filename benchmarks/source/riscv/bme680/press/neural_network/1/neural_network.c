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
dense_1 (Dense)              (None, 1)                 3         
=================================================================
Total params: 3
Trainable params: 3
Non-trainable params: 0
_________________________________________________________________
*/

const float output_neuron_weights[2] = {-1.182414, 0.1802671, };
const float output_neuron_bias = 1.052499771118164;


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
input[0] = input[0]*1.8026235382976384e-06 + -0.39923965339154605;
input[1] = input[1]*2.4983011552144543e-06 + -0.7340108726066276;
	float output = neuron(output_neuron_weights, output_neuron_bias, input, 2);
output = (output - -0.37499857438644063)/1.2499979050552e-05;
return output;
}

int main()
{
	float input[2] = {738541.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 29999.936229483574);
	return 0;
}
