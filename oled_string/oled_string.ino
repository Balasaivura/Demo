#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Display the text once
  display.setTextSize(1);               // Smallest size for more scroll space
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Balasai");
  display.display();

  // Start scrolling text to the left
  display.startscrollleft(0x00, 0x0F);  // Scroll full height
}

void loop() {
  // Nothing to do here — scrolling handled by hardware
}
