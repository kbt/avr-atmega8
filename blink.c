#include <avr/io.h>
#include <util/delay.h>

int is_set(int port, int pin) {
  return (port & (1 << pin)) > 0;
}

int main(void) {
  DDRC = 0xff;
  PORTC = (1 << PC4);

  // pull-up vcc to a switcher (Pxy is an INPUT by default)
  PORTD |= (1 << PD0);

  int mode = 0;
  int c1 = 0, c2 = 0;
  while (1) {
    c1 = c2;
    c2 = is_set(PIND, PD0);

    // when clicked
    if (c2 == 1 && c1 == 0) {
      mode = (mode + 1) % 2;

      if (mode == 0) {
        PORTC |= (1 << PC4) | (1 << PC5);
      } else if (mode == 1) {
        PORTC = (1 << PC4);
      }
    }

    PORTC ^= 0xff;

    _delay_ms(150);
  }
}
