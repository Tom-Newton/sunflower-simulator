#include <stdio.h>
#include <printf.h>
#include "../../superh/port/logmarkers.h"


int main(void)
{
	LOGMARK(0);
	printf_("Hello, World.\n");
	LOGMARK(1);

	return 0;
}
