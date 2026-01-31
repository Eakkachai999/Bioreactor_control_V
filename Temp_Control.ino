float setpointtemp = 25;  //setting the setpoint at here!

#define relay1 7  //circulate pump
#define relay2 2  //Heater
#include "max6675.h" //thermocople library
//-----------------------Temp Heater--------------------------------
int thermoDO = 8;
int thermoCS = 9;
int thermoCLK = 10;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
//-----------------------Temp Reactor--------------------------------
int thermoDO1 = 31; //blue
int thermoCS1 = 30; //purple
int thermoCLK1 = 32; //grey
MAX6675 thermocouple1(thermoCLK1, thermoCS1, thermoDO1);
//------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
}

void loop() {
  //--------------------Temp Read-----------------------------
  float TempHot = thermocouple.readCelsius(); //่พันเทปสีแดง
  Serial.print("Temp Heater Tank = ");
  Serial.println(TempHot);

  float TempReactor = thermocouple1.readCelsius(); //่พันเทปสีดำ
  Serial.print("Temp Reactor = ");
  Serial.println(TempReactor);

  //--------------------Temp Control-----------------------------
  float case1 = setpointtemp + 5;
  float case2 = setpointtemp+1;

  if (TempReactor < setpointtemp) {
    if (TempHot < case1) {
      digitalWrite(relay2, HIGH);
    }
    if (TempHot >= case1) {
      digitalWrite(relay2, LOW);
    }
  }
  if (TempReactor >= setpointtemp) {
    if (TempHot < case2) {
      digitalWrite(relay2, HIGH);
    }
    if (TempHot >= case2) {
      digitalWrite(relay2, LOW);
    }
  }
  delay(1000);//milisec
}
