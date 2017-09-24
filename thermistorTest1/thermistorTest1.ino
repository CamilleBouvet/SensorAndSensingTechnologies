#include <math.h>

double Thermistor(int RawADC) {
   double Temp;
   Temp = 0.1632*RawADC - 50.514;
    return Temp;
}
  
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(A0, INPUT);

}

int compte = 0;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(A0));
  Serial.print("  Measure ");
  Serial.print(int(compte));
  Serial.print(" : ");
  Serial.println(int (Thermistor(analogRead(0))));  // display Celsius
  compte++;
  delay(5000);

}
