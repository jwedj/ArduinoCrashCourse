// Map analog values from IR range sensor to a tone on a buzzer


int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor
int buzzerPin = 10;

void setup() {
  pinMode(buzzerPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); 
  tone(buzzerPin, sensorValue*10);  
  delay(50); 
  //noTone(buzzerPin);     
}
