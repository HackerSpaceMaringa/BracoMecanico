#include <Servo.h> 
 
Servo myservo[3];  // create servo object to control a servo 
int lastAng[3];                // a maximum of eight servo objects can be created 
int pos = 0;    // variab le to store the servo position 


void setup() 
{ 
  Serial.begin(9600);
  myservo[0].attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo[1].attach(10);
  myservo[2].attach(11);
} 
 
 
void loop() 
{ 
                
  
  if (Serial.available() > 2) {
                // read the incoming byte:
                int angulo[3];
                for(int i=0;i<3;i++){
                 
                  angulo[i] = Serial.parseInt();
                  //myservo[i].write(angulo[i]);
                                  
                  
                }
                
                
                //Serial.println(myservo[i]);
                for(int i=0;i<3;i++){
                 
                  for (int j = myservo[i].read(); j < angulo[i]; j++){
                    myservo[i].write(j);
                  
                    //lastAng[i] = j;
                    delay(30);
                  }
                  if (myservo[i].read() > angulo[i] ){
                    for (int j = myservo[i].read(); j > angulo[i]; j--){
                      myservo[i].write(j);
                  
                 
                    //lastAng[i] = j;
                    delay(30);
                      
                    } 
                  }
                 }
                 Serial.println("sshshshs");       
  }
  
  
} 
