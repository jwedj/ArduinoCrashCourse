const int VAL_PROBE = 0; // Analog pin 0. This is the soil probe
const int MOISTURE_LEVEL = 250; // the value after the LED goes ON
 
void setup() 
{
    Serial.begin(9600);
}
 
void LedState(int state) 
{
    digitalWrite(13, state);
}
 
void loop() 
{
    //Get the moisture reading from the soil probe
    int moisture = analogRead(VAL_PROBE);

    //If the soil is dry, turn on the LED and show the user a message that he/she needs to water
    if(moisture &gt; MOISTURE_LEVEL) 
    {
        LedState(HIGH);
        Serial.print('LOW MOISTURE: Your plant needs water!!!');
    } 

    //Otherwise, keep the LED off and show the user a message that the moisture level is fine
    else   
    {
        LedState(LOW);
        Serial.print('Moisture Level: Good');
    }

    //Delay before the loop repeats
    delay(100);
}
