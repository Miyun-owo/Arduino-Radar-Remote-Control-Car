//Bluetooth
#include<SoftwareSerial.h>
#include<Wire.h>

SoftwareSerial I2CBT(1,0);

//Ultrasonic Distance Sensor
const int trig=5;
const int echo=6;
int lecEcho;
int cm;

void setup(){
  
  //Ultrasonic Distance Sensor
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  //Bluetooth
  Serial.begin(9600);
  I2CBT.begin(9600);
  /*
   return 
   */
}

void loop(){

  //Ultrasonic Distance Sensor
  digitalWrite(trig,HIGH);
  delayMicroseconds(0.3);
  digitalWrite(trig,LOW);
  lecEcho = pulseIn(echo,HIGH);
  cm = lecEcho/58;
  Serial.print("d=");
  Serial.println(cm);

  //Bluetooth
  byte cmmd[20];
  int insize;
  while(1){
    //read message from buletooth
    if((insize=I2CBTavailable()))>0){
      Serial.print("input size = ");
      Serial.println(insize);
      for(int i=0;i<insize;i++){
        Serial.print(cmmd[i] = char(I2CBT.read()));
        Serial.print('\n');
      }
    }
    switch(cmmd[0]){
      //what it does rely on what you write here
      case ??:
        //...
        break;
    }
  }
}
