#  Examplo Input 

Acionamento do LED on board por meio de um botão tátcil na configuração pullup (acionamento LOW - 0). Neste projeto utilizou-se um resistor externo de 10k ohm, contudo o usuário pode substituir a topologia do circuito sugerido e utilizar os resistores internos pullup ou pulldown e consequentimento haverá mudanças na lógica de acionamento do LED on board.

## Como usar o exemplo

Após o projeto configurado e realizado a build, garanta que realizou a seleção do chip correto usando : `idf.py set-target <chip_name>`

### Hardware Necessários

* Uma placa de desenvolvimento ESP32/ESP32-S2/ESP32-C3 SoC (por exemplo, Franzininho WiFi, ESP32-DevKitC, ESP-WROVER-KIT, etc.)
* Um cabo USB para alimentação e programação


Algumas placas de desenvolvimento usam um LED endereçavel internamente na placa. Abaixo estão as placas de desenvolvimento que possuem:
| Placa                | Tipo de LED          | Pino                 |
| -------------------- | -------------------- | -------------------- |
| ESP32-WROOM- DevKit-1| Não Endereçado       | GPIO2                |
| Franzininho WiFi     | Endereçado           | GPIO18               |
| ESP32-C3-DevKitC-1   | Endereçado           | GPIO8                |
| ESP32-C3-DevKitM-1   | Endereçado           | GPIO8                |
| ESP32-S2-DevKitM-1   | Endereçado           | GPIO18               |
| ESP32-S2-Saola-1     | Endereçado           | GPIO18               |

Veja em [Development Boards](https://www.espressif.com/en/products/devkits) para mais informações.

### Configuração do Projeto

Baixe o exemplo na sua máquina e abra o arquivo no Visual Studio Code. É necessário
que o usuário tenha instalado a extensão da ESPRESSIF, caso não acesse esse link : https://www.youtube.com/watch?v=rxMg_zxO0q0 .
Abra o no menu de configuração do projeto (`idf.py menuconfig`).


### Build e Flash
Após configurado do seu projeto, selecione a porta de comunicação por meio do comando : `idf.py -p PORT flash monitor` 
para realizar a build, flash (gravar) e abrir o monitor serial do projeto.


## Problemas

* Primeramente volte a sessão "Configuração do Projeto"
* Segundamente verifique as GPIO do seu projeto e a topologia do circuito realizar no exemplo.
