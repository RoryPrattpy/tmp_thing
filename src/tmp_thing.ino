#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup() {
  display.setup();

  display.clearDisplay();
	display.display();

  pinMode(A0, INPUT);
}

void loop() {
  display.loop();

  show_temp(((analogRead(A0) * 3.3 / 4095.0) - 0.5) * 100);
}


void show_temp(float number) {
  display.clearDisplay();
  display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println(number);
	display.display();
}