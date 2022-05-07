
void Task1(void *parameter);

TaskHandle_t Task_Handle1 = NULL;

static const int led = LED_BUILTIN;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  xTaskCreate(Task1,"Toggle LED",1024,NULL,1,&Task_Handle1);

}

void loop() {
  //Loop is kept empty
}

void Task1(void *parameter){
  
  while(1){
    Serial.println("Task_1 Running");
    digitalWrite(led,HIGH);
    vTaskDelay(pdMS_TO_TICKS(500));
    digitalWrite(led,LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
  } 
}
