void Connected(){
  while(bleMouse.isConnected()) {
   while(Serial2.available()) {
 
    A = Serial2.readStringUntil('\n');
    
    x = splitString(A, ",", 1).toInt();
    y = splitString(A, ",", 2).toInt();
    
    if(digitalRead(Left) == 0) {bleMouse.press(MOUSE_LEFT);}
    if(digitalRead(Left) != 0) {bleMouse.release(MOUSE_LEFT);}
    
    if(digitalRead(Right) == 0) {bleMouse.press(MOUSE_RIGHT);}
    if(digitalRead(Right) != 0) {bleMouse.release(MOUSE_RIGHT);}
    
    bleMouse.move(x, y, z); delay(5);
    
  }
  while(!Serial2.available()){ 
  
    if(digitalRead(Left) == 0) {bleMouse.press(MOUSE_LEFT);}
    if(digitalRead(Left) != 0) {bleMouse.release(MOUSE_LEFT);}
    
    if(digitalRead(Right) == 0) {bleMouse.press(MOUSE_RIGHT);}
    if(digitalRead(Right) != 0) {bleMouse.release(MOUSE_RIGHT);}
    
    x = 0; y = 0; z = 0;
    bleMouse.move(x, y, z); delay(5); 
    }
    
    if (interruptFlag) {
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    bleMouse.end();
    Serial.println("state 1");
    state = 1;
    delay(300);
    interruptFlag = false;
    return loop();
     
  }
 }
}

void Disconnect(){
  Blynk.run();
//  mpu6050.update();
//  Serial.print("  Val: "); Serial.println(Val); 
//  if(mpu6050.getGyroZ() >= 75.00)  { Val++; if(Val >= 7) {Val = 7;} delay(500);}
//  if(mpu6050.getGyroZ() <= -75.00) { Val--; if(Val <= 0) {Val = 0;} delay(500);}
  if(digitalRead(Left) == 0)  {String push = "On"+String(Val);  Blynk.virtualWrite(V4, push); push ="";}
  if(digitalRead(Right) == 0) {String push = "Off"+String(Val); Blynk.virtualWrite(V4, push); push ="";}
  
  if (interruptFlag) {
    Blynk.disconnect();
    bleMouse.begin();
    Serial.println("state 0");
    state = 0;
    interruptFlag = false; 
  }
}
String splitString(String inputString, String delim, uint16_t pos){
String tmp = inputString;
  for(int i=0; i<pos; i++){
    tmp = tmp.substring(tmp.indexOf(delim)+1);
    if(tmp.indexOf(delim)== -1 
    && i != pos -1 )
      return "";
  }
  return tmp.substring(0,tmp.indexOf(delim));
}
