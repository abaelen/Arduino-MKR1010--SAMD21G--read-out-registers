# Arduino MKR1010 (SAMD21G) read out registers
 Code to read out the register states of the Arduino MKR 1010 Wifi (SAMDG18a)

This sketch dumps (selected) registers to the serial monitor.

For example,
The GENCLK registers are written out:
>*To read the CLKCTRL register, first do an 8-bit write to the CLKCTRL.ID bit group with the ID of the generic clock whose
configuration is to be read, and then read the CLKCTRL register.*


The GENCTRL registers are also written out.
It implements the statement in the Atmel datasheet: 
The GCLK peripheral's GENCTRL, GENDIV and CLKCTRL registers are indirectly addressed:

>*To read back from these generic clock registers, it's first necessary to do an 8-bit write to the register's ID bitfield, to identify the GCLK before performing a read.*

or 


>*To read the CLKCTRL register, first do an 8-bit write to the CLKCTRL.ID bit group with the ID of the generic clock whose configuration is to be read, and then read the CLKCTRL register.*

or
	
>*For example, the sequence to read the GENCTRL register of a specific Generic Clock Generator i is: 1. Do an 8-bit write of the i value to GENCTRL.ID. 2. Read the value of GENCTRL.*

