// Prueba básica para ESP32 IDEABoard
#define LED_BUILTIN 2  // En la mayoría de placas ESP32 el LED está en el pin 2

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP32 IDEABoard iniciada correctamente!");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Enciende LED
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);   // Apaga LED
  delay(1000);
}