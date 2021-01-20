#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"

float calc_temp(int temp_adc)
{
	return -131.64010877385589992628 + temp_adc * 0.00031174861360342560 +
		   0.00000000000054569682 * temp_adc * temp_adc;
}

int main(void)
{
	int temp_adc = 293804;

	LOGMARK(0);
	float temp = calc_temp(temp_adc);
	LOGMARK(1);

	printf("Converted temp = %f\n", temp);
	printf("expected_result = %f\n", -40.0000141217940);
	return 0;
}