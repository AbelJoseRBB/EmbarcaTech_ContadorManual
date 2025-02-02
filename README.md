# EmbarcaTech_ContadorManual
Tarefa do EmbarcaTech que propôs a implementação de um contador crescente e decrescente de 0 a 9 na matriz de LED 5x5, utilizando interrupções e debouncing.

# Vídeo Explicativo
A seguir um vídeo explicativo sobre o projeto.

https://drive.google.com/file/d/1js-l0dfnZoypWCTZ0U_E-DoNhz-pgu75/view?usp=sharing

# Intruções
Para executar o código em questão, deve-se possuir a extensão Wokwi Simulator instalada no Visual Studio Code ou acesso a placa BitDogLab.

Ao iniciar o código o Botão A, botão de cor preta no Wokwi, irá incrementar de 0 a 9 um contador e irá imprimir estes na matriz de LED 5x5, ao contrário do botão B, botão de cor verde no Wokwi, que irá decrementar a partir do número presente. Ao mesmo tempo o led RGB de cor vermelha ficará piscando 5 vezes por segundo durante todo o processo.

# Composição do código
**ContadorManual.c**
- `button_isr(uint gpio, uint32_t events)`: Detecta e registra pressionamentos válidos dos botões A e B, evitando - - leituras incorretas devido a ruídos (debouncing).
- `inicializar_pinos()`: Prepara os pinos dos botões e do LED para uso, configurando entradas com interrupções e uma saída para controle do LED.
- `piscar_led_vermelho()`: Ativa e desativa o LED num intervalo de 200ms, permintido que ele pisque 5 vezes por segundo
- `main()`: Lógica que confere qual botão foi pressionado e incrementa ou decrementa o número da matriz de LED 5x5

**contador.c**
- `contador(int cont, PIO pio, uint sm)`: Lógica de conferência do valor presente em contador para visualização na matriz de LED

**led_matriz.c**
- `matrix_rgb(double r, double g, double b)`: Converte valores RGB em um valor de 32 bits no formato específico da matriz.
- `desenho_pio(double *desenho, PIO pio, uint sm, double r, double g, double b)`: Lógica para desenhar o número na matriz de LED 5x5

# Desenvolvedor
Abel José Rocha Barros Bezerra
