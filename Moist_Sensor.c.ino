const int AirValue = 520;   //remplacer cette valeur avec Value_1
const int WaterValue = 260;  //remplacer cette valeur avec Value_2
int intervals = (AirValue - WaterValue)/3;
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600); // Port serial 9600 bps
}

/*
Sec: [520 430]
Mouillé: [430 350]
Très mouillé: [350 260]
*/

void loop() {

  soilMoistureValue = analogRead(A0);  //Lecture des valeurs

    if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
        {
        Serial.println("Très mouillé");
        }

        else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
            {
              Serial.println("Mouillé");
            }

              else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
                  {
                  Serial.println("Sec");
                  }

                  delay(100);
}
