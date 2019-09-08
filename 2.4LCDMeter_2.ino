#include <LiquidCrystal.h>
byte Pin_plus=0;
byte Pin_moins=0;
byte j=0;

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void setup() {

 lcd.begin(16, 2);
 pinMode(8, OUTPUT);
 pinMode(7,INPUT);
 pinMode(2,INPUT);
 lcd.setCursor(0,0);
 lcd.print("Speed 0 to 250:");
 
 
 
}

void loop() {

if ((digitalRead(2)==HIGH) && (digitalRead(7)==LOW))
 {
   if (j<255)
   {j++;
   lcd.setCursor(5,1);
   lcd.print("                ");
   lcd.setCursor(5,1);
   lcd.print(j);
   while((digitalRead(2)==HIGH) && (digitalRead(7)==LOW));}
 }
else if ((digitalRead(2)==LOW) && (digitalRead(7)==HIGH))
 {
   if (j>0)
   {j--;
   lcd.setCursor(5,1);
   lcd.print("                ");
   lcd.setCursor(5,1);
   lcd.print(j);
   while((digitalRead(2)==LOW) && (digitalRead(7)==HIGH));}
}

analogWrite(8,j);
lcd.noDisplay();
lcd.display();
delay(100);

}
