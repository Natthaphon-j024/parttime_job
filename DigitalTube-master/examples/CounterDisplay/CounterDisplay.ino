/*
 * Written by IOXhop : www.ioxhop.com
 * Author : Sonthaya Nongnuch (www.fb.me/maxthai)
 */

#include <DigitalTube.h>

// DigitalTube::DigitalTube(int sclk, int rclk, int dio)
DigitalTube dis(4, 2, 3);

int i = 0;

void setup() {
  dis.begin();
}

void loop() {
  dis.print(i); // Show 'i' to display
  i++;
  if (i>9999) {
    i = 0;
  }
  delay(500);
}
