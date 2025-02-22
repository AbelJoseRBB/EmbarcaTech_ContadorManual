// Desenvolvido por Abel José Rocha Barros Bezerra

#include <stdio.h>
#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "./Bibliotecas/led_matriz.h"
#include "./Bibliotecas/contador.h"
#include "hardware/clocks.h"
#include "pio_matrix.pio.h"

#define pin_red 13 
#define botaoA  5   
#define botaoB  6

double inicio[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

int i = 0; // Váriavel global contadora

// Variáveis globais para sinalizar o pressionamento dos botões
volatile bool botaoA_press = false;
volatile bool botaoB_press = false;

// Função para tratar da interrupções e debouncing em ambos os botões
void button_isr(uint gpio, uint32_t events){
    static absolute_time_t last_press = 0;
    absolute_time_t now = get_absolute_time();

    // Verifica se o intervalo de ativação é maior que 200ms (debouncing)
    if(absolute_time_diff_us(last_press, now) > 200000){
        if(gpio == botaoA){
            if(!gpio_get(botaoA))  // Verifica se o botão A está pressionado
                botaoA_press = true; // Sinaliza que o botão A foi pressionado
        }else{
            if(gpio == botaoB){
                if(!gpio_get(botaoB)) // Verifica se o botão  está pressionado 
                    botaoB_press = true; // Sinaliza que o botão B foi pressionado
            } 
        }
        last_press = now; // Atualiza o tempo do último acionamento 
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
    sleep_ms(100);
    gpio_put(pin_red, 0);   
    sleep_ms(100);
}

int main()
{
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    stdio_init_all();
    inicializar_pinos();

    desenho_pio(inicio, pio, sm, 1.0, 0.0, 1.0);

    while (true) {

        piscar_led_vermelho(); // Pisca o LED vermelho 5x por segundo

        if(botaoA_press){   // Garante que o botão A foi pressionado
            botaoA_press = false; 
            printf("Botão A pressionado\n");
            i++;

            // Garante que o contador não passe do valor máximo
            if(i > 9){    
                printf("Número não suportado\n");
                i--;
            }
 
            contador(i, pio, sm); // Chama a função que confere o valor do contador e imprime ele na matriz de LED
        }else{
            if(botaoB_press){   // Garante que o botão B foi pressionado
                printf("Botão B pressionado\n");
                botaoB_press = false; 
                i--;

                // Garante que o contador não passe do valor mínimo
                if(i < 0){
                    printf("Número não suportado\n");
                    i++;
                }

                contador(i, pio, sm); // Chama a função que confere o valor do contador e imprime ele na matriz de LED
            }
        }
    }
}
