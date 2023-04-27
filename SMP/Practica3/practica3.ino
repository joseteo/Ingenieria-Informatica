#define BOTON_1 2
#define BOTON_2 3
#define BOTON_3 7
#define PIN_IZDA 4
#define PIN_DER 5
#define PIN_PWD 6

uint8_t cont_vel;
bool sentido;
bool Pulsado1, Pulsado2, Pulsado3, PulsadoAnt1;
bool motor_on;


void setup()
{
	pinMode(BOTON_1, INPUT_PULLUP);
	pinMode(BOTON_2, INPUT_PULLUP);
  pinMode(BOTON_3, INPUT_PULLUP);

  pinMode(PIN_IZDA, OUTPUT);
  pinMode(PIN_DER, OUTPUT);
  pinMode(PIN_PWD, OUTPUT);
  Serial.begin(9600);
  cont_vel = 0;
  sentido = false;
	Pulsado1 = Pulsado2 = Pulsado3 = PulsadoAnt1 = false;

  digitalWrite(PIN_IZDA, sentido);
  digitalWrite(PIN_DER, !sentido);
  analogWrite(PIN_PWD, cont_vel);
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
    if(cont_vel == 0)
      cont_vel=85;
    else
      cont_vel=0;

    Serial.println("PULSADO BOTON 1");
    Serial.println(cont_vel);
    analogWrite(PIN_PWD, cont_vel);
  }

  if(comprueba_pulsacion(BOTON_2, Pulsado2)){
    sentido = !sentido;

    Serial.println("PULSADO BOTON 2");
    Serial.println(sentido);
    digitalWrite(PIN_DER, !sentido);
    digitalWrite(PIN_IZDA, sentido);
  }

  if(comprueba_pulsacion(BOTON_3, Pulsado3)){
    if(cont_vel == 255)
      cont_vel=85;
    else
      cont_vel+=85;

    Serial.println("PULSADO BOTON 3");
    Serial.println(cont_vel);
    analogWrite(PIN_PWD, cont_vel);
  }

}
