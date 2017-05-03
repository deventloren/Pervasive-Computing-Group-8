void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(0);

  analogValueAverage = 0.99*analogValueAverage + 0.01*analogValue;

  if(millis() > time + timeBetweenReadings){
    float load = analogToLoad(analogValueAverage);

    Serial.print("analogValue: ");Serial.println(analogValueAverage);
    Serial.print("             load: ");Serial.println(load,5);
    time = millis();
  }
}

float analogToLoad(float analogval){

  float load = mapfloat(analogval, analogvalA, analogvalB, loadA, loadB);
  return load;
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
}
