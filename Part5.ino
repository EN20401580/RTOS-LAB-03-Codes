
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

void testTask(void *parameter){
  while (1) {
    int a = 1;
    int b[100];
    
    for (int i = 0; i < 100; i++){
      b[i] = a + 1;
      
    }
  Serial.println(b[3]);
  }
}


void setup() {
  Serial.begin(115200);
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  Serial.println();
  Serial.println("---FreeRTOS Memory Demo---");
  xTaskCreatePinnedToCore(testTask,"Test Task",1280,NULL,1,NULL,app_cpu);
  vTaskDelete(NULL);
}

void loop() {

}
