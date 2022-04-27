#include <Servo.h>


const int BUTTON_PIN = 7; 
const int SERVO_PIN  = 9; 

Servo servo; 


int angle = 0;          
int lastButtonState;    
int currentButtonState; 

void setup() {
  Serial.begin(9600);                
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  servo.attach(SERVO_PIN);           

  servo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      
  currentButtonState = digitalRead(BUTTON_PIN); 

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    
    angle = random(0, 180);
   
    
    servo.write(angle);
    delay (1000);
    
  }     
    else { 
    angle = (80);
    servo.write(angle);
    }
  }
  
