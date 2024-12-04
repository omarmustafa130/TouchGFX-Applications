/*
 * myfile.c
 *
 *  Created on: Nov 20, 2024
 *      Author: Omarm
 */

#include "main.h"
#include "myfile.h"
#include "cmsis_os.h"
#include "task.h"
#include "queue.h"
#include <stdbool.h>

// Function prototypes
void StartLEDTask(void *argument);
void LEDTask_Init(void);
void LEDQueue_Init(void);

// Task and Queue Handles
osThreadId_t LEDTaskHandle;
osMessageQueueId_t LEDQueueHandle;

// Thread attributes
const osThreadAttr_t LEDTask_attributes = {
    .name = "LEDTask",
    .stack_size = 512 * 4,
    .priority = osPriorityNormal,
};

// Queue attributes
const osMessageQueueAttr_t LEDQueue_attributes = {
    .name = "LEDQueue"
};

// Initialize the LED Task
void LEDTask_Init(void)
{
    LEDTaskHandle = osThreadNew(StartLEDTask, NULL, &LEDTask_attributes);
}

// Initialize the LED Queue
void LEDQueue_Init(void)
{
    LEDQueueHandle = osMessageQueueNew(1, sizeof(bool), &LEDQueue_attributes);
}

// LED Task Implementation
void StartLEDTask(void *argument)
{
    bool LEDState = false; // Match the type being sent from Model::LED_Control

    // Infinite loop
    for (;;)
    {
        if (osMessageQueueGetCount(LEDQueueHandle) > 0)
        {
            if (osMessageQueueGet(LEDQueueHandle, &LEDState, NULL, 0) == osOK)
            {
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, LEDState ? GPIO_PIN_SET : GPIO_PIN_RESET);
            }
        }
        osDelay(10); // Delay to reduce task execution rate
    }
}
