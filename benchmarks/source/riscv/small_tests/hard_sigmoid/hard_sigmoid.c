#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../superh/port/logmarkers.h"

float relu(float x) {
	if (x < -2.5) {
		return 0;
	} else if (x > 2.5) {
		return 1;
	}
	return x*0.2 + 0.5;
}

int main(void)
{
	float x = 2.2334294;

	LOGMARK(0);
	float result = relu(x);
	LOGMARK(1);
	
	printf("result = %f\n", result);
	return 0;
}
