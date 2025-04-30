#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Scrollable message
const char* scrollMessage = "Welcome to VECTOR INDIA";
int xPos;
int scrollTextWidth;

// Constant lines
const char* line2 = "Hyderabad";
const char* line3 = "Bangalore";
const char* line4 = "Chennai";

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextWrap(false);
  display.setTextColor(SSD1306_WHITE);

  // Calculate scroll width
  display.setTextSize(1);
  scrollTextWidth = 6 * strlen(scrollMessage);
  xPos = SCREEN_WIDTH;
}

void loop() {
  display.clearDisplay();

  // 1️⃣ Scroll line (top, small font)
  display.setTextSize(1);
  display.setCursor(xPos, 0);
  display.print(scrollMessage);

  // Set font size for all constant lines
  display.setTextSize(2);

  // Line 2
  int w2 = strlen(line2) * 6 * 2;
  display.setCursor((SCREEN_WIDTH - w2) / 2, 12);
  display.print(line2);

  // Line 3
  int w3 = strlen(line3) * 6 * 2;
  display.setCursor((SCREEN_WIDTH - w3) / 2, 28);
  display.print(line3);

  // Line 4
  int w4 = strlen(line4) * 6 * 2;
  display.setCursor((SCREEN_WIDTH - w4) / 2, 44);
  display.print(line4);

  display.display();

  // Scroll logic
  xPos--;
  if (xPos < -scrollTextWidth) {
    xPos = SCREEN_WIDTH;
  }

  delay(10);
}
