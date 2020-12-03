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

	// if (temp == 37.999873) {
	// 	printf_("Correct");
	// } else {
	// 	printf_("Incorrect");
	// }


	// char buf[3];
	// gcvt(temp, 3, buf);
	// printf_("String obtained on concatenation: %s\n", buf);

	return 0;
}