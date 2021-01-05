#include "ESPino32CAM.h"
#include "ESPino32CAM_QRCode.h"
 
ESPino32CAM cam;   // Image capture object
ESPino32QRCode qr; // Image decoding object
 
// Set the camera pins
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22
#define flash 4
 
void setup() {
   
  Serial.begin(115200);
  Serial.println("QR Code Reader");
  // Define the flash pin.
  pinMode(flash,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(flash, LOW); // Turn off the flash.
     
  // Configure the camera pins.
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
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA;  
  config.jpeg_quality = 4;
  config.fb_count = 1;
   
  esp_err_t err = esp_camera_init(&config); // Initialize the camera.
   
  if (err != ESP_OK) {
     
    Serial.printf("Camera start failed with error 0x%x", err);//Informa erro se a câmera não for iniciada corretamente
    delay(1000);
    ESP.restart(); // Reboot the ESP
     
  }
 
  // Initialize the decoding object.
  qr.init(&cam);
  sensor_t *s = cam.sensor();
  s->set_framesize(s, FRAMESIZE_CIF);
  s->set_whitebal(s, true);
   
  //Serial.println();
  //Serial.println("Waiting for code."); 
 
}
 
void loop()
{
  unsigned long pv_time  = millis();
  digitalWrite(flash, HIGH); // Turn on the flash.
  delay(500);
  camera_fb_t *fb = cam.capture(); // Captura a imagem
  digitalWrite(flash, LOW); // Turn off the flash.
  if (!fb)
  {
    //Serial.println("Image capture failed.");
    return;
  }
  dl_matrix3du_t *rgb888, *rgb565;
  if (cam.jpg2rgb(fb, &rgb888))
  {
    rgb565 = cam.rgb565(rgb888);
  }
  cam.clearMemory(rgb888);
  cam.clearMemory(rgb565);
  dl_matrix3du_t *image_rgb;
  if (cam.jpg2rgb(fb, &image_rgb))
  {
    cam.clearMemory(fb);
         
    qrResoult res = qr.recognition(image_rgb); // Decodes the image containing the data.
     
    if (res.status) // If you can decode the image it shows the data on the screen.
    { 
      String result = "QR Code Read: " + res.payload; // Variable to show the data contained in the QR Code.
      //Serial.println();
      //Serial.println(result);  // Shows data on the serial monitor,
      int i=0;
      for(i=0;i<10;i++)
      {
        digitalWrite(flash, HIGH);
        delay(70);
        digitalWrite(flash, LOW); 
        delay(70); 
      }
      delay(70); 
      //Serial.write("id");
      //delay(70); 
      //i=0;
      //Serial.println(String(res.payload.length()));
      //for(i=0;i<res.payload.length();i++)
      //{
        delay(10);
        Serial.print(res.payload);
      //}
    }
    else{ // If you do not wait to receive code.
       //Serial.println();
       //Serial.println("Waiting for code."); 
     } 
     if(Serial.read()== 'a')
     {
        digitalWrite(flash, HIGH);
        delay(7000);
     }
     if(Serial.read()== 'b')
     {
        digitalWrite(flash, LOW);
        delay(7000);
     }
    }
     
  cam.clearMemory(image_rgb); // Delete image to receive a new image.
}
