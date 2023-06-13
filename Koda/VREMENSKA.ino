#include <Wire.h>
#include <SFE_BMP180.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <dht11.h>
#define DHT11PIN 2
#define OLED_RESET -1
#define solar A3
#define ALTITUDE 300.0
dht11 DHT11;
Adafruit_SH1106 display(OLED_RESET); /* Object of class Adafruit_SSD1306 */
SFE_BMP180 pressure;

void setup() {
  pinMode(solar, INPUT);
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay(); /* Clear display */
  display.setTextColor(WHITE);
  display.setTextSize(2); /* Select font size of text. Increases with size of argument. */
  display.setCursor(0,5);
  display.println("penis");
  display.println("penis");
  display.println("penis");
  display.display();
  delay(500);
   
}

void loop() {

    
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1.5);
  display.setCursor(0,5);

  char status;
  double T,P,p0,a;
  Serial.println();
  Serial.print("provided altitude: ");
  Serial.print(ALTITUDE,0);
  Serial.println(" meters, ");

  Serial.println();

  status = pressure.startTemperature();

  delay(status);

  int chk = DHT11.read(DHT11PIN);

  status = pressure.getTemperature(T);

  
  display.print("Vlaznost: ");
  display.print((float)DHT11.humidity, 1);
  display.println(" %");
    
  Serial.print("Humidity(%): ");
  Serial.println((float)DHT11.humidity, 2);
  
  display.print("Temperatura: ");
  //display.print((float)T,2);
  display.println(" C");
    
  Serial.print("Temperature( °C): ");
  Serial.println((float)DHT11.temperature, 2);

  float napetostCelice = analogRead(solar)*(5.00/1023);

  display.println("Napetost na celici: ");
  display.print(napetostCelice - 1.0, 1);
  display.println(" V");

  

  Serial.print(napetostCelice);

  status = pressure.startPressure(3);

  status = pressure.getPressure(P,T);


  display.print("absolute pressure: ");
 // display.print((float)P,2);
  display.println(" mb,");

  p0 = pressure.sealevel(P,ALTITUDE);

  display.print("relative (sea-level) pressure: ");
  display.print(p0,2);
  display.println(" mb,");

  a = pressure.altitude(P,p0);
  display.print("computed altitude: ");
  display.print(a,0);
  display.println(" meters,");  
Serial.println(p0);
Serial.println(a);
display.display();


  delay(1000);
  
}
