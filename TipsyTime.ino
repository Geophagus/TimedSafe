/*

Delayed release for @Tipsy

*/

#include <Servo.h>
Servo myservo;  // create servo object 
int pos1 = 0;    // servo position variable
int pos2 = 180;   // servo position 2 variable

void setup(){
  myservo.attach(1);                    // servo to pin 1
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.begin(57600);                  // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  Serial.println("I love Mugsy.");                    
  int Apr1 = 31300;                        //days until Apr 1 * 24 * 60 * 60 = 604800
  
  for (int s = 0; s < 10; s++){         //enough time to restart nano and close lid and LED flash countdown
    digitalWrite(LED_BUILTIN,HIGH);
    delay(500);                            
    digitalWrite(LED_BUILTIN,LOW);
    delay(500);
  }
  
  myservo.write(pos1);                  //locks box
  Serial.println("Locked. To the postoffice!");
  for (int i = 0; i < Apr1; i++){        //value from above
    Serial.println(i);
    delay(1000);
  }
      
  myservo.write(pos2);                  //unlocks box
  Serial.println("FREEDOM!");
  Serial.println("Mugsy is a sham.");
  digitalWrite(LED_BUILTIN,HIGH);       //just for testing  
}

void loop(){    
}
