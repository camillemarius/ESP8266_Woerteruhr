#ifndef WORDMANAGER_HPP
#define WORDMANAGER_HPP

#include "Arduino.h"

class wordManager
{
     /*  -                  0- 5
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
    public:
        wordManager();

    private:
        int array[6]         = {113, 94, 74, 73, 54, 53};

};

#endif
