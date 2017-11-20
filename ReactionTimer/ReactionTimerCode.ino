
// some constants for readability, using booleans to save memory
boolean ON  = 1 ;
boolean OFF = 0 ;
 
// Arduino pin setup - there are 3 pins used for LEDs,
// 1 for push-button. The pin at index success_led is
// the one the user should try to hit.
byte led_pins[3]       = {8,9,10} ;
byte button_pin        =    2 ;
byte success_led       =    1 ;  // refers to pin 9
 
// time_change is the number of milliseconds to add upon
// failure or subtract upon success.
// colorswitch_delay is the amount of time that the LED stays
// on. This value has time_change added to/subtracted from it.
// So that the user knows which LED was lit up when they hit
// the button, push_pause defines the number of milliseconds
// that the LED will stay on after the button is pressed.
unsigned int time_change       =   50 ;
unsigned int colorswitch_delay =  500 ;
unsigned int push_pause        = 2000 ;
 
void setup()
{
 
    for (int i=0 ; i < 3 ; i++)
    {
      pinMode( led_pins[i], OUTPUT ) ;
    }
    
    pinMode( button_pin, INPUT ) ;
}
 
void loop()
{
    // Makes sure that the button "flag" is set to "off" 
    boolean button_state = OFF ;
 
    //Turns on first LED (green)
    digitalWrite( led_pins[0], HIGH ) ;
        
    // Checks to see if the button has been pressed while the first green LED is on 
    button_state = digitalRead( button_pin ) ;
 
    // If the button has been pressed, stop cycling through the LEDs momentarily and decrease the game speed
    if ( button_state == ON )
         {
            delay( push_pause ) ;   //Stop cycling momentarily for the length of time that was specified for "push_pause"
 
            // set the button state back to off
            button_state = OFF ;
            
            //Decrease the game speed by adding "time_change" to "colorswitch_delay" to make "colorswitch_delay" larger
            colorswitch_delay = colorswitch_delay + time_change ;
           }

      //The delay between each LED lighting up
      delay( colorswitch_delay ) ;
      
      //Turn off the first green LED and start cycling again
      digitalWrite( led_pins[0], LOW ) ;
            
   
      //Turn on second LED (red)
      digitalWrite( led_pins[1], HIGH ) ;
        
      // Checks to see if the button has been pressed while the red LED is on 
      button_state = digitalRead( button_pin ) ;
 
      //if the button has been pressed, stop cycling through the LEDs momentarily and increase the game speed
      if ( button_state == ON )
         {
            delay( push_pause ) ;   //Stop cycling momentarily for the length of time that was specified for "push_pause"
 
            // set the button state back to off
            button_state = OFF ;
            
            //Increase the game speed by subtracting "time_change" from "colorswitch_delay" to make "colorswitch_delay" smaller
            colorswitch_delay = colorswitch_delay - time_change ;
          }
           
      //The delay between each LED lighting up
      delay( colorswitch_delay ) ;

      //Turn off the red LED and start cycling again
      digitalWrite( led_pins[1], LOW ) ;


      //Turns on third LED (green)
      digitalWrite( led_pins[2], HIGH ) ;
        
      // Checks to see if the button has been pressed while the thrid green LED is on 
      button_state = digitalRead( button_pin ) ;
 
      // If the button has been pressed, stop cycling through the LEDs momentarily and decrease the game speed
      if ( button_state == ON )
         {
            delay( push_pause ) ;   //Stop cycling momentarily for the length of time that was specified for "push_pause"
 
            // set the button state back to off
            button_state = OFF ;
            
            //Decrease the game speed by adding "time_change" to "colorswitch_delay" to make "colorswitch_delay" larger
            colorswitch_delay = colorswitch_delay + time_change ;
           }

      //The delay between each LED lighting up
      delay( colorswitch_delay ) ;

      //Turn off the third green LED and start cycling again
      digitalWrite( led_pins[2], LOW ) ;              
}
