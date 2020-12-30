#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"

float calc_pressure(int press_adc, int temp_adc)
{
	return 121771.01778708957135677338 + press_adc * -0.13286766259881455099 +
		   temp_adc * 0.07759797551468494703 +
		   0.00000000297212620071 * press_adc * press_adc +
		   0.00000000188673889397 * temp_adc * temp_adc +
		   -0.00000008387071013113 * press_adc * temp_adc;
}

int main(void)
{
	int press_adc = 738541;
	int temp_adc = 293804;

	LOGMARK(0);
	float press = calc_pressure(press_adc, temp_adc);
	LOGMARK(1);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 30026.59157041149);
	return 0;
}