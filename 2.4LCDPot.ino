/*#include <FreeDefaultFonts.h>
#include <MCUFRIEND_kbv.h>
#include <TFT_HX8357GLUE.h>*/
#include <UTFTGLUE.h>
#include <Adafruit_GFX.h>

/*#include <pin_magic.h>
#include <registers.h>
#include <SPFD5408_Adafruit_GFX.h>
#include <SPFD5408_Adafruit_TFTLCD.h>
#include <SPFD5408_TouchScreen.h>
*/
/*
#include <memorysaver.h>
#include <UTFT.h>*/
//#include <URTouch.h>


int XP = 7, XM = A1, YP = A2, YM = 6;

//==== Creating Objects
UTFTGLUE    myGLCD(0x0154,A2,A1,A3,A4,A0); //Parameters should be adjusted to your Display/Schield model
//URTouch  myTouch( 6, 5, 4, 3, 2);

#include <TouchScreen.h>         //Global Library
TouchScreen myTouch(XP, YP, XM, YM, 300);
TSPoint tp;


//==== Defining Variables
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
int x, y;
//char selectedUnit;

// RGB LEDs
const int redLed = 10;
//const int greenLed = 9;
//const int blueLed = 8;
int xR=38;
/*int xG=38;
int xB=38;*/

//int sensorValue = 0;
int outputValue = 0;
int transistorPin = 3;

void drawHomeScreen();
void drawLedControl();
void setLedColor();

void readResistiveTouch(void)
{
    tp = myTouch.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
}

void setup() {
 // Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();
  //myTouch.InitTouch();
  //myTouch.setPrecision(PREC_MEDIUM);
  // Defining Pin Modes
  //pinMode(VCC, OUTPUT); // VCC
  //pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  //pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(redLed, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(transistorPin, OUTPUT);
  /*pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);*/
  //pinMode(button, INPUT);
  //digitalWrite(VCC, HIGH); // +5V - Pin 13 as VCC
  //drawHomeScreen();  // Draws the Home Screen
  //currentPage = '0'; // Indicates that we are at Home Screen
  //selectedUnit = '0'; // Indicates the selected unit for the first example, cms or inches
 }

void loop() {
   // Home Screen
    //drawHomescreen()
    drawLedControl();
  readResistiveTouch();
  if (tp.z > 20 && tp.z < 1000) {
    //myTouch.read();
    x=tp.x; // X coordinate where the screen has been pressed
    y=tp.y; // Y coordinates where the screen has been pressed
      
    setLedColor();
    analogWrite(transistorPin, redLed);
    if (redLed >= 160) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    }
    else  { 
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);

    }
    delay(10);
  
  /*if (myTouch.dataAvailable()) {
        myTouch.read();
        x=myTouch.getX();
        y=myTouch.getY();
  }*/
  }
     
    
}


/*void drawHomescreen()
{
  // Button - RGB LED Control
  myGLCD.setColor(16, 167, 103);
  myGLCD.fillRoundRect (35, 140, 285, 180);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (35, 140, 285, 180);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(16, 167, 103);
  myGLCD.print("RGB LED CONTROL", CENTER, 152);
}*/


void drawLedControl() {
  /*myGLCD.setColor(100, 155, 203);
  myGLCD.fillRoundRect (10, 10, 60, 36);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 10, 60, 36);*/
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(100, 155, 203);
  /*myGLCD.print("<-", 18, 15);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.print("Back to Main Menu", 70, 18);*/
  myGLCD.setFont(BigFont);
  myGLCD.print("Motor Speed Control", CENTER, 50);
  myGLCD.print("Slider", 10, 95);
  /*myGLCD.print("R", 10, 135);
  myGLCD.print("G", 10, 175);
  myGLCD.print("B", 10, 215);*/
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(0,75,319,75); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(30, 138, 310, 148); // R - Slider
  /*myGLCD.drawRect(30, 178, 310, 188);
  myGLCD.drawRect(30, 218, 310, 228);*/  
}

 void setLedColor() {
  readResistiveTouch();
  if (tp.z > 20 && tp.z < 1000) {
    //myTouch.read();
    x=tp.x;
    y=tp.y;        
    // Area of the Red color slider
    if( (y>=130) && (y<=156)) {
      xR=x; // Stores the X value where the screen has been pressed in to variable xR
      if (xR<=38) { // Confines the area of the slider to be above 38 pixels
        xR=38;
      }
      if (xR>=303){ /// Confines the area of the slider to be under 310 pixels
        xR=303;
      }
    }
  /*
    // Area of the Green color slider
    if( (y>=170) && (y<=196)) {
      xG=x;
      if (xG<=38) {
        xG=38;
      }
      if (xG>=303){
        xG=303;
      }
    }
    // Area of the Blue color slider
    if( (y>=210) && (y<=236)) {
      xB=x;
      if (xB<=38) {
        xB=38;
      }
      if (xB>=303){
        xB=303;
      }
    }*/   
  }
  // Maps the values of the X - Axis from 38 to 0 and 310 to 255, because we need values from 0 to 255 for turning on the led
  
  int xRC = map(xR,38,310,0,255);
  /*
  int xGC = map(xG,38,310,0,255);
  int xBC = map(xB,38,310,0,255);*/
  
  // Sends PWM signal to the pins of the led
  analogWrite(redLed, xRC);
  /*analogWrite(greenLed, xGC);
  analogWrite(blueLed, xBC);*/
  
  // Draws a rectangle with the latest color combination 
  /*myGLCD.setColor(xRC, xGC, xBC);
  myGLCD.fillRoundRect(175, 87, 310, 119);*/
  
  // Draws the positioners
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(xR,139,(xR+4),147); // Positioner
  myGLCD.setColor(xRC, 0, 0);
  myGLCD.fillRect(31, 139, (xR-1), 147);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect((xR+5), 139, 309, 147);
  
  /*myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(xG,179,(xG+4),187);
  myGLCD.setColor(0, xGC, 0);
  myGLCD.fillRect(31, 179, (xG-1), 187);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect((xG+5), 179, 309, 187);
  
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(xB,219,(xB+4),227);
  myGLCD.setColor(0, 0, xBC);
  myGLCD.fillRect(31, 219, (xB-1), 227);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect((xB+5), 219, 309, 227);*/
}
