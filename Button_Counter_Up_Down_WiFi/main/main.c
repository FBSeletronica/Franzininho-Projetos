/* Autor: Halysson Junior

Data: 01/04/21

Descrição: Exemplo utilizando dois botões para realizar a contagem para mais e para menos

*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"



#define BTN_UP    15
#define BTN_DOWN  4

#define HIGH      1
#define LOW       0

void configMCU(){
  
  /*Configura botão mais como entrada digital */  
 gpio_pad_select_gpio(BTN_UP);
 gpio_set_direction(BTN_UP,GPIO_MODE_INPUT);
 /*Habilita pullup interno*/
 gpio_pullup_en(BTN_UP);
 gpio_pulldown_dis(BTN_UP); 
 
 /*Configura botão mais como entrada digital*/
 gpio_pad_select_gpio(BTN_DOWN);
 gpio_set_direction(BTN_DOWN,GPIO_MODE_INPUT);
 
 /*Habilita pullup interno*/
 gpio_pullup_en(BTN_DOWN);
 gpio_pulldown_dis(BTN_DOWN); 

}

void app_main(void){ // Main


 configMCU();  // Função para configuração dos GPIO

 ESP_LOGI("[INFO]", "CONTADOR PARA CIMA E PARA BAIXO"); // Mostra informação no terminal
 
 bool isPress_BTN_UP = 0; // Flag de indicação de botão para cima
 bool isPress_BTN_DOWN = 0; // Flag de indicação de botão para baixo
 int counter = 0; // Variável de contagem
  
  for(;;){// Loop  
      
   bool state_btn_up = gpio_get_level(BTN_UP); // Leitura do botão mais
   bool state_btn_down = gpio_get_level(BTN_DOWN); // Leitura do botão menos

   
   if(!state_btn_up && isPress_BTN_UP!= state_btn_up){  // Mapemento do botão mais
       counter ++; 
       ESP_LOGI("Contador", " %d", counter); // Atualiza o valor de counter 
    }
   isPress_BTN_UP = state_btn_up; // Atualiza o estado BTN_UP
   
   
   if(!state_btn_down &&  isPress_BTN_DOWN!= state_btn_down){ // Mapemento do botão menos
       counter --; 
       ESP_LOGI("Contador", " %d", counter); // Atualiza o valor de counter 
    }
   isPress_BTN_DOWN = state_btn_down; // Atualiza o estado BTN_DOWN

   vTaskDelay(10); // Delay 1ms
  } 
}
