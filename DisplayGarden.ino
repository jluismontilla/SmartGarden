
#include <SPI.h>

//Wire library for I2C BUS
#include <Wire.h>

//Time library
#include <DS3231.h>

//include Adafruit graphics & OLED libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// On an arduino MEGA 2560: 20(SDA), 21(SCL)

//Reset pin, not used but needed for library
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address;0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char message[]="Bonjour, voici un test...Montilla";
int x, minX;

void setup() {
  //Start wire library for I2C
  Wire.begin();
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  //Set color to white
  display.setTextColor(WHITE);

  display.setTextWrap(false);
  x = display.width();
  minX = -12 *strlen(message); //12 = 6 pixels/character * text size 2
}

void loop() {

//Serial.println(x);
  display.clearDisplay();
  display.setCursor(0,8);
  display.setTextSize(1);
  display.print("TEST SCROLLING TEXT");
  display.setTextSize(2);
  display.setCursor(x,20);
  display.print(message);
  display.display();
  x= x - 3; //Scroll speed
  if(x < minX)
    x = display.width();
  
}
