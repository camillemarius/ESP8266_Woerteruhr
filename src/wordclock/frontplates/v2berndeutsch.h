 #ifndef BERNDEUTSCH_H
 #define BERNDEUTSCH_H

 /*      -                  0- 5
        FÜÜF AB             5-10
        ZÄÄ AB             10-15
        VIERTU AB          15-20
        ZWENZG AB          20-25
        FÜÜF VOR HAUBI     25-30
        HAUBI              30-35
        FÜÜF AB HAUBI      35-40
        ZWENZG VOR         40-45
        VIERTU VOR         45-50
        ZÄÄ VOR            50-55
        FÜÜF VOR           55-60
*/
int PREFIX_IT_IS[7]         = {6, 103,104, 106, 107, 108, 109}; // ES IST
int INFIX_BEFORE[4]         = {3,89,90,91};                     // VOR
int INFIX_AFTER[3]          = {2,79,80};                       // NACH

int MINUTE_FIVE[4]          = {3,111,112,113};                  // FÜNF
int MINUTE_TEN[4]           = {3,100,101,102};                  // ZEHN
int MINUTE_QUARTER[7]       = {6,81,82,83,84,85,86};            // VIERTEL
int MINUTE_TWENTY[7]        = {6,92,93,94,95,96,97};            // ZWANZIG
int MINUTE_HALF[6]          = {5,70,71,72,73,74};               // HALB 

int HOUR_ONE[4]            = {3,34,35,36};                    // EINS 
int HOUR_TWO[5]            = {4,63,64,65,66};                    // ZWEI
int HOUR_THREE[4]          = {3,23,24,25};                       // DREI
int HOUR_FOUR[6]           = {5,54,55,56,57,58};                // VIER
int HOUR_FIVE[5]           = {4,37,38,39,40};                 // FÜNF
int HOUR_SIX[7]            = {6,29,30,31,32,33,34};             // SECHS
int HOUR_SEVEN[6]          = {5,26,27,28,29,30};                 // SIEBEN
int HOUR_EIGHT[6]          = {5,10,11,12,13,14};              // ACHT
int HOUR_NINE[5]           = {4,49,50,51,52};                  // NEUN
int HOUR_TEN[5]            = {4,15,16,17,18};                 // ZEHN
int HOUR_ELEVEN[5]         = {4,59,60,61,62};                  // ELF
int HOUR_TWELVE[7]         = {6,4,5,6,7,8,9};              // ZWÖLF

int preview_word[5]        = {4,19,20,21,22};                   // preview_word
int NO_INTERNET[7]        =  {6,87,88, 75, 76, 77, 78};         // no internet
#endif