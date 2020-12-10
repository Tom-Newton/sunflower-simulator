#include <stdio.h>
#include <printf.h>
#include <stdint.h>
#include <math.h>
#include "../../../superh/port/logmarkers.h"

int main(void)
{
	float x = 12.2334294;

	LOGMARK(0);
	1/(1 + expf(-x));
	LOGMARK(1);
	
	return 0;
}