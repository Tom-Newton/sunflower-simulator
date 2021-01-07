#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../superh/port/logmarkers.h"

float relu(float x) {
	if (x < 0) {
		return 0;
	}
	return x;
}

int main(void)
{
	float x = 12.2334294;

	LOGMARK(0);
	float result = relu(x);
	LOGMARK(1);
	
	printf("result = %f\n", result);
	return 0;
}
