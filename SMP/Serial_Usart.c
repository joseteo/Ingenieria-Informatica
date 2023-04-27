#include <avr/io.h>
#include <util/delay.h>

int dato;

void InitUART( unsigned char baudrate ) {    //Configurando la UART

  UBRRL = baudrate;                          //Seleccionando la velocidad

  UCSRB = (UCSRB | _BV(RXEN) | _BV(TXEN));  //Habilitando la transmisión y recepción
}

unsigned char ReceiveByte( void ){          //Función para recibir un byte

  while ( !(UCSRA &(1 << RXC)) );           //Esperar la recepción

  return UDR;                               //Retornar el dato tomado de la UART
}

void TransmitByte( unsigned char data )     //Funcion para transmitir dato

  while ( !( UCSRA &(1 << UDRE)) );        //Esperar transmision completa
  UDR = data;                             //Depositar el dato para transmitirlo
}

int main (void) {
 InitUART( 51 );                          //Inicializar la UART

 while(1){
   dato=ReceiveByte();                    //Recibir un dato de la UART
   TransmitByte(dato);                    //Mandar el mismo dato
 }
}
