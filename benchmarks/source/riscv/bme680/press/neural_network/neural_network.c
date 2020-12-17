#include <stdlib.h>
#include <stdio.h>
#include <printf.h>
#include <math.h>
#include "../../../../superh/port/logmarkers.h"


#define INPUT_SIZE 2
#define NUMBER_HIDDEN_LAYERS 2
#define LAYER_0_SIZE 3
float layer_0_weights[3][2] = {
{0.53522563, -0.29909855, },
{0.03290403, -0.42214727, },
{0.6206877, 0.21103811, },
};
float layer_0_biases[3] = {0.0, 0.0, 0.0, };

#define LAYER_1_SIZE 3
float layer_1_weights[3][3] = {
{0.82250667, 0.6464324, 0.15931773, },
{0.23434448, -0.7234938, -0.86362314, },
{-0.6926911, 0.049665928, -0.36499047, },
};
float layer_1_biases[3] = {0.0, 0.0, 0.0, };

float output_neuron_weights[3] = {-0.5744224, -0.9933629, 0.0003658533, };
float output_neuron_bias = 0.0;



float layer_0_output[LAYER_0_SIZE];
float layer_1_output[LAYER_1_SIZE];

float relu(float x)
{
    if (x < 0)
    {
        return 0;
    }
    return x;
}

float neuron(float *neuron_weights, float neuron_bias, float *inputVector, int inputVectorSize)
{
    float sum = neuron_bias;

    for (int i = 0; i < inputVectorSize; i++)
    {
        sum += neuron_weights[i] * inputVector[i];
    }
    return relu(sum);
}

float evaluate_network(float x_star[2])
{
    for (int neuron_index = 0; neuron_index < LAYER_0_SIZE; neuron_index++)
    {
        layer_0_output[neuron_index] = neuron(layer_0_weights[neuron_index], layer_0_biases[neuron_index], x_star, INPUT_SIZE);
    }


    for (int neuron_index = 0; neuron_index < LAYER_1_SIZE; neuron_index++)
    {
        layer_1_output[neuron_index] = neuron(layer_1_weights[neuron_index], layer_1_biases[neuron_index], layer_0_output, LAYER_0_SIZE);
    }

    return neuron(output_neuron_weights, output_neuron_bias, layer_1_output, LAYER_1_SIZE);
}

int main()
{
    float x_star[2] = {0.5, 0.8};

    LOGMARK(0);
    float value = evaluate_network(x_star);
    LOGMARK(1);

    printf_("value = %f\n", value);
    return 0;
}