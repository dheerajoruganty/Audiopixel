#include <Arduino.h>
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

int brgt=0;
int hhue=0;
int i=0;

int r=0;
int g=0;
int b=0;

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
    // END of Trinket-specific code.

    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    //strip.setBrightness(brgt); // Set BRIGHTNESS to about 1/5 (max = 255)
  pinMode(A0,INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(A1, INPUT);//hue node
  Serial.begin(9600);
  pinMode(A2, INPUT);//potentiometer
  pinMode(7, OUTPUT);//lights


}




void loop() {
  // put your main code here, to run repeatedly:
  int pixelHue=0;
  strip.setBrightness(brgt);

  if (digitalRead(A0) == HIGH) {
     brgt = brgt + 30; // push button for incresing brightnness
     if (brgt > 255) {
      brgt = 0;
     }
     Serial.println("Pin A0 HIGH");
     delay(400);
  }

  if (digitalRead(A1) == HIGH) {
    
    Serial.println("Pin A1 HIGH");
     delay(400);
    
    for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors 
      // before assigning to each pixel:

  }
    }
  }

for (i=0 ; i<=strip.numPixels(); i++){
strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
strip.show();

}
    } 








/*int j=0;
int r=0;
int g=0;
int b=0;

for(j=0;j<=6;j++){
  if(j=0);{
  r=255;
}
  if(j=1);{
  r=255;
  g=255;
}
  if(j=2);{
  g=255;
}
  if(j=3);{
  g=255;
  b=255;
}
  if(j=4);{
  b=255
}
  if(j=5);{
  r=255
  b=255
}
  if(j=6);{
  j=0;
}
}
*/
