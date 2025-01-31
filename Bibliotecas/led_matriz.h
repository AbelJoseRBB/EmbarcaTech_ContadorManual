#ifndef LED_MATRIZ_H
#define LED_MATRIZ_H

#include "hardware/pio.h"

#define NUM_PIXELS 25
#define OUT_PIN 7

uint32_t matrix_rgb(double r, double g, double b);
void limpar_todos_leds(PIO pio, uint sm);
void acender_leds(PIO pio, uint sm, double r, double g, double b);
void desenho_pio(double *desenho, PIO pio, uint sm, double r, double g, double b);

#endif // LED_MATRIX_H