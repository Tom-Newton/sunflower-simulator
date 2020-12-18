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
dense_4 (Dense)              (None, 5)                 15        
_________________________________________________________________
dense_5 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_6 (Dense)              (None, 5)                 30        
_________________________________________________________________
dense_7 (Dense)              (None, 1)                 6         
=================================================================
Total params: 81
Trainable params: 81
Non-trainable params: 0
_________________________________________________________________
*/

const float layer_0_weights[5][2] = {
{1.9309514, 0.13722636, },
{-0.07410216, -0.29086787, },
{-1.2401484, 1.2818477, },
{-0.19887048, -0.8422644, },
{0.6329865, 1.0519762, },
};
const float layer_0_biases[5] = {-0.08942555, 0.0, -0.60106605, 0.0, -0.85724986, };
float layer_0_output[5];

const float layer_1_weights[5][5] = {
{1.1999081, -0.08629125, -0.1863665, -0.17514348, 0.29114786, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.0074750297, 0.42830908, -0.14633283, -0.2670191, 0.0910242, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.5041371, 0.491691, 0.45597884, -0.21045804, 0.3225555, },
};
const float layer_1_biases[5] = {-0.000937856, 0.0, -0.14541428, 0.0, -0.50093096, };
float layer_1_output[5];

const float layer_2_weights[5][5] = {
{0.77290976, -0.08629125, -0.6385044, -0.17514348, 0.05232677, },
{-0.061998308, -0.24335754, -0.03159994, -0.60076475, -0.24263746, },
{0.6614517, 0.42830908, 0.120644554, -0.2670191, 0.31563973, },
{-0.16638696, -0.70468897, -0.42476273, -0.7165678, -0.0761593, },
{-0.46398544, 0.491691, 0.55767167, -0.21045804, -0.116610155, },
};
const float layer_2_biases[5] = {-0.0016303882, 0.0, -0.74130636, 0.0, -0.0946466, };
float layer_2_output[5];

const float output_neuron_weights[5] = {0.49856958, -0.0800395, 0.19256492, -0.21480465, -0.41229513, };
const float output_neuron_bias = -0.001190284499898553;


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
	input[0]=input[0]*5.7123272021021365e-05 + -0.7282645949960014;
	input[1]=input[1]*2.4983011552144543e-06 + -0.7340108726066276;
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
	return (output - -0.010179742927756977)/0.01020346946349399;
}

int main()
{
	float input[2] = {12840.0, 293804.0, };
	LOGMARK(0);
	float result = evaluate_network(input);
	LOGMARK(1);
	printf("result = %f\n", result);
	printf("expected_result = %f\n", 0.9976747035980225);
	return 0;
}
