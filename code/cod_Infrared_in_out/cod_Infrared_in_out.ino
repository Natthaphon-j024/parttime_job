#include <Arduino.h>
#include <TM1637Display.h>
#define CLK_rad 2
#define DIO_rad 3
#define CLK_gen 5
#define DIO_gen 4
int Infrared_IN = A3;
int Infrared_OUT = A7;
int valInfrared_IN = 0;
int valInfrared_OUT = 0;
int Allin = 0;
  int Present = 0;

#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};
TM1637Display display_rad(CLK_rad, DIO_rad);
TM1637Display display_gen(CLK_gen, DIO_gen);

void setup()
{
  Serial.begin(9600);
  display_rad.setBrightness(10);
 display_gen.setBrightness(10);
  display_gen.showNumberDec(0);
  display_rad.showNumberDec(0);
}
void loop()
{ 
  valInfrared_IN = analogRead(Infrared_IN);
  valInfrared_OUT = analogRead(Infrared_OUT);
  Serial.println("valInfrared_IN");
  Serial.println(valInfrared_IN);
   Serial.println("valInfrared_OUT");
  Serial.println(valInfrared_OUT);
  int line_in=0;
  int line_Present = 0;
  if (valInfrared_IN <= 200) {
poulup();
  }
else if (valInfrared_OUT <= 200) {
pouldow();
  }
 delay(500);
}

int poulup(){

 Allin++;
 Present++;
display_rad.setBrightness(10);
 display_gen.setBrightness(10);
display_gen.showNumberDec(Allin);
display_rad.showNumberDec(Present);
delay(200);
  }
int pouldow(){
  if(Present<=0){
    Present=0;
      display_rad.showNumberDec(Present);
      display_rad.setBrightness(10);
  }
  else{
  Present--;
  display_rad.setBrightness(10);
  display_rad.showNumberDec(Present);
  delay(200);
  }
}
