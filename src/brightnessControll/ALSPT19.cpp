#include "ALSPT19.hpp"

/*============================================================================
== PUBLIC
============================================================================*/
int ALSPT19::getIlluminance()
{
    calculateIlluminance();
    return actuall_illuminance;
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
ALSPT19::ALSPT19() :min_illuminance(20), max_illuminance(950), actuall_illuminance(50)
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
  actuall_illuminance = analogRead(A0);

  //set brightness Thresholds
  if(actuall_illuminance<=min_illuminance) {
    min_illuminance = actuall_illuminance;
  }

  if(actuall_illuminance>=max_illuminance) {
    max_illuminance = actuall_illuminance;
  }
  
  Serial.print("ALSPT19::calculateIlluminance::actuall_illuminance: ");
  Serial.print(min_illuminance);
  Serial.print("-");
  Serial.print(actuall_illuminance);
  Serial.print("-");
  Serial.print(max_illuminance);
  Serial.println("");
}
