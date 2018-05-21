void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(BLUE_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 

  int button_value = digitalRead(PUSH1);
  if (button_value == 0)
  {
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
  }
  digitalWrite(BLUE_LED, LOW);
  delay(1000);
  
}
