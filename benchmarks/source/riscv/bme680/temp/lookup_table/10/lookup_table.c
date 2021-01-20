#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"


#define input_dimension 1
#define side_length 10

float lookup_table[side_length] = {-40.00001412179845061701, -26.11996607981054552283
, -12.23744716396267939729, 1.64723055647627925069, 15.53375481807961477898
, 29.42275009916102135321, 43.31390418483351822942, 57.20690466605228863273
, 71.10237631236722677386, 85.00000676327326232240};

float step_sizes[input_dimension] = {44474.666666666664, };

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