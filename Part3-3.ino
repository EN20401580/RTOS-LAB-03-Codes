
void Task1(void *parameter);
void Task2(void *parameter);

TaskHandle_t Task_Handle1 = NULL;
TaskHandle_t Task_Handle2 = NULL;

static const int LED1 = 5;  //LED1 is connected to GPIO 5 pin(D5)
static const int LED2 = 4;  //LED2 is connected to GPIO 4 pin(D4)

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  xTaskCreate(Task1,"Toggle_LED_1",1024,NULL,1,&Task_Handle1);
  xTaskCreate(Task2,"Toggle_LED_2",1024,NULL,1,&Task_Handle2);

}

void loop() {
  //Loop is kept empty
}

void Task1(void *parameter){
  
  while(1){
    digitalWrite(LED1,HIGH);
    vTaskDelay(pdMS_TO_TICKS(500));
    digitalWrite(LED1,LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
  } 
}

void Task2(void *parameter){

  while(1){
    digitalWrite(LED2,HIGH);
    vTaskDelay(pdMS_TO_TICKS(300));
    digitalWrite(LED2,LOW);
    vTaskDelay(pdMS_TO_TICKS(300));
  } 
}
