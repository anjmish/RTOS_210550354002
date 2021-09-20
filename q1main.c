
#include <stdio.h>
#include "FreeRtos.h"
#include "task.h"
#include "freertos/queue.h"

QueueHandle_t intmq;

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
void Task4(void *p){
int count=0;
while(1){
   printf("BYEE:%d\n",count++);
   vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}
void Task5(void *p){
int count=0;
while(1){
   printf("GOOD DAY:%d\n",count++);
   vTaskDelay(1000 / portTICK_PERIOD_MS);
}



 int main(void)
{
    xTaskCreate(Task1,"task1",200,(void*)0,tskIDLE_PRIORITY,&Task1Handle);
     xTaskCreate(Task2,"task2",400,(void*)0,tskIDLE_PRIORITY,&Task2Handle);
 xTaskCreate(Task3,"task3",200,(void*)0,tskIDLE_PRIORITY,&Task3Handle);
  xTaskCreate(Task4,"task4",200,(void*)0,tskIDLE_PRIORITY,&Task4Handle);
   xTaskCreate(Task5,"task5",200,(void*)0,tskIDLE_PRIORITY,&Task5Handle);
    vTaskStartScheduller();
    intmq = xQueueCreate(3, sizeof(int));

    
    return 0;
}

