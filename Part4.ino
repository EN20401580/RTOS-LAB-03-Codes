
// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

void startTask1(void *parameter);
void startTask2(void *parameter);

const char msg[] = "Hello World";

static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;

void setup(){
  Serial.begin(115200);
  xTaskCreatePinnedToCore(startTask1,"Task_1",1024,NULL,1,&task_1,app_cpu);  
  xTaskCreatePinnedToCore(startTask2,"Task_2",1024,NULL,1,&task_2,app_cpu); 
}

void loop(){
  //Loop is kept empty
}

void startTask1(void *parameter) {
  
  int msg_len = strlen(msg);
  
  while (1) {
    Serial.println();
    for (int i = 0; i < msg_len; i++) {
      Serial.print(msg[i]);
    }
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void startTask2(void *parameter) {
  while (1) {
    Serial.print('*');
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}
