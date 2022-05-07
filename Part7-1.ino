
TaskHandle_t Task_Handle_A = NULL;
TaskHandle_t Task_Handle_B = NULL;

void Task_A(void *parameters);
void Task_B(void *parameters);

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(Task_A, "Task A", 1024, NULL, 1, &Task_Handle_A, 0);
  xTaskCreatePinnedToCore(Task_B, "Task B", 1024, NULL, 1, &Task_Handle_B, 1);
  vTaskDelete(NULL);
}

void loop() {
  //Execution should never get here
}

void Task_A(void *parameters){
  while(1){
    Serial.print("I am Task A I am Running on CORE_");
    Serial.println(xPortGetCoreID()); 
    vTaskDelay(pdMS_TO_TICKS(1500));
  }  
}

void Task_B(void *parameters){
  while(1){
    Serial.print("I am Task B I am Running on CORE_");
    Serial.println(xPortGetCoreID());
    vTaskDelay(pdMS_TO_TICKS(1500));
  }  
}
