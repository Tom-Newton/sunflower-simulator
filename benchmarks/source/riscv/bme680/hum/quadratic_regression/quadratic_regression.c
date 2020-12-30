#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"

float calc_humidity(int hum_adc, int temp_adc)
{
	return -5.36116391821633442305 + hum_adc * 0.00002792629384884560 +
		   temp_adc * -0.00009603176834021426 +
		   0.00000010574560849516 * hum_adc * hum_adc +
		   0.00000000005719819095 * temp_adc * temp_adc +
		   -0.00000000327206456926 * hum_adc * temp_adc;
}

int main(void)
{
	int hum_adc = 12840;
	int temp_adc = 293804;

	LOGMARK(0);
	float hum = calc_humidity(hum_adc, temp_adc);
	LOGMARK(1);

	printf("Converted hum = %f\n", hum);
	printf("expected_result = %f\n", 1.4977765320806782);
	return 0;
}