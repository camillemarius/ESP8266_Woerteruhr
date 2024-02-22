#include "WS2812.hpp"

/*============================================================================
== PUBLIC
============================================================================*/
void WS2812::showTime(int s, int m, int h) {
  
  strip->clear();
  deleteActualPixelColorArrayMap();
  
  brightness = lightMap.mapIlluminanceToLEDBrightness();

  // Es ist
  prefix();
  // Nach Ablauf der ersten halben Stunde nennt man die nächste volle Stunde
  if (m >= 25)
  {
    h++;
  }
  showMin(m);
  showHour(h);

  //strip->show();
  dimNewlyTurnedOn(brightness);
  //dimOn(brightness);
  copyPrevPixelColorArrayMap();
}

/*-----------------------------------------
-- ON/OFF
-----------------------------------------*/
void WS2812::allOff() {
  strip->clear();
  strip->fill(off, 0, led_cnt);
  strip->show();
}

void WS2812::dimOn(int finalBrightness) {
  //dimOff(finalBrightness);
  for(int brightness = lightMap.getminLedBrightness(); brightness < finalBrightness; brightness++) {
    strip->setBrightness(brightness);
    strip->show();
    delay(10);
  }
}

void WS2812::dimNewlyTurnedOn(int finalBrightness) {
  for(int brightness = 5; brightness <= finalBrightness; brightness++) {
    for(int i = 0; i < led_cnt; i++) {
      if (prevPixelColors[i] != actualPixelColors[i]) {
          if(actualPixelColors[i]==true) {
            //Serial.print("Led to dim: ");
            //Serial.println(i);
            setBrightnessFor(i, brightness);
          }
      }
    }
    strip->show();
    delayMicroseconds(10);
  }
}

void WS2812::setBrightnessFor(int ledIndex, uint8_t brightness) {
    // Set the adjusted color for the LED
    strip->setPixelColor(ledIndex, strip->Color(brightness, brightness, brightness));
}

void WS2812::dimOff(int actuallBrighntess) {
  for(int brightness = actuallBrighntess; brightness <= 3; brightness--) {
    strip->setBrightness(brightness);
    strip->show();
    delay(25);
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
  int MIN1_ONE[2]           = {1,0};
  int MIN1_TWO[3]           = {2,0,1};
  int MIN1_THREE[4]         = {3,0,1,2};
  int MIN1_FOUR[5]          = {4,0,1,2,3};
  
  int min1Cnt = m % 5;
  if(min1Cnt == 0) {
    strip->fill(off, 0, 3);
  }
  else if(min1Cnt == 1) {
    setPixelColorArrayMap(MIN1_ONE);
  }
  else if(min1Cnt == 2) {
    setPixelColorArrayMap(MIN1_TWO);
  }
  else if(min1Cnt == 3) {
    setPixelColorArrayMap(MIN1_THREE);
  }
  else if(min1Cnt == 4) {
    setPixelColorArrayMap(MIN1_FOUR);
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
      allOff();
      setPixelColorArrayMap(NO_INTERNET);
      strip->show();
}

/*-----------------------------------------
-- EFFECTS
-----------------------------------------*/
void WS2812::advertisingAnimation()
{
  rainbowWheel(30);

  strip->clear();
  strip->show();
  //strip->setBrightness(lightMap.mapIlluminanceToLEDBrightness());
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
  strip = new Adafruit_NeoPixel(ledcnt, D1, NEO_GRB + NEO_KHZ800);
  prevPixelColors = new bool[ledcnt];
  actualPixelColors = new bool[ledcnt];
}

void WS2812::initWS2812()
{
  strip->begin();

  brightness = lightMap.mapIlluminanceToLEDBrightness();
  strip->setBrightness(brightness);
  
}

void WS2812::setPixelColorArrayMap(int data[]) {
  for (int a = 1; a <= data[0]; a++)
  {
    strip->setPixelColor(data[a], strip->Color(brightness,brightness,brightness)); //  Set pixel's color (in RAM)
    actualPixelColors[data[a]] = true; //  Set pixel's color (in RAM)
  }
}

void WS2812::copyPrevPixelColorArrayMap() {
  for (int b = 0; b < led_cnt; b++)
  {
    prevPixelColors[b] = actualPixelColors[b]; //  Set pixel's color (in RAM)
    //Serial.println(prevPixelColors[j]);
    //Serial.println(", ");
  }
}

void WS2812::deleteActualPixelColorArrayMap() {
  for (int c = 0; c < led_cnt; c++)
  {
    actualPixelColors[c] = false;//  Set pixel's color (in RAM)
  }
}


