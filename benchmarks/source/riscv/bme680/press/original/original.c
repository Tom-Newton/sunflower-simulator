#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../../superh/port/logmarkers.h"
#include "../../BME680_driver/bme680.c"
#include "../../BME680_driver/bme680.h"

int main(void)
{

	struct bme680_dev dev;
	dev.calib.par_t1 = 26372;
	dev.calib.par_t2 = 26190;
	dev.calib.par_t3 = 3;
	
	dev.calib.par_p1 = 36338; 
	dev.calib.par_p2 = 55104;
	dev.calib.par_p3 = 88;
	dev.calib.par_p4 = 7194;
	dev.calib.par_p5 = 65442;
	dev.calib.par_p6 = 30;
	dev.calib.par_p7 = 43;
	dev.calib.par_p8 = 62766;
	dev.calib.par_p9 = 62990;
	dev.calib.par_p10 = 30;

	uint32_t temp_adc = 527136;
	uint32_t press_adc = 357152;

	LOGMARK(0);
	float temp = calc_temperature(temp_adc, &dev);
	float press = calc_pressure(press_adc, &dev);
	// temp=22.000028 press=69999.935282
	// 21.000093            49999.992044
	LOGMARK(1);

	if (roundf(temp) == 21) {
		printf_("temp_correct\n");
	} else {
		printf_("temp_wrong\n");
	}

	if (roundf(press) == 26036) {
		printf_("press_correct\n");
	} else {
		printf_("press_wrong\n");
	}

	printf_("Converted temp = %f\n", temp);
	printf_("Converted press = %f\n", press);

	return 0;
}