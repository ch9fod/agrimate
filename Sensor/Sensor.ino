#include <SPI.h>
#include <MySensor.h>  

//#define DIGITAL_INPUT_SOIL_SENSOR 3   // Digital input did you attach your soil sensor.  
//#define INTERRUPT DIGITAL_INPUT_SOIL_SENSOR-2 // Usually the interrupt = pin -2 (on uno/nano anyway)
#define CHILD_ID 0   // Id of the sensor child
unsigned long SLEEP_TIME = 30000; // Sleep time between reads (in milliseconds)
MySensor gw;
MyMessage msg(CHILD_ID, V_VAR1);
int cuenta = 0;

void setup()  
{ 
  gw.begin();

  // Send the sketch version information to the gateway and Controller
  gw.sendSketchInfo("Sensor1", "1.0");
  // sets the soil sensor digital pin as input
  //pinMode(DIGITAL_INPUT_SOIL_SENSOR, INPUT);      
  // Register all sensors to gw (they will be created as child devices)  
  gw.present(CHILD_ID, S_CUSTOM);
}
 
void loop()     
{ 
  if (cuenta == 255)
    cuenta = 0;
  else
    cuenta++;  
  gw.send(msg.set(cuenta));  // Send the inverse to gw as tripped should be when no water in soil
  // Power down the radio and arduino until digital input changes.
  //gw.sleep(INTERRUPT,CHANGE);
  gw.sleep(SLEEP_TIME);
}


