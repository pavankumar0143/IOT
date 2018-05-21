void setup() {
  // put your setup code here, to run once:
    pinMode(PUSH1, INPUT_PULLUP);
    pinMode(BLUE_LED, OUTPUT);
}

int count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int button_value = digitalRead(PUSH1);
  if (button_value == 0){
    count++;
    if (count%2){
      digitalWrite(BLUE_LED, HIGH);
    }

    else if(count%2 == 0){
      digitalWrite(BLUE_LED, LOW);
    }
  }
  
}
