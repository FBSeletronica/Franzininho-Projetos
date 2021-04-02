
/*
Autor : Halysson Junior 
Data : 02/04/21

Exemplo de PIR

    Nesse exemplo vamos realizar a leitura do PIR - "Passive Infrared" ou Sensor Infravermelhor Passivo
    mostrando seu estado no terminal. Pode ser alterado o nível lógico com o jumper na lateral do sensor.
    
    Datasheet : https://cdn-learn.adafruit.com/downloads/pdf/pir-passive-infrared-proximity-motion-sensor.pdf  
 */


/* Inclusão arquivos de cabeçalho*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

/*Definição dos Pinos*/
#define PIR 15
#define LED 2

void app_main(void) // Main
{
   /* INPUT*/ 
   gpio_pad_select_gpio(PIR);
   gpio_set_direction(PIR, GPIO_MODE_INPUT);

 bool last_state_PIR = 0; // Armazena o último estado do PIR
  
  for(;;){ // Loop 
    
    bool state_PIR = gpio_get_level(PIR);
    
     if(state_PIR && last_state_PIR != state_PIR){  // Se for acionado como HIGH
        ESP_LOGI("[INFO]","PIR ATIVO");             // Mostra o 
     }

     last_state_PIR = state_PIR;                    // Guada o último valor do PIR
     vTaskDelay(1);                                 // Delay 1ms
    
    }// endLoop

}// end