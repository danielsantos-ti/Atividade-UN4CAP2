#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "ws2812.h"

// Definições dos pinos
#define LED_PIN 7            // Pino para a matriz de LEDs (WS2812)
#define BUZZER_PIN 10        // Pino para o buzzer
#define BUTTON_A_PIN 5       // Pino para o botão A
#define BUTTON_B_PIN 6       // Pino para o botão B
#define JOYSTICK_BUTTON_PIN 22 // Pino para o botão do joystick

// Número de LEDs na matriz (5x5)
#define LED_COUNT 25

// Função para converter RGB para uint32
uint32_t rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b) {
    return (r << 16) | (g << 8) | b;
}

// Função para configurar todos os LEDs para uma cor específica
void set_color(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < LED_COUNT; i++) {
        ws2812_put_pixel(rgb_to_uint32(r, g, b));
    }
}

// Função para desligar todos os LEDs
void turn_off_leds() {
    for (int i = 0; i < LED_COUNT; i++) {
        ws2812_put_pixel(0); // Desliga o LED (preto)
    }
}

// Função para animar os LEDs acendendo-os um por um
void animate_leds() {
    for (int i = 0; i < LED_COUNT; i++) {
        ws2812_put_pixel(rgb_to_uint32(0, 0, 255));  // Azul
        sleep_ms(100);  // Delay entre os LEDs
    }
}

int main() {
    stdio_init_all();

    // Inicializa os GPIOs
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);

    gpio_init(JOYSTICK_BUTTON_PIN);
    gpio_set_dir(JOYSTICK_BUTTON_PIN, GPIO_IN);
    gpio_pull_up(JOYSTICK_BUTTON_PIN);

    // Inicializa o controlador WS2812
    ws2812_init(LED_PIN);

    // Inicializa o buzzer (se necessário no futuro)
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    while (1) {
        // Verifica o estado dos botões e do joystick
        if (!gpio_get(BUTTON_A_PIN)) {  // Botão A pressionado
            set_color(0, 0, 255);  // Todos os LEDs ficam azuis (100% de intensidade)
        } else if (!gpio_get(BUTTON_B_PIN)) {  // Botão B pressionado
            turn_off_leds();  // Desliga todos os LEDs
        } else if (!gpio_get(JOYSTICK_BUTTON_PIN)) {  // Joystick pressionado
            animate_leds();  // Animação: acende LEDs um a um
        }

        sleep_ms(50);  // Debounce
    }

    return 0;
}
