#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"

float calc_temperature(float temp_adc) {
	return -1.31714606e+02 + temp_adc*3.12207241e-04;
}

int main(void)
{

	LOGMARK(0);
	float temp = calc_temperature(543639);
	LOGMARK(1);

	printf("Converted temp = %f\n", temp);

	return 0;
}