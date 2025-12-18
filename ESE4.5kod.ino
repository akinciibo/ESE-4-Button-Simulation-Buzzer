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

lcd.setCursor(0,0);
lcd.print("aralik:");
lcd.setCursor(0,1);
lcd.print("sicaklik:");
}

double bartis=29.5;
double bazalis=28.5;
double aralikkucuk=10*bazalis; 
double aralikbuyuk=10*bartis;

void loop() {    
  buton1a();
  buton2a();
  double sicaklik =getTemparature();
  lcdaralik();
  lcdsicaklik(sicaklik);
  led (sicaklik);
}
void buton1a()
{
  if (digitalRead(buton1) ==LOW) 
  {
    bartis=bartis+1;
    bazalis=bazalis+1;
    delay(100);
  }
}

void buton2a()
{ 
   if (digitalRead(buton2) == LOW) {
    bartis = bartis - 1;
    bazalis = bazalis - 1;
    delay(100);
  }
}
double getTemparature()
{
  aralikkucuk=10*bazalis;
  aralikbuyuk=10*bartis;
  double sicaklik =random (aralikkucuk,aralikbuyuk)/10.0; 
  return sicaklik;
}
void lcdaralik()
{
  lcd.setCursor(7,0);
  lcd.print(bazalis,1);
  lcd.print("-");
  lcd.print(bartis,1);
}
void lcdsicaklik(double sicaklik)
{
  lcd.setCursor(10,1);
  lcd.print(sicaklik,1);
}
void led(double sicaklik)
{
  if(sicaklik>=25)
    {   
      digitalWrite(kirmiziled,HIGH);
      digitalWrite(yesilled,LOW);
    }
    else
    {
      digitalWrite(yesilled,HIGH);
      digitalWrite(kirmiziled,LOW);
    }
}