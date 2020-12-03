#include <stdio.h>
#include <printf.h>

static float calc_temperature(uint32_t temp_adc, struct bme680_dev *dev)
{
	float var1 = 0;
	float var2 = 0;
	float calc_temp = 0;

	/* calculate var1 data */
	var1  = ((((float)temp_adc / 16384.0f) - ((float)dev->calib.par_t1 / 1024.0f))
			* ((float)dev->calib.par_t2));

	/* calculate var2 data */
	var2  = (((((float)temp_adc / 131072.0f) - ((float)dev->calib.par_t1 / 8192.0f)) *
		(((float)temp_adc / 131072.0f) - ((float)dev->calib.par_t1 / 8192.0f))) *
		((float)dev->calib.par_t3 * 16.0f));

	/* t_fine value*/
	dev->calib.t_fine = (var1 + var2);

	/* compensated temperature data*/
	calc_temp  = ((dev->calib.t_fine) / 5120.0f);

	return calc_temp;
}

int
main(void)
{
	printf_("Hello, World.\n");

	return 0;
}