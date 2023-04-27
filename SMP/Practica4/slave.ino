#include<Wire.h>

#define DIRECC_I2C 3

#define PIN_DISPARADOR 5
#define PIN_ECO 4
#define TIMEOUT_ECO 23200 // <anchura máxima del pulso generado por el módulo>

uint16_t cm; // Variable global para almacenar la distancia medida

unsigned long leeDistancia(uint8_t triggerPin, uint8_t ecoPin)
{
	delayMicroseconds(2); // Por seguridad
	digitalWrite(triggerPin, HIGH); // Activa el trigger 10 us
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
	return pulseIn(ecoPin, HIGH, TIMEOUT_ECO); // Lee la anchura del pulso en us
}

void callback_peticion_i2c()
{
cm = leeDistancia(PIN_DISPARADOR, PIN_ECO) / 58; // Función que se llamará repetidamente para actualizar la distancia medida
	uint8_t b[2];
	b[0]=lowByte(cm); // cm & 0xFF;
	b[1]=highByte(cm); // (cm & 0xFF00) >> 8
	Wire.write(b, 2);
}

void setup()
{
	pinMode(PIN_DISPARADOR, OUTPUT);
	pinMode(PIN_ECO, INPUT);
    digitalWrite(PIN_DISPARADOR, LOW);
  
	Wire.begin(DIRECC_I2C);
	Wire.onRequest(callback_peticion_i2c);
}

void loop(){}
