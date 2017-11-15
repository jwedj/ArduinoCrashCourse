// Tape the accelerometer to a glove or directly to the back of your hand. 
//
// Circuit:
// Vin -> 5V
// Gnd -> Gnd
// Z -> A0

int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor


// Include the servo library to add servo-control functions:

#include <Servo.h> 

// Create a servo "object", called servo1. Each servo object
// controls one servo (you can have a maximum of 12):

Servo servo1;


void setup() 
{ 

  // Enable control of a servo on pin 9:

  servo1.attach(9);
} 


void loop() 
{ 
  int sensorposition;    // Input value from the analog pin.
  int servoposition;   // Output value to the servo.

  // Read the position of the accelerometer:

  sensorposition = analogRead(sensorPin);

  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() that range
  // to the servo's range of 0 to 180 degrees. 

  servoposition = map(sensorposition, 400, 500, 0, 180);
  servoposition = constrain(servoposition, 0, 180);

  // Now we'll command the servo to move to that position:

  servo1.write(servoposition);

 // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); 
 
  delay(20);
} 

