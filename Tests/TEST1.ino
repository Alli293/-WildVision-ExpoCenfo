#include "esp_camera.h"
#include "FS.h"
#include "SPIFFS.h"
#include "soc/soc.h"          // Para evitar brownout
#include "soc/rtc_cntl_reg.h" // Para evitar brownout

// ===========================
// CONFIGURACIÓN DE PINES - AI Thinker
// ===========================
#define PWDN_GPIO_NUM    -1
#define RESET_GPIO_NUM   -1
#define XCLK_GPIO_NUM     0
#define SIOD_GPIO_NUM    26
#define SIOC_GPIO_NUM    27

#define Y9_GPIO_NUM      35
#define Y8_GPIO_NUM      34
#define Y7_GPIO_NUM      39
#define Y6_GPIO_NUM      36
#define Y5_GPIO_NUM      21
#define Y4_GPIO_NUM      19
#define Y3_GPIO_NUM      18
#define Y2_GPIO_NUM       5
#define VSYNC_GPIO_NUM   25
#define HREF_GPIO_NUM    23
#define PCLK_GPIO_NUM    22

void setup() {
  // Desactivar el detector de brownout (muy común en AI Thinker)
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  Serial.begin(115200);
  Serial.println("\nIniciando ESP32-CAM AI Thinker...");

  // Montar SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("❌ Error al montar SPIFFS");
    return;
  }

  // Configuración de la cámara
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  // FORZAMOS que use el modelo AI Thinker
  // Esta es la diferencia respecto al código anterior
  #if defined(CAMERA_MODEL_AI_THINKER)
    // Usa la configuración estándar de AI Thinker
  #endif

  // Ajustar calidad y frame size
  if (psramFound()) {
    config.frame_size = FRAMESIZE_VGA; // 640x480
    config.jpeg_quality = 12;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_QVGA; // 320x240
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // Inicializar cámara
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("❌ Error al iniciar la cámara: 0x%x\n", err);
    delay(5000);
    ESP.restart();
    return;
  }

  Serial.println("✅ Cámara inicializada correctamente.");

  // Capturar una foto
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("❌ Error al capturar la foto.");
    ESP.restart();
    return;
  }

  // Guardar la foto en SPIFFS
  File file = SPIFFS.open("/foto.jpg", FILE_WRITE);
  if (!file) {
    Serial.println("❌ Error al abrir el archivo para escribir.");
    esp_camera_fb_return(fb);
    return;
  }

  file.write(fb->buf, fb->len);
  file.close();
  esp_camera_fb_return(fb);

  Serial.println("📷 Foto capturada y guardada como /foto.jpg");
}

void loop() {
  delay(10000);
}
}
