#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib> 
#include "Lexico.h"
#include "Semantico.h"
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
        {   88,   641,    88,   641,   641,    88,   641,   641,   641,   641,    641,    641,    641,   641,   641,   641,   641,   641,   641,   641,   641,   641,   641,   641,        88,      88,      88,       88,       88,   641,     641,   641,    641,   641,     641,   641,   641,  641,    641,    641,   641,  641,    641,  641,   641,  641,   641,    641,     641,  641,   641,  641,   641,  641,    641,  641,    641,   641,     641,     641,  641}, //41
        {  642,   642,    93,    93,   642,   642,    93,   642,   642,    93,     93,    642,     93,    93,    93,    93,    93,    93,    93,    93,    89,    90,    91,    92,       642,     642,     642,      642,      642,    93,     642,   642,    642,   642,     642,   642,   642,  642,    642,    642,   642,  642,    642,  642,   642,  642,   642,    642,     642,  642,   642,  642,   642,  642,    642,  642,    642,   642,     642,     642,  642}, //42
        {   94,   643,    93,   643,   643,    96,   643,   643,   643,   643,    643,    643,    643,   643,   643,   643,   643,   643,   643,   643,   643,   643,   643,   643,        95,      95,      95,       95,       95,   643,     643,   643,    643,   643,     643,   643,   643,  643,    643,    643,   643,  643,    643,  643,   643,  643,   643,    643,     643,  643,   643,  643,   643,  643,    643,  643,    643,   643,     643,     643,  643}, //43
        {  644,   644,    98,    98,   644,    97,    98,   644,   644,    98,     98,    644,     98,    98,    98,    98,    98,    98,    98,    98,    98,    98,    98,    98,       644,     644,     644,      644,      644,    98,     644,   644,    644,   644,     644,   644,   644,  644,    644,    644,   644,  644,    644,  644,   644,  644,   644,    644,     644,  644,   644,  644,   644,  644,    644,  644,    644,   644,     644,     644,  644}, //44
        {   99,   645,   645,   645,   645,   645,   100,   645,   645,   645,    645,    645,    645,   645,   645,   645,   645,   645,   645,   645,   645,   645,   645,   645,       645,     645,     645,      645,      645,   645,     645,   645,    645,   645,     645,   645,   645,  645,    645,    645,   645,  645,    645,  645,   645,  645,   645,    645,     645,  645,   645,  645,   645,  645,    645,  645,    645,   645,     645,     645,  645}, //45
        {  646,   646,   646,   101,   646,   646,   102,   646,   646,   646,    646,    646,    646,   646,   646,   646,   646,   646,   646,   646,   646,   646,   646,   646,       646,     646,     646,      646,      646,   646,     646,   646,    646,   646,     646,   646,   646,  646,    646,    646,   646,  646,    646,  646,   646,  646,   646,    646,     646,  646,   646,  646,   646,  646,    646,  646,    646,   646,     646,     646,  646}, //46

    };

    std::vector<std::vector<int>> matrizProducciones = {
        {0},
        {8, 4, 2}, 
        {2, 1002, 1031, 1001, 1000, 1030},
        {-100},             
        {4, 9},  
        {4, 14},
        {4, 16},
        {-100},
        {1034, 17, 1033},
        {1002, 30, 1053, 11, 1051},
        {-100},
        {12, 1000, 2000},    //accion 
        {-100},
        {12, 1000, 1052},
        {1002, 36, 1004, 1000, 2000, 1052},  //accion
        {-100},
        {1058, 17, 9, 1006, 41, 1005, 30, 1004, 1000, 2000, 1057}, //accion
        {17, 1002, 27},
        {17, 1002, 47},
        {17, 1002, 48},
        {17, 1002, 51},
        {17, 1002, 57},
        {17, 59},
        {17, 64},
        {17, 65},
        {17, 66},
        {-100},
        {28, 1000, 2001}, //accion 
        {2009, 67, 1004, 2002}, //accion 
        {54},
        {1035, 2035},  //accion
        {1036, 2036},  //accion
        {1037, 2037},  //accion
        {1038, 2038},  //accion
        {1039, 2039},  //accion
        {1040, 2040},  //accion
        {1024, 2035},
        {1025, 2036},
        {1026, 2036},
        {1027, 2037},
        {1028, 2038},
        {41, 1003, 30, 1004, 44},
        {30, 1004, 44},
        {-100},
        {46, 1000, 2000},  //accion
        {-100},
        {45, 1000, 1003},
        {67, 1059},
        {1006, 49, 67, 1005, 1050},
        {49, 67, 1003},
        {-100},
        {1006, 52, 1000, 1005, 1049},
        {52, 1000, 1003},
        {-100},
        {55},
        {1007},
        {1008},
        {1000, 1007},
        {1000, 1008},
        {1044, 62, 60, 17, 1006, 67, 1005, 1041},
        {60, 17, 1006, 67, 1005, 1042},
        {-100},
        {17, 1043},
        {-100},
        {1048, 17, 1006, 67, 1005, 1047},
        {1046, 1006, 67, 1005, 1054, 17, 1045},
        {1056, 17, 1006, 67, 1029, 67, 1005, 1000, 1055},
        {68, 70},
        {68, 70, 1009, 2005}, //accion
        {-100},               
        {71, 73},
        {71, 73, 1010, 2005}, //accion
        {-100},
        {75, 1011},
        {75},
        {76, 78},
        {78, 82},
        {-100},
        {79, 2004, 88},   //accion
        {78, 1012, 2005}, //accion
        {78, 1013, 2005}, //accion
        {-100},
        {1014},
        {1015},
        {1016},
        {1017},
        {1018},
        {1019},
        {89, 2003, 94}, //accion
        {88, 94, 1020, 2005}, //accion
        {88, 94, 1021, 2005}, //accion
        {88, 94, 1022, 2005}, //accion
        {88, 94, 1023, 2005}, //accion
        {-100},
        {97, 1000, 2001}, //accion 
        {36},
        {1006, 2008, 67, 1005, 2007}, //accion
        {1006, 99, 1005},
        {-100},
        {101, 1000, 2001}, //accion
        {-100},
        {101, 1000, 2001, 1003}, //accion
        {-100}
    };

    //Pilas para generacion de IR
    std::stack<int> pilaSaltos;
    std::stack<std::string> pilaOperadoresIR;
    std::stack<std::string> pilaOperandos;

    //Pila para analizis sintactico
    std::stack<int> pila;

    //Pila para analizis semantico
    std::stack<char> pilaTipos;
    std::stack<std::string> pilaOperadores;
    //pilas auxiliares 
    std::stack<std::string> pilaTemporalDeclaraciones;
    std::stack<int> pilaTemporalAcciones;
    
    int pilaAnterior = 0;
    int valorMPAnterior = 0;
    int valorMP = 0;
    int fila = 0;
    int columna = 0;
    int valorToken = 0;

    Lexico lexico;
    Token token = lexico.siguienteToken();
    //

    void accionesSemanticas(std::string lexema, std::string gramema, int valorAccion, int valorTipo, 
        std::stack<char>& pilaTipos, std::stack<std::string>& pilaOperadores)
    {
        switch (valorAccion) {
        case 2000: Semantico::declarar(lexema, gramema, valorTipo); break; 
        case 2001: Semantico::insertarTipo(lexema, gramema, pilaTipos); break; 
        case 2002: Semantico::insertarOperador(lexema, gramema, pilaOperadores); break; 
        case 2003: Semantico::accionTres(pilaTipos, pilaOperadores); break; 
        case 2004: Semantico::accionCuatro(pilaTipos, pilaOperadores); break;
        case 2005: Semantico::accionCinco(lexema, gramema, pilaOperadores); break;
        case 2006: Semantico::accionCinco(lexema, gramema, pilaOperadores); break; 
        case 2007: Semantico::accionSiete(pilaOperadores); break;
        case 2008: Semantico::accionOcho(pilaOperadores); break;
        case 2009: Semantico::accionNueve(pilaTipos, pilaOperadores); break;
        default: break;
        } 
    }

    void analizar(std::string lexema, std::string gramema) {
        //Llamada a acciones semanticas 
        if (!pila.empty()) {
            int top = pila.top();

            // Declaración (2000)
            if (top == 2000) {
                pilaTemporalDeclaraciones.push(lexema);
                pilaTemporalAcciones.push(top);
                pila.pop();
            }
            // Acciones 2001 a 2009
            else if (top >= 2001 && top <= 2009) {
                accionesSemanticas(lexema, gramema, top, 0, pilaTipos, pilaOperadores);
                pila.pop();
            }
            // Tipos 2035 a 2039
            else if (top >= 2035 && top <= 2039) {
                if (!pilaTemporalDeclaraciones.empty() && !pilaTemporalAcciones.empty()) {
                    accionesSemanticas(
                        pilaTemporalDeclaraciones.top(), "null",
                        pilaTemporalAcciones.top(), top, 
                        pilaTipos, pilaOperadores  
                    );
                    pilaTemporalDeclaraciones.pop(); 
                    pilaTemporalAcciones.pop(); 
                }
                pila.pop();
            }
        }

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

        //Si de la nueva prodcuccion insertada el tope es igual al token actual lo saco y voy al siguiente
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
        return valToken - 1000;
    }

    int identificaToken(std::string lexema, std::string gramema) {
        // 1. Primero verificamos el tipo gramatical (gramema) para constantes
        if (gramema == "Cteentera") return 1024;
        if (gramema == "Ctereal") return 1025;
        if (gramema == "Ctenotacion") return 1026;
        if (gramema == "Ctecaracter") return 1027;
        if (gramema == "Ctestring") return 1028;

        // 2. Luego verificamos palabras reservadas
        if (lexema == "include") return 1030;
        if (lexema == "lib") return 1031;
        if (lexema == "endlib") return 1032;
        if (lexema == "class") return 1033;
        if (lexema == "endclass") return 1034;
        if (lexema == "def") return 1051;
        if (lexema == "of") return 1053;
        if (lexema == "const") return 1052;
        if (lexema == "function") return 1057;
        if (lexema == "endfunction") return 1058;
        if (lexema == "int") return 1035;
        if (lexema == "float") return 1036;
        if (lexema == "char") return 1037;
        if (lexema == "string") return 1038;
        if (lexema == "bool") return 1039;
        if (lexema == "void") return 1040;
        if (lexema == "return") return 1059;
        if (lexema == "write") return 1050;
        if (lexema == "read") return 1049;
        if (lexema == "if") return 1041;
        if (lexema == "endif") return 1044;
        if (lexema == "elseif") return 1042;
        if (lexema == "else") return 1043;
        if (lexema == "while") return 1047;
        if (lexema == "endwhile") return 1048;
        if (lexema == "do") return 1045;
        if (lexema == "dowhile") return 1054;
        if (lexema == "enddo") return 1046;
        if (lexema == "for") return 1055;
        if (lexema == "to") return 1029;
        if (lexema == "endfor") return 1056;

        // 3. Verificamos símbolos y operadores
        if (lexema == ".") return 1001;
        if (lexema == ",") return 1003;
        if (lexema == "=") return 1004;
        if (lexema == ";") return 1002;
        if (lexema == "(") return 1005;
        if (lexema == ")") return 1006;
        if (lexema == "++") return 1007;
        if (lexema == "--") return 1008;
        if (lexema == "||") return 1009;
        if (lexema == "&&") return 1010;
        if (lexema == "!") return 1011;
        if (lexema == "+") return 1012;
        if (lexema == "-") return 1013;
        if (lexema == "==") return 1014;
        if (lexema == "!=") return 1015;
        if (lexema == "<") return 1016;
        if (lexema == "<=") return 1017;
        if (lexema == ">") return 1018;
        if (lexema == ">=") return 1019;
        if (lexema == "*") return 1020;
        if (lexema == "/") return 1021;
        if (lexema == "%") return 1022;
        if (lexema == "**") return 1023;

        
        return 1000;
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

            if(X == Y && W >= Z)
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




