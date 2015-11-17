

Adafruit_MPL115A2 mpl115a2 = Adafruit_MPL115A2();

void setup() 
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  Serial.println("Getting barometric pressure ...");
  mpl115a2.begin();
}

void loop() 
{
  float pressureKPA = 0, temperatureC = 0, temperatureF = 0;    

  mpl115a2.getPT(&pressureKPA,&temperatureC);
  Serial.print("Pressure (kPa): "); Serial.print(pressureKPA, 4); Serial.print(" kPa  ");
  Serial.print("Temp (*C): "); Serial.print(temperatureC, 1); Serial.println(" *C both measured together");
  
  pressureKPA = mpl115a2.getPressure();  
  Serial.print("Pressure (kPa): "); Serial.print(pressureKPA, 4); Serial.println(" kPa");

  temperatureC = mpl115a2.getTemperature();  
  Serial.print("Temp (*C): "); Serial.print(temperatureC, 2); Serial.println(" *C");
  
  temperatureF = ((temperatureC * 1.8) + 32);
  Serial.print("Temp (*F): "); Serial.print(temperatureF, 2); Serial.println(" *F");
  
  delay(1000);
}
