#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
// #include "../../../../superh/port/logmarkers.h"

float gaussian_kernel(float x[2], float y[2])
{
	return 172.55812E9 * expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) / 11.25731E12);
}

float (*evaluate_cross_kernel(float x_star[2]))[9]
{
	static float train_input_points[9][2] = {
		{738541.0, 293804.0},
		{758979.0, 492409.0},
		{776224.0, 694076.0},
		{478920.0, 293804.0},
		{523927.0, 492409.0},
		{562362.0, 694076.0},
		{221477.0, 293804.0},
		{290846.0, 492409.0},
		{350295.0, 694076.0}};

	float evaluated_cross_kernel[9];

	for (int i = 0; i < 9; i++)
	{
		evaluated_cross_kernel[i] = gaussian_kernel(x_star, train_input_points[i]);
	}
	return &evaluated_cross_kernel;
}

// [0.71952032 - 0.84608666 0.77310838 - 1.74601382 1.98624047 - 1.72270744 1.02691494 - 1.14059084 0.94990313]

// bme680_press bme680_temp

int main(void)
{
	uint32_t temp_adc = 543639;
	uint32_t press_adc = 643639;

	// evaluate_test_kernel({})

	// LOGMARK(0);
	// LOGMARK(1);

	// printf_("Converted press = %f\n", press);

	return 0;
}
