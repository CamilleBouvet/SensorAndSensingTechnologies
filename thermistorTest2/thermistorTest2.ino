#include <math.h>

double tableAandB[7][3] = 
{
    {22,1.5008,-78.368},
    {352,0.1526,-37.131},
    {463,0.1632,-50.514},
    {771,0.1164,17.872},
    {925,0.2507,54.314},
    {1012,1.0971,82.831},
    {1023,21.267,163}
    };

double Thermistor(int RawADC, double a, double b) {
   double Temp;
   Temp = a*RawADC + b;
   Serial.println(a);
   Serial.println(b);
   return Temp;
}
  
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(A0, INPUT);

}

int compte = 0;
int i = 0;
bool valueFind = true;
int vOut = 0;

void loop() {
  i = -1;
  valueFind = true;
  vOut = analogRead(A0);
  Serial.print(int(vOut));
  Serial.print("  Measure ");
  Serial.print(int(compte));
  Serial.print(" : ");
  while((i<=6) && (valueFind))
  {
    i++;
    if(vOut <= tableAandB[i][0])
    {
      valueFind = false;
      Serial.println(i);
    }
  }
  Serial.println(int (Thermistor(vOut,tableAandB[i][1], tableAandB[i][2])));  // display Celsius
  compte++;
  delay(5000);

}
