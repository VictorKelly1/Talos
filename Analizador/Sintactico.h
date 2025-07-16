#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib> 
#include "Lexico.h"
#include <stack>
#include <unordered_map>

using namespace std;

public class Sintactico
{
public:

    Sintactico() {
        pila.push(1);
    }

    const int matrizPredictiva[47][61] = {
        //   0,     1,     2,     3,     4,     5,     6,     7,     8,     9,     10,     11,     12,    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,    23,        24,      25,      26,       27,       28,    29,      30,    31,     32,    33,      34,    35,    36,   37,     38,     39,    40,   41,     42,   43,    44,   45,    46,     47,      48,   49,    50,   51,    52,   53,     54,   55,     56,    57,      58,      59,   60}
        //  id,     .,     ;,     ,,     =,     (,     ),    ++,    --,    ||,     &&,      !,     + ,     -,    ==,    !=,     <,    <=,     >,    >=,     *,     /,     %,    **, cteentera, ctereal, ctenota, ctecarac, ctestrin,    to, include,   lib, endlib, class, endclas,   int, float, char, string,   bool,  void,   if, elseif, else, endif,   do, enddo,  while, endwhil, read, write,  def, const,   of, dowhil,  for, endfor, funct, endfunc,  return,    $}
        {  600,   600,   600,   600,   600,   600,   600,   600,   600,   600,    600,    600,    600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,       600,     600,     600,      600,      600,   600,       1,   600,    600,     8,     600,   600,   600,  600,    600,    600,   600,  600,    600,  600,   600,  600,   600,    600,     600,  600,   600,    1,     1,  600,    600,  600,    600,     1,     600,     600,  600}, //0
        {  601,   601,   601,   601,   601,   601,   601,   601,   601,   601,    601,    601,    601,   601,   601,   601,   601,   601,   601,   601,   601,   601,   601,   601,       601,     601,     601,      601,      601,   601,       2,   601,    601,     3,     601,   601,   601,  601,    601,    601,   601,  601,    601,  601,   601,  601,   601,    601,     601,  601,   601,    3,     3,  601,    601,  601,    601,     3,     601,     601,  601}, //1
        {  602,   602,   602,   602,   602,   602,   602,   602,   602,   602,    602,    602,    602,   602,   602,   602,   602,   602,   602,   602,   602,   602,   602,   602,       602,     602,     602,      602,      602,   602,     602,   602,    602,     7,     602,   602,   602,  602,    602,    602,   602,  602,    602,  602,   602,  602,   602,    602,     602,  602,   602,    4,     5,  602,    602,  602,    602,     6,     602,     602,    7}, //2
        {  603,   603,   602,   603,   603,   603,   603,   603,   603,   603,    603,    603,    603,   603,   603,   603,   603,   603,   603,   603,   603,   603,   603,   603,       603,     603,     603,      603,      603,   603,     603,   603,    603,     8,     603,   603,   603,  603,    603,    603,   603,  603,    603,  603,   603,  603,   603,    603,     603,  603,   603,  603,   603,  603,    603,  603,    603,   603,     603,     603,  603}, //3
        {   12,   604,   604,   604,   604,   604,   604,   604,   604,   604,    604,    604,    604,   604,   604,   604,   604,   604,   604,   604,   604,   604,   604,   604,       604,     604,     604,      604,      604,   604,     604,   604,    604,    10,     604,   604,   604,  604,    604,    604,   604,  604,    604,  604,   604,  604,   604,    604,     604,  604,   604,    9,    10,  604,    604,  604,    604,    10,      10,      10,  604}, //4
        {   11,   605,   605,   605,   605,   605,   605,   605,   605,   605,    605,    605,    605,   605,   605,   605,   605,   605,   605,   605,   605,   605,   605,   605,       605,     605,     605,      605,      605,   605,     605,   605,    605,   605,     605,   605,   605,  605,    605,    605,   605,  605,    605,  605,   605,  605,   605,    605,     605,  605,   605,  605,   605,  605,    605,  605,    605,   605,     605,     605,  605}, //5
        {  606,   606,   606,    13,   606,   606,   606,   606,   606,   606,    606,    606,    606,   606,   606,   606,   606,   606,   606,   606,   606,   606,   606,   606,       606,     606,     606,      606,      606,   606,     606,   606,    606,   606,     606,   606,   606,  606,    606,    606,   606,  606,    606,  606,   606,  606,   606,    606,     606,  606,   606,  606,   606,   12,    606,  606,    606,   606,     606,     606,  606}, //6
        {  607,   607,   607,   607,   607,   607,   607,   607,   607,   607,    607,    607,    607,   607,   607,   607,   607,   607,   607,   607,   607,   607,   607,   607,       607,     607,     607,      607,      607,   607,     607,   607,    607,    15,     607,   607,   607,  607,    607,    607,   607,  607,    607,  607,   607,  607,   607,    607,     607,  607,   607,   15,    14,  607,    607,  607,    607,    15,     607,     607,  607}, //7
        {  608,   608,   608,   608,   608,   608,   608,   608,   608,   608,    608,    608,    608,   608,   608,   608,   608,   608,   608,   608,   608,   608,   608,   608,       608,     608,     608,      608,      608,   608,     608,   608,    608,   608,     608,   608,   608,  608,    608,    608,   608,  608,    608,  608,   608,  608,   608,    608,     608,  608,   608,  608,   608,  608,    608,  608,    608,    16,     608,     608,  608}, //8
        {   17,   609,   609,   609,   609,   609,   609,    21,    21,   609,    609,    609,    609,   609,   609,   609,   609,   609,   609,   609,   609,   609,   609,   609,       609,     609,     609,      609,      609,   609,     609,   609,    609,   609,      26,   609,   609,  609,    609,    609,   609,   22,     26,   26,    26,   24,    26,     23,      26,   20,    19,  609,   609,  609,     26,   25,     26,   609,      10,      18,  609}, //9
        {   27,   610,   610,   610,   610,   610,   610,   610,   610,   610,    610,    610,    610,   610,   610,   610,   610,   610,   610,   610,   610,   610,   610,   610,       610,     610,     610,      610,      610,   610,     610,   610,    610,   610,     610,   610,   610,  610,    610,    610,   610,  610,    610,  610,   610,  610,   610,    610,     610,  610,   610,  610,   610,  610,    610,  610,    610,   610,     610,     610,  610}, //10
        {  611,   611,   611,   611,    28,   611,   611,    29,    29,   611,    611,    611,    611,   611,   611,   611,   611,   611,   611,   611,   611,   611,   611,   611,       611,     611,     611,      611,      611,   611,     611,   611,    611,   611,     611,   611,   611,  611,    611,    611,   611,  611,    611,  611,   611,  611,   611,    611,     611,  611,   611,  611,   611,  611,    611,  611,    611,   611,     611,     611,  611}, //11
        {  612,   612,   612,   612,   612,   612,   612,   612,   612,   612,    612,    612,    612,   612,   612,   612,   612,   612,   612,   612,   612,   612,   612,   612,       612,     612,     612,      612,      612,   612,     612,   612,    612,   612,     612,    30,    31,   32,     33,     34,    35,  612,    612,  612,   612,  612,   612,    612,     612,  612,   612,  612,   612,  612,    612,  612,    612,   612,     612,     612,  612}, //12
        {  613,   613,   613,   613,   613,   613,   613,   613,   613,   613,    613,    613,    613,   613,   613,   613,   613,   613,   613,   613,   613,   613,   613,   613,        36,      37,      38,       39,       40,   613,     613,   613,    613,   613,     613,   613,   613,  613,    613,    613,   613,  613,    613,  613,   613,  613,   613,    613,     613,  613,   613,  613,   613,  613,    613,  613,    613,   613,     613,     613,  613}, //13
        {   42,   614,   614,   614,   614,   614,    43,   614,   614,   614,    614,    614,    614,   614,   614,   614,   614,   614,   614,   614,   614,   614,   614,   614,       614,     614,     614,      614,      614,   614,     614,   614,    614,   614,     614,   614,   614,  614,    614,    614,   614,  614,    614,  614,   614,  614,   614,    614,     614,  614,   614,  614,   614,  614,    614,  614,    614,   614,     614,     614,  614}, //14
        {   44,   615,   615,   615,    45,   615,    45,   615,   615,   615,    615,    615,    615,   615,   615,   615,   615,   615,   615,   615,   615,   615,   615,   615,       615,     615,     615,      615,      615,   615,     615,   615,    615,   615,     615,   615,   615,  615,    615,    615,   615,  615,    615,  615,   615,  615,   615,    615,     615,  615,   615,  615,   615,  615,    615,  615,    615,   615,     615,     615,  615}, //15
        {  616,   616,   616,    46,    45,   616,    45,   616,   616,   616,    616,    616,    616,   616,   616,   616,   616,   616,   616,   616,   616,   616,   616,   616,       616,     616,     616,      616,      616,   616,     616,   616,    616,   616,     616,   616,   616,  616,    616,    616,   616,  616,    616,  616,   616,  616,   616,    616,     616,  616,   616,  616,   616,  616,    616,  616,    616,   616,     616,     616,  616}, //16
        {  617,   617,   617,   617,   617,   617,   617,   617,   617,   617,    617,    617,    617,   617,   617,   617,   617,   617,   617,   617,   617,   617,   617,   617,       617,     617,     617,      617,      617,   617,     617,   617,    617,   617,     617,   617,   617,  617,    617,    617,   617,  617,    617,  617,   617,  617,   617,    617,     617,  617,   617,  617,   617,  617,    617,  617,    617,   617,     617,      47,  617}, //17
        {  618,   618,   618,   618,   618,   618,   618,   618,   618,   618,    618,    618,    618,   618,   618,   618,   618,   618,   618,   618,   618,   618,   618,   618,       618,     618,     618,      618,      618,   618,     618,   618,    618,   618,     618,   618,   618,  618,    618,    618,   618,  618,    618,  618,   618,  618,   618,    618,     618,  618,    48,  618,   618,  618,    618,  618,    618,   618,     618,     618,  618}, //18
        {  619,   619,   619,    49,   619,   619,    50,   619,   619,   619,    619,    619,    619,   619,   619,   619,   619,   619,   619,   619,   619,   619,   619,   619,       619,     619,     619,      619,      619,   619,     619,   619,    619,   619,     619,   619,   619,  619,    619,    619,   619,  619,    619,  619,   619,  619,   619,    619,     619,  619,   619,  619,   619,  619,    619,  619,    619,   619,     619,     619,  619}, //19
        {  620,   620,   620,   620,   620,   620,   620,   620,   620,   620,    620,    620,    620,   620,   620,   620,   620,   620,   620,   620,   620,   620,   620,   620,       620,     620,     620,      620,      620,   620,     620,   620,    620,   620,     620,   620,   620,  620,    620,    620,   620,  620,    620,  620,   620,  620,   620,    620,     620,   51,   620,  620,   620,  620,    620,  620,    620,   620,     620,     620,  620}, //20
        {  621,   621,   621,    52,   621,   621,    53,   621,   621,   621,    621,    621,    621,   621,   621,   621,   621,   621,   621,   621,   621,   621,   621,   621,       621,     621,     621,      621,      621,   621,     621,   621,    621,   621,     621,   621,   621,  621,    621,    621,   621,  621,    621,  621,   621,  621,   621,    621,     621,  621,   621,  621,   621,  621,    621,  621,    621,   621,     621,     621,  621}, //21
        {  622,   622,   622,   622,   622,   622,   622,    54,    54,   622,    622,    622,    622,   622,   622,   622,   622,   622,   622,   622,   622,   622,   622,   622,       622,     622,     622,      622,      622,   622,     622,   622,    622,   622,     622,   622,   622,  622,    622,    622,   622,  622,    622,  622,   622,  622,   622,    622,     622,  622,   622,  622,   622,  622,    622,  622,    622,   622,     622,     622,  622}, //22
        {  623,   623,   623,   623,   623,   623,   623,    55,    56,   623,    623,    623,    623,   623,   623,   623,   623,   623,   623,   623,   623,   623,   623,   623,       623,     623,     623,      623,      623,   623,     623,   623,    623,   623,     623,   623,   623,  623,    623,    623,   623,  623,    623,  623,   623,  623,   623,    623,     623,  623,   623,  623,   623,  623,    623,  623,    623,   623,     623,     623,  623}, //23
        {  624,   624,   624,   624,   624,   624,   624,    57,    58,   624,    624,    624,    624,   624,   624,   624,   624,   624,   624,   624,   624,   624,   624,   624,       624,     624,     624,      624,      624,   624,     624,   624,    624,   624,     624,   624,   624,  624,    624,    624,   624,  624,    624,  624,   624,  624,   624,    624,     624,  624,   624,  624,   624,  624,    624,  624,    624,   624,     624,     624,  624}, //24
        {  625,   625,   625,   625,   625,   625,   625,   625,   625,   625,    625,    625,    625,   625,   625,   625,   625,   625,   625,   625,   625,   625,   625,   625,       625,     625,     625,      625,      625,   625,     625,   625,    625,   625,     625,   625,   625,  625,    625,    625,   625,   59,    625,  625,   625,  625,   625,    625,     625,  625,   625,  625,   625,  625,    625,  625,    625,   625,     625,     625,  625}, //25
        {  626,   626,   626,   626,   626,   626,   626,   626,   626,   626,    626,    626,    626,   626,   626,   626,   626,   626,   626,   626,   626,   626,   626,   626,       626,     626,     626,      626,      626,   626,     626,   626,    626,   626,     626,   626,   626,  626,    626,    626,   626,  626,     60,   61,    61,  626,   626,    626,     626,  626,   626,  626,   626,  626,    626,  626,    626,   626,     626,     626,  626}, //26
        {  627,   627,   627,   627,   627,   627,   627,   627,   627,   627,    627,    627,    627,   627,   627,   627,   627,   627,   627,   627,   627,   627,   627,   627,       627,     627,     627,      627,      627,   627,     627,   627,    627,   627,     627,   627,   627,  627,    627,    627,   627,  627,    627,   62,    63,  627,   627,    627,     627,  627,   627,  627,   627,  627,    627,  627,    627,   627,     627,     627,  627}, //27
        {  628,   628,   628,   628,   628,   628,   628,   628,   628,   628,    628,    628,    628,   628,   628,   628,   628,   628,   628,   628,   628,   628,   628,   628,       628,     628,     628,      628,      628,   628,     628,   628,    628,   628,     628,   628,   628,  628,    628,    628,   628,  628,    628,  628,   628,  628,   628,     64,     628,  628,   628,  628,   628,  628,    628,  628,    628,   628,     628,     628,  628}, //28
        {  629,   629,   629,   629,   629,   629,   629,   629,   629,   629,    629,    629,    629,   629,   629,   629,   629,   629,   629,   629,   629,   629,   629,   629,       629,     629,     629,      629,      629,   629,     629,   629,    629,   629,     629,   629,   629,  629,    629,    629,   629,  629,    629,  629,   629,   65,   629,    629,     629,  629,   629,  629,   629,  629,    629,  629,    629,   629,     629,     629,  629}, //29
        {  630,   630,   630,   630,   630,   630,   630,   630,   630,   630,    630,    630,    630,   630,   630,   630,   630,   630,   630,   630,   630,   630,   630,   630,       630,     630,     630,      630,      630,   630,     630,   630,    630,   630,     630,   630,   630,  630,    630,    630,   630,  630,    630,  630,   630,  630,   630,    630,     630,  630,   630,  630,   630,  630,    630,   66,    630,   630,     630,     630,  630}, //30
        {   67,   631,   631,   631,   631,    67,   631,   631,   631,   631,    631,     67,    631,   631,   631,   631,   631,   631,   631,   631,   631,   631,   631,   631,        67,      67,      67,       67,       67,   631,     631,   631,    631,   631,     631,   631,   631,  631,    631,    631,   631,  631,    631,  631,   631,  631,   631,    631,     631,  631,   631,  631,   631,  631,    631,  631,    631,   631,     631,     631,  631}, //31
        {  632,   632,    69,    69,   632,   632,    69,   632,   632,    68,    632,    632,    632,   632,   632,   632,   632,   632,   632,   632,   632,   632,   632,   632,       632,     632,     632,      632,      632,    69,     632,   632,    632,   632,     632,   632,   632,  632,    632,    632,   632,  632,    632,  632,   632,  632,   632,    632,     632,  632,   632,  632,   632,  632,    632,  632,    632,   632,     632,     632,  632}, //32
        {   70,   633,   633,   633,   633,    70,   633,   633,   633,   633,    633,     70,    633,   633,   633,   633,   633,   633,   633,   633,   633,   633,   633,   633,        70,      70,      70,       70,       70,   633,     633,   633,    633,   633,     633,   633,   633,  633,    633,    633,   633,  633,    633,  633,   633,  633,   633,    633,     633,  633,   633,  633,   633,  633,    633,  633,    633,   633,     633,     633,  633}, //33
        {  634,   634,    72,    72,   634,   634,    72,   634,   634,    72,     71,    634,    634,   634,   634,   634,   634,   634,   634,   634,   634,   634,   634,   634,       634,     634,     634,      634,      634,    72,     634,   634,    634,   634,     634,   634,   634,  634,    634,    634,   634,  634,    634,  634,   634,  634,   634,    634,     634,  634,   634,  634,   634,  634,    634,  634,    634,   634,     634,     634,  634}, //34
        {   74,   635,   635,   635,   635,    74,   635,   635,   635,   635,    635,     73,    635,   635,   635,   635,   635,   635,   635,   635,   635,   635,   635,   635,        74,      74,      74,       74,       74,   635,     635,   635,    635,   635,     635,   635,   635,  635,    635,    635,   635,  635,    635,  635,   635,  635,   635,    635,     635,  635,   635,  635,   635,  635,    635,  635,    635,   635,     635,     635,  635}, //35
        {   75,   636,   636,   636,   636,    75,   636,   636,   636,   636,    636,    636,    636,   636,   636,   636,   636,   636,   636,   636,   636,   636,   636,   636,        75,      75,      75,       75,       75,   636,     636,   636,    636,   636,     636,   636,   636,  636,    636,    636,   636,  636,    636,  636,   636,  636,   636,    636,     636,  636,   636,  636,   636,  636,    636,  636,    636,   636,     636,     636,  636}, //36
        {  637,   637,    77,    77,   637,   637,    77,   637,   637,   637,     77,    637,    637,   637,    76,    76,    76,    76,    76,    76,   637,   637,   637,   637,       637,     637,     637,      637,      637,    77,     637,   637,    637,   637,     637,   637,   637,  637,    637,    637,   637,  637,    637,  637,   637,  637,   637,    637,     637,  637,   637,  637,   637,  637,    637,  637,    637,   637,     637,     637,  637}, //37
        {   78,   638,   638,   638,   638,   638,    78,   638,   638,   638,    638,    638,    638,   638,   638,   638,   638,   638,   638,   638,   638,   638,   638,   638,        78,      78,      78,       78,       78,   638,     638,   638,    638,   638,     638,   638,   638,  638,    638,    638,   638,  638,    638,  638,   638,  638,   638,    638,     638,  638,   638,  638,   638,  638,    638,  638,    638,   638,     638,     638,  638}, //38
        {  639,   639,    81,   81,   639,   639,     81,   639,   639,    81,     81,    639,     79,    80,    81,    81,    81,    81,    81,    81,   639,   639,   639,   639,       639,     639,     639,      639,      639,   81,     639,   639,    639,   639,     639,   639,   639,  639,    639,    639,   639,  639,    639,  639,   639,  639,   639,    639,     639,  639,   639,  639,   639,  639,    639,  639,    639,   639,     639,     639,  639}, //39
        {  640,   640,   640,   640,   640,   640,   640,   640,   640,   640,    640,    640,    640,   640,    82,    83,    84,    85,    86,    87,   640,   640,   640,   640,       640,     640,     640,      640,      640,   640,     640,   640,    640,   640,     640,   640,   640,  640,    640,    640,   640,  640,    640,  640,   640,  640,   640,    640,     640,  640,   640,  640,   640,  640,    640,  640,    640,   640,     640,     640,  640}, //40
        {   88,   641,   641,   641,   641,    88,   641,   641,   641,   641,    641,    641,    641,   641,   641,   641,   641,   641,   641,   641,   641,   641,   641,   641,        88,      88,      88,       88,       88,   641,     641,   641,    641,   641,     641,   641,   641,  641,    641,    641,   641,  641,    641,  641,   641,  641,   641,    641,     641,  641,   641,  641,   641,  641,    641,  641,    641,   641,     641,     641,  641}, //41
        {  642,   642,    93,    93,   642,   642,    93,   642,   642,    93,     93,    642,     93,    93,    93,    93,    93,    93,    93,    93,    89,    90,    91,    92,       642,     642,     642,      642,      642,    93,     642,   642,    642,   642,     642,   642,   642,  642,    642,    642,   642,  642,    642,  642,   642,  642,   642,    642,     642,  642,   642,  642,   642,  642,    642,  642,    642,   642,     642,     642,  642}, //42
        {   94,   643,   643,   643,   643,    96,   643,   643,   643,   643,    643,    643,    643,   643,   643,   643,   643,   643,   643,   643,   643,   643,   643,   643,        95,      95,      95,       95,       95,   643,     643,   643,    643,   643,     643,   643,   643,  643,    643,    643,   643,  643,    643,  643,   643,  643,   643,    643,     643,  643,   643,  643,   643,  643,    643,  643,    643,   643,     643,     643,  643}, //43
        {  644,   644,    98,    98,   644,    97,    98,   644,   644,    98,     98,    644,     98,    98,    98,    98,    98,    98,    98,    98,    98,    98,    98,    98,       644,     644,     644,      644,      644,    98,     644,   644,    644,   644,     644,   644,   644,  644,    644,    644,   644,  644,    644,  644,   644,  644,   644,    644,     644,  644,   644,  644,   644,  644,    644,  644,    644,   644,     644,     644,  644}, //44
        {   99,   645,   645,   645,   645,   645,   100,   645,   645,   645,    645,    645,    645,   645,   645,   645,   645,   645,   645,   645,   645,   645,   645,   645,       645,     645,     645,      645,      645,   645,     645,   645,    645,   645,     645,   645,   645,  645,    645,    645,   645,  645,    645,  645,   645,  645,   645,    645,     645,  645,   645,  645,   645,  645,    645,  645,    645,   645,     645,     645,  645}, //45
        {  646,   646,   646,   101,   646,   646,   102,   646,   646,   646,    646,    646,    646,   646,   646,   646,   646,   646,   646,   646,   646,   646,   646,   646,       646,     646,     646,      646,      646,   646,     646,   646,    646,   646,     646,   646,   646,  646,    646,    646,   646,  646,    646,  646,   646,  646,   646,    646,     646,  646,   646,  646,   646,  646,    646,  646,    646,   646,     646,     646,  646}, //46

    };

    std::vector<std::vector<int>> matrizProducciones = {
        {0},
        {8, 4, 2}, 
        {2, 147, 138, 137, 136, 135},
        {-100},             
        {4, 9},  
        {4, 14},
        {4, 16},
        {-100},
        {141, 17, 140},
        {147, 30, 143, 11, 142},
        {-100},
        {12, 136},
        {-100},
        {12, 136, 145},
        {147, 36, 146, 136, 145},
        {-100},
        {151, 17, 9, 150, 41, 149, 30, 146, 136, 148},
        {17, 147, 27},
        {17, 147, 47},
        {17, 147, 48},
        {17, 147, 51},
        {17, 147, 57},
        {17, 59},
        {17, 64},
        {17, 65},
        {17, 66},
        {-100},
        {28, 136},
        {67, 146},
        {54},
        {152},
        {153},
        {154},
        {155},
        {156},
        {157},
        {158},
        {159},
        {160},
        {161},
        {162},
        {41, 144, 30, 146, 44},
        {30, 146, 44},
        {-100},
        {46, 136},
        {-100},
        {45, 136, 144},
        {67, 163},
        {150, 49, 67, 149, 164},
        {49, 67, 144},
        {-100},
        {150, 52, 136, 149, 165},
        {52, 136, 144},
        {-100},
        {55},
        {166},
        {167},
        {136, 166},
        {136, 167},
        {169, 62, 60, 17, 150, 67, 149, 168},
        {60, 17, 150, 67, 149, 170},
        {-100},
        {17, 171},
        {-100},
        {173, 17, 150, 67, 149, 172},
        {176, 150, 67, 149, 175, 17, 174},
        {179, 17, 150, 67, 178, 67, 149, 136, 177},
        {68, 70},
        {68, 70, 180},
        {-100},
        {71, 73},
        {71, 73, 181},
        {-100},
        {75, 182},
        {75},
        {76, 78},
        {78, 82},
        {-100},
        {79, 88},
        {78, 183},
        {78, 184},
        {-100},
        {185},
        {186},
        {187},
        {188},
        {189},
        {190},
        {89, 94},
        {89, 94, 191},
        {89, 94, 192},
        {89, 94, 193},
        {89, 94, 194},
        {-100},
        {97, 136},
        {36},
        {150, 67, 149},
        {150, 99, 149},
        {-100},
        {101, 136},
        {-100},
        {101, 136, 144},
        {-100}
    };

    std::stack<int> pila;
    
    int pilaAnterior = 0;
    int valorMPAnterior = 0;
    int valorMP = 0;
    int fila = 0;
    int columna = 0;
    int valorToken = 0;

    Lexico lexico;
    Token token = lexico.siguienteToken();
    //

    void analizar(std::string lexema, std::string gramema) {
        //validaciones
        //si es comentario paso al siguiente token
        if (gramema == "Cometario de linea" || gramema == "Comentario de bloque") {
            Token token = lexico.siguienteToken();
            analizar(token.lexema, token.gramema);
            return;
        }
        if (lexema == "" && pila.empty()) {
            std::cout << "Analisis finalizado, la sintaxis es Correcta!." << std::endl;
            return;
        }
        if (lexema != "" && !pila.empty()) {
            valorToken = identificaToken(lexema, gramema);
            //std::cout << "--------: " << valorToken << std::endl; //Debug lines
        }
        else {
            std::cout << "Final inesperado." << std::endl;
            return;
        }
        

        //si tope es igual lo saco y paso al siguiente
        if (!pila.empty() && pila.top() == valorToken) {
            //std::cout << "saca1: " << pila.top() << std::endl; //Debug lines
            pila.pop();
            Token token = lexico.siguienteToken();
            analizar(token.lexema, token.gramema);
            return;
        }

        //si el tope de la pila no es terminal, sino produccion calculo lo que se inserta y saco el top
        // Validación antes de acceder a pila.top()
        if (!pila.empty()) {
            fila = nuevaFila(pila.top());
            //std::cout << "fila: " << fila << std::endl; //Debug lines
        }
        else {
            return;
        }
        columna = nuevaColumna(valorToken);
        //std::cout << "colum: " << columna << std::endl; //Debug lines
        valorMP = matrizPredictiva[fila][columna];
        //std::cout << "valor: " << valorMP << std::endl;  //Debug lines
        // si hay error lo muestra aqui 
        if (valorMP >= 600 || pila.empty()) {
            //std::cout << "top   : " << pila.top() << std::endl;  //Debug lines
            std::cout << "Ha ocurrido un error!: " << error(valorMP) << std::endl;
            return;
        }

        
        if (!pila.empty()) {
            //std::cout << "saca2: " << pila.top() << std::endl; //Debug lines
            pila.pop();
        }else {
            
            return;
        }

        //inserta los valores en la pila si no es vacio
        if (matrizProducciones[valorMP][0] != -100) {
            const std::vector<int>& produccion = matrizProducciones[valorMP];
            for (int i = 0; i < produccion.size(); ++i) {
                pila.push(produccion[i]);
                //std::cout << "inserta: " << produccion[i] << std::endl;  //Debug lines
            }
        }

        //Si de la nueva prodcuccion insertada el tope es igual al token actual lo scao y voy al siguiente
        if (!pila.empty() && pila.top() == valorToken) {
            //std::cout << "saca3: " << pila.top() << std::endl; //Debug lines
            pila.pop();
            Token token = lexico.siguienteToken();
            analizar(token.lexema, token.gramema);
            return;
        }//Si la pila tiene valores pero el tope no es igual, llamo de nuevo a la funcion con el mismo token para que se valide lo nuevo arriba
        else if(!pila.empty() && pila.top() != valorToken){
            analizar(lexema, gramema);
            return;
        }

        if (lexema != "" && pila.empty()) {
            std::cout << "Final de archivo inesperado: " << std::endl;
            return;
        }
        
    }

    int nuevaColumna(int valToken) {
        // Map token values (135-194) to column numbers
        switch (valToken) {
        case 135: return 30;  // include
        case 136: return 0;    // id
        case 137: return 1;    // .
        case 138: return 31;   // lib
        case 139: return 32;   // endlib
        case 140: return 33;   // class
        case 141: return 34;   // endclass
        case 142: return 51;   // def
        case 143: return 53;   // of
        case 144: return 3;    // ,
        case 145: return 52;   // const
        case 146: return 4;    // /= (assuming = is mapped to same as /=)
        case 147: return 2;    // ;
        case 148: return 57;   // function
        case 149: return 5;    // (
        case 150: return 6;    // )
        case 151: return 58;   // endfunction
        case 152: return 35;   // int
        case 153: return 36;   // float
        case 154: return 37;   // char
        case 155: return 38;   // string
        case 156: return 39;   // bool
        case 157: return 40;   // void
        case 158: return 24;   // cteentera
        case 159: return 25;   // ctereal
        case 160: return 26;   // ctenotacion
        case 161: return 27;   // ctecaracter
        case 162: return 28;   // ctestring
        case 163: return 59;   // return
        case 164: return 50;   // write
        case 165: return 49;   // read
        case 166: return 7;    // ++
        case 167: return 8;    // --
        case 168: return 41;   // if
        case 169: return 44;   // endif
        case 170: return 42;   // elseif
        case 171: return 43;   // else
        case 172: return 47;   // while
        case 173: return 48;   // endwhile
        case 174: return 45;   // do
        case 175: return 54;   // dowhile
        case 176: return 46;   // enddo
        case 177: return 55;   // for
        case 178: return 29;   // to
        case 179: return 56;   // endfor
        case 180: return 9;    // ||
        case 181: return 10;   // &&
        case 182: return 11;   // !
        case 183: return 12;   // +
        case 184: return 13;   // -
        case 185: return 14;   // ==
        case 186: return 15;   // !=
        case 187: return 16;   // <
        case 188: return 17;   // <=
        case 189: return 18;   // >
        case 190: return 19;   // >=
        case 191: return 20;   // *
        case 192: return 21;   // /
        case 193: return 22;   // %
        case 194: return 23;   // **
        default: return 0;     // default to id (0)
        }
    }

    int identificaToken(std::string lexema, std::string gramema) {
        // 1. Primero verificamos el tipo gramatical (gramema) para constantes
        if (gramema == "Cteentera") return 158;
        if (gramema == "Ctereal") return 159;
        if (gramema == "Ctenotacion") return 160;
        if (gramema == "Ctecaracter") return 161;
        if (gramema == "Ctestring") return 162;

        // 2. Luego verificamos palabras reservadas
        if (lexema == "include") return 135;
        if (lexema == "lib") return 138;
        if (lexema == "endlib") return 139;
        if (lexema == "class") return 140;
        if (lexema == "endclass") return 141;
        if (lexema == "def") return 142;
        if (lexema == "of") return 143;
        if (lexema == "const") return 145;
        if (lexema == "function") return 148;
        if (lexema == "endfunction") return 151;
        if (lexema == "int") return 152;
        if (lexema == "float") return 153;
        if (lexema == "char") return 154;
        if (lexema == "string") return 155;
        if (lexema == "bool") return 156;
        if (lexema == "void") return 157;
        if (lexema == "return") return 163;
        if (lexema == "write") return 164;
        if (lexema == "read") return 165;
        if (lexema == "if") return 168;
        if (lexema == "endif") return 169;
        if (lexema == "elseif") return 170;
        if (lexema == "else") return 171;
        if (lexema == "while") return 172;
        if (lexema == "endwhile") return 173;
        if (lexema == "do") return 174;
        if (lexema == "dowhile") return 175;
        if (lexema == "enddo") return 176;
        if (lexema == "for") return 177;
        if (lexema == "to") return 178;
        if (lexema == "endfor") return 179;

        // 3. Verificamos símbolos y operadores
        if (lexema == ".") return 137;
        if (lexema == ",") return 144;
        if (lexema == "=") return 146;
        if (lexema == ";") return 147;
        if (lexema == "(") return 149;
        if (lexema == ")") return 150;
        if (lexema == "++") return 166;
        if (lexema == "--") return 167;
        if (lexema == "||") return 180;
        if (lexema == "&&") return 181;
        if (lexema == "!") return 182;
        if (lexema == "+") return 183;
        if (lexema == "-") return 184;
        if (lexema == "==") return 185;
        if (lexema == "!=") return 186;
        if (lexema == "<") return 187;
        if (lexema == "<=") return 188;
        if (lexema == ">") return 189;
        if (lexema == ">=") return 190;
        if (lexema == "*") return 191;
        if (lexema == "/") return 192;
        if (lexema == "%") return 193;
        if (lexema == "**") return 194;

        
        return 136;
    }

    int nuevaFila(int n) {//obtengo la fila de la Matriz predictiva con la relacion que tiene en la Matriz de producciones
        switch (n) {
        case 1:
            return 0;
        case 2:
        case 3:
            return 1;
        case 4:
        case 5:
        case 6:
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
        case 13:
            return 6;
        case 14:
        case 15:
            return 7;
        case 16:
            return 8;
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            return 9;
        case 27:
            return 10;
        case 28:
        case 29:
            return 11;
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
            return 12;
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
            return 13;
        case 41:
        case 42:
        case 43:
            return 14;
        case 44:
        case 45:
            return 15;
        case 46:
            return 16;
        case 47:
            return 17;
        case 48:
            return 18;
        case 49:
        case 50:
            return 19;
        case 51:
            return 20;
        case 52:
        case 53:
            return 21;
        case 54:
            return 22;
        case 55:
        case 56:
            return 23;
        case 57:
        case 58:
            return 24;
        case 59:
            return 25;
        case 60:
        case 61:
            return 26;
        case 62:
        case 63:
            return 27;
        case 64:
            return 28;
        case 65:
            return 29;
        case 66:
            return 30;
        case 67:
            return 31;
        case 68:
        case 69:
            return 32;
        case 70:
            return 33;
        case 71:
        case 72:
            return 34;
        case 73:
        case 74:
            return 35;
        case 75:
            return 36;
        case 76:
        case 77:
            return 37;
        case 78:
            return 38;
        case 79:
        case 80:
        case 81:
            return 39;
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
            return 40;
        case 88:
            return 41;
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
            return 42;
        case 94:
        case 95:
        case 96:
            return 43;
        case 97:
        case 98:
            return 44;
        case 99:
        case 100:
            return 45;
        case 101:
        case 102:
            return 46;
        default:
            return 0;
        }
    }

    std::string error(int codigo) {
        switch (codigo) {
            // 
        case 600: return "Error 600: Se esperaba 'include', 'def', 'const', 'function' o 'class' al inicio del programa";
        case 601: return "Error 601: Declaracion de libreria invalida. Formato correcto: 'include <id>.lib;'";
        case 602: return "Error 602: Declaracion de variable incompleta. Formato: 'def <id> of <tipo>;'";
        case 603: return "Error 603: Declaracion de constante invalida. Formato: 'const <id> = <valor>;'";
        case 604: return "Error 604: Funcion mal definida. Formato: 'function <id> = <tipo>(<params>) ... end_function'";
        case 605: return "Error 605: Clase mal definida. Formato: 'class ... endclass'";
        case 606: return "Error 606: Parametros de funcion invalidos. Formato: '<id> = <tipo>[, ...]'";
        case 607: return "Error 607: Estatuto no reconocido. Se esperaba asignacion, retorno, etc.";
        case 608: return "Error 608: Operador relacional faltante. Use '==', '!=', '<', '<=', '>', o '>='";
        case 609: return "Error 609: Expresion invalida. Comience con identificador, constante, '(', o '!'";
        case 610: return "Error 610: Estructura 'if' incompleta. Formato: 'if (EXPR) ESTATUTOS [elseif|else] endif'";
        case 611: return "Error 611: Estructura 'while' incompleta. Formato: 'while (EXPR) ESTATUTOS endwhile'";
        case 612: return "Error 612: Estructura 'do-while' incompleta. Formato: 'do ESTATUTOS dowhile (EXPR) enddo'";
        case 613: return "Error 613: Estructura 'for' incompleta. Formato: 'for id (EXPR to EXPR) ESTATUTOS endfor'";
        case 614: return "Error 614: Falta 'endif' en estructura 'if'";
        case 615: return "Error 615: Falta 'endwhile' en estructura 'while'";
        case 616: return "Error 616: Falta 'enddo' en estructura 'do-while'";
        case 617: return "Error 617: Falta 'endfor' en estructura 'for'";
        case 618: return "Error 618: Condicion invalida en estructura de control";
        case 619: return "Error 619: Bloque de estatutos vacio o invalido";
        case 620: return "Error 620: Operador binario sin operandos validos";
        case 621: return "Error 621: Operador unario '!' mal utilizado";
        case 622: return "Error 622: Parentesis no balanceados en expresion";
        case 623: return "Error 623: Operador aritmetico invalido";
        case 624: return "Error 624: Operador logico invalido";
        case 625: return "Error 625: Operando izquierdo faltante";
        case 626: return "Error 626: Operando derecho faltante";
        case 627: return "Error 627: Expresion incompleta";
        case 628: return "Error 628: Uso invalido de operador 'to' en 'for'";
        case 629: return "Error 629: Precedencia de operadores mal formada";
        case 630: return "Error 630: Tipo de dato no reconocido. Use 'int', 'float', 'char', 'string', 'bool' o 'void'";
        case 631: return "Error 631: Valor constante invalido";
        case 632: return "Error 632: Incompatibilidad de tipos en asignacion";
        case 633: return "Error 633: Literal de cadena mal formado";
        case 634: return "Error 634: Literal de caracter invalido";
        case 635: return "Error 635: Literal numerico invalido";
        case 636: return "Error 636: Tipo de retorno invalido en funcion";
        case 637: return "Error 637: Parametro de funcion con tipo invalido";
        case 638: return "Error 638: Valor de retorno invalido";
        case 639: return "Error 639: Conversion de tipo no permitida";
        case 640: return "Error 640: Llamada a funcion invalida. Formato: '<id>(<args>)'";
        case 641: return "Error 641: Argumento de funcion invalido";
        case 642: return "Error 642: Funcion no definida";
        case 643: return "Error 643: Numero incorrecto de argumentos";
        case 644: return "Error 644: Falta ')' en llamada a funcion";
        case 645: return "Error 645: Falta 'end_function' en declaracion";
        case 646: return "Error 646: Retorno fuera de funcion";

        default: return "Codigo de error desconocido";
        }
    }
    /*   EXAMPLE OF CORRECT GRAMMATIC

include math.lib;
include iostream.lib;

        def NumeroEntero of int;
        def NumeroDecimal of float;
        def Palabra of string;

        const CONSTANTE = 1 ;

        function Analizar = int(S = int)
            def VariableDeFuncion of int;
            --N;
            return S - N;
        endfunction

        function Relacionar = string(P = int)
            def Hola of string;

            if(X == Y  && W >= Z)
               ++N;
            endif

            return P;

        endfunction

class
        while (X == Y)
             ++X;
        endwhile
        do

        dowhile(X==Y  || W != Z)enddo

        if(X==Y)

        elseif(W==Z)

        else
        endif

        for A ( B to C)
        endfor

        N = X + B;
        N++;

        read(N);
        write(N + B);
endclass


    */

};

