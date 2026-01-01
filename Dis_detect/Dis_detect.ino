//Bluetooth
#include<SoftwareSerial.h>
#include<Wire.h>

SoftwareSerial I2CBT(1,0);

//Ultrasonic Distance Sensor
const int trig=5;
const int echo=6;

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

int get_distance()
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(0.3);
  digitalWrite(trig,LOW);
  return pulseIn(echo,HIGH)/58;
}

bool catch_message(int &v1, int &v2)
{
  if (!I2CBT.available()) return false;

  String data = I2CBT.readStringUntil('\n'); // 讀到換行
  int commaIndex = data.indexOf(',');

  if (commaIndex == -1) return false; // 沒逗號 = 格式錯誤

  v1 = data.substring(0, commaIndex).toInt();
  v2 = data.substring(commaIndex + 1).toInt();

  // 限制在 0~128
  v1 = constrain(v1, 0, 128);
  v2 = constrain(v2, 0, 128);

  return true;
}


void loop()
{
  analogWrite(5, 255);
  analogWrite(6, 255);

  //Bluetooth
  byte cmmd[20];
  int insize;
  while(1){
    //read message from buletooth
   
    switch(cmmd[0]){
      //what it does rely on what you write here
    }
  }
}
