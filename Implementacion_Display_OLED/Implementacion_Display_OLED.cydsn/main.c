/* ========================================
    U N I V E R S I D A D  D E  P A M P L O N A 
    FACULTAD DE INGENIERIA Y ARQUITECTURA
    SISTEMAS EMBEBIDOS I - 2024-1
    
    Autores:
    Kevin Andres Rios Trigos 
    Edwin Alexander Calderon Leal
    
    Tutor: 
    Ing. Julio Cesar Ospino Arias
   
 * ========================================
*/
#include "project.h"
//#include <stdlib.h>
#include "ssd1306.h"
#include "math.h"
#include "stdio.h"

#define DISPLAY_ADDRESS 0x3C // 0x3C, Es la direccion de registro del dispay OLED (ssd1306 - I2C 128x64)

int32 out;
char8 str[12];
float ADCVoltaje = 0;
//uint16 D;

int main(void) {
    
     
      CyGlobalIntEnable;              //Inicializamos la interrupciones Globales
    
      I2COLED_Start();                // Inicializamos la comunicacion I2C
   
      display_init(DISPLAY_ADDRESS);  // Inicializamos el dispay en la direccion de registro

      display_clear();                // Limpiamos el Display
      display_update();               // Actualizamos el Dispay
      gfx_setTextSize(1);             // Asignamos tamaño 1 a los textos a mostrar en la oled
      gfx_setTextColor(WHITE);        // Asignamos color blanco a los textos a mostar
    
      ADC_Start();                                  // Inicializamos el ADC
      ADC_StartConvert();                           // Inicializamos la convercion del ADC
      ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);     // Esparamos el resultado
    
    
    for(;;) {
        
        display_clear();                          // Limpiamos el display
        out = ADC_GetResult32();                  // Leemos el ADC 
        ADCVoltaje = ADC_CountsTo_mVolts(out);    // Convertimos la lectura del ADC a mV
        sprintf(str,"%.3f",ADCVoltaje);           // Convertimos la lectura en mV a Caracteres y guardamos en str

        gfx_setCursor(0,0);                       // Nos ubicamos en origen del display (0,0)
        gfx_print("SISTEMAS EMBEBIDOS I");        // Mostramos en el Diplay en la posicion
        gfx_drawLine(0, 10, 127, 10, WHITE);      // Trazamos una linea desde la posiscion (0,10) hasta (127, 10)
        gfx_setCursor(10,20);                     // Nos ubicamos en la posicion (10, 20)
        gfx_println("Volt = ");                   // Mostramos en el Diplay en la posicion
        gfx_setCursor(102,20);                    // Nos ubicamos en la posicion (102, 20)
        gfx_println("mV");                        // Mostramos en el Diplay en la posicion
        gfx_setCursor(48,20);                     // Nos ubicamos en la posicion (54, 20)
        gfx_print(str);                           // Mostramos en el dispay la variable str en la posicion
        
        display_update();                         // Actualizamos el Display 
        CyDelay(500);                             // Hacemos un retardo de 500 ms
       
    }
}


