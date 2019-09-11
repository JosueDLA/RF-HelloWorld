/*
 * Codigo Receptor
 * 
 * Conexiones del Emisor:
 * -DATA  - pin 7
 * 
*/

#include <VirtualWire.h>

const int data = 7;

void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("Receptor: Setup");

    // Se inicializa el RF
    vw_setup(2000);  // velocidad: Bits per segundo
    vw_set_rx_pin(data);    //entrada del RF
    vw_rx_start();       // Se inicia como receptor
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    //verificamos si hay un dato valido en el RF
    if (vw_get_message(buf, &buflen)) {
      int i;
    
      //verificamos si hay un dato valido en el RF
      Serial.print("Mensaje: ");
      
      for (i = 0; i < buflen; i++)
      {
          Serial.print((char)buf[i]);
      }
      Serial.println("");
    }
}
