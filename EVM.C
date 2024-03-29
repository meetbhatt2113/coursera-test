//Arduino based EVM Code
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define sw1 15
#define sw2 16
#define sw3 17
#define sw4 18
#define sw5 19
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
void setup()
{
pinMode(sw1, INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
pinMode(sw5,INPUT);
lcd.begin(16, 2);
lcd.print("Voting Machine");
lcd.setCursor(0,1);
lcd.print("Example Circuit");
delay(3000);
digitalWrite(sw1, HIGH);
digitalWrite(sw2, HIGH);
digitalWrite(sw3, HIGH);
digitalWrite(sw4, HIGH);
digitalWrite(sw5, HIGH);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" A ");
lcd.setCursor(3,0);
lcd.print(" B ");
lcd.setCursor(6,0);
lcd.print(" C "); 
lcd.setCursor(9,0); 
lcd.print(" D "); 
lcd.print("TOT"); 
lcd.setCursor(12,0); 
}
void loop() 
{
lcd.setCursor(0,0); 
lcd.print(" A "); 
lcd.setCursor(1,1); 
lcd.print(vote1);
lcd.setCursor(3,0); 
lcd.print(" B "); 
lcd.setCursor(4,1); 
lcd.print(vote2); 
lcd.setCursor(6,0); 
lcd.print(" C "); 
lcd.setCursor(7,1); 
lcd.print(vote3); 
lcd.setCursor(9,0); 
lcd.print(" D "); 
lcd.setCursor(10,1); 
lcd.print(vote4); 
lcd.setCursor(12,0); 
lcd.print("TOT"); 
lcd.setCursor(13,1); 
lcd.print(vote1+vote2+vote3+vote4); 
if(digitalRead(sw1)==0) 
vote1++; 
while(digitalRead(sw1)==0); 
if(digitalRead(sw2)==0) 
vote2++; 
while(digitalRead(sw2)==0); 
if(digitalRead(sw3)==0) 
vote3++; 
while(digitalRead(sw3)==0); 
if(digitalRead(sw4)==0) 
vote4++; 
while(digitalRead(sw4)==0); 
if(digitalRead(sw5)==0) 
{
int vote=vote1+vote2+vote3+vote4; 
if(vote) 
{
if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4)) {
lcd.clear(); 
lcd.print("A Wins"); 
delay(20000); 
lcd.clear(); 
}
else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4)) {
lcd.clear(); 
lcd.print("B Wins"); 
delay(2000); 
lcd.clear(); 
}
else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4)) {
lcd.clear(); 
lcd.print("C Wins");


delay(2000);
lcd.clear();
}
else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd.setCursor(0,0);
lcd.clear();
lcd.print("D Wins");
delay(2000);
lcd.clear();
}
else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd.setCursor(0,0);
lcd.clear();
lcd.print("D Wins");
delay(2000);
lcd.clear();
}
else
{
lcd.clear();
lcd.print(" Tie Up Or ");
lcd.setCursor(0,1);
lcd.print(" No Result ");
delay(1000);
lcd.clear();
}
}
else
{
lcd.clear();
lcd.print("No Voting....");
delay(1000);
lcd.clear();
}
vote1=0;vote2=0;vote3=0;vote4=0,vote=0;
lcd.clear();
}
}
