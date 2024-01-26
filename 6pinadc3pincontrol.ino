#include <Arduino.h>
#include <freertos/FreeRTOS.h>

const int analogInputPin1 = 34; 
const int analogInputPin2 = 4; 
const int analogInputPin3 = 15; 
const int analogInputPin4 = 32; 
const int analogInputPin5 =33; 
const int analogInputPin6 = 35; 
const int sampleCount = 1000;
unsigned long startTime = 0;

int sum1 = 0;
int sum2 = 0;
int sum3 = 0;
int sum4 = 0;
int sum5 = 0;
int sum6 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(analogInputPin1, INPUT);
  pinMode(analogInputPin2, INPUT);
  pinMode(analogInputPin3, INPUT);
  pinMode(analogInputPin4, INPUT);
  pinMode(analogInputPin5, INPUT);
  pinMode(analogInputPin6, INPUT);
  
  
  xTaskCreatePinnedToCore(readAnalogPin1, "ReadPin1", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(readAnalogPin2, "ReadPin2", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(readAnalogPin3, "ReadPin3", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(readAnalogPin4, "ReadPin4", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(readAnalogPin5, "ReadPin5", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(readAnalogPin6, "ReadPin6", 10000, NULL, 1, NULL, 0);
}

void loop() {
  
}

void readAnalogPin1(void *pvParameters) {
  for (;;) {
    sum1 = 0;

    for (int i = 0; i < sampleCount; i++) {
      int adcValue1 = analogRead(analogInputPin1);
      sum1 += adcValue1;
    }

    float average1 = static_cast<float>(sum1) / sampleCount;
    Serial.print("Pin1 Average: ");
    Serial.println(average1);
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}

void readAnalogPin2(void *pvParameters) {
  for (;;) {
    sum2 = 0;

    for (int i = 0; i < sampleCount; i++) {
      int adcValue2 = analogRead(analogInputPin2);
      sum2 += adcValue2;
    }

    float average2 = static_cast<float>(sum2) / sampleCount;
    Serial.print("Pin2 Average: ");
    Serial.println(average2);
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}

void readAnalogPin3(void *pvParameters) {
  for (;;) {
    sum3 = 0;

    for (int i = 0; i < sampleCount; i++) {
      int adcValue3 = analogRead(analogInputPin3);
      sum3 += adcValue3;
    }

    float average3 = static_cast<float>(sum3) / sampleCount;
    Serial.print("Pin3 Average: ");
    Serial.println(average3);
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}

void readAnalogPin4(void *pvParameters) {
  for (;;) {
    sum4 = 0;

    for (int i = 0; i < sampleCount; i++) {
      int adcValue4 = analogRead(analogInputPin4);
      sum4 += adcValue4;
    }

    float average4 = static_cast<float>(sum4) / sampleCount;
    Serial.print("Pin4 Average: ");
    Serial.println(average4);
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}

void readAnalogPin5(void *pvParameters) {
  for (;;) {
    sum5 = 0;

    for (int i = 0; i < sampleCount; i++) {
      int adcValue5 = analogRead(analogInputPin5);
      sum5 += adcValue5;
    }

    float average5 = static_cast<float>(sum5) / sampleCount;
    Serial.print("Pin5 Average: ");
    Serial.println(average5);
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}

void readAnalogPin6(void *pvParameters) {
  for (;;) {
    sum6 = 0;

    for (int i = 0; i < sampleCount; i++) {
      int adcValue6 = analogRead(analogInputPin6);
      sum6 += adcValue6;
    }

    float average6 = static_cast<float>(sum6) / sampleCount;
    Serial.print(" /Pin6 Average: ");
    Serial.println(average6);
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}
