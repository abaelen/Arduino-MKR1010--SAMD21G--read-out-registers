/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

void setup() {
// Start serial monitor
   Serial.begin(115200);
  while(!Serial){};
  Serial.println("Begin");


 Serial.println("APBCMASK register:");
 Serial.println("");
 Serial.println("*****************************************************************");
                 Serial.print(PM->APBCMASK.bit.PAC2_); Serial.println(":1 bit: 0 PAC2 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.EVSYS_); Serial.println(":1 bit: 1 EVSYS APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM0_); Serial.println(":1 bit: 2 SERCOM0 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM1_); Serial.println(":1 bit: 3 SERCOM1 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM2_); Serial.println(":1 bit: 4 SERCOM2 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM3_); Serial.println(":1 bit: 5 SERCOM3 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM4_); Serial.println(":1 bit: 6 SERCOM4 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM5_); Serial.println(":1 bit: 7 SERCOM5 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TCC0_); Serial.println(":1 bit: 8 TCC0 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TCC1_); Serial.println(":1 bit: 9 TCC1 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TCC2_); Serial.println(":1 bit: 10 TCC2 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC3_); Serial.println(":1 bit: 11 TC3 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC4_); Serial.println(":1 bit: 12 TC4 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC5_); Serial.println(":1 bit: 13 TC5 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC6_); Serial.println(":1 bit: 14 TC6 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC7_); Serial.println(":1 bit: 15 TC7 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.ADC_); Serial.println(":1 bit: 16 ADC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.AC_); Serial.println(":1 bit: 17 AC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.DAC_); Serial.println(":1 bit: 18 DAC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.PTC_); Serial.println(":1 bit: 19 PTC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.I2S_); Serial.println(":1 bit: 20 I2S APB Clock Enable ");
Serial.println("***********************APBCMASK******************************");

Serial.println("CLKCTRL register:");
Serial.println("");
Serial.println("***********************PCLKSR******************************");
               Serial.print(SYSCTRL->PCLKSR.bit.XOSCRDY); Serial.println(":1 bit: 0 XOSC Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.XOSC32KRDY); Serial.println(":1 bit: 1 XOSC32K Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.OSC32KRDY); Serial.println(":1 bit: 2 OSC32K Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.OSC8MRDY); Serial.println(":1 bit: 3 OSC8M Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLRDY); Serial.println(":1 bit: 4 DFLL Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLOOB); Serial.println(":1 bit: 5 DFLL Out Of Bounds");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLLCKF); Serial.println(":1 bit: 6 DFLL Lock Fine");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLLCKC); Serial.println(":1 bit: 7 DFLL Lock Coarse");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLRCS); Serial.println(":1 bit: 8 DFLL Reference Clock Stopped");
               Serial.print(SYSCTRL->PCLKSR.bit.BOD33RDY); Serial.println(":1 bit: 9 BOD33 Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.BOD33DET); Serial.println(":1 bit: 10 BOD33 Detection");
               Serial.print(SYSCTRL->PCLKSR.bit.B33SRDY); Serial.println(":1 bit: 11 BOD33 Synchronization Ready");
               //Serial.print(SYSCTRL->PCLKSR.bit.:3;bit: 12..14 Reserved");
               Serial.print(SYSCTRL->PCLKSR.bit.DPLLLCKR); Serial.println(":1 bit: 15 DPLL Lock Rise");
               Serial.print(SYSCTRL->PCLKSR.bit.DPLLLCKF); Serial.println(":1 bit: 16 DPLL Lock Fall");
               Serial.print(SYSCTRL->PCLKSR.bit.DPLLLTO); Serial.println(":1 bit: 17 DPLL Lock Timeout");
               //Serial.print(SYSCTRL->PCLKSR.bit.:14;bit: 18..31 Reserved");
Serial.println("***********************PCLKSR******************************");

Serial.println("XOSC register:");
Serial.println("");
Serial.println("***********************XOSC******************************");
               //Serial.print(); Serial.println(":1 bit: 0 Reserved");
               Serial.print(SYSCTRL->XOSC.bit.ENABLE); Serial.println(":1 bit: 1 Oscillator Enable");
               Serial.print(SYSCTRL->XOSC.bit.XTALEN); Serial.println(":1 bit: 2 Crystal Oscillator Enable");
               //Serial.print(":3; bit: 3.. 5 Reserved");
               Serial.print(SYSCTRL->XOSC.bit.RUNSTDBY); Serial.println(":1 bit: 6 Run in Standby");
               Serial.print(SYSCTRL->XOSC.bit.ONDEMAND); Serial.println(":1 bit: 7 On Demand Control");
               Serial.print(SYSCTRL->XOSC.bit.GAIN); Serial.println(":3; bit: 8..10 Oscillator Gain");
               Serial.print(SYSCTRL->XOSC.bit.AMPGC); Serial.println(":1 bit: 11 Automatic Amplitude Gain Control");
               Serial.print(SYSCTRL->XOSC.bit.STARTUP); Serial.println(":4; bit: 12..15 Start-Up Time");
Serial.println("***********************XOSC******************************");
Serial.println("XOSC32K register:");
Serial.println("");
Serial.println("***********************XOSC32K******************************");
              // Serial.print(SYSCTRL->XOSC32K.bit.); Serial.println(":1 bit: 0 Reserved");
               Serial.print(SYSCTRL->XOSC32K.bit.ENABLE); Serial.println(":1 bit: 1 Oscillator Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.XTALEN); Serial.println(":1 bit: 2 Crystal Oscillator Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.EN32K); Serial.println(":1 bit: 3 32kHz Output Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.EN1K); Serial.println(":1 bit: 4 1kHz Output Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.AAMPEN); Serial.println(":1 bit: 5 Automatic Amplitude Control Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.RUNSTDBY); Serial.println(":1 bit: 6 Run in Standby");
               Serial.print(SYSCTRL->XOSC32K.bit.ONDEMAND); Serial.println(":1 bit: 7 On Demand Control");
               Serial.print(SYSCTRL->XOSC32K.bit.STARTUP); Serial.println(":3 bit: 8..10 Oscillator Start-Up Time");
              // Serial.print(SYSCTRL->XOSC32K.bit.); Serial.println(":1 bit: 11 Reserved");
               Serial.print(SYSCTRL->XOSC32K.bit.WRTLOCK); Serial.println(":1 bit: 12 Write Lock");
              // Serial.print(SYSCTRL->XOSC32K.bit.); Serial.println(":3 bit: 13..15 Reserved");
Serial.println("***********************XOSC32K******************************");



Serial.println("CLKCTRL register:");
Serial.println("");

 for (uint8_t i=0;i<25;i++) { 
    uint8_t *clkctrl;
    clkctrl = (uint8_t *) (0x40000C02UL);
    *clkctrl=i;
    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
    
  Serial.print("GENCTRL register "); Serial.println(i);
  Serial.print("***********************CLKCTRL ID: "); Serial.print(i);Serial.println("******************************");
               Serial.print(GCLK->CLKCTRL.bit.ID); Serial.println(":6 bit: 0.. 5 Generic Clock Selection ID ");
               //Serial.print(GCLK->CLKCTRL.bit.); Serial.println(":2 bit): 6.. 7 Reserved ");
               Serial.print(GCLK->CLKCTRL.bit.GEN); Serial.println(":4 bit: 8..11 Generic Clock Generator ");
               //Serial.print(GCLK->CLKCTRL.bit.); Serial.println(":2 bit: 12..13 Reserved ");
               Serial.print(GCLK->CLKCTRL.bit.CLKEN); Serial.println(":1 bit: 14 Clock Enable ");
               Serial.print(GCLK->CLKCTRL.bit.WRTLOCK); Serial.println(":1 bit: 15 Write Lock ");
  Serial.print("***********************CLKCTRL ID: "); Serial.print(i);Serial.println("******************************");
 }


 
 Serial.println("GENCTRL register:");
 Serial.println("");

 for (uint8_t i=0;i<9;i++) { 
    uint8_t *genctrl;
    genctrl = (uint8_t *) (0x40000C04UL);
    *genctrl=i;
    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
    
 Serial.print("GENCTRL register "); Serial.println(i);
 Serial.print("***********************GENCTRL ID: "); Serial.print(i);Serial.println("******************************");

  Serial.print(GCLK->GENCTRL.bit.ID);Serial.println(":4 bit: 0.. 3 Generic Clock Generator Selection ");
 // Serial.print(GCLK->GENCTRL.bit.);Serial.println(":4 bit: 4.. 7 Reserved ");
  Serial.print(GCLK->GENCTRL.bit.SRC);Serial.println(":5 bit: 8..12 Source Select ");
 //Serial.print(GCLK->GENCTRL.bit.);Serial.println(":3 bit: 13..15 Reserved ");
  Serial.print(GCLK->GENCTRL.bit.GENEN);Serial.println(":1 bit: 16 Generic Clock Generator Enable ");
  Serial.print(GCLK->GENCTRL.bit.IDC);Serial.println(":1 bit: 17 Improve Duty Cycle ");
  Serial.print(GCLK->GENCTRL.bit.OOV);Serial.println(":1 bit: 18 Output Off Value ");
  Serial.print(GCLK->GENCTRL.bit.OE);Serial.println(":1 bit: 19 Output Enable ");
  Serial.print(GCLK->GENCTRL.bit.DIVSEL);Serial.println(":1 bit: 20 Divide Selection ");
  Serial.print(GCLK->GENCTRL.bit.RUNSTDBY);Serial.println(":1 bit: 21 Run in Standby ");
 //Serial.print(GCLK->GENCTRL.bit.);Serial.println(":10 bit: 22..31 Reserved ");
Serial.print("***********************GENCTRL ID: "); Serial.print(i);Serial.println("******************************");
}


 Serial.println("GENDIV register:");
 Serial.println("");

 for (uint8_t i=0;i<9;i++) { 
    uint8_t *gendiv;
    gendiv = (uint8_t *) (0x40000C08UL);
    *gendiv=i;
    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
    
 Serial.print("GENDIV register "); Serial.println(i);
 Serial.print("***********************GENDIV ID: "); Serial.print(i);Serial.println("******************************");

 Serial.print(GCLK->GENDIV.bit.ID);Serial.println(":4: bit: 0.. 3 Generic Clock Generator Selection");
 //Serial.print(GCLK->GENDIV.bit.);Serial.println(":4: bit: 4.. 7 Reserved");
 Serial.print(GCLK->GENDIV.bit.DIV);Serial.println(":16: bit: 8..23 Division Factor");
 //Serial.print(GCLK->GENDIV.bit.);Serial.println(":8: bit: 24..31 Reserved");
Serial.print("***********************GENDIV ID: "); Serial.print(i);Serial.println("******************************");
}



Serial.println("SPI started");
/*
PORT->Group[g_APinDescription[6].ulPort].PINCFG[g_APinDescription[6].ulPin].bit.PMUXEN = 1;

  // Switch the port multiplexer to peripheral H (GCLK_IO[4])
  PORT->Group[g_APinDescription[6].ulPort].PMUX[g_APinDescription[6].ulPin >> 1].reg |= PORT_PMUX_PMUXE_H;
 */
}


void loop() {
  // put your main code here, to run repeatedly:

}
/*
void SERCOM5_Handler() //Outcommented the Variant.cpp SERCOM5_Handler function
{
  //  5 INTFLAGS TO BE DECODED
  //  BIT0  DRE   DATA REGISTER EMPTY
  //  BIT1  TXC   TRANSMIT COMPLETE
  //  BIT2  RXC   RECEIVE COMPLETE
  //  BIT3  SSL   SLAVE SELECT LOW
  //  BIT7  ERROR BUFOVR ERROR HAS OCCURRED
    uint8_t chr = 'a';    
  
  if (SERCOM5->SPI.INTFLAG.bit.SSL && SERCOM5->SPI.INTENSET.bit.SSL)
  {
    // FLAG IS SET WHEN nSS IS DETECTED GOING LOW
    // INITIALIZE STATE MACHINE & OTHER VARIABLES
    Serial.println("SS low detected");
    
    SERCOM5->SPI.DATA.reg = (uint32_t) 'a';                 // preload shift register with first outgoing data
    SERCOM5->SPI.INTFLAG.reg = SERCOM_SPI_INTFLAG_SSL;            // clear the flag
  }
  
  if (SERCOM5->SPI.INTFLAG.bit.DRE && SERCOM5->SPI.INTENSET.bit.DRE)
  {
    // NOTE - FLAG IS CLEARED BY WRITING NEW DATA TO DATA REGISTER
    // NOTE - NOT USED IN THIS APPLICATION

    Serial.println("DRE empty");

    if (chr > 'a'+26) chr='a'; else chr++;
    SERCOM5->SPI.DATA.reg = (uint32_t) chr;                     // dummy write
  }
  
  if (SERCOM5->SPI.INTFLAG.bit.TXC && SERCOM5->SPI.INTENSET.bit.TXC )
  {
    // NOTE - IN SLAVE MODE THIS BIT IS SET WHEN nSS IS PULLED HIGH
    Serial.println("SS High");

    SERCOM5->SPI.INTFLAG.reg = SERCOM_SPI_INTFLAG_TXC;

  }
  
  if (SERCOM5->SPI.INTFLAG.bit.RXC && SERCOM5->SPI.INTENSET.bit.RXC)
  {
    // NOTE - FLAG IS CLEARED BY READING THE DATA REGISTER
    // NOTE - SET WHEN AN ADDRESS MATCH IS DETECTED AS VALID DATA

  }
  
  if (SERCOM5->SPI.INTFLAG.bit.ERROR && SERCOM5->SPI.INTENSET.bit.ERROR)
  {
    SERCOM5->SPI.INTFLAG.reg = SERCOM_SPI_INTFLAG_ERROR;
  }
  
}
*/
