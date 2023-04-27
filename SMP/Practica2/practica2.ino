#define PIN_BOTON_1 2
#define PIN_BOTON_2 3

int pulsaciones;
bool Pulsado1, Pulsado2;
bool PulsadoAnt1, PulsadoAnt2;
// segmentos a activar para cada valor del digito
uint8_t tabla7seg[10]={0x3f,0x6,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};
// pines a utilizar para el display
uint8_t pines_display[7]={4,5,6,7,8,9,10};
uint8_t contador = 0;

void setup()
{
	pinMode(PIN_BOTON_1, INPUT);
	pinMode(PIN_BOTON_2, INPUT);
  pinMode(pines_display[0], OUTPUT);
  pinMode(pines_display[1], OUTPUT);
  pinMode(pines_display[2], OUTPUT);
  pinMode(pines_display[3], OUTPUT);
  pinMode(pines_display[4], OUTPUT);
  pinMode(pines_display[5], OUTPUT);
  pinMode(pines_display[6], OUTPUT);
	Serial.begin(9600);
	pulsaciones = 0;
	Pulsado1 = Pulsado2 = PulsadoAnt1 = PulsadoAnt2 = false;
}

void write_display(int num){
  for(int i = 0; i < 7; i++){
    digitalWrite(pines_display[i], bitRead( tabla7seg[num] , i));
  }
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
    write_display(pulsaciones);
	}

	if ( PulsadoAnt2 )
	{	if ( !digitalRead(PIN_BOTON_2) )
		{	Pulsado2=true;	}
		else PulsadoAnt2 = false;
	}
	else if( !digitalRead(PIN_BOTON_2) )
	{
		Pulsado2 = true;
    if( (pulsaciones-1) >= 0 ){
		  Serial.println(--pulsaciones);
      write_display(pulsaciones);
    }
	}

  pulsaciones%=9;
	if ( Pulsado1 ) PulsadoAnt1 = true;
	if ( Pulsado2 ) PulsadoAnt2 = true;
	Pulsado1 = Pulsado2 = false;
}
