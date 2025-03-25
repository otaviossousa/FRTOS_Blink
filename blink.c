// Branch: multitasking 

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>


const uint LED_PIN_RED = 13;
const uint LED_PIN_BLUE = 12;

void setup()
{
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
}

void vBlinkTask(void *pvParameters)
{
    uint *LED = (uint *)pvParameters;
    
    for (;;)
    {
        gpio_put(*LED, 1);
        vTaskDelay(250 / portTICK_PERIOD_MS);
        gpio_put(*LED, 0);
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}

int main() 
 {
    setup();
    
    xTaskCreate(vBlinkTask, "Blink Task 1", 128, (void *)&LED_PIN_RED, 1, NULL);
    xTaskCreate(vBlinkTask, "Blink Task 2", 128, (void *)&LED_PIN_BLUE, 1, NULL);
    
    vTaskStartScheduler();
    for (;;)
        ;
}