#include <avr/io.h>

#include <util/delay.h>

int main (void) {
   DDRC = 0xff;

   PORTC ^= (1 << PC4);
   while (1) {
       PORTC ^= (1 << PC5);
       PORTC ^= (1 << PC4);
       _delay_ms(500);
   }

   return 0;
}
