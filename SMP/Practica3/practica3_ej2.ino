#define BOTON_1 2
#define BOTON_2 3
#define BOTON_3 7
#define PIN_PWD 9
#include <Servo.h>

uint8_t cont_grado;
bool Pulsado1, Pulsado2, Pulsado3;
Servo Miservo;

void setup()
{
	pinMode(BOTON_1, INPUT_PULLUP);
	pinMode(BOTON_2, INPUT_PULLUP);
  pinMode(BOTON_3, INPUT_PULLUP);

  pinMode(PIN_PWD, OUTPUT);
  Serial.begin(9600);
  cont_grado = 0;
	Pulsado1 = Pulsado2 = Pulsado3 = false;

  analogWrite(PIN_PWD, cont_grado);
	Miservo.attach(9);
}

bool comprueba_pulsacion( unsigned int boton, bool &PulsadoAnt){
  bool Pulsado = !digitalRead(boton);
  bool out = false;

  if( !PulsadoAnt && Pulsado){
    out = true;
  }

  PulsadoAnt = Pulsado;

  return out;
}

void loop()
{
  if(comprueba_pulsacion(BOTON_1, Pulsado1)){
    if(cont_grado != 180)
      cont_grado+=30;
    else
      Serial.println("Angulo maximo alcanzado");

    Serial.println(cont_grado);
    Miservo.write(cont_grado);
  }

  if(comprueba_pulsacion(BOTON_2, Pulsado2)){
		if(cont_grado != 0)
      cont_grado-=30;
    else
      Serial.println("Angulo minimo alcanzado");

    Serial.println(cont_grado);
    Miservo.write(cont_grado);
  }

  if(comprueba_pulsacion(BOTON_3, Pulsado3)){
		int aux = cont_grado;


		if(aux > 0){
			for(int i = aux; i >= 0; i--){
				delay(10);
				Miservo.write(i);
			}
          	delay(1000);
			for(int i = 0; i <= aux; i++){
				delay(10);
				Miservo.write(i);
			}
		}
  }

}
