#include "AmbientLightController.hpp"

/*============================================================================
== PUBLIC
============================================================================*/
AmbientLightController::AmbientLightController() : MIN_LED_BRIGHTNESS(30), MAX_LED_BRIGHNTESS(200)
{
  ;
}

int AmbientLightController::getLedBrightness(void)
{
  // LED_BRIGHNESS:     1-15
  // ILLUMINANCE:       X
  // MIN_ILLUMINANCE:   1
  // MAX_ILLUMINANCE:   15
  // ledBrighntess:       0-120
  // ledBrighntess = (ledBrighntess/(MAX_ILLUMINANCE-MIN_ILLUMINANCE))*alspt19.getIlluminance() + 1

  // Define constants
  const uint16_t ILLUMINANCE = alspt19.getIlluminance();
  const uint16_t MIN_ILLUMINANCE = alspt19.getMinIlluminance();   // Minimum illuminance
  const uint16_t MAX_ILLUMINANCE = alspt19.getMaxIlluminance();   // Maximum illuminance

  // Apply a logarithmic transformation to map illuminance to brightness
  //float brightnessFloat = map(alspt19.getIlluminance(), MIN_LED_BRIGHTNESS, MAX_LED_BRIGHNTESS, MIN_ILLUMINANCE, MAX_ILLUMINANCE);
  float brightnessFloat = map(ILLUMINANCE, MIN_ILLUMINANCE, MAX_ILLUMINANCE, MIN_LED_BRIGHTNESS, MAX_LED_BRIGHNTESS);

  // Convert the floating-point brightness value to an integer
  uint16_t ledBrighntess = static_cast<uint16_t>(brightnessFloat);
  Serial.print("AmbientLightController::getLedBrightness::ledBrighntess: ");
  Serial.print(MIN_LED_BRIGHTNESS);
  Serial.print("-");
  Serial.print(ledBrighntess);
  Serial.print("-");
  Serial.print(MAX_LED_BRIGHNTESS);
  Serial.println("");

  return ledBrighntess;
}

int AmbientLightController::getminLedBrightness(void) {
  return MIN_LED_BRIGHTNESS;
}

int AmbientLightController::getmaxLedBrightness(void) {
  return MAX_LED_BRIGHNTESS;
}



