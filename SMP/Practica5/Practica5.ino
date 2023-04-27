#include<Wire.h>
#include<LiquidCrystal.h>

#define PIN_INT_CODIF 2
#define BOTON 3

bool Pulsado, PulsadoAnt;
LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7);

void setup(){
  pinMode(BOTON, INPUT_PULLUP);
  Pulsado=false;
}

bool comprueba_pulsacion( unsigned int boton, bool &PulsadoA){
  bool Pul = !digitalRead(boton);
  bool out = false;

  if( !PulsadoA && Pul){
    out = true;
  }

  PulsadoA = Pul;

  return out;
}

void loop(){
  delay(500);

  if(comprueba_pulsacion(BOTON, Pulsado)){
    if(cont_vel == 0)
      cont_vel=85;
    else
      cont_vel=0;

    Serial.println("PULSADO BOTON");
    Serial.println(cont_vel);
    analogWrite(PIN_PWD, cont_vel);
  }


}
