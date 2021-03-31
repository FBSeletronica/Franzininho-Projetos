/* Exemplo de Botão
    Nesse exemplo ao pressionar  botão táctil o LED_ONBOARD é acionado e mostra no terminal. */


/* Inclusão arquivos de cabeçalho*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

/* Definições de Pinos*/

#define BTN 15 
#define LED_ONBOARD 2 
#define HIGH 1
#define LOW 0

void app_main(void){  // Main


 /* OUTPUT*/
 gpio_pad_select_gpio(LED_ONBOARD);  
 gpio_set_direction(LED_ONBOARD,GPIO_MODE_OUTPUT);

/* INPUT*/
 gpio_pad_select_gpio(BTN);  
 gpio_set_direction(BTN,GPIO_MODE_INPUT);
 
 /* Habilita pulldown*/
 //gpio_pulldown_en(BTN);
 //gpio_pullup_dis(BTN);


/* Habilita pullup*/
  gpio_pullup_en(BTN);
  gpio_pulldown_dis(BTN) 
 

int last_state_btn = 0;       

    while (1) { // Loop
     
  
      int state_btn = gpio_get_level(BTN); // Leitura do botão
      
      if(!state_btn && !last_state_btn) {
          gpio_set_level(LED_ONBOARD,HIGH);// Se botão for zero então ... liga LED
          ESP_LOGI("[INFO]", "LED LIGADO");// Mostra informação no monitor "LED LIGADO"
          last_state_btn = 1;
      }
      
      else if(state_btn && last_state_btn){
        gpio_set_level(LED_ONBOARD,LOW);// Senão... desliga LED
         ESP_LOGI("[INFO]", "LED DESLIGADO"); // Mostra informação no monitor "LED DESLIGADO"
        last_state_btn = 0;
      }
      vTaskDelay(1); // Delay 1 ms
    
    }// endLoop

}// endMain