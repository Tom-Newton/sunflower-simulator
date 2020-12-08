#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <vector>
#include "../../../../superh/port/logmarkers.h"

std::vector<float> apply_kernel(std::vector<float> x_star) {
	static std::vector<std::vector<float>> train_input_points = ;
}

int main(void)
{

	struct bme680_dev dev;
	dev.calib.par_t1 = 26372;
	dev.calib.par_t2 = 26190;
	dev.calib.par_t3 = 3;

	uint32_t temp_adc = 543639;
	uint32_t press_adc = 643639;

	LOGMARK(0);
	calc_temperature(temp_adc, &dev);
	float press = calc_pressure(press_adc, &dev);
	LOGMARK(1);

	printf_("Converted press = %f\n", press);

	return 0;
}
