#include "ALSPT19.hpp"

/*============================================================================
== PUBLIC
============================================================================*/
int ALSPT19::getIlluminance()
{
    calculateIlluminance();
    return actuall_brightness;
}

int ALSPT19::getMinIlluminance() {
  return min_illuminance;
}

int ALSPT19::getMaxIlluminance() {
  return max_illuminance;
}
/*============================================================================
== PRIVATE
============================================================================*/
ALSPT19::ALSPT19() :min_illuminance(0), max_illuminance(0), actuall_brightness(0)
{
  ;
}

void ALSPT19::calculateIlluminance()
{
  // LED Brightness: 1-15
  // Sensor: 0-120
  // 0.083*value+5
  // new_brightness = (13/120)*x+5=0.1083*x+2
  // new_brightness = (14/120)*x+1=0.1166*x+1
  int value = analogRead(0);
  actuall_brightness = static_cast<int> (0.1166*value+1);

  //set brightness Thresholds
  if(actuall_brightness<=min_illuminance) {
    min_illuminance = actuall_brightness;
  }

  if(actuall_brightness>=max_illuminance) {
    max_illuminance = actuall_brightness;
  }
}
