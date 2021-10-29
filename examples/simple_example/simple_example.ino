// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            10

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      300

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 1; // delay for half a second


void algorithm1();
void algorithm2();
void algorithm3();
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pinMode(8, INPUT);

  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
}

uint8_t r[NUMPIXELS] = {0, };
uint8_t g[NUMPIXELS] = {0, };
uint8_t b[NUMPIXELS] = {0, };

uint32_t cnt = 0;
uint8_t buttonCount = 0;
void loop() {
//  int button = digitalRead(8);
////  Serial.print("button: " );
////  Serial.println(button);
////  Serial.print("mode: " );
////  Serial.println(buttonCount);
//
//  if(button > 0)
//  {
//    buttonCount++;
//    if(buttonCount >2)
//      buttonCount = 0;
//  }
//  if(buttonCount == 0)
//  {
////    Serial.println("al1");
//    algorithm1();
//  }
//  else if(buttonCount == 1)
//  {
////    Serial.println("al2");
//    algorithm2();
//  }
//  else if(buttonCount == 2)
//  {
////    Serial.println("al3");
//    algorithm3();
//  }
    
    algorithm2();
}

void algorithm1()
{
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(r[i]+=2,g[i]+=4,b[i]-=10)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).
}

void algorithm2()
{
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    long randomNum = random();
//    Serial.println(randomNum);
    randomSeed(randomNum);
    pixels.setPixelColor(i, pixels.Color(random(0,100),random(0,100),random(0,100))); // Moderately bright green color.
  }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
}
void algorithm3()
{
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(50,50,50)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}
