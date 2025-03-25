#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>


const uint LED_PIN_RED = 12;

void vBlinkTask()
{
    for (;;)
    {
        gpio_put(LED_PIN_RED, 1);
        vTaskDelay(500);
        gpio_put(LED_PIN_RED, 0);
        vTaskDelay(500);
        printf("Blinking\n");
    }

}

int main() 
 {
    stdio_init_all();
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    xTaskCreate(vBlinkTask, "Blink", 128, NULL, 1, NULL);
    vTaskStartScheduler();
}