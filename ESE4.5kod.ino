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
  buton1a( sicaklik);
  buton2a(sicaklik);
  lcda( sicaklik );
  led (sicaklik);
}
void buton1a(double sicaklik )
{
  double aralikkucuk=10*bazalis;
  double aralikbuyuk=10*bartis;
  if (digitalRead(buton1) ==LOW) 
  {
    bartis=bartis+1;
    bazalis=bazalis+1;
    sicaklik =random (aralikkucuk,aralikbuyuk)/10.0;
    delay(100);
  }
  return sicaklik;
}
void buton2a(double sicaklik)
{ 
   double aralikkucuk=10*bazalis;
   double aralikbuyuk=10*bartis;
   if (digitalRead(buton2) == LOW) {
    bartis = bartis - 1;
    bazalis = bazalis - 1;
    sicaklik = random(aralikkucuk, aralikbuyuk) / 10.0;
    delay(100);
  }
  return sicaklik;
}
void lcda(double sicaklik)
{
  lcd.setCursor(0,0);
  lcd.print("aralik:");
  lcd.print(bazalis,1);
  lcd.print("-");
  lcd.print(bartis,1);

  lcd.setCursor(0,1);
  lcd.print("sicaklik : ");
  lcd.print(sicaklik);
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