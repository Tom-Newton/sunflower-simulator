#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../superh/port/logmarkers.h"

int main(void)
{
	float x = 12.2334294;

	LOGMARK(0);
	float result = x/(1 + fabsf(x));
	LOGMARK(1);
	
	printf("result = %f\n", result);
	return 0;
}