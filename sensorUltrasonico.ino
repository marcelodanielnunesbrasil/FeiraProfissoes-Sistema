#include <NewPing.h>

#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200
#define beep 2

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
  Serial.begin(115200);  
  pinMode(beep, OUTPUT);
}

void loop(){
  delay(50);
  Serial.print("Ping: ");
  int dist = sonar.ping();
  int distancia = sonar.convert_cm(dist);
  Serial.print(distancia);
  Serial.println("cm");

  if(distancia < 10){
    digitalWrite(beep, HIGH); 
  }else if(distancia < 20){
    digitalWrite(beep, HIGH); 
    delay(20);
    digitalWrite(beep, LOW);
    delay(20);
  }else if(distancia < 40){
    digitalWrite(beep, HIGH); 
    delay(50);
    digitalWrite(beep, LOW);
    delay(50);
  }else if(distancia < 60){
    digitalWrite(beep, HIGH); 
    delay(100);
    digitalWrite(beep, LOW);
    delay(100);
  }else{
    digitalWrite(beep, LOW); 
  }
}

