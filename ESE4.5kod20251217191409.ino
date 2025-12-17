#include <LiquidCrystal.h>

#define buton1 2
#define buton2 3
#define kirmiziled 6 
#define yesilled 7
LiquidCrystal lcd (13,12,11,10,9,8);
void setup() {
lcd.begin(16,2);

pinMode(buton1 ,INPUT_PULLUP);
pinMode(buton2 ,INPUT_PULLUP);
pinMode(kirmiziled,OUTPUT);
pinMode (yesilled,OUTPUT);  

}

double bartis=29.5;
double bazalis=28.5;

void loop() {
  double aralikkucuk=10*bazalis;
  double aralikbuyuk=10*bartis;
  double sicaklik =random (aralikkucuk,aralikbuyuk)/10.0;
  if (digitalRead(buton1) ==LOW) 
  {
    bartis=bartis+1;
    bazalis=bazalis+1;
    sicaklik =random (aralikkucuk,aralikbuyuk)/10.0;
    digitalWrite(kirmiziled,HIGH);
    delay(100);
    digitalWrite(kirmiziled,LOW);
  }
    lcd.setCursor(0,0);
    lcd.print("aralik:");
    lcd.print(bazalis,1);
    lcd.print("-");
    lcd.print(bartis,1);

    lcd.setCursor(0,1);
    lcd.print("sicaklik : ");
    lcd.print(sicaklik);

  if (digitalRead(buton2) == LOW)
  {
    bartis=bartis-1;
    bazalis=bazalis-1;
    sicaklik =random (aralikkucuk,aralikbuyuk)/10.0;
    digitalWrite(yesilled,HIGH);
    delay(100);
    digitalWrite(yesilled,LOW);
  }
  lcd.setCursor(0,0);
  lcd.print("aralik:");
  lcd.print(bazalis,1);
  lcd.print("-");
  lcd.print(bartis,1);

  lcd.setCursor(0,1);
  lcd.print("sicaklik : ");
  lcd.print(sicaklik);
  
  int yanma=10;
  int sonme =90;
  

    if(sicaklik>=25)
    {
      int fark =sicaklik-25;
      int aradakifark=fark/2;
      
      yanma=(aradakifark*10)+yanma;
      sonme=100-yanma;
      digitalWrite(kirmiziled,HIGH);
      delay(yanma);

      digitalWrite(kirmiziled,LOW);
      delay(sonme);
    }
    if (sicaklik<25)
    {
      int fark =25-sicaklik;
      int aradakifark=fark/2;
      
      yanma=(aradakifark*100)+yanma;
      sonme=100-yanma;
      digitalWrite(yesilled,HIGH);
      delay(yanma);

      digitalWrite(yesilled,LOW);
      delay(sonme);


    }

}
