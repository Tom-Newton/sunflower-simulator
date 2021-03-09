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
{-0.18315959, },
{1.3248327, },
{-0.4247179, },
{0.1823173, },
{-0.62392366, },
};
const float layer_0_biases[5] = {0.22217287, 0.2598483, 0.0, 0.17940527, 0.3131442, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.12486154, -0.16072106, 0.6806878, -0.22345054, -0.17118049, },
{0.5055371, 1.1101942, -0.08514148, 0.22339672, -1.318354, },
{-0.3289851, -0.4468569, -0.65243775, 0.028314114, -0.1458646, },
{0.5017225, -0.8125455, -0.2959177, 0.08360757, 0.8207949, },
{0.030408796, 0.2720098, 0.12794471, 0.15998274, 0.77045685, },
};
const float layer_1_biases[5] = {0.0, -0.021901578, 0.0, 0.18447796, 0.16314565, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.12486154, -0.16072106, 0.6806878, -0.22345054, -0.17118049, },
{0.6286453, 0.4164365, -0.08514148, -0.32962242, -0.8464989, },
{-0.3289851, -0.4468569, -0.65243775, 0.028314114, -0.1458646, },
{0.41827965, -0.45786843, -0.2959177, 0.74664015, -0.0029242772, },
{0.07499117, 1.0602597, 0.12794471, 1.1850526, -0.33549884, },
};
const float layer_2_biases[5] = {0.0, -0.24029087, 0.0, 0.22000138, -0.20447434, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.16119552, 0.6351068, -0.4247179, 0.7282993, -0.4493511, };
const float output_neuron_bias = 0.6594065427780151;


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
float input_0[1] = {26372/input[0]};
input_0[0] = input_0[0]*19.318190900019623 + -0.7340108726066273;
	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input_0, 1);
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
output = (output - 0.32000005950859406)/5563858.142387389;
output = output*(26372*26372);
return output;
}

int main()
{
	float input[1] = {293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", -40.00001412179845);
	return 0;
}
