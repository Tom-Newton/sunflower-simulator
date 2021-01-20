#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"


#define input_dimension 1
#define side_length 3

float lookup_table[side_length] = {-40.00001412179845061701, 22.47813875189458343584, 85.00000676327326232240};

float step_sizes[input_dimension] = {200136.0, };

float convert(float input[input_dimension]) {
    input[0] -= 293804;
    int lower_bound0;
    int difference0 = modff(input[0]/step_sizes[0], &lower_bound0);

    float base = lookup_table[lower_bound0];
    float result = base;
    if (difference0 > 0) {
        result += (lookup_table[lower_bound0 + 1] - base)*difference0;
    }
    return result;
}

int main() {
    float input[input_dimension] = {293804, };
    LOGMARK(0);
    float result = convert(input);
    LOGMARK(1);
    printf("result = %f\n", result);
	printf("expected_result = %f\n", -40.00001412179845);
    return 0;
}