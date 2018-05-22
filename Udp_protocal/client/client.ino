#include<WiFi.h>
#include<SPI.h>

char ssid[]="Lenovo";
char pass[]="123456789";

IPAddress ip(192,168,43,123);

char data[15];

unsigned int LP = 5555;

WiFiUDP Udp;

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

  Udp.begin(LP);
  

}

void loop() {

  int packetsize = Udp.parsePacket()
  
  
  if (Serial.available()){
    Serial.readBytes(Data, 15);
    Udp.beginPacket(ip, 2500);
    Udp.write()
    Udp.endPacket()

    for (i = 0; i < 10; i++){
      data[i] =' ';
    }
    
  }
  delay(100);
}

void printWifiStatus(){
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress IP = WiFi.localIP();
  Serial.print("IP Address : ");
  Serial.print(IP);
}

