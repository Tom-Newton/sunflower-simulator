#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"


#define side_length 10

float lookup_table[side_length][side_length] = {
{109999.9453595911, 112636.52270191544, 115307.84401089848, 118010.14283686725, 120739.13940145235, 123490.19913628366, 126257.93819576256, 129036.38314878286, 131819.14181255916, 134599.01552325932, },
{100375.14283200243, 102781.28919489897, 105218.3916944536, 107682.96573539254, 110171.06028092145, 112678.40319877394, 115200.04257341025, 117730.49345965647, 120263.89450261164, 122793.65600072431, },
{90783.55963180067, 92961.98819956092, 95167.76315517705, 97397.68643712682, 99648.13926319481, 101915.2142718024, 104194.39192458961, 106480.67423835046, 108768.72717350243, 111052.56367522004, },
{81221.04614132407, 83174.16348696988, 85151.17685501014, 87149.1789709244, 89164.88651755011, 91194.75905829637, 93234.70989710563, 95280.22671089102, 97326.49968791714, 99368.13881921898, },
{71682.83114860281, 73412.72252754758, 75163.20001942023, 76931.65098257376, 78715.13049450166, 80510.46704135495, 82314.00728057706, 84121.72350103152, 85929.3274905822, 87732.0214388912, },
{62164.763304337495, 63673.20721497866, 65199.04907748943, 66739.97430260312, 68293.37898934323, 69856.46236393832, 71426.00496650094, 72998.46287186845, 74570.06726453619, 76136.60840058821, },
{52662.07283870911, 53950.52658720487, 55253.29295608219, 56568.358420818855, 57893.46244815162, 59226.17666530036, 60563.716070324735, 61903.01995167831, 63240.83714658707, 64573.54259869246, },
{43170.607249754255, 44240.22128025478, 45321.146714345596, 46411.67367803957, 47509.887049079494, 48613.7323360588, 49720.859588196065, 50828.69095744106, 51934.49161525746, 53035.218529251644, },
{33685.59763083104, 34537.20127986225, 35397.18031761711, 36264.13069947302, 37136.48447692344, 38012.562363997626, 38890.45010043248, 39768.05260514317, 40643.15052430569, 41513.28093904345, },
{24202.737054454465, 24836.84920633505, 25476.44716767474, 26120.434480319065, 26767.591834909075, 27416.61630046389, 28066.029971576805, 28714.220667686266, 29359.484083988675, 29999.936229483574, },
};

float step_sizes[2] = {61638.555555555555, 44474.666666666664, };

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