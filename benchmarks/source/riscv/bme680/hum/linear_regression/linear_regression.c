#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"

float calc_pressure(int hum_adc, int temp_adc) {
	return -89.51764238413738894451 + hum_adc*0.00596649629726170999 + temp_adc*0.00002528203539170807;
}

int main(void)
{
	int hum_adc = 12840;
	int temp_adc = 293804;

	LOGMARK(0);
	float hum = calc_pressure(hum_adc, temp_adc);
	LOGMARK(1);

	printf("Converted hum = %f\n", hum);
	printf("expected_result = %f\n", -5.479866801071632);
	return 0;
}