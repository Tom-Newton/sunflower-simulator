#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"

float calc_temperature(int temp_adc) {
	return -131.75881136057657272431 + temp_adc*0.00031228797504455460;
}

int main(void)
{
	int temp_adc = 293804;

	LOGMARK(0);
	float temp = calc_temperature(temp_adc);
	LOGMARK(1);

	printf("Converted temp = %f\n", temp);
	printf("expected_result = %f\n", -40.007355140586256);
	return 0;
}