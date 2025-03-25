// Branch: mutex 

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "semphr.h"

const uint LED_PIN_RED = 13;
const uint LED_PIN_BLUE = 12;

SemaphoreHandle_t xMutex;
int sharedCounter = 0;

void vTask1(void *pvParameters)
{
    for (;;)
    {
        // protege região critica
        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
        {
            sharedCounter++;
            printf("Task 1: Counter = %d\n", sharedCounter);
            xSemaphoreGive(xMutex);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        // protege região critica
        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
        {
            sharedCounter++;
            printf("Task 2: Counter = %d\n", sharedCounter);
            xSemaphoreGive(xMutex);
        }
        vTaskDelay(700 / portTICK_PERIOD_MS);
    }
}


int main() 
 {
    stdio_init_all();
    xMutex = xSemaphoreCreateMutex();

    if (xMutex != NULL)
    {
        xTaskCreate(vTask1, "Task 1", 256, NULL, 1, NULL);
        xTaskCreate(vTask2, "Task 2", 256, NULL, 1, NULL);
        vTaskStartScheduler();
    }
    
    while (1)
    {
        ;
    }
    
    return 0;
}