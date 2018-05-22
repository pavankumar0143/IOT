#include<WiFi.h>
#include<SPI.h>

char ssid[]="Ftp";
char pass[]="pavan123456789";

int status = WL_IDLE_STATUS;

uint16_t port = 9999;

IPAddress server(192,168,1,122);

WiFiClient client; 

void setup() {

  Serial.begin(9600);

  pinMode(31,INPUT_PULLUP)
  
  WiFi.begin(ssid,pass);
  
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print("Retry ");
    Serial.println(ssid);
    delay(1000);
  }

  Serial.println(" Wifi Conneted");

  Serial.println("Attempting to connect to Server");

  while (!client.connect(server, port);
  Serial.println(" Connected to Server");
  
}

void loop() {
  if (client.available()){
    char msg = client.read();
    Serial.print(msg);
  }
  
  if (! digitalRead(31)){
    delay(200);
    client.println("Hello Server");
  }
}
