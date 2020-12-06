#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include "../../../../superh/port/logmarkers.h"
#include "../../BME680_driver/bme680.c"
#include "../../BME680_driver/bme680.h"

int main(void)
{

	struct bme680_dev dev;
	dev.calib.par_t1 = 26372;
	dev.calib.par_t2 = 26190;
	dev.calib.par_t3 = 3;

	uint32_t temp_adc = 543639;

	LOGMARK(0);
	float temp = calc_temperature(temp_adc, &dev);
	LOGMARK(1);

	printf_("Converted temp = %f\n", temp);

	return 0;
}