#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "pico/stdlib.h"

#define LED_PIN 12
#define BUTTON_PIN 5

SemaphoreHandle_t xButtonSemaphore;

void buttonISR(uint gpio, uint32_t events)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(xButtonSemaphore, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void vLedTask(void *pvParameters)
{
    for (;;)
    {
        if (xSemaphoreTake(xButtonSemaphore, portMAX_DELAY) == pdTRUE)
        {
            gpio_put(LED_PIN, 1); // Liga o LED
            vTaskDelay(500 / portTICK_PERIOD_MS);
            gpio_put(LED_PIN, 0); // Desliga o LED
        }
    }
}

void setup(void)
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}
int main()
{

    setup();
    
    xButtonSemaphore = xSemaphoreCreateBinary();
    if (xButtonSemaphore != NULL)
    {
        gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, buttonISR);
        xTaskCreate(vLedTask, "LED Task", 128, NULL, 1, NULL);
        vTaskStartScheduler();
    }

    while (1);
    return 0;
}