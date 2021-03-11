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
dense (Dense)                (None, 5)                 15        
_________________________________________________________________
dense_1 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_2 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_3 (Dense)              (None, 1)                 6         
=================================================================
Total params: 81
Trainable params: 81
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[5][2] = {
{0.9122251, -0.22440521, },
{0.6800617, -0.12397748, },
{-0.03522849, 0.6086332, },
{0.6101183, 0.59188, },
{-0.1682164, -0.14972699, },
};
const float layer_0_biases[5] = {0.049461048, 0.0010483825, -0.050998278, -0.040895596, 0.0, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{0.75534654, 0.43387067, -0.15692106, 0.45015356, 0.004502833, },
{0.40089026, 0.30405042, -0.79294354, -0.33746096, -0.58098555, },
{0.40127945, 0.19735523, 0.33752537, -0.40879062, 0.4234438, },
{0.46403784, 0.8033955, 0.20690992, -0.24189098, 0.54449797, },
{-0.13455972, -0.16671309, -0.17065412, 0.12848441, -0.068864286, },
};
const float layer_1_biases[5] = {-0.035989717, -0.029908737, -0.016173976, -0.24484414, 0.1383278, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.5612315, 0.30803087, -0.07126515, 0.59490174, -0.15545292, },
{0.35498118, 0.40559515, -0.7725546, 0.096092805, -0.56928355, },
{0.3782856, 0.16790946, 0.58504856, -0.19502695, 0.255578, },
{0.40940264, 0.79774034, 0.29166484, -0.037847135, 0.3404269, },
{-0.20722388, -0.19964872, -0.083006576, 0.244739, -0.124305606, },
};
const float layer_2_biases[5] = {0.019088784, -0.21931015, -0.03702139, -0.046383835, -0.07090579, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.63309896, 0.42213863, 0.36354202, 0.3915532, -0.11297802, };
const float output_neuron_bias = -0.0011973213404417038;


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
input[1] = input[0]/input[1];
input[0] = input[0]*5.7123272021021365e-05 + -0.7282645949960014;
input[1] = input[1]*11.819142211288188 + -0.21709761474494596;
	for (int neuron_index = 0; neuron_index < 5; neuron_index++)
	{
		layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], input, 2);
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
	float input[2] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 1.0578433578280062);
	return 0;
}
