void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(BLUE_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 
  int button_value = 1 ;
  button_value = digitalRead(PUSH1);
  while (!button_value)
  {
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
    button_value = digitalRead(PUSH1);
  }
  digitalWrite(BLUE_LED, LOW);
  delay(1000);
  
}
