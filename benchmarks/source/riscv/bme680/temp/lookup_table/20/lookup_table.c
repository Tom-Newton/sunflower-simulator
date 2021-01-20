#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"


#define input_dimension 1
#define side_length 20

float lookup_table[side_length] = {-40.00001412179845061701, -33.42572072482798972715
, -26.85063087791149882833, -20.27505665031785753172
, -13.69899804204706050825, -7.12245505309911131064, -0.54542768347400849560
, 6.03208406682824715972, 12.61008019780765643247, 19.18856070946421965573
, 25.76752560179793505313, 32.34697487480880084831, 38.92690852849682414671
, 45.50732656286199784290, 52.08822897790432904230, 58.66961577362381063949
, 65.25148695002044973990, 71.83384250709423213266, 78.41668244484517913406
, 85.00000676327326232240};

float step_sizes[input_dimension] = {21066.947368421053, };

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