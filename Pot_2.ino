const int ledr=11;
const int ledg=10;
const int ledb=9;
const int pot1=A0;
const int pot2=A1;
const int pot3=A2;

void setup() {
pinMode(ledr,OUTPUT);
pinMode(ledr,OUTPUT);
pinMode(ledr,OUTPUT);
}

void loop() {
int potvalue;
int ledvalue;

potvalue=analogRead(pot1);
ledvalue=map(potvalue,0,1023,0,255);
analogWrite(ledr,ledvalue);

potvalue=analogRead(pot2);
ledvalue=map(potvalue,0,1023,0,255);
analogWrite(ledg,ledvalue);

potvalue=analogRead(pot3);
ledvalue=map(potvalue,0,1023,0,255);
analogWrite(ledb,ledvalue);
}
