#include "Keyboard.h"

#define PASTE 3
#define MIC 2
#define BACKSPACE 4
#define ENTER 18
#define COPY 19
#define HOME 21

bool state;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  
  pinMode(PASTE,     INPUT_PULLUP);
  pinMode(MIC,       INPUT_PULLUP);
  pinMode(BACKSPACE, INPUT_PULLUP);
  pinMode(ENTER,     INPUT_PULLUP);
  pinMode(COPY,      INPUT_PULLUP);
  pinMode(HOME,      INPUT_PULLUP);
  
}

void loop() {
//-----------------------------// MICRO //---------------------------//
  if(digitalRead(MIC) == 0 and state == 0){
    state = 1;
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('m');
    }
  if(digitalRead(MIC) == 0 and state == 1){
    Keyboard.releaseAll();
    delay(250);
    state = 0;
    }
//-----------------------------// HOME //---------------------------//
  if(digitalRead(HOME) == 0 and state == 0){
    state = 1;
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('H');
    delay(100);
    }
  if(digitalRead(HOME) == 1 and state == 1){
    Keyboard.releaseAll();
    state = 0;
    }
//-----------------------------// ENTER //---------------------------//
  if(digitalRead(ENTER) == 0){
    Keyboard.press(KEY_RETURN);
    delay(100);
    }
  if(digitalRead(ENTER) == 1){
    Keyboard.release(KEY_RETURN);
    state = 0;
    }
//-----------------------------// COPY //---------------------------//
  if(digitalRead(COPY) == 0 and state == 0){
    state = 1;
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('c');
    delay(100);
    }
  if(digitalRead(COPY) == 1 and state == 1){
    Keyboard.releaseAll();
    state = 0;
    }
//-----------------------------// PASTE //---------------------------//
  if(digitalRead(PASTE) == 0 and state == 0){
    state = 1;
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('v');
    }
    
  if(digitalRead(PASTE) == 0 and state == 1){
    Keyboard.releaseAll();
    delay(200);
    }
//-----------------------------// BACKSPACE //---------------------------//
  if(digitalRead(BACKSPACE) == 0){
    Keyboard.press(KEY_BACKSPACE);
    delay(100);
    }
  if(digitalRead(BACKSPACE) == 1){
    Keyboard.release(KEY_BACKSPACE);
    }
}
