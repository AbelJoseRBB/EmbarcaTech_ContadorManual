#include "../Bibliotecas/led_matriz.h"

uint32_t matrix_rgb(double r, double g, double b) {
    unsigned char R = r * 255;
    unsigned char G = g * 255;
    unsigned char B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

void limpar_todos_leds(PIO pio, uint sm) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 0.0, 0.0));
    }
}

void acender_leds(PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        pio_sm_put_blocking(pio, sm, matrix_rgb(b, r, g));
    }
}

// Função para desenhar a matriz
void desenho_pio(double *desenho, PIO pio, uint sm, double r, double g, double b){
    for(int16_t i = 0; i < NUM_PIXELS; i++){
        pio_sm_put_blocking(pio, sm, matrix_rgb(desenho[i] * r, desenho[i] * g, desenho[i] * b));
    }   
}

