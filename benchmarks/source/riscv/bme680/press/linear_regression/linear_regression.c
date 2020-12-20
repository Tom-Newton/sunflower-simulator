#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"

float calc_pressure(int press_adc, int temp_adc) {
	return 140933.29737532057333737612 + press_adc*-0.16900348190596004017 + temp_adc*0.03516931427662117748;
}

 
int main(void)
{
	int press_adc = 738541;
	int temp_adc = 293804;

	LOGMARK(0);
	float press = calc_pressure(press_adc, temp_adc);
	LOGMARK(1);

	printf("Converted press = %f\n", press);
	printf("expected_result = %f\n", 26450.18205673934);
	return 0;
}