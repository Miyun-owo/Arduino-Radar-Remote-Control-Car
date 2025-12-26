int dis=0; //from dis_detect

//LED
int r=3;
int y=4;
int g=5;

//Switch
int sIn=7;
int sOut=6;

//Joystick

//OLED

void setup(){

  //LED
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);

  //Switch
  Serial.begin(115200);
  pinMode(sIn,INPUT);
  pinMode(sOut,OUTPUT);

  //Joystick

  //OLED
  
}

void loop(){

 //LED
  if(dis>=0 && dis<10){
    digitalWrite(r,HIGH);
    digitalWrite(y,LOW);
    digitalWrite(g,LOW);
  }
  else if(dis>=10 && dis<=30){
    digitalWrite(r,LOW);
    digitalWrite(y,HIGH);
    digitalWrite(g,LOW);
  }
  else{
    digitalWrite(r,LOW);
    digitalWrite(y,LOW);
    digitalWrite(g,HIGH);
  }

  //Switch
  int switchStatus = digitalRead(sIn);
  digitalWrite(sOut,switchStatus);
  Serial.println(switchStatus);
  /*
   TODO:
   if(sIn!=HIGH){
   stop transfer "dis" info from bluetooth
   }
   */

   //Joystick

   //OLED
  
}
