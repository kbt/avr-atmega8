# https://de.wikibooks.org/wiki/C-Programmierung_mit_AVR-GCC/_Hello_World


CFLAGS=-DF_CPU=16000000UL

all:
	avr-gcc -mmcu=atmega8a $(CFLAGS) -Os -c blink.c -o blink.o
	avr-gcc blink.o -o blink.elf
	avr-objcopy -O ihex -j .text -j .data blink.elf blink.hex

clean:
	rm *.o *.hex *.elf

install:
	scp blink.hex pi:avr/
	ssh pi sudo avrdude -p atmega8 -c linuxgpio -U flash:w:avr/blink.hex:i

ctags:
	ctags -R . /usr/lib/avr/include
