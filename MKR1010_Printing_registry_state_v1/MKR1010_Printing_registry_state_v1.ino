/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

String ID_selection(uint8_t grp,uint32_t id) {
  switch (grp){
    case 1:
      switch (id){
        case 0x00 : return " - GCLKDFLL48M_REF DFLL48M Reference"; break; 
        case 0x01 : return " - GCLKDPLL FDPLL96M input clock source for reference"; break; 
        case 0x02 : return " - GCLKDPLL_32K FDPLL96M 32kHz clock for FDPLL96M internal lock timer"; break; 
        case 0x03 : return " - GCLKWDT WDT"; break; 
        case 0x04 : return " - GCLKRTC RTC"; break; 
        case 0x05 : return " - GCLKEIC EIC"; break; 
        case 0x06 : return " - GCLKUSB USB"; break; 
        case 0x07 : return " - GCLKEVSYS_CHANNEL_0 EVSYS_CHANNEL_0"; break; 
        case 0x08 : return " - GCLKEVSYS_CHANNEL_1 EVSYS_CHANNEL_1"; break; 
        case 0x09 : return " - GCLKEVSYS_CHANNEL_2 EVSYS_CHANNEL_2"; break; 
        case 0x0A : return " - GCLKEVSYS_CHANNEL_3 EVSYS_CHANNEL_3"; break; 
        case 0x0B : return " - GCLKEVSYS_CHANNEL_4 EVSYS_CHANNEL_4"; break; 
        case 0x0C : return " - GCLKEVSYS_CHANNEL_5 EVSYS_CHANNEL_5"; break; 
        case 0x0D : return " - GCLKEVSYS_CHANNEL_6 EVSYS_CHANNEL_6"; break; 
        case 0x0E : return " - GCLKEVSYS_CHANNEL_7 EVSYS_CHANNEL_7"; break; 
        case 0x0F : return " - GCLKEVSYS_CHANNEL_8 EVSYS_CHANNEL_8"; break; 
        case 0x10 : return " - GCLKEVSYS_CHANNEL_9 EVSYS_CHANNEL_9"; break; 
        case 0x11 : return " - GCLKEVSYS_CHANNEL_10 EVSYS_CHANNEL_10"; break; 
        case 0x12 : return " - GCLKEVSYS_CHANNEL_11 EVSYS_CHANNEL_11"; break; 
        case 0x13 : return " - GCLKSERCOMx_SLOW SERCOMx_SLOW"; break; 
        case 0x14 : return " - GCLKSERCOM0_CORE SERCOM0_CORE"; break; 
        case 0x15 : return " - GCLKSERCOM1_CORE SERCOM1_CORE"; break; 
        case 0x16 : return " - GCLKSERCOM2_CORE SERCOM2_CORE"; break; 
        case 0x17 : return " - GCLKSERCOM3_CORE SERCOM3_CORE"; break; 
        case 0x18 : return " - GCLKSERCOM4_CORE SERCOM4_CORE"; break; 
        case 0x19 : return " - GCLKSERCOM5_CORE SERCOM5_CORE"; break; 
        case 0x1A : return " - GCLKTCC0,GCLK_TCC1 TCC0,TCC1"; break; 
        case 0x1B : return " - GCLKTCC2,GCLK_TC3 TCC2,TC3"; break; 
        case 0x1C : return " - GCLKTC4,GCLK_TC5 TC4,TC5"; break; 
        case 0x1D : return " - GCLKTC6,GCLK_TC7 TC6,TC7"; break; 
        case 0x1E : return " - GCLKADC ADC"; break; 
        case 0x1F : return " - GCLKAC_DIG AC_DIG"; break; 
        case 0x20 : return " - GCLKAC_ANA AC_ANA"; break; 
        case 0x21 : return " - GCLKDAC DAC"; break; 
        case 0x22 : return " - GCLKPTC PTCReserved"; break; 
        case 0x23 : return " - GCLKI2S_0 I2S_0"; break; 
        case 0x24 : return " - GCLKI2S_1 I2S_1";break;
      }
    case 2:
      switch(id){
        case 0x00: return" XOSC XOSC oscillator output"; break; 
        case 0x01: return" GCLKIN Generator input pad"; break; 
        case 0x02: return" GCLKGEN1 Generic clock generator 1 output"; break; 
        case 0x03: return" OSCULP32K OSCULP32K oscillator output"; break; 
        case 0x04: return" OSC32K OSC32K oscillator output"; break; 
        case 0x05: return" XOSC32K XOSC32K oscillator output"; break; 
        case 0x06: return" OSC8M OSC8M oscillator output"; break; 
        case 0x07: return" DFLL48M DFLL48M output"; break; 
        case 0x08: return" FDPLL96M FDPLL96M output"; break;  
      }
      break;
  }
  return "";
}


void setup() {
// Start serial monitor
   Serial.begin(115200);
  while(!Serial){};
  Serial.println("Begin");


            GCLK->GENCTRL.reg = GCLK_GENCTRL_ID( (4u) ) | // Generic Clock Generator 3
                      GCLK_GENCTRL_SRC_OSC8M | // Selected source is RC OSC 8MHz (already enabled at reset)
                      GCLK_GENCTRL_OE | // Output clock to a pin for tests
                      GCLK_GENCTRL_GENEN ;
  // Enable the port multiplexer for pin PA6
    PORT->Group[g_APinDescription[6].ulPort].PINCFG[g_APinDescription[6].ulPin].bit.PMUXEN = 1;
  // Switch the port multiplexer for pin PA6 to peripheral H (GCLK_IO[4])
  PORT->Group[g_APinDescription[6].ulPort].PMUX[g_APinDescription[6].ulPin >> 1].reg |= PORT_PMUX_PMUXE_H;
  Serial.println("");

 for (uint8_t i=0;i<25;i++) { 
    uint8_t *clkctrl;
    clkctrl = (uint8_t *) (0x40000C02UL);
    *clkctrl=i;
    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
    
  Serial.print("***********************CLKCTRL ID: "); Serial.print(i);Serial.println("******************************");
               Serial.print(GCLK->CLKCTRL.bit.ID); Serial.println(ID_selection(1,(uint32_t) GCLK->CLKCTRL.bit.ID));// Serial.println("            :6 bit: 0.. 5 Generic Clock Selection ID");
               //Serial.print(GCLK->CLKCTRL.bit.); Serial.println("            :2 bit): 6.. 7 Reserved ");
               Serial.print(GCLK->CLKCTRL.bit.GEN); Serial.println("            :4 bit: 8..11 Generic Clock Generator");
               //Serial.print(GCLK->CLKCTRL.bit.); Serial.println("            :2 bit: 12..13 Reserved ");
               Serial.print(GCLK->CLKCTRL.bit.CLKEN); Serial.println("            :1 bit: 14 Clock Enable ");
               Serial.print(GCLK->CLKCTRL.bit.WRTLOCK); Serial.println("            :1 bit: 15 Write Lock ");
 }

 for (uint8_t i=0;i<9;i++) { 
    uint8_t *genctrl;
    genctrl = (uint8_t *) (0x40000C04UL);
    *genctrl=i;
    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
    
 Serial.print("***********************GENCTRL ID: "); Serial.print(i);Serial.println("******************************");
                Serial.print(GCLK->GENCTRL.bit.ID);Serial.println("            :4 bit: 0.. 3 Generic Clock Generator Selection ");
               // Serial.print(GCLK->GENCTRL.bit.);Serial.println("            :4 bit: 4.. 7 Reserved ");
                Serial.print(GCLK->GENCTRL.bit.SRC);Serial.print("            ");Serial.println(ID_selection(2,(uint32_t) GCLK->GENCTRL.bit.SRC));//;Serial.println("            :5 bit: 8..12 Source Select ");
               //Serial.print(GCLK->GENCTRL.bit.);Serial.println("            :3 bit: 13..15 Reserved ");
                Serial.print(GCLK->GENCTRL.bit.GENEN);Serial.println("            :1 bit: 16 Generic Clock Generator Enable ");
                Serial.print(GCLK->GENCTRL.bit.IDC);Serial.println("            :1 bit: 17 Improve Duty Cycle ");
                Serial.print(GCLK->GENCTRL.bit.OOV);Serial.println("            :1 bit: 18 Output Off Value ");
                Serial.print(GCLK->GENCTRL.bit.OE);Serial.println("            :1 bit: 19 Output Enable ");
                Serial.print(GCLK->GENCTRL.bit.DIVSEL);Serial.println("            :1 bit: 20 Divide Selection ");
                Serial.print(GCLK->GENCTRL.bit.RUNSTDBY);Serial.println("            :1 bit: 21 Run in Standby ");
               //Serial.print(GCLK->GENCTRL.bit.);Serial.println("            :10 bit: 22..31 Reserved ");
}

 for (uint8_t i=0;i<9;i++) { 
    uint8_t *gendiv;
    gendiv = (uint8_t *) (0x40000C08UL);
    *gendiv=i;
    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
    
 Serial.print("***********************GENDIV ID: "); Serial.print(i);Serial.println("******************************");
               Serial.print(GCLK->GENDIV.bit.ID);Serial.println("            :4: bit: 0.. 3 Generic Clock Generator Selection");
               //Serial.print(GCLK->GENDIV.bit.);Serial.println("            :4: bit: 4.. 7 Reserved");
               Serial.print(GCLK->GENDIV.bit.DIV);Serial.println("            :16: bit: 8..23 Division Factor");
               //Serial.print(GCLK->GENDIV.bit.);Serial.println("            :8: bit: 24..31 Reserved");
}

Serial.println("***********************CPUSEL******************************");
               Serial.print(PM->CPUSEL.bit.CPUDIV); Serial.println("            :3 bit:  0.. 2  CPU Prescaler Selection");
               //Serial.print(PM->CPUSEL.bit.)& Serial.printlin(":5 bit:  3.. 7  Reserved");
Serial.println("***********************CPUSEL******************************");
Serial.println("***********************APBASEL******************************");
                Serial.print(PM->APBASEL.bit.APBADIV); Serial.println("            :3 bit:  0.. 2  APBA Prescaler Selection");
              //  Serial.print(PM->APBASEL.bit.); Serial.println("            :5 bit:  3.. 7  Reserved");
Serial.println("***********************APBASEL******************************");
Serial.println("***********************APBBSEL******************************");
                Serial.print(PM->APBBSEL.bit.APBBDIV); Serial.println("            :3 bit:  0.. 2  APBB Prescaler Selection");
               // Serial.print(PM->APBBSEL.bit.); Serial.println("            :5 bit:  3.. 7  Reserved");
Serial.println("***********************APBBSEL******************************");
Serial.println("***********************APBCSEL******************************");
                Serial.print(PM->APBCSEL.bit.APBCDIV); Serial.println("            :3 bit:  0.. 2  APBC Prescaler Selection");
               // Serial.print(PM->APBCSEL.bit.); Serial.println("            :5 bit:  3.. 7  Reserved");
Serial.println("***********************AHBMASK******************************");
                 Serial.print(PM->AHBMASK.bit.HPB0_); Serial.println("            :1 bit 0 HPB0 AHB Clock Mask");
                 Serial.print(PM->AHBMASK.bit.HPB1_); Serial.println("            :1 bit 1 HPB1 AHB Clock Mask");
                 Serial.print(PM->AHBMASK.bit.HPB2_); Serial.println("            :1 bit 2 HPB2 AHB Clock Mask");
                 Serial.print(PM->AHBMASK.bit.DSU_); Serial.println("            :1 bit 3 DSU AHB Clock Mask");
                 Serial.print(PM->AHBMASK.bit.NVMCTRL_); Serial.println("            :1 bit 4 NVMCTRL AHB Clock Mask");
                 Serial.print(PM->AHBMASK.bit.DMAC_); Serial.println("            :1 bit 5 DMAC AHB Clock Mask");
                 Serial.print(PM->AHBMASK.bit.USB_); Serial.println("            :1 bit 6 USB AHB Clock Mask");
                 //Serial.print(PM->AHBMASK.bit.); Serial.println(:25 bit 7..31 Reserved");
Serial.println("***********************AHBMASK******************************");
Serial.println("***********************APBAMASK******************************");
               Serial.print(PM->APBAMASK.bit.PAC0_); Serial.println("            :1 bit: 0 PAC0 APB Clock Enable ");
               Serial.print(PM->APBAMASK.bit.PM_); Serial.println("            :1 bit: 1 PM APB Clock Enable ");
               Serial.print(PM->APBAMASK.bit.SYSCTRL_); Serial.println("            :1 bit: 2 SYSCTRL APB Clock Enable ");
               Serial.print(PM->APBAMASK.bit.GCLK_); Serial.println("            :1 bit: 3 GCLK APB Clock Enable ");
               Serial.print(PM->APBAMASK.bit.WDT_); Serial.println("            :1 bit: 4 WDT APB Clock Enable ");
               Serial.print(PM->APBAMASK.bit.RTC_); Serial.println("            :1 bit: 5 RTC APB Clock Enable ");
               Serial.print(PM->APBAMASK.bit.EIC_); Serial.println("            :1 bit: 6 EIC APB Clock Enable ");
              // Serial.print(PM->APBAMASK.bit.); Serial.println("            :25 bit: 7..31 Reserved "); 
Serial.println("***********************APBAMASK******************************"); 
Serial.println("***********************APBBMASK******************************"); 
               Serial.print(PM->APBBMASK.bit.PAC1_); Serial.println("            :1 bit: 0 PAC1 APB Clock Enable ");
               Serial.print(PM->APBBMASK.bit.DSU_); Serial.println("            :1 bit: 1 DSU APB Clock Enable ");
               Serial.print(PM->APBBMASK.bit.NVMCTRL_); Serial.println("            :1 bit: 2 NVMCTRL APB Clock Enable ");
               Serial.print(PM->APBBMASK.bit.PORT_); Serial.println("            :1 bit: 3 PORT APB Clock Enable ");
               Serial.print(PM->APBBMASK.bit.DMAC_); Serial.println("            :1 bit: 4 DMAC APB Clock Enable ");
               Serial.print(PM->APBBMASK.bit.USB_); Serial.println("            :1 bit: 5 USB APB Clock Enable ");
               Serial.print(PM->APBBMASK.bit.HMATRIX_); Serial.println("            :1 bit: 6 HMATRIX APB Clock Enable ");
              // Serial.print(PM->APBBMASK.bit.); Serial.println("            :25 bit: 7..31 Reserved ");
Serial.println("***********************APBBMASK******************************");  
 
Serial.println("***********************APBCMASK******************************");
                 Serial.print(PM->APBCMASK.bit.PAC2_); Serial.println("            :1 bit: 0 PAC2 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.EVSYS_); Serial.println("            :1 bit: 1 EVSYS APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM0_); Serial.println("            :1 bit: 2 SERCOM0 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM1_); Serial.println("            :1 bit: 3 SERCOM1 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM2_); Serial.println("            :1 bit: 4 SERCOM2 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM3_); Serial.println("            :1 bit: 5 SERCOM3 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM4_); Serial.println("            :1 bit: 6 SERCOM4 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.SERCOM5_); Serial.println("            :1 bit: 7 SERCOM5 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TCC0_); Serial.println("            :1 bit: 8 TCC0 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TCC1_); Serial.println("            :1 bit: 9 TCC1 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TCC2_); Serial.println("            :1 bit: 10 TCC2 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC3_); Serial.println("            :1 bit: 11 TC3 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC4_); Serial.println("            :1 bit: 12 TC4 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC5_); Serial.println("            :1 bit: 13 TC5 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC6_); Serial.println("            :1 bit: 14 TC6 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.TC7_); Serial.println("            :1 bit: 15 TC7 APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.ADC_); Serial.println("            :1 bit: 16 ADC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.AC_); Serial.println("            :1 bit: 17 AC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.DAC_); Serial.println("            :1 bit: 18 DAC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.PTC_); Serial.println("            :1 bit: 19 PTC APB Clock Enable ");
                 Serial.print(PM->APBCMASK.bit.I2S_); Serial.println("            :1 bit: 20 I2S APB Clock Enable ");
Serial.println("***********************APBCMASK******************************");
Serial.println("***********************RCAUSE******************************");
                   Serial.print(PM->RCAUSE.bit.POR); Serial.println("            :1  bit: 0 Power On Reset");
                   Serial.print(PM->RCAUSE.bit.BOD12); Serial.println("            :1  bit: 1 Brown Out 12 Detector Reset");
                   Serial.print(PM->RCAUSE.bit.BOD33); Serial.println("            :1  bit: 2 Brown Out 33 Detector Reset");
                 //  Serial.print(PM->RCAUSE.bit. ); Serial.println("            :1  bit: 3 Reserved");
                   Serial.print(PM->RCAUSE.bit.EXT); Serial.println("            :1  bit: 4 External Reset");
                 //??????  Serial.print(PM->RCAUSE.bit.WDT); Serial.println("            :1  bit: 5 Watchdog Reset");
                   Serial.print(PM->RCAUSE.bit.SYST); Serial.println("            :1  bit: 6 System Reset Request");
                  // Serial.print(PM->RCAUSE.bit. ); Serial.println("            :1  bit: 7 Reserved");
Serial.println("***********************RCAUSE******************************");

Serial.println("***********************PCLKSR******************************");
               Serial.print(SYSCTRL->PCLKSR.bit.XOSCRDY); Serial.println("            :1 bit: 0 XOSC Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.XOSC32KRDY); Serial.println("            :1 bit: 1 XOSC32K Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.OSC32KRDY); Serial.println("            :1 bit: 2 OSC32K Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.OSC8MRDY); Serial.println("            :1 bit: 3 OSC8M Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLRDY); Serial.println("            :1 bit: 4 DFLL Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLOOB); Serial.println("            :1 bit: 5 DFLL Out Of Bounds");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLLCKF); Serial.println("            :1 bit: 6 DFLL Lock Fine");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLLCKC); Serial.println("            :1 bit: 7 DFLL Lock Coarse");
               Serial.print(SYSCTRL->PCLKSR.bit.DFLLRCS); Serial.println("            :1 bit: 8 DFLL Reference Clock Stopped");
               Serial.print(SYSCTRL->PCLKSR.bit.BOD33RDY); Serial.println("            :1 bit: 9 BOD33 Ready");
               Serial.print(SYSCTRL->PCLKSR.bit.BOD33DET); Serial.println("            :1 bit: 10 BOD33 Detection");
               Serial.print(SYSCTRL->PCLKSR.bit.B33SRDY); Serial.println("            :1 bit: 11 BOD33 Synchronization Ready");
               //Serial.print(SYSCTRL->PCLKSR.bit.:3;bit: 12..14 Reserved");
               Serial.print(SYSCTRL->PCLKSR.bit.DPLLLCKR); Serial.println("            :1 bit: 15 DPLL Lock Rise");
               Serial.print(SYSCTRL->PCLKSR.bit.DPLLLCKF); Serial.println("            :1 bit: 16 DPLL Lock Fall");
               Serial.print(SYSCTRL->PCLKSR.bit.DPLLLTO); Serial.println("            :1 bit: 17 DPLL Lock Timeout");
               //Serial.print(SYSCTRL->PCLKSR.bit.:14;bit: 18..31 Reserved");
Serial.println("***********************PCLKSR******************************");

Serial.println("***********************XOSC******************************");
               //Serial.print(); Serial.println("            :1 bit: 0 Reserved");
               Serial.print(SYSCTRL->XOSC.bit.ENABLE); Serial.println("            :1 bit: 1 Oscillator Enable");
               Serial.print(SYSCTRL->XOSC.bit.XTALEN); Serial.println("            :1 bit: 2 Crystal Oscillator Enable");
               //Serial.print(":3; bit: 3.. 5 Reserved");
               Serial.print(SYSCTRL->XOSC.bit.RUNSTDBY); Serial.println("            :1 bit: 6 Run in Standby");
               Serial.print(SYSCTRL->XOSC.bit.ONDEMAND); Serial.println("            :1 bit: 7 On Demand Control");
               Serial.print(SYSCTRL->XOSC.bit.GAIN); Serial.println("            :3; bit: 8..10 Oscillator Gain");
               Serial.print(SYSCTRL->XOSC.bit.AMPGC); Serial.println("            :1 bit: 11 Automatic Amplitude Gain Control");
               Serial.print(SYSCTRL->XOSC.bit.STARTUP); Serial.println("            :4; bit: 12..15 Start-Up Time");
Serial.println("***********************XOSC******************************");

Serial.println("***********************XOSC32K******************************");
              // Serial.print(SYSCTRL->XOSC32K.bit.); Serial.println("            :1 bit: 0 Reserved");
               Serial.print(SYSCTRL->XOSC32K.bit.ENABLE); Serial.println("            :1 bit: 1 Oscillator Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.XTALEN); Serial.println("            :1 bit: 2 Crystal Oscillator Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.EN32K); Serial.println("            :1 bit: 3 32kHz Output Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.EN1K); Serial.println("            :1 bit: 4 1kHz Output Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.AAMPEN); Serial.println("            :1 bit: 5 Automatic Amplitude Control Enable");
               Serial.print(SYSCTRL->XOSC32K.bit.RUNSTDBY); Serial.println("            :1 bit: 6 Run in Standby");
               Serial.print(SYSCTRL->XOSC32K.bit.ONDEMAND); Serial.println("            :1 bit: 7 On Demand Control");
               Serial.print(SYSCTRL->XOSC32K.bit.STARTUP); Serial.println("            :3 bit: 8..10 Oscillator Start-Up Time");
              // Serial.print(SYSCTRL->XOSC32K.bit.); Serial.println("            :1 bit: 11 Reserved");
               Serial.print(SYSCTRL->XOSC32K.bit.WRTLOCK); Serial.println("            :1 bit: 12 Write Lock");
              // Serial.print(SYSCTRL->XOSC32K.bit.); Serial.println("            :3 bit: 13..15 Reserved");
Serial.println("***********************XOSC32K******************************");

Serial.println("***********************OSC32K******************************");
            // Serial.print(SYSCTRL->OSC32K.bit.); Serial.println("            :1 bit: 0 Reserved");
             Serial.print(SYSCTRL->OSC32K.bit.ENABLE); Serial.println("            :1 bit: 1 Oscillator Enable");
             Serial.print(SYSCTRL->OSC32K.bit.EN32K); Serial.println("            :1 bit: 2 32kHz Output Enable");
             Serial.print(SYSCTRL->OSC32K.bit.EN1K); Serial.println("            :1 bit: 3 1kHz Output Enable");
            // Serial.print(SYSCTRL->OSC32K.bit.:2; bit: 4.. 5 Reserved");
             Serial.print(SYSCTRL->OSC32K.bit.RUNSTDBY); Serial.println("            :1 bit: 6 Run in Standby");
             Serial.print(SYSCTRL->OSC32K.bit.ONDEMAND); Serial.println("            :1 bit: 7 On Demand Control");
             Serial.print(SYSCTRL->OSC32K.bit.STARTUP); Serial.println("            :3 bit: 8..10 Oscillator Start-Up Time");
            // Serial.print(SYSCTRL->OSC32K.bit.); Serial.println("            :1 bit: 11 Reserved");
             Serial.print(SYSCTRL->OSC32K.bit.WRTLOCK); Serial.println("            :1 bit: 12 Write Lock");
            // Serial.print(SYSCTRL->OSC32K.bit.); Serial.println("            :3 bit: 13..15 Reserved");
             Serial.print(SYSCTRL->OSC32K.bit.CALIB); Serial.println("            :7 bit: 16..22 Oscillator Calibration");
            // Serial.print(SYSCTRL->OSC32K.bit.:9; bit: 23..31 Reserved");
Serial.println("***********************OSC32K******************************");
Serial.println("***********************OSCULP32K******************************");
             Serial.print(SYSCTRL->OSCULP32K.bit.CALIB); Serial.println("            :5 bit: 0.. 4 Oscillator Calibration/");
            // Serial.print(SYSCTRL->OSCULP32K.bit.); Serial.println("            :2 5.. 6 Reserved");
             Serial.print(SYSCTRL->OSCULP32K.bit.WRTLOCK); Serial.println("            :1 bit: 7 Write Lock");
Serial.println("***********************OSCULP32K******************************");
Serial.println("***********************OSC8M******************************");
               //Serial.print(SYSCTRL->OSC8M.bit.); Serial.println("            :1 bit: 0 Reserved ");
               Serial.print(SYSCTRL->OSC8M.bit.ENABLE); Serial.println("            :1 bit: 1 Oscillator Enable ");
               //Serial.print(SYSCTRL->OSC8M.bit.); Serial.println("            :4 bit: 2.. 5 Reserved ");
               Serial.print(SYSCTRL->OSC8M.bit.RUNSTDBY); Serial.println("            :1 bit: 6 Run in Standby ");
               Serial.print(SYSCTRL->OSC8M.bit.ONDEMAND); Serial.println("            :1 bit: 7 On Demand Control ");
               Serial.print(SYSCTRL->OSC8M.bit.PRESC); Serial.println("            :2 bit: 8.. 9 Oscillator Prescaler ");
               //Serial.print(SYSCTRL->OSC8M.bit.); Serial.println("            :6 bit: 10..15 Reserved ");
               Serial.print(SYSCTRL->OSC8M.bit.CALIB); Serial.println("            :12 bit: 16..27 Oscillator Calibration ");
               //Serial.print(SYSCTRL->OSC8M.bit.); Serial.println("            :2 bit: 28..29 Reserved ");
               Serial.print(SYSCTRL->OSC8M.bit.FRANGE); Serial.println("            :2 bit: 30..31 Oscillator Frequency Range ");
Serial.println("***********************OSC8M******************************");
Serial.println("***********************DFLLCTRL******************************");
              // Serial.print(SYSCTRL->DFLLCTRL.bit.); Serial.println("            :1  bit: 0 Reserved ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.ENABLE); Serial.println("            :1  bit: 1 DFLL Enable ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.MODE); Serial.println("            :1  bit: 2 Operating Mode Selection ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.STABLE); Serial.println("            :1  bit: 3 Stable DFLL Frequency ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.LLAW); Serial.println("            :1  bit: 4 Lose Lock After Wake ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.USBCRM); Serial.println("            :1  bit: 5 USB Clock Recovery Mode ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.RUNSTDBY); Serial.println("            :1  bit: 6 Run in Standby ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.ONDEMAND); Serial.println("            :1  bit: 7 On Demand Control ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.CCDIS); Serial.println("            :1  bit: 8 Chill Cycle Disable ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.QLDIS); Serial.println("            :1  bit: 9 Quick Lock Disable ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.BPLCKC); Serial.println("            :1  bit: 10 Bypass Coarse Lock ");
               Serial.print(SYSCTRL->DFLLCTRL.bit.WAITLOCK); Serial.println("            :1  bit: 11 Wait Lock ");
              // Serial.print(SYSCTRL->DFLLCTRL.bit.); Serial.println("            :4;  bit: 12..15 Reserved ");
Serial.println("***********************DFLLCTRL******************************");

Serial.println("***********************VREF******************************");
              // Serial.print(SYSCTRL->VREF.bit.); Serial.println("            :1  bit: 0 Reserved ");
               Serial.print(SYSCTRL->VREF.bit.TSEN); Serial.println("            :1  bit: 1 Temperature Sensor Enable ");
               Serial.print(SYSCTRL->VREF.bit.BGOUTEN); Serial.println("            :1  bit: 2 Bandgap Output Enable ");
             //  Serial.print(SYSCTRL->VREF.bit.); Serial.println("            :13  bit: 3..15 Reserved ");
               Serial.print(SYSCTRL->VREF.bit.CALIB); Serial.println("            :11 bit: 16..26 Bandgap Voltage Generator Calibration ");
              // Serial.print(SYSCTRL->VREF.bit.); Serial.println("            :5  bit: 27..31 Reserved ");
Serial.println("***********************VREF******************************");
Serial.println("***********************DPLLCTRLA******************************");
             //  Serial.print(SYSCTRL->DPLLCTRLA.bit.); Serial.println("            :1  bit: 0 Reserved ");
               Serial.print(SYSCTRL->DPLLCTRLA.bit.ENABLE); Serial.println("            :1  bit: 1 DPLL Enable ");
             //  Serial.print(SYSCTRL->DPLLCTRLA.bit.); Serial.println(" :4  bit: 2.. 5 Reserved ");
               Serial.print(SYSCTRL->DPLLCTRLA.bit.RUNSTDBY); Serial.println("            :1  bit: 6 Run in Standby ");
               Serial.print(SYSCTRL->DPLLCTRLA.bit.ONDEMAND); Serial.println("            :1  bit: 7 On Demand Clock Activation ");
Serial.println("***********************DPLLCTRLA******************************");
Serial.println("***********************DPLLCTRLB******************************");
               Serial.print(SYSCTRL->DPLLCTRLB.bit.FILTER); Serial.println("            :2;  bit: 0.. 1 Proportional Integral Filter Selection");
               Serial.print(SYSCTRL->DPLLCTRLB.bit.LPEN); Serial.println("            :1;  bit: 2 Low-Power Enable");
               Serial.print(SYSCTRL->DPLLCTRLB.bit.WUF); Serial.println("            :1;  bit: 3 Wake Up Fast");
               Serial.print(SYSCTRL->DPLLCTRLB.bit.REFCLK); Serial.println("            :2;  bit: 4.. 5 Reference Clock Selection");
              // Serial.print(SYSCTRL->DPLLCTRLB.bit.); Serial.println("            :2;  bit: 6.. 7 Reserved");
               Serial.print(SYSCTRL->DPLLCTRLB.bit.LTIME); Serial.println("            :3;  bit: 8..10 Lock Time");
              // Serial.print(SYSCTRL->DPLLCTRLB.bit.); Serial.println("            :1;  bit: 11 Reserved");
               Serial.print(SYSCTRL->DPLLCTRLB.bit.LBYPASS); Serial.println("            :1;  bit: 12 Lock Bypass");
              // Serial.print(SYSCTRL->DPLLCTRLB.bit.); Serial.println("            :3;  bit: 13..15 Reserved");
               Serial.print(SYSCTRL->DPLLCTRLB.bit.DIV); Serial.println("            :11;  bit: 16..26 Clock Divider");
              // Serial.print(SYSCTRL->DPLLCTRLB.bit.); Serial.println("            :5;  bit: 27..31 Reserved");
Serial.println("***********************DPLLCTRLB******************************");

Serial.println("***********************DPLLSTATUS******************************");
               Serial.print(SYSCTRL->DPLLSTATUS.bit.LOCK); Serial.println("            :1 bit: 0 DPLL Lock Status");
               Serial.print(SYSCTRL->DPLLSTATUS.bit.CLKRDY); Serial.println("            :1 bit: 1 Output Clock Ready");
               Serial.print(SYSCTRL->DPLLSTATUS.bit.ENABLE); Serial.println("            :1 bit: 2 DPLL Enable");
               Serial.print(SYSCTRL->DPLLSTATUS.bit.DIV); Serial.println("            :1 bit: 3 Divider Enable");
              // Serial.print(SYSCTRL->DPLLSTATUS.bit.); Serial.println("            :4 bit: 4.. 7 Reserved");
Serial.println("***********************DPLLSTATUS******************************");

for (uint8_t y=1;y<3;y++) { 
    Serial.print("***********************PORT "); Serial.print(y); Serial.println("**********************************");
              Serial.print(PORT->Group[y].DIR.bit.DIR,BIN); Serial.println("            :bit  0..31  Port Data Direction");
              Serial.print(PORT->Group[y].OUT.bit.OUT,BIN); Serial.println("            :bit  0..31  Port Data Output Value");
              Serial.print(PORT->Group[y].IN.bit.IN,BIN); Serial.println("            :bit  0..31  Port Data Input Value");
              Serial.print(PORT->Group[y].CTRL.bit.SAMPLING,BIN); Serial.println("            :bit:  0..31  Input Sampling Mode");
              for (uint8_t i=0;i<16;i++) {
                Serial.print(2*i); Serial.print("&"); Serial.print(2*i+2); Serial.print("-");Serial.print(PORT->Group[y].PMUX[i].bit.PMUXE); Serial.println("            bit 0.. 3  Peripheral Multiplexing Even");
                Serial.print(2*i+1); Serial.print("&"); Serial.print(2*i+3); Serial.print("-"); Serial.print(PORT->Group[y].PMUX[i].bit.PMUXO); Serial.println("         bit 4.. 7  Peripheral Multiplexing Odd");
              }
              for (uint8_t i=0;i<32;i++) {
                Serial.print("********Pin:");Serial.print(i); Serial.print(" on port: "); Serial.print(y); Serial.println("************"); Serial.print("    ");
                Serial.print(PORT->Group[y].PINCFG[i].bit.PMUXEN); Serial.println("            :1 bit 0 Peripheral Multiplexer Enable "); Serial.print("    ");
                 Serial.print(PORT->Group[y].PINCFG[i].bit.INEN); Serial.println("            :1 bit 1 Input Enable "); Serial.print("    ");
                Serial.print(PORT->Group[y].PINCFG[i].bit.PULLEN); Serial.println("            :1 bit 2 Pull Enable "); Serial.print("    ");
               //Serial.print(PORT->Group[y].PINCFG[i].bit.); Serial.println("            :3 bit 3.. 5 Reserved "); Serial.print("    ");
                Serial.print(PORT->Group[y].PINCFG[i].bit.DRVSTR); Serial.println("            :1 bit 6 Output Driver Strength Selection ");
               //Serial.print(PORT->Group[y].PINCFG[i].bit.); Serial.println("            :1 bit 7 Reserved ");
               //Serial.print("********Pin:");Serial.print(i); Serial.println("************");
              }
  Serial.print("***********************PORT "); Serial.print(y); Serial.println("**********************************");
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
