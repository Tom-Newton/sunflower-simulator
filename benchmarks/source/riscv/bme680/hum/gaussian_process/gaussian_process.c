#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
// #include "../../../../superh/port///logmarkers.h"

float gaussian_kernel(float x[2], float y[2])
{
	return expf(4.5551530550530925) * expf(4.5551530550530925) *
		   expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) /
				(2 * expf(15.27860381595202) * expf(15.27860381595202))) *
		   expf(4.5551530550530925) * expf(4.5551530550530925) *
		   expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) /
				(2 * expf(12.880708856351463) * expf(12.880708856351463)));
}

void evaluate_cross_kernel(float x_star[2], float (*cross_kernel)[9])
{
	static float train_input_points[9][2] = {
		{12840.0, 293804.0},
		{12801.0, 492409.0},
		{12749.0, 694076.0},
		{23062.0, 293804.0},
		{22269.0, 492409.0},
		{20847.0, 694076.0},
		{30255.0, 293804.0},
		{29335.0, 492409.0},
		{27476.0, 694076.0}};

	for (int i = 0; i < 9; i++)
	{
		(*cross_kernel)[i] = gaussian_kernel(x_star, train_input_points[i]);
	}
}

float mean(float x_star[2])
{
	static float parameter_mean[9] = {
		0.71952031919512293712,
		-0.84608665506750924123,
		0.77310838388285674228,
		-1.74601381574944980457,
		1.98624046616336613624,
		-1.72270743631820266728,
		1.02691494163362762038,
		-1.14059083707456920820,
		0.94990312864955228633};

	float cross_kernel[9];
	evaluate_cross_kernel(x_star, &cross_kernel);

	float mean = 0;
	for (int i = 0; i < 9; i++)
	{
		mean += cross_kernel[i] * parameter_mean[i];
	}
	return mean;
}

int main(void)
{
	float x_star[2] = {12840, 293804};

	//LOGMARK(0);
	float hum = mean(x_star);
	//LOGMARK(1);

	printf("Converted hum = %f\n", hum);

	return 0;
}
