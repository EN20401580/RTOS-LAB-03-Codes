
void Task1(void *parameter);
void Task2(void *parameter);

TaskHandle_t Task_Handle1 = NULL;
TaskHandle_t Task_Handle2 = NULL;

static const int led = LED_BUILTIN;

void setup() {
  pinMode(led,OUTPUT);
  xTaskCreate(Task1,"Toggle_LED_1",1024,NULL,1,&Task_Handle1);
  xTaskCreate(Task2,"Toggle_LED_2",1024,NULL,1,&Task_Handle1);

}

void loop() {
  //Loop is kept empty
}

void Task1(void *parameter){
  
  while(1){
    digitalWrite(led,HIGH);
    vTaskDelay(pdMS_TO_TICKS(500));
    digitalWrite(led,LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
  } 
}

void Task2(void *parameter){
  
  while(1){
    digitalWrite(led,HIGH);
    vTaskDelay(pdMS_TO_TICKS(300));
    digitalWrite(led,LOW);
    vTaskDelay(pdMS_TO_TICKS(300));
  } 
}
