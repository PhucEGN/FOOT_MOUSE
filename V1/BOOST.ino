void Boost_LCD(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
}

void Show_Number(int num){  
 lcd.setCursor(7,0);
 lcd.print(">");
 lcd.setCursor(11,0);
 lcd.print("<");
 lcd.setCursor(9,0);
 lcd.print(num);
}

void String_Concat(){
 Val = map(analogRead(POT),0,4096, 0,10);
 lcd.setCursor(9-sdt.length()/2,2);
 sdt = sdt + String(Val);
 lcd.print(sdt);
 Timer = millis();
}

void Check_sdt(){
  if(sdt.length() >= 9){
    lcd.clear(); 
    Watting_Calling();
    lcd.clear();
    lcd.setCursor(8,1);
    lcd.print("Call Ok");
    delay(1500);
    lcd.clear();
    lcd.setCursor(9-sdt.length()/2,2);
    lcd.print(sdt);
    Timer = millis();
  }
  else
  {
   for(int i = 0; i < 10; i++){
    lcd.noBacklight();
    delay(100);
    lcd.backlight();
    delay(100);
   }
   Timer = millis();
  }
}
