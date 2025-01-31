#include <stdio.h>
#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "./Bibliotecas/led_matriz.h"
#include "hardware/clocks.h"
#include "pio_matrix.pio.h"

#define pin_red 13
#define botaoA  5
#define botaoB  6

int i = 0;

// Variáveis globais para sinalizar o pressionamento dos botões
volatile bool botaoA_press = false;
volatile bool botaoB_press = false;

// Função para tratar da interrupções dem ambos os botões
void button_isr(uint gpio, uint32_t events){
    static absolute_time_t last_press = 0;
    absolute_time_t now = get_absolute_time();

    if(absolute_time_diff_us(last_press, now) > 100000){
        if(gpio == botaoA){
            if(!gpio_get(botaoA))  // Verifica se o botão A está pressionado
                botaoA_press = true; // Sinaliza que o botão A foi pressionado
        }else{
            if(gpio == botaoB){
                if(!gpio_get(botaoB)) // Verifica se o botão  está pressionado 
                    botaoB_press = true; // Sinaliza que o botão B foi pressionado
            } 
        }
        last_press = now;
    }
}

void inicializar_pinos(){
    // Inicializa e configura o botão A como pull up
    gpio_init(botaoA);
    gpio_set_dir(botaoA, GPIO_IN);
    gpio_pull_up(botaoA);

    // Configura a interrupção para o botão A
    gpio_set_irq_enabled_with_callback(botaoA,  GPIO_IRQ_EDGE_FALL, true, &button_isr);

    // Inicializa e configura o botão B como pull up
    gpio_init(botaoB);
    gpio_set_dir(botaoB, GPIO_IN);
    gpio_pull_up(botaoB);

    // Configura a interrupção para o botão B
    gpio_set_irq_enabled_with_callback(botaoB,  GPIO_IRQ_EDGE_FALL, true, &button_isr);

    // Inicializa o LED
    gpio_init(pin_red);
    gpio_set_dir(pin_red, GPIO_OUT);
}

// Pisca o LED vermelho 
void piscar_led_vermelho(){ 
    gpio_put(pin_red, 1);
    gpio_put(pin_red, 0);   
    sleep_ms(200);
}

double num0[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

double num1[25] = {
    0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

double num2[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

double num3[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

double num4[25] = {
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0
};

double num5[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

double num6[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

double num7[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0
};

double num8[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

double num9[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

int main()
{
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    stdio_init_all();

    inicializar_pinos();

    while (true) {

        if(botaoA_press){
            printf("Botão A pressionado\n");
            botaoA_press = false; // reseta a flag
            i = (i + 1) % 10;
        }else{
            if(botaoB_press){
                printf("Botão B pressionado\n");
                botaoB_press = false;
            i = (i - 1 + 10) % 10;
            }
        }
        switch (i){
        case 0:
            desenho_pio(num0, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 1:
            desenho_pio(num1, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 2:
            desenho_pio(num2, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 3:
            desenho_pio(num3, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 4:
            desenho_pio(num4, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 5:
            desenho_pio(num5, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 6:
            desenho_pio(num6, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 7:
            desenho_pio(num7, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 8:
            desenho_pio(num8, pio, sm, 1.0, 0.0, 1.0);
            break;
        case 9:
            desenho_pio(num9, pio, sm, 1.0, 0.0, 1.0);
            break;
        default: printf("Número não suportado!\n");
            break;
        }
    }
}
