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
dense (Dense)                (None, 5)                 20        
_________________________________________________________________
dense_1 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_2 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_3 (Dense)              (None, 1)                 6         
=================================================================
Total params: 86
Trainable params: 86
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[5][3] = {
{0.074555196, 1.2079806, -1.2445992, },
{-0.06931627, -0.27208197, -0.03532976, },
{-0.04935762, 0.21316573, -0.23892392, },
{-0.18602628, -0.7878662, -0.47489914, },
{-0.39620587, 1.3213911, -0.9466668, },
};
const float layer_0_biases[5] = {-0.04632201, 0.0, -0.25182542, 0.0, 0.4337979, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.69579965, -0.08629125, -0.5643517, -0.17514348, 0.8555747, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.015078565, 0.42830908, -0.16632183, -0.2670191, 0.022206595, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{1.2369785, 0.491691, 0.80855757, -0.21045804, 0.91945064, },
};
const float layer_1_biases[5] = {-0.05103354, 0.0, -0.16734432, 0.0, -0.05936432, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.76510894, -0.08629125, -0.61120325, -0.17514348, 0.5348394, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.29468164, 0.42830908, 0.15346502, -0.2670191, 0.7652385, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.4462465, 0.491691, 0.5157841, -0.21045804, -0.15770929, },
};
const float layer_2_biases[5] = {-0.0033822618, 0.0, -0.0015630266, 0.0, -0.12889777, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.8559172, -0.0800395, 0.38027358, -0.21480465, -0.3718608, };
const float output_neuron_bias = 0.02302389033138752;


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
	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input_0, 3);
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
	printf("expected_result = %f\n", 3.2541512843195712);
	return 0;
}
