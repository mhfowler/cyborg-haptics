#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

int ledPin = 2;

void setup() {
  Serial.begin(115200);
  // initialize digital pin as an output.
//  Serial.println("++ setup");
//  pinMode(ledPin, OUTPUT);

    delay(12000);
//    Serial.println("++ after 12000 delay");

  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.println("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  bno.setExtCrystalUse(true);
  Serial.println("++ IMU is connected");

    
}
 
// the loop function runs over and over again forever
void loop() {
//  Serial.println("++ red");
//  Bean.setLed(255, 0, 0);
//  Bean.sleep(1000);
  
//  Serial.println("++ blue");
//  Bean.setLed(0, 0, 255);
//  Bean.sleep(1000);

  // update LEDS
//  Serial.println("++ LED + green");
//   Bean.setLed(0, 255, 0);              
//  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(200);              // wait for a second
//  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
//  delay(200);              // wait for a second

 /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  
  /* Display the floating point data */
  int x = (int) event.orientation.x;
  int y = (int) event.orientation.y;
  int z = (int) event.orientation.z;
  String s = String(x) + ',' + String(y) + ',' + String(z);
  Serial.println(s);

}


