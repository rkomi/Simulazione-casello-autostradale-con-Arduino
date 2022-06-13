#include<Servo.h>
Servo myservo;
int red=11;
int yellow=12; //variabili
int green=13;
int sensore=10;
int sensoredue=8;
int statoprec=0;
void setup()
{
  myservo.attach(9);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(sensore,INPUT);
  pinMode(sensoredue,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  spegni(red,0);
 sensore1();
 sens2();
 ultpas();
}
void inizioServo(int t)
{
  myservo.write(90);
  delay(t);
  myservo.write(170); //sottoprogramma per il servomotore con inclinazione di 90° e poi 170°
  delay(t);
} 
/*inizioServo(2000);*/

void accendi(int pin,int t)
{
  digitalWrite(pin, HIGH); //sottoprogramma per accensione diodi led
  delay(t);
}
void spegni(int pin,int t)
{
 digitalWrite(pin,LOW); //sottoprogramma per spegnimento diodi led
 delay(t);
}

void semaforo()
{ 
 accendi(green,1000);
 spegni(green,0);
 accendi(yellow,500); //è un semaforo intermittenza dei colori con diversa durata di luminosità
 spegni(yellow,0);
 accendi(red,2000);
 spegni(red,0);
}
/*semaforo();*/
void sensore1()
{
 
if((digitalRead(sensore)==LOW)&&(digitalRead(sensoredue)==HIGH))
{
 myservo.write(170);  
 digitalWrite(green, HIGH);//alzare la barra e accensione led verde
 }
 
}/*sensore1();*/
void sens2()
{
   statoprec!=statoprec;
  if((digitalRead(sensoredue)==LOW)&&(digitalRead(sensore)==HIGH))
  {
   digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);//intermittenza led giallo
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);
  }
}
void ultpas()
{
if((digitalRead(sensoredue)==HIGH)||(digitalRead(sensore)==HIGH))
{
  
  digitalWrite(red,HIGH);
  spegni(yellow,0);
  statoprec!=statoprec;

  if((digitalRead(sensoredue)==HIGH)&&(digitalRead(sensore)==HIGH)){
    myservo.write(90);
    
    
    }


  
  }  
}
