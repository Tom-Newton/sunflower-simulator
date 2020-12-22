#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"


#define side_length 3

float lookup_table[side_length][side_length] = {
{0.6738861229968898, 0.7831876885060771, 1.0008048854766318, },
{40.956260869941204, 45.376208617261995, 54.48257832289435, },
{99.00158055168443, 100.0, 100.0, },
};

float step_sizes[2] = {8753.0, 200136.0, };

float convert(float input[2]) {
    input[0] -= 12749;
    input[1] -= 293804;

    int lower_bound0;
    int lower_bound1;

    int difference0 = modff(input[0]/step_sizes[0], &lower_bound0);
    int difference1 = modff(input[1]/step_sizes[1], &lower_bound1);

    float base = lookup_table[lower_bound0][lower_bound1];
    float result = base;
    if (difference0 > 0) {
        result += (lookup_table[lower_bound0 + 1][lower_bound1] - base)*difference0;
    }
    if (difference1 > 0) {
        result += (lookup_table[lower_bound0][lower_bound1 + 1] - base)*difference1;
    }
    return result;
}

int main() {
    float input[2] = {12749, 293804, };
    LOGMARK(0);
    float result = convert(input);
    LOGMARK(1);
    printf("result = %f\n", result);
	printf("expected_result = %f\n", 0.6738861229968898);
    return 0;
}