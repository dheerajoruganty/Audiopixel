// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    7

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 6

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
}


// loop() function -- runs repeatedly as long as board is on ---------------
int b=100; //rate of change of lights



void loop() 
{
  colorWipe(strip.Color(  252,   0,   0), b); // Red
  colorWipefollow(strip.Color( 252,   0,  0), b);
  //colorWipe2(strip.Color( 0 , 255, 255), 12);//grenn
  //colorWipe2follow(strip.Color(  0,   0, 255), 12);
  //colorWipe(strip.Color(  0,   0, 255), 12);//blue
  //colorWipe2(strip.Color(255,   0,   0), 500);
  //colorWipe(strip.Color(0  , 255,   0), 500);
  //colorWipe2(strip.Color(  0,   0, 255), 500);
}
  void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels()+4; i=i+1) { // For each pixel in strip...
    strip.setPixelColor(i, color);//  Set pixel's color (in RAM)
    strip.setPixelColor(i-1, color/2);
    strip.setPixelColor(i-2, color/6);
    strip.setPixelColor(i-3, color/12);
    
    
    strip.show();                          //  Update strip to match
    delay(wait); //  Pause for a moment
    strip.clear();
  }
}
void colorWipe2(uint32_t color, int wait) {
  for(int i=strip.numPixels(); i>=0; i=i-1) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait); //  Pause for a moment
    strip.clear();
  }
}
void colorWipefollow(uint32_t color, int wait) {
  for(int i=strip.numPixels()-1; i>=-4; i=i-1) { // For each pixel in strip...
    strip.setPixelColor(i, color);//  Set pixel's color (in RAM)
    strip.setPixelColor(i+1, color/2);
    strip.setPixelColor(i+2, color/6);
    strip.setPixelColor(i+3, color/12);
    
    
    strip.show();                          //  Update strip to match
    delay(wait); //  Pause for a moment
    strip.clear();
  }
}
