//****************************************************************************
// @Module        Capture / Compare Unit 62 (CCU62)
// @Filename      CCU62.C
// @Project       DAvE_config.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains functions that use the CCU62 module.
//
//----------------------------------------------------------------------------
// @Date          29.09.2021 09:41:09
//
//****************************************************************************

// USER CODE BEGIN (CCU62_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (CCU62_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CCU62_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (CCU62_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CCU62_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU62_General,6)
	extern const unsigned int ARRAY_SIZE;
	extern	unsigned int index;
	extern volatile unsigned int rampIndex;
// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU62_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (CCU62_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (CCU62_General,9)

// USER CODE END


//****************************************************************************
// @Function      void CCU62_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the CCU62 function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          29.09.2021
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void CCU62_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of KERNEL REGISTERS :
  ///  -----------------------------------------------------------------------
  ///  - CCU62 Module is enabled.
  ///  - The CCU62 module clock = 65,000 MHz. 
  ///  - T12 is enabled.
  ///  - T13 is enabled.
  ///  - MCM is enabled.

  CCU62_KSCFG    =  0x0003;      // Kernel State Configuration Register


  _nop();    //No operation function as Delay
  _nop();    //No operation function as Delay
  _nop();    //No operation function as Delay
  _nop();    //No operation function as Delay

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 Timer 12:
  ///  -----------------------------------------------------------------------
  ///  - Timer 12 Input clock factor (T12CLK) is 0
  ///  - prescaler factor is 0
  ///  - Timer 12 run bit is reset
  ///  - Single shot mode is disabled
  ///  - Timer 12 works in edge aligned mode
  ///  - Interrupt on period match is enabled
  ///  - Interrupt on one match is disabled
  ///  - No External run selection is selected.
  ///  - Timer mode is selected.
  ///  - 

  CCU62_T12PR    =  0x0595;      // load CCU62 T12 period register

  ///  -----------------------------------------------------------------------
  ///  Configuration of T13HR Signal:
  ///  -----------------------------------------------------------------------
  ///  - Signal T13HRB is selected as Input
  CCU62_PISELH   =  0x0021;      // Load CCU62 Port Input Selection register


  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 Timer 13:
  ///  -----------------------------------------------------------------------
  ///  - Timer 13 Input Clock factor (T13CLK) is 0
  ///  - prescaler factor is 0
  ///  - Timer 13 run bit is reset
  ///  - Trigger control is disabled
  ///  - No External run selection is selected.
  ///  - Counter mode is selected.
  ///  - Counter mode Counts the rising edges at the input T13HR.
  ///  - Single shot mode is disabled
  ///  - Interrupt on period match is disabled
  ///  - Interrupt on compare match is disabled

  CCU62_T13PR    =  0x0001;      // load CCU62 T13 period register

  CCU62_TCTR2    =  0x0020;      // load CCU62 timer control register 2

  ///  -----------------------------------------------------------------------
  ///  Configuration of Multi Channel Mode:
  ///  -----------------------------------------------------------------------
  ///  - Multi channel mode is disabled


  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 Channel 0:
  ///  -----------------------------------------------------------------------
  ///  - Channel 0 is disabled
  ///  - T12 modulation for output CC60 is disabled
  ///  - T13 modulation for output CC60 is disabled
  ///  - T13 modulation for output CC60 is disabled

  ///  - Generation interrupt on flag ICC60R is disabled
  ///  - Generation interrupt on flag ICC60F is disabled

  CCU62_CC60SR   =  0x0000;      // Load CCU62 capture/compare shadow 
                                 // register for channel 0

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 Channel 1:
  ///  -----------------------------------------------------------------------
  ///  - Channel 1 is disabled
  ///  - T12 modulation for output CC61 is disabled
  ///  - T13 modulation for output CC61 is disabled
  ///  - T13 modulation for output CC61 is disabled

  ///  - Generation interrupt on flag ICC61R is disabled
  ///  - Generation interrupt on flag ICC61F is disabled

  CCU62_CC61SR   =  0x0000;      // Load CCU62 capture/compare shadow 
                                 // register for channel 1

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 Channel 2:
  ///  -----------------------------------------------------------------------
  ///  - Channel 2 is disabled
  ///  - T12 modulation for output CC62 is disabled
  ///  - T13 modulation for output CC62 is disabled
  ///  - T13 modulation for output CC62 is disabled

  ///  - Generation interrupt on flag ICC62R is disabled
  ///  - Generation interrupt on flag ICC62F is disabled

  CCU62_CC62SR   =  0x0000;      // Load CCU62 capture/compare shadow 
                                 // register for channel 2

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 Channel 3:
  ///  -----------------------------------------------------------------------
  ///  - T13 output is not inverted


  CCU62_CC63SR   =  0x0000;      // load CCU62 capture/compare shadow 
                                 // register for channel 3


  CCU62_T12DTC   =  0x0001;      // load CCU62 dead time control register for 
                                 // timer T12

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 trap control:
  ///  -----------------------------------------------------------------------
  ///  - Trap can only be generated by SW by setting the bit TRPF
  ///  - The trap state is left when a zero-match of T12 (while counting up) 
  ///    is detected (synchronization to T12)
  ///  - Bit TRPF is automatically cleared by HW (according to TRPPEN, TRPM0 
  ///    and TRPM1)
  ///  - Trap interrupt is disabled


  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU62 interrupt control:
  ///  -----------------------------------------------------------------------
  ///  - For channel 0 interrupts is node I0 selected
  ///  - For channel 1 interrupts is node I0 selected
  ///  - For channel 2 interrupts is node I0 selected
  ///  - For correct hall event interrupt is node I0 selected
  ///  - For error interrupts is node I0 selected
  ///  - For T12 interrupts is node I0 selected
  ///  - For T13 interrupts is node I0 selected


  CCU62_INP      =  0x0000;      // Load CCU62 capture/compare interrupt node 
                                 // pointer register

  CCU62_IEN      =  0x0080;      // Load CCU62 capture/compare interrupt 
                                 // enable register


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CCU62 Channel Port Pins:
  ///  -----------------------------------------------------------------------


  CCU62_PISELL   =  0x3FC0;      // Load CCU62 Port Input Selection register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CCU62 Channels Interrupts:
  ///  -----------------------------------------------------------------------
  ///  NodeI0 service request node configuration:
  ///  - NodeI0 interrupt priority level (ILVL) = 13
  ///  - NodeI0 interrupt group level (GLVL) = 0
  ///  - NodeI0 group priority extension (GPX) = 0

  CCU62_0IC      =  0x0074;     


  ///  -----------------------------------------------------------------------
  ///  Configuration of T12, T13 ---- CCU62_TCTR4 Register:
  ///  -----------------------------------------------------------------------
  ///  - Enable shadow transfer of T12 and T13
  ///  - Timer 12 run bit is reset
  ///  - Timer 13 run bit is reset
  CCU62_TCTR4    =  0x4040;      // load CCU62 timer control register 4


  // USER CODE BEGIN (NodeI3,3)

  // USER CODE END

} //  End of function CCU62_vInit


//****************************************************************************
// @Function      void CCU62_viNodeI0(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CCU62 node 
//                I0. If the content of the corresponding compare timer 
//                (configurable) equals the content of the capture/compare 
//                register or if a capture event occurs at the associated 
//                port pin, the interrupt request flag is set and an 
//                interrupt is triggered (only if enabled).
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          29.09.2021
//
//****************************************************************************

// USER CODE BEGIN (NodeI0,1)

// USER CODE END

_interrupt(CCU62_NodeI0_INT)  void CCU62_viNodeI0(void)
{
  // USER CODE BEGIN (NodeI0,2)

  // USER CODE END

  if(CCU62_IS & 0x0080)  // if CCU62_IS_T12PM
  {
    // Timer T12 period match detection

    // USER CODE BEGIN (NodeI0,19)
	  if(rampIndex < 5250 && rampIndex > 4500){
	  }
	  else{
	  index++;
	  index = index%ARRAY_SIZE;
	  }
    // USER CODE END

    CCU62_ISR |= 0x0080;  // clear flag CCU62_IS_T12PM
  }


} //  End of function CCU62_viNodeI0




// USER CODE BEGIN (CCU62_General,10)

// USER CODE END

