#include "WS2812.hpp"

WS2812::WS2812(int ledcnt)
{
  led_cnt = ledcnt;
  strip = new Adafruit_NeoPixel(led_cnt, D1, NEO_GRB + NEO_KHZ800);
}
void WS2812::ws2812_init()
{
  strip->begin();
  //strip.show();
  strip->setBrightness(BRIGHTNESS);
}

void WS2812::ws2812_array_set(int data[])
{
  for (int j = 1; j <= data[0]; j++)
  {
    strip->setPixelColor(data[j], white); //  Set pixel's color (in RAM)
  }
}

void WS2812::regulate_brightness() {
      // LED: 1-15
  // Sensor: 0-120
  //0.083*value+5
  // new_brightness = (13/120)*x+5=0.1083*x+2
  // new_brightness = (14/120)*x+1=0.1166*x+1
  int value = analogRead(0);
  int new_brightness = (double) 0.1166*value+1;
  strip->setBrightness(new_brightness);

}

void WS2812::prefix()
{
  ws2812_array_set(PREFIX_IT_IS);
}

void WS2812::min(int m)
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
    ws2812_array_set(MINUTE_FIVE);
    ws2812_array_set(INFIX_AFTER);
  }
  if (m >= 10 && m < 15)
  {
    ws2812_array_set(MINUTE_TEN);
    ws2812_array_set(INFIX_AFTER);
  }
  if (m >= 15 && m < 20)
  {
    ws2812_array_set(MINUTE_QUARTER);
    ws2812_array_set(INFIX_AFTER);
  }
  if (m >= 20 && m < 25)
  {
    ws2812_array_set(MINUTE_TWENTY);
    ws2812_array_set(INFIX_AFTER);
  }
  if (m >= 25 && m < 30)
  {
    ws2812_array_set(MINUTE_FIVE);
    ws2812_array_set(INFIX_BEFORE);
    ws2812_array_set(MINUTE_HALF);
  }

  if (m >= 30 && m < 35)
  {
    ws2812_array_set(MINUTE_HALF);
  }
  if (m >= 35 && m < 40)
  {
    ws2812_array_set(MINUTE_FIVE);
    ws2812_array_set(INFIX_AFTER);
    ws2812_array_set(MINUTE_HALF);
  }
  if (m >= 40 && m < 45)
  {
    ws2812_array_set(MINUTE_TWENTY);
    ws2812_array_set(INFIX_BEFORE);
  }
  if (m >= 45 && m < 50)
  {
    ws2812_array_set(MINUTE_QUARTER);
    ws2812_array_set(INFIX_BEFORE);
  }
  if (m >= 50 && m < 55)
  {
    ws2812_array_set(MINUTE_TEN);
    ws2812_array_set(INFIX_BEFORE);
  }
  if (m >= 55 && m < 60)
  {
    ws2812_array_set(MINUTE_FIVE);
    ws2812_array_set(INFIX_BEFORE);
  }
}

void WS2812::hour(int h)
{
  if (h == 24 || h == 12 || h == 0)
  {
    ws2812_array_set(HOUR_TWELVE);
  }
  if (h == 1 || h == 13)
  {
    ws2812_array_set(HOUR_ONE);
  }
  if (h == 2 || h == 14)
  {
    ws2812_array_set(HOUR_TWO);
  }
  if (h == 3 || h == 15)
  {
    ws2812_array_set(HOUR_THREE);
  }
  if (h == 4 || h == 16)
  {
    ws2812_array_set(HOUR_FOUR);
  }
  if (h == 5 || h == 17)
  {
    ws2812_array_set(HOUR_FIVE);
  }
  if (h == 6 || h == 18)
  {
    ws2812_array_set(HOUR_SIX);
  }
  if (h == 7 || h == 19)
  {
    ws2812_array_set(HOUR_SEVEN);
  }
  if (h == 8 || h == 20)
  {
    ws2812_array_set(HOUR_EIGHT);
  }
  if (h == 9 || h == 21)
  {
    ws2812_array_set(HOUR_NINE);
  }
  if (h == 10 || h == 22)
  {
    ws2812_array_set(HOUR_TEN);
  }
  if (h == 11 || h == 23)
  {
    ws2812_array_set(HOUR_ELEVEN);
  }
}

void WS2812::ws2812_refresh(int s, int m, int h)
{
  strip->clear();
  prefix();
  if (m >= 25)
  {
    h++;
  }
  min(m);
  hour(h);
  strip->show();
}


uint32_t WS2812::Wheel(byte WheelPos) {
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


void WS2812::rainbow(uint8_t wait) {
  uint16_t j;

  for(j=0; j<256; j++) {
    //for(i=0; i<strip.numPixels(); i++) 
    for (int i = 1; i <= preview_word[0]; i++){
      strip->setPixelColor(preview_word[i], Wheel((i*15+j) & 255));
    }
    strip->show();
    delay(wait);
  }
}

void WS2812::dimm(uint8_t wait) {
  for (int i=0; i<4;i++)
  {
    for (int j = 1; j <= 40; j++)
    {
      ws2812_array_set(preview_word);
      strip->setBrightness(j);
      strip->show();
      delay(20);
    }
    for (int j = 40; j > 0; j--)
    {
      ws2812_array_set(preview_word);
      strip->setBrightness(j);
      strip->show();
      delay(20);
    }
  }
}

void WS2812::preview()
{
  rainbow(30);

  strip->clear();
  strip->show();
  strip->setBrightness(BRIGHTNESS);
}

void WS2812::all_off() {
  strip->fill(off, 0, led_cnt);
  strip->show();
}