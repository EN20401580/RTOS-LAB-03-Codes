static const int LED = LED_BUILTIN;

int Input_val = 500;
char val_as_chars;
String char_str;

void User_Input(void *parameter);
void LED_Blink(void *parameter);

TaskHandle_t Task_Handle1 = NULL;
TaskHandle_t Task_Handle2 = NULL;

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  
  xTaskCreate(User_Input,"User Input",1024,NULL,1,&Task_Handle1);  
  xTaskCreate(LED_Blink,"LED Blink",1024,NULL,1,&Task_Handle2);   
}
void loop(){
  //Loop is kept empty
}

void User_Input(void *parameter){
  
  while(1){
    if(Serial.available()>0){
      val_as_chars = Serial.read();
      char_str = char_str + val_as_chars; 
      Input_val = char_str.toInt();     
    }  
    if(Serial.available()==0){
      vTaskDelay(pdMS_TO_TICKS(50));
      char_str = "";
    }
  }
}

void LED_Blink(void *parameter) {
  
  while(1) {
    digitalWrite(LED, HIGH);
    vTaskDelay(pdMS_TO_TICKS(Input_val));
    digitalWrite(LED, LOW);
    vTaskDelay(pdMS_TO_TICKS(Input_val));
    Serial.print("Current delay - ");
    Serial.println(Input_val);
  }
}
