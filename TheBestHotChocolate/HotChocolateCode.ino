

//The Best Hot Chocolate!!! (or any other hot beverage!!!)

//Declare all variables used in code
int RED_PIN= 9;    //The red part of the led is controlled by pin 9 on the Arduino
int GREEN_PIN= 10; //The green part of the led is controlled by pin 10 on the Arduino
int BLUE_PIN= 11;  //The blue part of the led is controlled by pin 11 of the Arduino

float voltage, degreesC, degreesF;    //Declare varuables for voltage, degrees C and degrees F.  The TMP36 sensor actually collects voltage values that we will calculate temperature from

const int temperaturePin = A0;      //The TMP36 temperature sensor is controlled by pin A0 on the Arduino


//The getVoltage function will be used later in our program to get the voltage values from the temperature sensor
float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}


void setup()
{
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps.  We want the serial port so that we can see the actual numerical values of the temperature in the serial monitor

   // Here we'll configure the Arduino pins we're using to
   // drive the LED to be outputs:

   pinMode(RED_PIN, OUTPUT);
   pinMode(GREEN_PIN, OUTPUT);
   pinMode(BLUE_PIN, OUTPUT);
}


void loop()
{
  voltage = getVoltage(temperaturePin);   //Get the voltage from the temperature sensor.  This is where we are using the function we wrote at the start of the program!!!
  degreesC = (voltage - 0.5) * 100.0;     //Convert the voltage to the degrees C temperature value
  degreesF = degreesC * (9.0/5.0) + 32.0;   //Convert the degrees C temperature to a degrees F temperature.  We will use the F temperature for the rest of the program.

  Serial.println(degreesF);   //Print the degrees F temperature in the serial monitor

  if(degreesF < 100)    //Too cold
  {
    analogWrite(RED_PIN, LOW);      //Red is off
    analogWrite(GREEN_PIN, LOW);    //Green is off
    analogWrite(BLUE_PIN, HIGH);    //Blue is on because your drink is too cold!
  }
  
  if(degreesF >= 100 && degreesF <= 140)  //This is your ideal temperature range, according to our Google research!!
  {
    analogWrite(RED_PIN, LOW);      //Red is off
    analogWrite(GREEN_PIN, HIGH);   //Green is on because your drink is the perfect temperature!!!
    analogWrite(BLUE_PIN, LOW);    //Blue is off
  }

  if(degreesF > 140)    //Too hot
  {
    analogWrite(RED_PIN, HIGH);      //Red is on because your drink is too hot!!
    analogWrite(GREEN_PIN, LOW);    //Green is off
    analogWrite(BLUE_PIN, LOW);    //Blue is iff
  }
   
  delay(500);                           //wait 200 ms before sending new data
}
