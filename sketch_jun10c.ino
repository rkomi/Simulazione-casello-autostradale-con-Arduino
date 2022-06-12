#include <Servo.h>
int Color = 2;
int Time = 0;
int Sensore = 13;
int Green = 6;
int Yellow = 4;
int Red = 2;
Servo myservo;


//dichiarazione dei tipi di PIN
void setup() {
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  myservo.attach(10);
  Serial.begin(9600);

}


//...............
void loop() {

    Serial.println(digitalRead(Sensore));
    Serial.println(Time);

    if((digitalRead(Sensore)==LOW) && (Time==0)){

      Time = 1;
      Serial.println("Condizione 1 vera");
      
      }



    TimeOne();
    delay(500);
    

    TimeTwo();
    delay(500);

    TimeThree();
    delay(500);

    
  
}
  
  




//Sottoprogramma per l'accensione di un LED specifico
void Led_On(int Color){
  
  digitalWrite(Color, HIGH);
  
  }


//Sottoprogramma per lo spegnimento di un LED specifico
void Led_Off(int Color){

  digitalWrite(Color, LOW);
  
  }


//Sottoprogramma per lo spegnimento generale di tutti i LED
void General_Led_Shutdown(){
  
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, LOW);
  
  }


void TimeOne(){

    if(Time==1){

        Color = Green;
        Led_On(Green);
        myservo.write(10);
    }


    if((Time==1) && (digitalRead(Sensore)==HIGH)){

      Led_Off(Green);
      delay(30);
      Time = 2; 
      
    }
}

void TimeTwo(){

    if(Time==2){

        Color = Yellow;
        Led_On(Yellow);
        myservo.write(90);

        
    }


    if((Time==2) && (digitalRead(Sensore)==HIGH)){

      Led_Off(Yellow);
      delay(100);
      Time=3;
      
    }
}

void TimeThree(){

    if(Time==3){

        Color = Red;
        Led_On(Red);
        myservo.write(150);
    }


    if((Time==3) && (digitalRead(Sensore)==HIGH)){

      Led_Off(Red);
      delay(20);
      Time=0;
      
    }
}
