/*
 * Codigo Emisor
 * 
 * Conexiones del Emisor:
 * -GND   - pin 5
 * -VCC   - pin 6
 * -DATA  - pin 7
 * 
*/

#include <VirtualWire.h>

const int gnd = 5;
const int vcc = 6;
const int data = 7;

void setup()
{
  Serial.begin(9600);  
  Serial.println("Emisor: Setup");

  //Se configura el pin para funcionar como VCC
  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);

  //Se configura el pin para funcionar como GND
  pinMode(gnd, OUTPUT);
  digitalWrite(gnd, LOW);

  // Se inicializa el RF
  vw_setup(2000); // velocidad: Bits por segundo
  vw_set_tx_pin(data); // Salida para el RF 
}

void loop()
{
    const char *msg = "Hola mundo";
 
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    delay(200);
}
