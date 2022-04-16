#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT11

const int BOTON1 = 2;
const int BOTON2 = 3;
const int BOTON3 = 4;
const int LED1 = 6;
const int LED2 = 7;

int dato1;
int dato2;
int dato3;
float t;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(BOTON1,INPUT);
  pinMode(BOTON2,INPUT);
  pinMode(BOTON3,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);

}

void loop() {
  t = dht.readTemperature();
  dato1 = digitalRead (BOTON1);
  dato2 = digitalRead (BOTON2);
  dato3 = digitalRead (BOTON3);
  
  if ((t > 31)&&(dato1 == 0))
  {
    if ((dato2 == 1)||(dato3 == 1))
    {
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,HIGH);  
    }
    else
    {
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,HIGH); 
    }
  }
  else if ((dato1 == 1) && (t < 31))
  {
    digitalWrite (LED1,HIGH);
    digitalWrite (LED2,LOW);
  }
  else if ((dato1 == 1)&& (t > 31))
  {
    
    if ((dato2 == 1)||(dato3 == 1))
    {
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,HIGH);
    }
    else
    {
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,LOW); 
    }
  }
  else
  {
    if ((dato2 == 1)||(dato3 == 1))
    {
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,HIGH);
    }
    else
    {
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,LOW);
    }
  }
  
  delay (10);
  Serial.println(t);
}
