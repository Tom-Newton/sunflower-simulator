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
	
	dev.calib.par_h1 = 785; 
	dev.calib.par_h2 = 1009;
	dev.calib.par_h3 = 0;
	dev.calib.par_h4 = 45;
	dev.calib.par_h5 = 20;
	dev.calib.par_h6 = 120;
	dev.calib.par_h7 = 156;

	uint32_t temp_adc = 527136;
	uint32_t hum_adc = 18481;

	LOGMARK(0);
	float temp = calc_temperature(temp_adc, &dev);
	float hum = calc_humidity(hum_adc, &dev);
	LOGMARK(1);

	if (roundf(temp) == 33) {
		printf_("temp_correct\n");
	} else {
		printf_("temp_wrong\n");
	}

	if (roundf(hum) == 29) {
		printf_("hum_correct\n");
	} else {
		printf_("hum_wrong\n");
	}

	printf_("Converted temp = %f\n", temp);
	printf_("Converted hum = %f\n", hum);

	return 0;
}