#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <printf.h>
#include "../../../../../superh/port/logmarkers.h"


#define side_length 20

float lookup_table[side_length][side_length] = {
{109999.9453595911, 111244.2740330191, 112496.84486995968, 113757.24584201576, 115025.0996897864, 116300.00431857529, 117581.53207678751, 118869.22905231429, 120162.61439105586, 121461.17964201349, 122764.38813365917, 124071.67438656848, 125382.44356757507, 126696.07099096804, 128011.90167250668, 129329.24994226453, 130647.39912253516, 131965.60127722588, 133283.07703933702, 134599.01552325932, },
{105436.37697004402, 106629.06759257358, 107829.57683750846, 109037.5072273866, 110252.49464243873, 111474.1511972706, 112702.06455914646, 113935.79728408607, 115174.88617474509, 116418.84166431152, 117667.14723091346, 118919.25884729045, 120174.60447073773, 121432.58357857625, 122692.56675463727, 123953.8953324705, 125215.88110118633, 126477.80608002242, 127738.92236787827, 128998.45207418328, },
{100880.82389875813, 102022.17760710907, 103170.93572553352, 104326.71545093897, 105489.16592986695, 106657.91360081843, 107832.56155111086, 109012.68889131692, 110197.85015107642, 111387.5747003201, 112581.36620018943, 113778.70208817758, 114979.03310225604, 116181.7828489783, 117386.34742077123, 118592.09506782705, 119798.36593019601, 121004.4718358423, 122209.69617056545, 123413.29382579801, },
{96332.81203539381, 97423.11440444204, 98520.41585693166, 99624.34838257998, 100734.57451572368, 101850.73512874266, 102972.44882623703, 104099.3113564991, 105230.89504389589, 106366.74824600953, 107506.39483961255, 108649.33373977999, 109795.03845666366, 110942.95669466436, 112092.50999894098, 113243.09345438256, 114394.07544233995, 115544.79746056341, 116694.5740119169, 117842.69256753709, },
{91791.86726961148, 92831.38831238895, 93877.5115545997, 94929.88389221666, 95988.18136366147, 97052.05938056715, 98121.15215808126, 99195.0721621249, 100273.4095770495, 101355.73179735012, 102441.58294730828, 103530.48343264783, 104621.92952849435, 105715.39300812452, 106810.32081717894, 107906.13479818532, 109002.23147039385, 110097.98187006368, 111192.73145645093, 112285.80008883406, },
{87257.36029659204, 88246.35273791655, 89241.55848102705, 90242.63943711972, 91249.2852602644, 92261.16600261503, 93277.93157970592, 94299.21125231516, 95324.61312816488, 96353.72368693174, 97386.10733223964, 98421.30597450356, 99458.83864868515, 100498.20117120235, 101538.86584040792, 102580.28118521046, 103621.8717665549, 104663.03803660095, 105703.15626054058, 106741.57850606859, },
{82729.12759640749, 83667.83205990892, 84612.36849746012, 85562.41393842518, 86517.67175795794, 87477.82674438857, 88442.54459843728, 89411.47144855915, 90384.23338551984, 91360.43601949172, 92339.6640631456, 93321.48094439555, 94305.42845263206, 95291.02642244686, 96277.77245901164, 97265.14170941833, 98252.58668441905, 99239.53713511435, 100225.39998922928, 101209.55935168036, },
{78206.53964654774, 79095.17945919337, 79989.27703153403, 80888.52460956451, 81792.6393902283, 82701.32098957726, 83614.25097488823, 84531.09241242979, 85451.48943381073, 86375.0668240189, 87301.42963443103, 88230.16282424312, 89160.83093393619, 90092.97779454607, 91026.12627665252, 91959.77808313593, 92893.41358986803, 93826.49173860342, 94758.44998641845, 95688.70431609947, },
{73689.12233667319, 74527.90526358636, 75371.77840614555, 76220.44932044474, 77073.64912072805, 77931.09233770499, 78792.47648261508, 79657.48162641929, 80525.7699968835, 81396.98559648362, 82270.7538442214, 83146.6812445964, 84024.35508713125, 84903.3431799901, 85783.193621363, 86663.43461241157, 87543.57431567756, 88423.10076294611, 89301.48181662636, 90178.16518875948, },
{69176.40155644421, 69965.51980090438, 70759.36694419153, 71557.66594097296, 72360.16191310978, 73166.58438829563, 73976.6468951741, 74790.04657301995, 75606.46379858421, 76425.56183285615, 77246.98649064217, 78070.36583600548, 78895.30990675096, 79721.41047126906, 80548.24082117548, 81375.35560329365, 82202.2906946234, 83028.5631240203, 83853.67104437132, 84677.09375909397, },
{64667.748845926275, 65407.37735724632, 66151.37922264547, 66899.49287937587, 67651.47754252139, 68407.07781499423, 69166.02331287104, 69928.0283046918, 70692.79136715912, 71459.99505981545, 72229.30562141156, 73000.3726908124, 73772.82905541411, 74546.29043016536, 75320.35527039733, 76094.60462176676, 76868.6020107036, 77641.89337882579, 78414.00706483873, 79184.45383747006, },
{60162.99891423013, 60853.30046937481, 61547.62518718755, 62245.72706546182, 62947.37949194984, 63652.342217374695, 64360.361010208224, 65071.167324776194, 65784.47798496671, 66499.99488594585, 67217.40471640999, 67936.37870402462, 68656.57238681741, 69377.62541340078, 70099.16137500064, 70820.78767235835, 71542.0954206499, 72262.65939563085, 72982.03802426143, 73699.773423095, },
{55661.523164922415, 56302.64328110644, 56947.441266534996, 57595.68675303393, 58247.167375756, 58901.65810173295, 59558.92091337913, 60218.704504654765, 60880.74399200396, 61544.76064230015, 62210.461620145696, 62877.53975698283, 63545.6733445795, 64214.5259555517, 64883.7462936749, 65552.96807681878, 66221.80995540739, 66889.87546936392, 67556.75304653907, 68222.01604564385, },
{51162.8474876635, 51754.91612025769, 52350.32178358462, 52948.84981199925, 53550.302157592465, 54154.46906759288, 54761.12879594005, 55370.04732681977, 55980.97811211692, 56593.661824848634, 57207.82613074411, 57823.18548023716, 58439.44092323414, 59056.27994910827, 59673.37635445256, 60290.39014119641, 60906.96744775174, 61522.74051590296, 62137.32769618997, 62750.333494550134, },
{46666.49777211378, 47209.62931464505, 47755.76106123324, 48304.694112264864, 48856.24480111183, 49410.21871447837, 49966.410431447286, 50524.60327376349, 51084.56906915156, 51646.0679295616, 52208.848046330706, 52772.64550433772, 53337.18411731502, 53902.17528656061, 54467.31788536603, 55032.29817153959, 55596.789730458724, 56160.453451125846, 56722.937537732374, 57283.87755924745, },
{42171.84599725953, 42666.13761021082, 43163.09615794535, 43662.53856593227, 44164.295608468325, 44668.18826693066, 45174.027495760405, 45681.613998933644, 46190.73801855908, 46701.179137329105, 47212.70609663441, 47725.07663223274, 48238.0373294395, 48751.32349987788, 49264.65908189025, 49777.7565667689, 50290.3169530106, 50802.029730834794, 51312.57289922957, 51821.613017798205, },
{37678.72591317768, 38124.26254017362, 38572.13596982114, 39022.179005644575, 39474.23691632536, 39928.146127446744, 40383.734013936824, 40840.8187022266, 41299.20888360611, 41758.703640338426, 42219.0922861661, 42680.15422291537, 43141.65881497132, 43603.365283458734, 44065.02262201959, 44526.36953612601, 44987.13440790828, 45447.03528850629, 45905.77991997275, 46363.06578876164, },
{33186.50944354786, 33583.358792050654, 33982.217493666845, 34382.93427849533, 34785.36895836101, 35189.37344850328, 35594.791586061096, 36001.45895748129, 36409.20273617661, 36817.8415318283, 37227.18525279285, 37637.03498313442, 38047.182875863524, 38457.41206401596, 38867.496591253686, 39277.20136371111, 39686.28212484345, 40094.485455058166, 40501.54879792537, 40907.20051476553, },
{28694.722478030442, 29042.936693658394, 29392.83505237928, 29744.28225439162, 30097.15269822788, 30451.31382962411, 30806.62598568951, 31162.94224718998, 31520.108300116575, 31877.962307769027, 32236.33479464011, 32595.04854343999, 32953.918506649854, 33312.75173403966, 33671.34731762496, 34029.49635557253, 34386.98193659184, 34743.57914636833, 35099.0550976057, 35453.16898524342, },
{24202.737054454465, 24502.351056925905, 24803.325777860562, 25105.541926636175, 25408.888527363815, 25713.248593040844, 26018.498995108228, 26324.510340297424, 26631.146855783063, 26938.266283707366, 27245.71978618925, 27553.35186197567, 27861.000275934628, 28168.496002626864, 28475.663185226233, 28782.319111086657, 29088.274205275113, 29393.33204340445, 29697.28938510648, 29999.936229483574, },
};

float step_sizes[2] = {29197.21052631579, 21066.947368421053, };

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