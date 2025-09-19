#include <WiFi.h>
#include <esp_now.h>

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  Serial.print("Nhận được: ");
  Serial.println((char*)incomingData);
}

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Lỗi ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
}
