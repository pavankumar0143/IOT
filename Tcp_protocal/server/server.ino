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

void loop() {

  WiFiClient client = server.available();
  
  
  if (client == true){
    if (client.available()){
      char client_msg = client.read();
      Serial.println(client_msg);
    }
    else{
      server.print ("Hello\n");
      delay(600);
    }
  }
}

void printWifiStatus(){
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress IP = WiFi.localIP();
  Serial.print("IP Address : ");
  Serial.print(IP);
}

