#define PIN_BOTON_1 2
#define PIN_BOTON_2 3

int pulsaciones;
bool Pulsado1, Pulsado2;
bool PulsadoAnt1, PulsadoAnt2;

void setup()
{
	pinMode(PIN_BOTON_1, INPUT);
	pinMode(PIN_BOTON_2, INPUT);
	Serial.begin(9600);
	pulsaciones = 0;
	Pulsado1 = Pulsado2 = PulsadoAnt1 = PulsadoAnt2 = false;
}

void loop()
{

	if ( PulsadoAnt1 )
	{	if ( !digitalRead(PIN_BOTON_1) )
		{	Pulsado1=true;	}
		else PulsadoAnt1 = false;
	}
	else if( !digitalRead(PIN_BOTON_1) ) 
	{
		Pulsado1 = true;
		Serial.println(++pulsaciones);
	}

	if ( PulsadoAnt2 )
	{	if ( !digitalRead(PIN_BOTON_2) )
		{	Pulsado2=true;	}
		else PulsadoAnt2 = false;
	}
	else if( !digitalRead(PIN_BOTON_2) ) 
	{
		Pulsado2 = true;
		Serial.println(++pulsaciones);
	}
	
	if ( Pulsado1 ) PulsadoAnt1 = true;
	if ( Pulsado2 ) PulsadoAnt2 = true;
	Pulsado1 = Pulsado2 = false;
}