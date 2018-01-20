# Atmega8A-PU
![](https://photos05.redcart.pl/templates/images/description/995/Image/kuba/21/Mikrokontroler_AVR_ATmega8A-PU.jpg) 


## avrdude
```
# /etc/avrdude.conf
# Connection with Raspberry PI
programmer
  id    = "linuxgpio";
  desc  = "Use the Linux sysfs interface to bitbang GPIO lines";
  type  = "linuxgpio";
  reset = 12;
  sck   = 11;
  mosi  = 10;
  miso  = 9;
;
```

## Fuse settings
http://www.engbedded.com/fusecalc/

For an external crystal 16Mhz ```lfuse``` is changed into ```0xFF```
```avrdude -p atmega8 -c linuxgpio -v -U lfuse:w:0xff:m```

Current state: ```Fuses OK (E:FF, H:D9, L:FF)```

## Resources
[ATmega8A - Complete Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/Microchip%208bit%20mcu%20AVR%20ATmega8A%20data%20sheet%2040001974A.pdf)

https://www.rototron.info/raspberry-pi-avr-programmer-spi-tutorial/  
http://www.circuitstoday.com/how_to_work_with_32k_crystal_and_avr_microcontroller  
http://www.microchip.com/wwwproducts/en/atmega8a
