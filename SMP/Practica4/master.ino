#include<Wire.h>
#include<LiquidCrystal.h>

#define DIRECC_I2C_ESCLAVO 3

#define PIN_RS 12
#define PIN_EN 11
#define PIN_D4 5
#define PIN_D5 4
#define PIN_D6 3
#define PIN_D7 2


LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7);

void leer_esclavo()
{
	int cm1, cm2;
  	Wire.requestFrom(DIRECC_I2C_ESCLAVO, 2);
	cm1 = Wire.read();
	cm2 = Wire.read();

	if(cm1 != -1 && cm2 != -1) // Lectura correcta
	{
		uint16_t cm;
		cm = (cm2 << 8) + cm1;
		// Imprimimos el numero de centímetros en la LCD
		lcd.print(cm, DEC);
		lcd.print(" cm");
	}
	else // Lectura errónea
	{
		lcd.print("ERROR al leer");
	}
}

void setup()
{
	Wire.begin();
	lcd.begin(16, 2);
}

void loop()
{
delay(500);
lcd.clear();
lcd.print("J.T.L.V 31/03/21  ");
lcd.setCursor(0,1);
leer_esclavo();
}
