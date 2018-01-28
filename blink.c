#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SET_BIT(x,y) (x|=(1<<y))
#define XOR_BIT(x,y) (x^=(1<<y))

int is_set(int port, int pin) {
  return (port & (1 << pin)) > 0;
}

ISR(INT0_vect)
{
  cli();
  XOR_BIT(PORTC,PC5); 

  //TODO use timers instead of delay
  _delay_ms(200);
  sei();
}

int main(void) {
  DDRC = 0xff;
  PORTC = (1 << PC4);

  SET_BIT(MCUCR, ISC11);
  
  // Turns on INT0
  SET_BIT(GICR, INT0);

  // pull-up vcc to a switcher (Pxy is an INPUT by default)
  PORTD |= (1 << PD2);

  sei();

  int c1 = 0, c2 = 0;
  while (1) {
    PORTC ^= (1 << PC4);

    _delay_ms(200);
  }
}
