#include <stdio.h>
#include "FreeRtos.h"
#include "task.h"
#include "freertos/timers.h"

void *const timer_id;
TimerHandle_t timer_handle;
void task3(void *params)
{
    timer_handle = xTimerCreate("timer",(10000 / portTICK_PERIOD_MS),pdFALSE,timer_id, callback);

    xTimerStart(my_timer_handle, 1);
    while (1)
    {
        printf("task3\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
void callback(TimerHandle_t xTimer)
{
    printf("Callback\n");
}


TaskHandle_t Task1Handle = NULL;
TaskHandle_t Task2Handle = NULL;
TaskHandle_t Task3Handle = NULL;
TaskHandle_t Task4Handle = NULL;
TaskHandle_t Task5Handle = NULL;

void Task1(void *p){
int count=0;
while(1){
   printf("hello:%d\n",count++);
   vTaskDelay(1000 / portTICK_PERIOD_MS);
}

}
void Task2(void *p){
int count=0;
while(1){
   printf("hello WORLD:%d\n",count++);
   vTaskDelay(2000 / portTICK_PERIOD_MS);
}

}
void Task3(void *p){
int count=0;
while(1){
   printf("HII:%d\n",count++);
   vTaskDelay(5000 / portTICK_PERIOD_MS);
}

}




 int main(void)
{
    xTaskCreate(Task1,"task1",200,(void*)0,tskIDLE_PRIORITY,&Task1Handle);
     xTaskCreate(Task2,"task2",400,(void*)0,tskIDLE_PRIORITY,&Task2Handle);
 xTaskCreate(Task3,"task3",200,(void*)0,tskIDLE_PRIORITY,&Task3Handle);
  
    vTaskStartScheduller();
    while(1)
    {
        /* code */
    }
    
    return 0;
}