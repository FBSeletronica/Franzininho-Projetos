/* 
Autor : Halysson Junior
Data 31/03/21

*//* Exemplo de Input
    Nesse exemplo ao pressionar  botão táctil o LED_ONBOARD é acionado e mostra no terminal. Na montagem do circuito foi utilizado um resistor de 
   pullup externo. 
    Caso o usário deseje acionar os resistores de pullup(I) ou pulldown(II) internos, só descomentar o que deseja utilizar.
 */


/* Inclusão arquivos de cabeçalho*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"
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
 
 /* Habilita pullup*/
  gpio_pullup_en(BTN);
  gpio_pulldown_dis(BTN); 

 ESP_LOGI("[INFO]", "INICIANDO CONTADOR FRANZININHO");


 /* Habilita pulldown
 gpio_pulldown_en(BTN);
 gpio_pullup_dis(BTN);
 */


      
unsigned int counter = 0;
bool last_state_btn = 0;
    while (1) { // Loop
     
  
      bool state_btn = gpio_get_level(BTN); // Leitura do botão
      
      if(!state_btn && !last_state_btn) {last_state_btn = 1;}
      
      else if(state_btn && last_state_btn) {
        counter ++;
         ESP_LOGI("Contador ", " %d", counter);// Mostra informação no monitor "LED LIGADO"
        last_state_btn = 0;
      }
      vTaskDelay(1); // Delay 1 ms
    
    }// endLoop

}// endMain