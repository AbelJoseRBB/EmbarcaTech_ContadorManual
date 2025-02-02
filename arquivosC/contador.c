#include "../Bibliotecas/contador.h"

// Define a matriz do número 0
double num0[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Define a matriz do número 1
double num1[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0
};

// Define a matriz do número 2
double num2[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Define a matriz do número 3
double num3[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Define a matriz do número 4
double num4[25] = {
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0
};

// Define a matriz do número 5
double num5[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Define a matriz do número 6
double num6[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Define a matriz do número 7
double num7[25] = {
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Define a matriz do número 8
double num8[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Define a matriz do número 9
double num9[25] = {
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0
};

// Função que confere e imprime o valor do contador na matriz de LED
void contador(int cont, PIO pio, uint sm){
    switch (cont){
        case 0: desenho_pio(num0, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 1: desenho_pio(num1, pio, sm, 1.0, 0.0, 1.0);
                break;       
        case 2: desenho_pio(num2, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 3: desenho_pio(num3, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 4: desenho_pio(num4, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 5: desenho_pio(num5, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 6: desenho_pio(num6, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 7: desenho_pio(num7, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 8: desenho_pio(num8, pio, sm, 1.0, 0.0, 1.0);
                break;
        case 9: desenho_pio(num9, pio, sm, 1.0, 0.0, 1.0);
                break;
        default: printf("Número não suportado\n");
                break;
    }
}






