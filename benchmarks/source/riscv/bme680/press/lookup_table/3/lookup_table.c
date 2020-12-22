#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"


#define side_length 3

float lookup_table[side_length][side_length] = {
{109999.9453595911, 122112.26907406899, 134599.01552325932, },
{66921.57699755783, 74339.4984441863, 81929.7493071954, },
{24202.737054454465, 27091.968134586506, 29999.936229483574, },
};

float step_sizes[2] = {277373.5, 200136.0, };

float convert(float input[2]) {
    input[0] -= 221477;
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
    float input[2] = {221477, 293804, };
    LOGMARK(0);
    float result = convert(input);
    LOGMARK(1);
    printf("result = %f\n", result);
	printf("expected_result = %f\n", 109999.9453595911);
    return 0;
}