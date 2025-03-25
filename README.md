# Exemplo de Uso do FreeRTOS na BitDogLab

Este repositório contém exemplos de uso do FreeRTOS na placa BitDogLab (Raspberry Pi Pico W). Cada exemplo está em uma branch separada para facilitar o entendimento e a organização.

## Requisitos

- Placa BitDogLab (Raspberry Pi Pico W)
- SDK do Raspberry Pi Pico versão 1.5.1 configurado
- FreeRTOS integrado ao ambiente de desenvolvimento (baixe o código no [FreeRTOS](https://freertos.org/) e configure a variável de ambiente `FREERTOS_KERNEL_PATH`)
- Compilador compatível (ex.: GCC para ARM)

## Exemplos Disponíveis

### 1. Blink
- **Descrição:** Faz o LED azul da placa piscar usando uma única tarefa do FreeRTOS.
- **Conceito:** Demonstra o uso básico de tarefas em um sistema de tempo real.
- **Arquivo:** [`blink.c`](https://github.com/otaviossousa/FRTOS_Blink/blob/blink/blink.c)
- **Branch:** [blink](https://github.com/otaviossousa/FRTOS_Blink/tree/blink)

### 2. Multitasking
- **Descrição:** Utiliza duas tarefas para alternar o piscar de dois LEDs na placa.
- **Conceito:** Introdução ao multitarefa no FreeRTOS.
- **Arquivo:** [`multitasking.c`](https://github.com/otaviossousa/FRTOS_Blink/blob/multitasking/multitasking.c)
- **Branch:** [multitasking](https://github.com/otaviossousa/FRTOS_Blink/tree/multitasking)

### 3. Queue
- **Descrição:** Implementa uma fila (queue) para transferir dados entre tarefas:
  - Uma tarefa lê a temperatura do sensor interno e armazena na fila.
  - Outra tarefa calcula a média das temperaturas armazenadas e imprime o resultado.
- **Conceito:** Demonstra a comunicação entre tarefas utilizando filas no FreeRTOS.
- **Arquivo:** [`queue.c`](https://github.com/otaviossousa/FRTOS_Blink/blob/queue/queue.c)
- **Branch:** [queue](https://github.com/otaviossousa/FRTOS_Blink/tree/queue)

### 4. Semáforo
- **Descrição:** 
  - Uma Interrupção de Serviço (ISR), gerada pelo pressionamento do botão, sinaliza um evento via semáforo.
  - Uma tarefa aguarda o evento do semáforo para acionar o LED.
- **Conceito:** Ilustra a sincronização de eventos entre uma ISR e tarefas usando semáforos.
- **Arquivo:** [`semaforo.c`](https://github.com/otaviossousa/FRTOS_Blink/blob/semaforo/semaforo.c)
- **Branch:** [semaforo](https://github.com/otaviossousa/FRTOS_Blink/tree/semaforo)

### 5. Mutex
- **Descrição:** Duas tarefas compartilham o acesso a um contador utilizando um mutex para evitar condições de disputa.
- **Conceito:** Mostra como proteger recursos compartilhados entre tarefas usando mutexes no FreeRTOS.
- **Arquivo:** [`mutex.c`](https://github.com/otaviossousa/FRTOS_Blink/blob/mutex/mutex.c)
- **Branch:** [mutex](https://github.com/otaviossousa/FRTOS_Blink/tree/mutex)