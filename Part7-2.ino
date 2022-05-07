#include <WiFi.h>

const char* ssid     = "EN20401580";  //Hotspot name
const char* password = "Hashan#2000";   //Hotspot password

void Task_A(void *parameters){
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) { //connecting to the wifi
    delay(500);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());  //IP address printing

  Serial.print("Connected to wifi hotspot using CORE_");
  Serial.println(xPortGetCoreID());

  vTaskDelete(NULL);
}

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(Task_A, "Task A", 4096, NULL, 1, NULL, 0); //Wifi connect task
}                                                                    //pinned to core 0

void loop() { 
  //Execution should never get here
}
