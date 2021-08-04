#include <Arduino.h>
#include "kalman.h"

KalmanFilter filter(0.5, 0.1, 0.1); // Measurment Uncertainty, Error Uncertainty, Process Variance

class kalman
{
  public:
  double filteredData;
  double sensorData;
};

void setup () {}

void loop () 
{
  kalman kal;
  kal.filteredData = filter.updateEstimate(kal.sensorData);
  
  Serail.print("Filtered Data: ");
  Serial.print(kal.filteredData);
  Serial.println();
}
