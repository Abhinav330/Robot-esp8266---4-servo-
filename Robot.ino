#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "H8p4XVi5EOR8fjNQfOedRX67K9S5C4NF";              //Your Project authentication key
char ssid[] = "Abhi";                                       // Name of your network (HotSpot or Router name)
char pass[] = "hello420";   

#define d 400
#define e 100
#define light D0
int x , a;

Servo servo1;
Servo servo3;
Servo servo2;
Servo servo4;

void setup() {
  Serial.begin(115200);    
  servo1.attach(D6);             // 1 --> stand position = 127 degree
  servo3.attach(D2);             // 2 --> stand position = 75 degree
  servo2.attach(D3);             // 3 --> stand position = 124 degree
  servo4.attach(D8);             // 4 --> stand position = 67 degree
  pinMode(light,OUTPUT);
 
 servo1.write(127);   // -- degrees  --> for forward
 servo2.write(75);   // ++ degrees  --> for forward
 servo3.write(124);   // -- degrees  --> for forward
 servo4.write(67);   // ++ degrees  --> for forward

Blynk.begin(auth, ssid, pass);
 delay(2000);

    
}

BLYNK_WRITE(V0) // Button Widget writes to Virtual Pin V5 
{
  a = param.asInt() ;
  
}

BLYNK_WRITE(V1) // Button Widget writes to Virtual Pin V5 
{
  x = param.asInt() ;
  
}

void loop() 
{
  if (x == 2 && a == 0)
  {
    digitalWrite(light,LOW);
    go(); 
  }
  
 else if (x == 2 && a == 1)
  { 
    digitalWrite(light,HIGH);
    go(); 
  }
  
else if (x == 1 && a == 1) 
  {
    digitalWrite(light,HIGH);
    stand();
  }

else if (x == 1 && a == 0) 
  {
    digitalWrite(light,LOW);
    stand();
  }

else if (a == 1) 
  {
    digitalWrite(light,HIGH);
  }
  
else if (a == 0) 
  {
    digitalWrite(light,LOW);
  }  
  
Serial.println(a);
Blynk.run();
}

void go()
{

servo3.write(109);
delay(300);
servo4.write(60);  
delay(300);    
servo2.write(84);
delay(300);
servo1.write(118);
delay(300);   

servo3.write(124);
delay(100);
servo4.write(40);  
delay(200);    
servo2.write(69);
delay(100);
servo1.write(127);
delay(100);   

  }
  

void stand()
{
  servo1.write(127);
 servo2.write(75); 
 servo3.write(124);  
 servo4.write(67);   
}
