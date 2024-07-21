void Enter_Click(){
  while(digitalRead(ENTER) == 0){
    if(digitalRead(ENTER) == 1 and X == 0){ Check_sdt(); }
    if(millis() - Timer >= 1500){ X = 1; String_Concat(); }
  }
}

void Watting_Calling(){
    for(int z = 0; z < 100; z++){
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("CALLING");
    lcd.setCursor(i,2);
    lcd.write(0);
    lcd.setCursor(i,3);
    lcd.write(0);
    delay(50);
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("CALLING");
    lcd.setCursor(i,2);
    lcd.write(1);
    lcd.setCursor(i,3);
    lcd.write(1);
    delay(50);  
    lcd.clear();
    i++;
    if(i==20){
    i=0;}
    }
}
