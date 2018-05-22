void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PUSH1, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly: 
  int analog_value = analogRead(A0);
  Serial.println(analog_value);
  delay(1000);
 
}
