void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(BLUE_LED, HIGH);
  delay(1000);
  digitalWrite(BLUE_LED, LOW);
  delay(1000);
  
}
