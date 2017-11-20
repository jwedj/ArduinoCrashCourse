
//RGB LED "mood light" controlled by a photoresistor

//Make an RGB LED display  different colors depending on how much ligth there is!

//An RGB LED is actually three LEDs (red, green, and blue) in
//one package. When you run them at different brightnesses,
//the red, green and blue mix to form new colors.




// First we'll define the pins by name to make the sketch
// easier to follow.

// Here's a trick: putting the word "const" in front of a
// variable indicates that this is a "constant" value that will
// never change. (You don't have to do this, but if you do, the
// Arduino will give you a friendly warning if you accidentally
// try to change the value, so it's considered good form.)

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int photocellPin = A0;


void setup()
{
// Here we'll configure the Arduino pins we're using to
// drive the LED to be outputs:

pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);
}


void loop()
{
  //First, use the photoresistor to give the Arduino the numerical value for how much light there is
  //We simply take a reading from pin A0 to measure the light intensity. This value will be in the range of something like 0 to 700.
  int reading = analogRead(photocellPin);

  
  //Next, depending on the amount of light, change the color of the LED.
  //This is done with a bunch of if-else statements.  
  //Basically, if-else statements give the Arduino a list of "scenarios" that can happen, along with instructions for each one
  //If-else statements will typically start with the first statement being "if".  All other statements after are written as "else if"
  //Just in case we get any random values not covered by the if-else statements, the last statement just reads "else"
  //Think of the last statement as saying 'if anything else that I didn't tell you about should happen, follow these instructions'

  //Each set of instructions in the if-else statements is turning on a certain combination of the led colors.  We are just using the digitalWrite 
  //function like we did for the blink funtion we did earlier.
  
  if (reading > 650)     //If the light reading is greater than 650
    {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);  //Green LED on              //TOGETHER TO MAKE CYAN
      digitalWrite(BLUE_PIN, HIGH);   //Blue LED on
    }
  else if (reading > 600)          //If the light reading is greater than 600
    {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);   //Green LED on for GREEN ONLY
      digitalWrite(BLUE_PIN, LOW);
    }
  else if (reading > 550)         //If the light reading is greater than 550
    {
      digitalWrite(RED_PIN, HIGH);  //Red LED on                  //TOGETHER MAKE YELLOW
      digitalWrite(GREEN_PIN, HIGH);  //Green LED on
      digitalWrite(BLUE_PIN, LOW);
    }
  else if (reading > 500)     //If the light reading is greater than 500
    {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);  //Green LED on to go back to GREEN ONLY
      digitalWrite(BLUE_PIN, LOW);
    }
  else if (reading > 450)     //If the light reading is greater than 450
    {
      digitalWrite(RED_PIN, HIGH);    //Red LED on for RED ONLY
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
    }
  else if (reading > 400)     //If the light reading is greater than 400
    {
      digitalWrite(RED_PIN, HIGH);    //Red LED on              //TOGETHER MAKE MAGENTA
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);   //Blue LED on
    }
  else if (reading > 350)     //If the light reading is greater than 350
    {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);   //Blue LED on for BLUE ONLY
    }
  else                        //If the light reading is anything that doesn't fall into the ranges detailed above
    {
      digitalWrite(RED_PIN, HIGH);    //Red LED on        //All together make white
      digitalWrite(GREEN_PIN, HIGH);  //Green LED on
      digitalWrite(BLUE_PIN, HIGH);   //Blue LED on
    }
}




