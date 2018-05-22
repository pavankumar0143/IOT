void setup() {
  // put your setup code here, to run once:
  pinMode(30, OUTPUT);
  pinMode(39, OUTPUT);

}

int count = 5;

void loop() {
  // put your main code here, to run repeatedly: 

  if ( count == 5 ){ 
    digitalWrite(30, HIGH);
    delay(1000);
    digitalWrite(30, LOW);
    delay(1000);
    digitalWrite(39, HIGH);
    delay(1000);
    digitalWrite(39, LOW);    
    delay(1000);
  }

  while(count > 0){
      digitalWrite(30, HIGH);
      delay(1000);
      digitalWrite(30, LOW);
      delay(1000);
      count = count -1;
    }
  
  if (count == 0 ){
    digitalWrite(39, HIGH);
    delay(1000);
    digitalWrite(39, LOW);
    delay(1000);
    count = count -1 ;
  }
}
