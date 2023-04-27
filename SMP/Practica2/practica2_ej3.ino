#define PIN_BOTON_1 2
#define PIN_BOTON_2 3

int pulsaciones;
bool Pulsado1;
// segmentos a activar para cada valor del digito
uint8_t tabla7seg[10]={0x3f,0x6,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};
// pines a utilizar para el display
uint8_t pines_display[9]={4,5,6,7,8,9,10}, pin_multiplexor1={11}, pin_multiplexor2={12};
uint8_t contador = 0;
unsigned long myTime=0;
int var=0;

void setup()
{
	pinMode(PIN_BOTON_1, INPUT);
  pinMode(pines_display[0], OUTPUT);
  pinMode(pines_display[1], OUTPUT);
  pinMode(pines_display[2], OUTPUT);
  pinMode(pines_display[3], OUTPUT);
  pinMode(pines_display[4], OUTPUT);
  pinMode(pines_display[5], OUTPUT);
  pinMode(pines_display[6], OUTPUT);
	pinMode(pines_display[7], OUTPUT);
	pinMode(pines_display[8], OUTPUT);
	pinMode(pin_multiplexor1, OUTPUT);
	pinMode(pin_multiplexor2, OUTPUT);
	Serial.begin(9600);
	pulsaciones = 0;
}

void write_display(int num){
  for(int i = 0; i < 7; i++){
    digitalWrite(pines_display[i], bitRead( tabla7seg[num] , i));
  }

}

void write_dos_segmentos(int num){
	int decena = num / 10;
	int numero = num % 10;

	digitalWrite(pin_multiplexor1, HIGH);
	write_display(decena);
  	delay(25);
	digitalWrite(pin_multiplexor1, LOW);

	digitalWrite(pin_multiplexor2, HIGH);
	write_display(numero);
  	delay(25);
	digitalWrite(pin_multiplexor2, LOW);
}

void loop()
{

  	if( millis() >= myTime+1000){
		Serial.println(++pulsaciones);
      	myTime+=1000;
	}

	pulsaciones%=61;

  	if( !digitalRead(PIN_BOTON_1) ){
		pulsaciones=0;
	}

	write_dos_segmentos(pulsaciones);
}
