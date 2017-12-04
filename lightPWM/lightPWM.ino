const int LED = 9; //pin for LED
const int BUTTON = 7; //pin for button
boolean state = false;  //the state of button; true means HIGN, false means LOW
boolean old_state = false;   //the previous state of button
int ledState = 0;  //the state of led; 0 means off, 1 means on
int brightness = 128; //the initial brightness of led
unsigned long startTime = 0; // when did the pressing begin

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);  // set the button pin tu HIGH when it's not pressed
}

void loop() {
  state = digitalRead(BUTTON);  //read the status of the button

  if((state == LOW) && (old_state == HIGH)){  //check if the status of button was changed
    ledState = 1 - ledState;  //change the state of led
    startTime = millis();  //millis() will return how many milliseconds have passed since the board 
                           //has been reset
    delay(10);
  }

  if((state == LOW) && (old_state == LOW)){  //check if the button is being held
    if((ledState == 1) && (millis() - startTime > 500)){ //check if the button is held for more
                                                          //than 500 ms
      brightness ++;  //increment brightness by 1
      delay(10);
      if(brightness > 255){ //255 is the max brightness
        brightness = 0; //if brightness is over 255, then reset the brightness to 0
      }
    }
  }  
  old_state = state; //change the previous state of button 
  if(ledState == 1){
    analogWrite(LED, brightness);
  }else{
    analogWrite(LED, 0);
  }

}
