/* 
Autor : Halysson Junior
Data 31/03/21

 Exemplo de Input
    Nesse exemplo ao pressionar irá iniciar uma contagem indefinida e será mostrado
    os valores de contagem no terminal. Foi adotado a topologia utilizando resistor de pullup 
    interno da placa Franzininho Wi-Fi
 */


/* Inclusão arquivos de cabeçalho*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

/* Definições do Pino*/

#define BTN 15 


void app_main(void){  // Main

/* INPUT*/
 gpio_pad_select_gpio(BTN);  
 gpio_set_direction(BTN,GPIO_MODE_INPUT);
 
 /* Habilita pullup*/
  gpio_pullup_en(BTN);
  gpio_pulldown_dis(BTN); 

 /* Mensagem de inicialização*/
 ESP_LOGI("[INFO]", "INICIANDO CONTADOR FRANZININHO");


 /* Habilita pulldown*/
 //gpio_pulldown_en(BTN);
 //gpio_pullup_dis(BTN);
 


      
unsigned int counter = 0; // Variavel para receber o incremento após ser pressionar o botão
bool last_state_btn = 0; // Variável para auxiliar do botão
    
    while (1) { // Loop
     
      bool state_btn = gpio_get_level(BTN); // Leitura do botão
      
      if(!state_btn && !last_state_btn) {last_state_btn = 1;} // Se botão pressionado seta variável last_state_btn
      
      else if(state_btn && last_state_btn) { /* Botão pressionado e last_state_btn em 1, realiza a contagem
                                             e mostra no terminal o valor da contagem*/
        counter ++;
         ESP_LOGI("Contador ", " %d", counter);
        last_state_btn = 0; // Reseta a variável
      }
      vTaskDelay(1); // Delay 1 ms
    
    }// endLoop

}// endMain