
## Descrição do Código

O código realiza as seguintes operações:

1. **Controle de LEDs**:
    - **Botão A**: Acende todos os LEDs com a cor azul (100% de intensidade).
    - **Botão B**: Desliga todos os LEDs.
    - **Joystick**: Aciona uma animação de LEDs azuis, fazendo com que os LEDs pisquem um a um.

2. **Configuração de GPIO**:
    - O código configura três pinos de entrada (para botões e joystick) usando resistores pull-up internos.

3. **Controle do Buzzer**:
    - O buzzer é configurado (se necessário no futuro) com o pino 10.

## Problemas Conhecidos

Este código contém vários erros que precisam ser corrigidos no futuro, tais como:

- **Erro de definição de pino para os botões**: A linha `define BUTTON_A_PIN 5` está incorreta, o correto seria `#define BUTTON_A_PIN 5`.
- **Função `ws2812_put_pixel`**: A função não está corretamente implementada para controlar os LEDs, é necessário revisar a função para garantir que ela controle corretamente a matriz de LEDs.
- **Função `rgb_to_uint32`**: A função `rgb_to_uint32` não está implementada no código, precisa ser criada para converter as cores RGB em valores inteiros para os LEDs.

Esses erros devem ser corrigidos antes de rodar o código corretamente.

## Dependências

- **pico/stdlib.h**: Biblioteca padrão do Raspberry Pi Pico.
- **hardware/gpio.h**: Biblioteca para controle de GPIOs.
- **ws2812.h**: Biblioteca para controlar LEDs WS2812.

## Como Usar

Este código precisa ser compilado e carregado no seu Raspberry Pi Pico. Para compilar, utilize o CMake para configurar o ambiente de build e o SDK do Pico.

*Nota*: O processo de compilação não está detalhado neste README, pois já foi configurado o arquivo `CMakeLists.txt`.


