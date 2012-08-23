#include <io.h>

#define pin6mask  (0x01 << 6)

void dot();
void dash();
void space();

int main(void) {
  /* Hold the watchdog timer so it doesn't reset our chip */
  WDTCTL = WDTPW + WDTHOLD;

  /* Configure all pins on port 1 as output pins */
  P1DIR = 0xff;

  /* Set pin 6 high.  Basically, this command sets any combination
   * of the pins on port 1 high.  Pin 0 is 2^0, pin 1 is 2^2, etc.
   * Values can be binary or'd together. Other pins are low.
   */
  P1OUT = pin6mask;


  /* Toggle the state of pin 6 on port 1 by exclusive or'ing with
     the mask that represents that pin. */
   
 
  P1OUT = P1OUT ^ pin6mask;  

  // put lisp morse code conversion output below


  while(1){
    dot();space();dot();space();dot();space();space();dash();space();dash();space();dash();space();space();dot();space();dot();space();dot();space();space();
  }



}

void dot () {
  volatile int a=0;
  volatile int x=0;
  for(x=0;x<3200;x++){
    a=a+1;
  };
  P1OUT=P1OUT ^ pin6mask;
  for(x=0;x<7500;x++){
    a=a+1;
  };
  P1OUT=P1OUT ^ pin6mask;
  for(x=0;x<3200;x++){
    a=a+1;
  };


}


void dash () {
  volatile int a=0;
  volatile int x=0;
  for(x=0;x<3200;x++){
    a=a+1;
  };
  P1OUT=P1OUT ^ pin6mask;
  for(x=0;x<15000;x++){
    a=a+1;
  };
  P1OUT=P1OUT ^ pin6mask;
  for(x=0;x<3200;x++){
    a=a+1;
  };
}

void space () {
  volatile int x=0;
  volatile int a=0;

  for(x=0;x<7500;x++){
    a=a+1;
  }

}



   

