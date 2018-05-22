#include<WiFi.h>
#include<SPI.h>

// user name and password of wifi hotspot

char ssid[]="Ftp";
char pass[]="pavan123456789";

IPAddress ip,gateway,subnetmask;

void setup()
{
  
  Serial.begin(9600);
  
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
  if(WiFi.localIP()==INADDR_NONE){
    Serial.println("Getting IP address");
    delay(1000);
  }

  // Finding ip address
  
  ip=WiFi.localIP();
  Serial.print("ip address : ");
  Serial.println(ip);
  delay(100);

  // Finding Gateway address
  
  gateway=WiFi.gatewayIP();
  Serial.print("gateway address :");
  Serial.println(gateway);
  delay(100);

  // Finding subnetmask
  subnetmask = WiFi.subnetMask();
  Serial.print("subnetmask :");
  Serial.println(subnetmask);
  delay(100);
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
