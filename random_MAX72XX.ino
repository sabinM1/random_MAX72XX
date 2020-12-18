// Including the required Arduino libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Initialization
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 15
#define CS_PIN 4
#define DATA_PIN 5
#define CLK_PIN 18
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

uint32_t prevTimeAnim = 0;

void graphicRandom()
{
  // Is it time to animate?
  if (millis()-prevTimeAnim < 150) //150 random time
    return ;
  prevTimeAnim = millis();    // starting point for next time

  // now run the animation
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
  for (uint8_t i=0; i<mx.getColumnCount(); i++)
    mx.setColumn(i, (uint8_t)random(255));
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
}

void setup() {
  // Intialize the object
  mx.begin();

  // Set the intensity (brightness) of the display (0-15)
  mx.control(MD_MAX72XX::INTENSITY, 7);

  // Clear the display
  mx.clear();
}

void loop() {
  graphicRandom();
}
