#include <CapacitiveSensor.h>
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);

void setup()                    
{
   Serial.begin(9600);
   randomSeed(analogRead(A0));

}
int lastFreq = 0;
void loop()                    
{
  digitalWrite(11, HIGH);
  if(digitalRead(12) == HIGH){
    
  
    long raw =  cs_4_8.capacitiveSensor(30);

    Serial.print("Raw: ");
    Serial.print(raw);    
    long freq = map(raw, 8, 1200, 300, 4000);
    Serial.print(" | Fq: ");
    Serial.println(freq);

    if(raw < 8){
      noTone(3);
      return;
    }
    
    tone(3, freq);
  }
  else{ 
    int freq = analogRead(A7);
    freq -= 512;
    freq = abs(freq);
    freq = map(freq,0,512,1000,4000);
    if(lastFreq == freq) return;
    if(freq == 6000) return;


    Serial.print("Freq: ");
    Serial.println(freq);
    tone(3, freq);
    delay(10);

    lastFreq = freq;
  }
}
