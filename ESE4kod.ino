#include <LiquidCrystal.h>

#define buzzer 4
#define buton1 2
#define buton2 3
#define sariled 5
#define kirmiziled 6 
#define yesilled 7
LiquidCrystal lcd (13,12,11,10,9,8);
void setup() {

lcd.begin(16,2);
pinMode(buton1 ,INPUT_PULLUP);
pinMode(buton2 ,INPUT_PULLUP);
pinMode(buzzer,OUTPUT);
pinMode (sariled,OUTPUT);
pinMode(kirmiziled,OUTPUT);
pinMode (yesilled,OUTPUT);  

}
double bartis=29.5;
double bazalis=28.5;
void loop() {
  if (digitalRead(buton1) ==LOW)
  {
    bartis=bartis+1;
    bazalis=bazalis+1;
    digitalWrite(kirmiziled,HIGH);
    delay(300);
    digitalWrite(kirmiziled,LOW);
    
  }
  if (digitalRead(buton2) == LOW)
  {
    bartis=bartis-1;
    bazalis=bazalis-1;
    digitalWrite(yesilled,HIGH);
    delay(300);
    digitalWrite(yesilled,LOW);
    
  }
  long aralikkucuk=10*bazalis;
  long aralikbuyuk=10*bartis;
  long sicaklik =random (aralikkucuk,aralikbuyuk)/10.0;


  

  if (sicaklik>35)
  {
    int buzzercalma=100;
    int buzzersusma =900;

    if(sicaklik>=40)
    {

      int fark =sicaklik-40;
      int aradakifark=fark/2;
      
      buzzercalma=(aradakifark*100)+buzzercalma;
      buzzersusma=1000-buzzercalma;
    }
      digitalWrite(buzzer,HIGH);
      digitalWrite(sariled,HIGH);
      delay(buzzercalma);
      
      digitalWrite(buzzer,LOW);
      digitalWrite(sariled,LOW);
      delay(buzzersusma);
      
  }

  lcd.setCursor(0,0);
  lcd.print("aralik:");
  lcd.print(bazalis,1);
  lcd.print("-");
  lcd.print(bartis,1);

  lcd.setCursor(0,1);
  lcd.print("sicaklik : ");
  lcd.print(sicaklik);

  delay(300);
}
