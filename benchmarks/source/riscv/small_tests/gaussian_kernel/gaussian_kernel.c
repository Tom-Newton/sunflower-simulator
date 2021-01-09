#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../superh/port/logmarkers.h"

float gaussian_kernel(float x[2], float y[2])
{
	return 1.2 * expf(-((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])) * 1E-20);
}

int main(void)
{
	float x[2] = {12.2334294, 1.3453965};
	float y[2] = {324.8219347, 0.32452};

	LOGMARK(0);
	float result = gaussian_kernel(x, y);
	LOGMARK(1);

	printf("result = %f\n", result);
	return 0;
}