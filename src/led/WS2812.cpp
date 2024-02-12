#include "WS2812.hpp"

/*============================================================================
== PUBLIC
============================================================================*/
void WS2812::showTime(int s, int m, int h) {
  strip->clear();
  // Es ist
  prefix();
  // Nach Ablauf der ersten halben Stunde nennt man die nächste volle Stunde
  if (m >= 25)
  {
    h++;
  }
  showMin(m);
  showHour(h);
  dimOn(lightMap.mapIlluminanceToLEDBrightness());
  //strip->show();
}

void WS2812::adjustBrightness() {
  strip->setBrightness(lightMap.mapIlluminanceToLEDBrightness());
}

/*-----------------------------------------
-- ON/OFF
-----------------------------------------*/
void WS2812::allOff() {
  strip->fill(off, 0, led_cnt);
  strip->show();
}

void WS2812::dimOn(int finalBrightness) {
  for(int brightness = 3; brightness <= finalBrightness; brightness++) {
    strip->setBrightness(brightness);
    strip->show();
    //delay(1);
  }
}

/*-----------------------------------------
-- WORDCLOCK
-----------------------------------------*/
void WS2812::prefix()
{
  setPixelColorArrayMap(PREFIX_IT_IS);
}

void WS2812::showMin(int m)
{
  //1min Anzeige
  if (m % 5)
  {
    strip->fill(white, 0, m % 5);
  }
  else
  {
    strip->fill(off, 0, 3);
  }

  //5min Anzeige
  if (m >= 5 && m < 10)
  {
    setPixelColorArrayMap(MINUTE_FIVE);
    setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 10 && m < 15)
  {
    setPixelColorArrayMap(MINUTE_TEN);
    setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 15 && m < 20)
  {
    setPixelColorArrayMap(MINUTE_QUARTER);
    setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 20 && m < 25)
  {
    setPixelColorArrayMap(MINUTE_TWENTY);
    setPixelColorArrayMap(INFIX_AFTER);
  }
  if (m >= 25 && m < 30)
  {
    setPixelColorArrayMap(MINUTE_FIVE);
    setPixelColorArrayMap(INFIX_BEFORE);
    setPixelColorArrayMap(MINUTE_HALF);
  }

  if (m >= 30 && m < 35)
  {
    setPixelColorArrayMap(MINUTE_HALF);
  }
  if (m >= 35 && m < 40)
  {
    setPixelColorArrayMap(MINUTE_FIVE);
    setPixelColorArrayMap(INFIX_AFTER);
    setPixelColorArrayMap(MINUTE_HALF);
  }
  if (m >= 40 && m < 45)
  {
    setPixelColorArrayMap(MINUTE_TWENTY);
    setPixelColorArrayMap(INFIX_BEFORE);
  }
  if (m >= 45 && m < 50)
  {
    setPixelColorArrayMap(MINUTE_QUARTER);
    setPixelColorArrayMap(INFIX_BEFORE);
  }
  if (m >= 50 && m < 55)
  {
    setPixelColorArrayMap(MINUTE_TEN);
    setPixelColorArrayMap(INFIX_BEFORE);
  }
  if (m >= 55 && m < 60)
  {
    setPixelColorArrayMap(MINUTE_FIVE);
    setPixelColorArrayMap(INFIX_BEFORE);
  }
}

void WS2812::showHour(int h)
{
  if (h == 24 || h == 12 || h == 0)
  {
    setPixelColorArrayMap(HOUR_TWELVE);
  }
  if (h == 1 || h == 13)
  {
    setPixelColorArrayMap(HOUR_ONE);
  }
  if (h == 2 || h == 14)
  {
    setPixelColorArrayMap(HOUR_TWO);
  }
  if (h == 3 || h == 15)
  {
    setPixelColorArrayMap(HOUR_THREE);
  }
  if (h == 4 || h == 16)
  {
    setPixelColorArrayMap(HOUR_FOUR);
  }
  if (h == 5 || h == 17)
  {
    setPixelColorArrayMap(HOUR_FIVE);
  }
  if (h == 6 || h == 18)
  {
    setPixelColorArrayMap(HOUR_SIX);
  }
  if (h == 7 || h == 19)
  {
    setPixelColorArrayMap(HOUR_SEVEN);
  }
  if (h == 8 || h == 20)
  {
    setPixelColorArrayMap(HOUR_EIGHT);
  }
  if (h == 9 || h == 21)
  {
    setPixelColorArrayMap(HOUR_NINE);
  }
  if (h == 10 || h == 22)
  {
    setPixelColorArrayMap(HOUR_TEN);
  }
  if (h == 11 || h == 23)
  {
    setPixelColorArrayMap(HOUR_ELEVEN);
  }
}

void WS2812::showNoInternet(void) {
    setPixelColorArrayMap(MINUTE_FIVE);
}

/*-----------------------------------------
-- EFFECTS
-----------------------------------------*/
void WS2812::advertisingAnimation()
{
  rainbowWheel(30);

  strip->clear();
  strip->show();
  strip->setBrightness(lightMap.mapIlluminanceToLEDBrightness());
}

void WS2812::rainbowWheel(uint8_t wait) {
  uint16_t j;

  for(j=0; j<256; j++) {
    //for(i=0; i<strip.numPixels(); i++) 
    for (int i = 1; i <= preview_word[0]; i++){
      strip->setPixelColor(preview_word[i], colourWheel((i*15+j) & 255));
    }
    strip->show();
    delay(wait);
  }
}

uint32_t WS2812::colourWheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


/*============================================================================
== PRIVATE
============================================================================*/
WS2812::WS2812(int ledcnt)
{
  led_cnt = ledcnt;
  strip = new Adafruit_NeoPixel(led_cnt, D1, NEO_GRB + NEO_KHZ800);
}

void WS2812::initWS2812()
{
  strip->begin();
  //strip.show();
  strip->setBrightness(lightMap.mapIlluminanceToLEDBrightness());
}

void WS2812::setPixelColorArrayMap(int data[])
{
  for (int j = 1; j <= data[0]; j++)
  {
    strip->setPixelColor(data[j], white); //  Set pixel's color (in RAM)
  }
}
