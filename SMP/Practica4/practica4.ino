//texto
#define PIN_DISPARADOR 5
#define PIN_ECO 4
#define TIMEOUT_ECO

uint16_t cm;
cm = leeDistancia(PIN_DISPARADOR, PIN_ECO) / 58;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin();
  int cm1, cm2;

  Wire.requestFrom
}

unsigned long leeDistancia(uint8_t triggerPin, uint8_t ecoPin){
 delayMicroseconds(2);
 digitalWrite(triggerPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(triggerPin, LOW);
 return pulseIn(ecoPin, HIGH, TIMEOUT_ECO);
}

void loop(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
