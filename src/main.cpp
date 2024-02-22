/*=================================================================================
--Includes
=================================================================================*/
#include <Arduino.h>
#include <led/WS2812.hpp>
#include <time/SwissTime.hpp>

/*=================================================================================
--Variablen
=================================================================================*/
const int sleeptime = 22; 
const int wakeuptime = 5;

const double wakeupdelay_ms = 60*1000; // ms

// Time instance
SwissTime swissTime(wakeupdelay_ms);
// Led-Strip Instance
WS2812 ws2812(114);



/*=================================================================================
--Setup
=================================================================================*/
void setup()
{
  // Serial Init
  Serial.begin(9600);

  // Init WS2812
  ws2812.initWS2812();
  ws2812.advertisingAnimation();
}

/*=================================================================================
--Main
=================================================================================*/
void loop()
{
  /*---------------------------------------------------------------------------
  -- Update Time
  ---------------------------------------------------------------------------*/
  bool error = swissTime.getTime();
  if (error == false)
  {
    /*---------------------------------------------------------------------------
    -- Turn qlocktwo off by night
    ---------------------------------------------------------------------------*/
    if ((swissTime.h >= sleeptime) || (swissTime.h < wakeuptime))
    {
      ws2812.allOff();
      if(swissTime.h >= wakeuptime-1) {
        // check time more often one showHour before wakeup
        delay(wakeupdelay_ms);
      }
      else {
        //delay(wakeupdelay_ms*60);
        delay(wakeupdelay_ms);
      }
    }
    else
    {
      ws2812.showTime(swissTime.s, swissTime.m, swissTime.h);
      // If await next Miniute Boundary is bigger zero, show Time again.
      //if(swissTime.awaitNextMinuteBoundary()) {
      //  ws2812.showTime(swissTime.s, swissTime.m, swissTime.h);
      //}
      (void) swissTime.awaitNextMinuteBoundary();
      //delay(wakeupdelay_ms);
    } 
  } else {
    ws2812.showNoInternet();
  }
}