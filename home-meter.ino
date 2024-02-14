#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int led1=13;       //lavatrice
int led2=12;       //forno
int led3=11;       //aspirapolvere
int led4=10;       //asciuga capelli
int pulsante1=9;
int pulsante2=8;
int pulsante3=7;
int pulsante4=6;
int statopuls1=LOW;
int statopuls2=LOW;
int statopuls3=LOW;
int statopuls4=LOW;
int carico=0;
int potenza=3000;
bool test1=false;
bool test2=false;
bool test3=false;
bool test4=false;
int x1=0;
int x2=0;
int x3=0;
int x4=0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(pulsante1,INPUT);
  pinMode(pulsante2,INPUT);
  pinMode(pulsante3,INPUT);
  pinMode(pulsante4,INPUT);
  lcd.setCursor(0,0);
  lcd.print("carico");
  lcd.setCursor(7,0);
  lcd.print(">");
  lcd.setCursor(9,0);
  lcd.print("potenza");
  
  lcd.setCursor(1,1);
  lcd.print(carico);
  lcd.setCursor(7,1);
  lcd.print(">");
  lcd.setCursor(10,1);
  lcd.print(potenza);
}

void loop() {
  statopuls1=digitalRead(pulsante1);
  statopuls2=digitalRead(pulsante2);
  statopuls3=digitalRead(pulsante3);
  statopuls4=digitalRead(pulsante4);


  if(statopuls1==HIGH and test1==false){
    test1=true;
    delay(10);
  }

  if(test1==true){   
    while(x1<1){
      digitalWrite(led1,HIGH);
      x1++;
      carico=carico + 700;    //lavatrice
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("carico");
      lcd.setCursor(7,0);
      lcd.print(">");
      lcd.setCursor(9,0);
      lcd.print("potenza");
  
      lcd.setCursor(1,1);
      lcd.print(carico);
      lcd.setCursor(7,1);
      lcd.print(">");
      lcd.setCursor(10,1);
      lcd.print(potenza);
      delay(200);
    }
   }

   

  if(statopuls2==HIGH and test2==false){
    test2=true;
    delay(10);
  }

  if(test2==true){
    while(x2<1){
      digitalWrite(led2,HIGH);
      x2++;
      carico=carico + 1000;    //forno
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("carico");
      lcd.setCursor(7,0);
      lcd.print(">");
      lcd.setCursor(9,0);
      lcd.print("potenza");
  
      lcd.setCursor(1,1);
      lcd.print(carico);
      lcd.setCursor(7,1);
      lcd.print(">");
      lcd.setCursor(10,1);
      lcd.print(potenza);
      delay(200);
    }
  }



  if(statopuls3==HIGH and test3==false){
    test3=true;
    delay(10);
  }

  if(test3==true){    
    while(x3<1){
      digitalWrite(led3,HIGH);
      x3++;
      carico=carico + 2000;    //aspirapolvere
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("carico");
      lcd.setCursor(7,0);
      lcd.print(">");
      lcd.setCursor(9,0);
      lcd.print("potenza");
  
      lcd.setCursor(1,1);
      lcd.print(carico);
      lcd.setCursor(7,1);
      lcd.print(">");
      lcd.setCursor(10,1);
      lcd.print(potenza);
      delay(200);
    }
  }



  if(statopuls4==HIGH and test4==false){
    test4=true;
    delay(10);
  }

  if(test4==true){    
    while(x4<1){
      digitalWrite(led4,HIGH);
      x4++;
      carico=carico + 400;    //asciuga capelli
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("carico");
      lcd.setCursor(7,0);
      lcd.print(">");
      lcd.setCursor(9,0);
      lcd.print("potenza");
  
      lcd.setCursor(1,1);
      lcd.print(carico);
      lcd.setCursor(7,1);
      lcd.print(">");
      lcd.setCursor(10,1);
      lcd.print(potenza);
      delay(200);
    }
  }

  
  if(carico>=potenza){
    test1=false;
    test2=false;
    test3=false;
    test4=false;
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    carico=0;
    x1=0;
    x2=0;
    x3=0;
    x4=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("carico");
    lcd.setCursor(7,0);
    lcd.print(">");
    lcd.setCursor(9,0);
    lcd.print("potenza");
  
    lcd.setCursor(1,1);
    lcd.print(carico);
    lcd.setCursor(7,1);
    lcd.print(">");
    lcd.setCursor(10,1);
    lcd.print(potenza);
    delay(1000);
 }
}
