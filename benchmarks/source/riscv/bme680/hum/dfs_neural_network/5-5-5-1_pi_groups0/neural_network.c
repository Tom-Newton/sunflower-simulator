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
dense_1 (Dense)              (None, 5)                 20        
_________________________________________________________________
dense_2 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_3 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_4 (Dense)              (None, 1)                 6         
=================================================================
Total params: 86
Trainable params: 86
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[5][3] = {
{0.07490252, 1.2079924, -1.2446645, },
{-0.06931627, -0.27208197, -0.03532976, },
{-0.049357627, 0.2131657, -0.23892392, },
{-0.18602628, -0.7878662, -0.47489914, },
{-0.3962224, 1.3219317, -0.94611967, },
};
const float layer_0_biases[5] = {-0.045899596, 0.0, -0.25182542, 0.0, 0.4338932, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.6954019, -0.08629125, -0.5643517, -0.17514348, 0.85571426, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.015078565, 0.42830908, -0.16632183, -0.2670191, 0.022206606, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{1.2363076, 0.491691, 0.80855757, -0.21045804, 0.9195333, },
};
const float layer_1_biases[5] = {-0.05063017, 0.0, -0.16734435, 0.0, -0.059411075, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.7649637, -0.08629125, -0.61120325, -0.17514348, 0.5346606, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.29445362, 0.42830908, 0.15346502, -0.2670191, 0.76497585, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.4462465, 0.491691, 0.51578414, -0.21045804, -0.15770929, },
};
const float layer_2_biases[5] = {-0.003658102, 0.0, -0.0016205251, 0.0, -0.12889777, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.8556019, -0.0800395, 0.37992662, -0.21480465, -0.3718608, };
const float output_neuron_bias = 0.023205775767564774;


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
	printf("expected_result = %f\n", 3.2719771264831614);
	return 0;
}
