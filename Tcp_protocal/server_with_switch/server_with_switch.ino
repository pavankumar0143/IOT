#include<WiFi.h>
#include<SPI.h>

char ssid[]="Ftp";
char pass[]="pavan123456789";

IPAddress ip(192,168,1,122);

unsigned char data = 0;

WiFiServer server(8888);

boolean alreadyConnected = false;

void setup() {

  Serial.begin(9600);

  pinMode(31, INPUT_PULLUP);
 
  
  WiFi.config(ip);

  // Connect to wifi
  WiFi.begin(ssid,pass);
  
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print("Retry ");
    Serial.println(ssid);
    delay(1000);
  }
  
  Serial.println("connected");
  delay(1000);

  // Check for returned ip
  while (WiFi.localIP()==INADDR_NONE){
    Serial.println("Getting IP address");
    delay(1000);
  }


  Serial.println(" Got ip address");

  printWifiStatus();

  server.begin();
  

}

int toggle = 0;
char incomingByte;

void loop() {

  WiFiClient client = server.available();
  
  if (client == true){

    // send data only when serial data is available

    int analog_value = analogRead(A0);
    delay(300);
    if ( analog_value){
      
      if (toggle == 0){
          Serial.print("Message Sent :");
          toggle= 1;
       }

      char sent_msg[10];
       
      itoa(analog_value, sent_msg, 10);
      
      client.print(sent_msg);
      
      Serial.println(sent_msg);
    }
    
    if (! digitalRead(31)){
      delay(200);
      client.println("Hello Client");
    }
  
    
    if (client.available()){
      char client_msg = client.read();
      Serial.print(client_msg);
    }

   
    
    if ( Serial.available()){
        if (toggle == 0){
          Serial.print("Message Sent :");
          toggle= 1;
        }
        incomingByte = Serial.read();
        delay(200);
        client.print(incomingByte);
        
        Serial.print(incomingByte);
              
    }
//    else{
//      server.print ("Hello\n");
//      delay(600);
//    }
  }
}

void printWifiStatus(){
  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress IP = WiFi.localIP();
  Serial.print("IP Address : ");
  Serial.println(IP);
}




