#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* message = "This is example scrolling message!";
int xPos;
int textWidth;
int textSize = 2;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);  // 💡 Prevent text from wrapping to next line

  // Estimate text width
  textWidth = 6 * textSize * strlen(message);
  xPos = SCREEN_WIDTH;
}

void loop() {
  display.clearDisplay();
  display.setCursor(xPos, 25);  // Adjust Y as needed
  display.print(message);
  display.display();

  xPos--;  // Scroll left

  if (xPos < -textWidth) {
    xPos = SCREEN_WIDTH;
  }

  delay(10);  // Adjust speed
}
