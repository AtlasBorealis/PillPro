/*
void printRtcTime(){
  //Prints time in UTC format
  Serial.print(month());
  Serial.print("/");
  Serial.print(day());
  Serial.print("/");
  Serial.print(year());
  Serial.print("-");
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.println(second());
}//END PRINTRTCTIME
*/

void espDebuggingSetup(){
  Serial.begin(115200);
  pinMode(2,OUTPUT); //GPIO 2 built in LED
}

void espDebuggingSetEnd(){
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(2,LOW);
}

void light_blip(int reps){
  for (int repi = 0; repi < reps; repi += 1){
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    delay(500);
  }
}