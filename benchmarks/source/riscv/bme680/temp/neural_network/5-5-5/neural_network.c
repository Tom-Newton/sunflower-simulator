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
dense (Dense)                (None, 5)                 10        
_________________________________________________________________
dense_1 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_2 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_3 (Dense)              (None, 1)                 6         
=================================================================
Total params: 76
Trainable params: 76
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[5][1] = {
{1.132797, },
{-0.0800395, },
{0.021279693, },
{-0.21480465, },
{-0.49361348, },
};
const float layer_0_biases[5] = {-0.0001558267, 0.0, -0.17357811, 0.0, 0.0, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.89164156, -0.08629125, -0.6277853, -0.17514348, -0.12680006, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{-0.00072205777, 0.42830908, -0.14078188, -0.2670191, 0.20532304, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.38235137, 0.491691, 0.6512296, -0.21045804, -0.03804189, },
};
const float layer_1_biases[5] = {0.0003982258, 0.0, -0.1489443, 0.0, 0.0, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.8616928, -0.08629125, -0.64855313, -0.17514348, -0.12680006, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.42403206, 0.42830908, 0.12322723, -0.2670191, 0.20532304, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.38235137, 0.491691, 0.6512296, -0.21045804, -0.03804189, },
};
const float layer_2_biases[5] = {-0.0003431976, 0.0, -0.00016890012, 0.0, 0.0, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.9747483, -0.0800395, 0.35411385, -0.21480465, -0.49361348, };
const float output_neuron_bias = -1.8758910869109968e-08;


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
	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 1);
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
