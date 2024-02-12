#include "LightMapping.hpp"

/*============================================================================
== PUBLIC
============================================================================*/
int LightMapping::mapIlluminanceToLEDBrightness()
{
  // LED_BRIGHNESS:     1-15
  // ILLUMINANCE:       X
  // MIN_ILLUMINANCE:   1
  // MAX_ILLUMINANCE:   15
  // ADC_VALUE:       0-120
  // adc_value = (ADC_VALUE/(MAX_ILLUMINANCE-MIN_ILLUMINANCE))*alspt19.getIlluminance() + 1

  // Define constants
  const uint16_t MIN_ILLUMINANCE = alspt19.getMinIlluminance();   // Minimum illuminance
  const uint16_t MAX_ILLUMINANCE = alspt19.getMaxIlluminance();   // Maximum illuminance
  const uint16_t MIN_ADC_THRESHOLD = 0;                           // ADC maximum value
  const uint16_t MAX_ADC_THRESHOLD = 1023;                        // ADC maximum value

  // Apply a logarithmic transformation to map illuminance to brightness
  float brightnessFloat = map(alspt19.getIlluminance(), MIN_ADC_THRESHOLD, MAX_ADC_THRESHOLD, MIN_ILLUMINANCE, MAX_ILLUMINANCE);
  //float brightnessFloat = log(alspt19.getIlluminance() - MIN_ILLUMINANCE + 1) / log(MAX_ILLUMINANCE - MIN_ILLUMINANCE + 1) * ADC_THRESHOLD;
  
  // Convert the floating-point brightness value to an integer
  uint16_t adc_value = static_cast<uint16_t>(brightnessFloat);

  // Ensure the ADC value is within the valid range
  adc_value = min(adc_value, MAX_ADC_THRESHOLD);
  adc_value = max(adc_value, MIN_ADC_THRESHOLD);

  return alspt19.getIlluminance();
}
/*============================================================================
== PRIVATE
============================================================================*/
LightMapping::LightMapping()
{
  ;
}

