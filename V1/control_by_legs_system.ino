//---------------------------------- LCD
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
//----------------------------------
#define POT 35
#define buttonPin 4
#define ENTER 15
//---------------------------------- Variable
int Val;
String sdt;
long Timer;
boolean X;
//---------------------------------- Animation
int i=0;
int j=0;
byte customChar1[] = {
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18
};

byte customChar2[] = {
  0x03,
  0x03,
  0x03,
  0x03,
  0x03,
  0x03,
  0x03,
  0x03
};
//------------------------------ SOS
volatile bool buttonPressed = false;

void IRAM_ATTR handleButtonPress() {
  buttonPressed = true;
}
//-------------------------------

void setup() {
  Serial.begin(9600);
  Wire.begin(23,22);
  Boost_LCD();
  
  pinMode(ENTER,INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, RISING);
  
}

void loop() {
  Show_Number(map(analogRead(POT),0,4096,0,10));
  Enter_Click();
  Timer = millis();
  X = 0;
  
//----------------------------------- Ngắt ngoài
  if (buttonPressed){
    Check_sdt();
   buttonPressed = false; 
  }
}
