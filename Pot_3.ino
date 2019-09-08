const int led=11;
const int pot=A0;

void setup() {
pinMode(led,OUTPUT);

}

void loop() {
int potvalue;
int ledvalue;

potvalue=analogRead(pot);
ledvalue=map(potvalue,0,1023,0,255);
analogWrite(led,ledvalue);
}
