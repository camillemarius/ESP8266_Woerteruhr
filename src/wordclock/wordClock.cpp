#include "WordClock.hpp"

/*============================================================================
== PUBLIC
============================================================================*/

WordClock::WordClock(){
    ws2812eco   = new WS2812(114);
    lightMap    = new AmbientLightController();
}

void WordClock::showTime(int s, int m, int h) {
  
  ws2812eco->clearPixelColorArray();
  ws2812eco->deleteActualPixelColorArrayMap();
  
  brightness = lightMap->getLedBrightness();

  // Es ist
  //setPrefix();
  // Nach Ablauf der ersten halben Stunde nennt man die nächste volle Stunde
  if (m >= 25)
  {
    h++;
  }
  setMin(m);
  setHour(h);

  ws2812eco->dimNewlyTurnedOn(brightness);
  ws2812eco->copyPrevPixelColorArrayMap();
}

void WordClock::showAdvertisingAnimation(void) {
  ws2812eco->clearPixelColorArray();
  ws2812eco->rainbowWheel(preview_word, 30);
}

void WordClock::showNoInternet(void) {
    ws2812eco->clearPixelColorArray();
    ws2812eco->setPixelColorArrayMap(NO_INTERNET);
    ws2812eco->show();
}

void WordClock::allOff(void) {
    ws2812eco->allOff();
}

/*============================================================================
== PRIVATE
============================================================================*/

void WordClock::setPrefix(void) {
  ws2812eco->setPixelColorArrayMap(PREFIX_IT_IS);
}

void WordClock::setMin(int m) {
  //1min Anzeige
  int MIN1_ONE[2]           = {0,-1};
  int MIN1_TWO[3]           = {0,1,-1};
  int MIN1_THREE[4]         = {0,1,2,-1};
  int MIN1_FOUR[5]          = {0,1,2,3,-1};
  
  int min1Cnt = m % 5;
  if(min1Cnt == 0) {
    ws2812eco->deletePixelColorArrayFromTo(0,3);
  }
  else if(min1Cnt == 1) {
    ws2812eco->setPixelColorArrayMap(MIN1_ONE);
  }
  else if(min1Cnt == 2) {
    ws2812eco->setPixelColorArrayMap(MIN1_TWO);
  }
  else if(min1Cnt == 3) {
    ws2812eco->setPixelColorArrayMap(MIN1_THREE);
  }
  else if(min1Cnt == 4) {
    ws2812eco->setPixelColorArrayMap(MIN1_FOUR);
  }


  //5min Anzeige
  if (m >= 5 && m < 10)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_FIVE);
    ws2812eco->setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 10 && m < 15)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_TEN);
    ws2812eco->setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 15 && m < 20)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_QUARTER);
    ws2812eco->setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 20 && m < 25)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_TWENTY);
    ws2812eco->setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 25 && m < 30)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_FIVE);
    ws2812eco->setPixelColorArrayMap(INFIX_BEFORE);
    ws2812eco->setPixelColorArrayMap(MINUTE_HALF);
  }

  if (m >= 30 && m < 35)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_HALF);
  }
  if (m >= 35 && m < 40)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_FIVE);
    ws2812eco->setPixelColorArrayMap(INFIX_AFTER);
    ws2812eco->setPixelColorArrayMap(MINUTE_HALF);
  }
  if (m >= 40 && m < 45)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_TWENTY);
    ws2812eco->setPixelColorArrayMap(INFIX_BEFORE);
  }
  if (m >= 45 && m < 50)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_QUARTER);
    ws2812eco->setPixelColorArrayMap(INFIX_BEFORE);
  }
  if (m >= 50 && m < 55)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_TEN);
    ws2812eco->setPixelColorArrayMap(INFIX_BEFORE);
  }
  if (m >= 55 && m < 60)
  {
    ws2812eco->setPixelColorArrayMap(MINUTE_FIVE);
    ws2812eco->setPixelColorArrayMap(INFIX_BEFORE);
  }
}

void WordClock::setHour(int h) {
  if (h == 24 || h == 12 || h == 0)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_TWELVE);
  }
  if (h == 1 || h == 13)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_ONE);
  }
  if (h == 2 || h == 14)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_TWO);
  }
  if (h == 3 || h == 15)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_THREE);
  }
  if (h == 4 || h == 16)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_FOUR);
  }
  if (h == 5 || h == 17)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_FIVE);
  }
  if (h == 6 || h == 18)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_SIX);
  }
  if (h == 7 || h == 19)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_SEVEN);
  }
  if (h == 8 || h == 20)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_EIGHT);
  }
  if (h == 9 || h == 21)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_NINE);
  }
  if (h == 10 || h == 22)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_TEN);
  }
  if (h == 11 || h == 23)
  {
    ws2812eco->setPixelColorArrayMap(HOUR_ELEVEN);
  }
}

