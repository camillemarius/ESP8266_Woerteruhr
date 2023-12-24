#ifndef SEISLERDEUTSCH_H
#define SEISLERDEUTSCH_H
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
        int PREFIX_IT_IS[7] = {6, 113, 94, 74, 73, 54, 53}; // ES IST
        int INFIX_BEFORE[4] = {3, 31, 16, 11};              // VOR
        int INFIX_AFTER[3] = {2, 97, 110};                  // NACH

        int MINUTE_FIVE[5] = {4, 112, 95, 92, 75};            // FÜNF
        int MINUTE_TEN[4] = {3, 33, 14, 13};                  // ZEHN
        int MINUTE_QUARTER[7] = {6, 111, 96, 91, 76, 71, 56}; // VIERTEL
        int MINUTE_TWENTY[7] = {6, 55, 52, 35, 32, 15, 12};   // ZWANZIG
        int MINUTE_HALF[6] = {5, 10, 17, 30, 37, 50};         // HALB

        int HOUR_ONE[4] = {3, 6, 21, 26};                    // EINS
        int HOUR_TWO[5] = {4, 109, 98, 89, 78};              // ZWEI
        int HOUR_THREE[5] = {4, 4, 23, 24, 43};              // DREI
        int HOUR_FOUR[6] = {5, 48, 39, 28, 19, 8};           // VIER
        int HOUR_FIVE[6] = {5, 107, 100, 87, 80, 67};        // FÜNF
        int HOUR_SIX[7] = {6, 60, 47, 40, 27, 20, 7};        // SECHS
        int HOUR_SEVEN[6] = {5, 105, 102, 85, 82, 65};       // SIEBEN
        int HOUR_EIGHT[6] = {5, 106, 101, 86, 81, 66};       // ACHT
        int HOUR_NINE[6] = {5, 108, 99, 88, 79, 68};         // NEUN
        int HOUR_TEN[8] = {7, 104, 103, 84, 83, 64, 63, 44}; // ZEHN
        int HOUR_ELEVEN[5] = {4, 38, 29, 18, 9};             // ELF
        int HOUR_TWELVE[7] = {6, 62, 45, 42, 25, 22, 5};     // ZWÖLF

        int preview_word[5] = {4, 61, 46, 41, 26}; // preview_word

#endif