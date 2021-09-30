//****************************************************************************
// @Module        General Purpose Timer Unit (GPT2)
// @Filename      GPT2.C
// @Project       DAvE_config.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains functions that use the GPT2 module.
//
//----------------------------------------------------------------------------
// @Date          30.09.2021 14:42:54
//
//****************************************************************************

// USER CODE BEGIN (GPT2_General,1)

// USER CODE END

//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (GPT2_General,2)

// USER CODE END

//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT2_General,3)

// USER CODE END

//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPT2_General,4)

// USER CODE END

//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT2_General,5)

// USER CODE END

//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,6)
// Externe Globale Variablen von der Main.c übernehmen
extern const unsigned int ARRAY_SIZE;
extern unsigned int rampIndex;
extern volatile float velocity;
volatile unsigned int inc;
// USER CODE END

//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,7)

// USER CODE END

//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (GPT2_General,8)

// USER CODE END

//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (GPT2_General,9)

// USER CODE END

//****************************************************************************
// @Function      void GPT2_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the GPT2 function
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
// @Date          30.09.2021
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void GPT2_vInit(void) {
	// USER CODE BEGIN (Init,2)

	// USER CODE END
	///  -----------------------------------------------------------------------
	///  Configuration of Timer Block Prescaler 1:
	///  -----------------------------------------------------------------------
	GPT12E_KSCCFG = 0x0003;	 // Module Enable

	_nop();	 // one cycle delay

	_nop();	 // one cycle delay

	///  -----------------------------------------------------------------------
	///  Configuration of Timer Block Prescaler 2:
	///  -----------------------------------------------------------------------
	///  - prescaler for timer block 2 is 2

	///  -----------------------------------------------------------------------
	///  Configuration of the GPT2 Core Timer 5:
	///  -----------------------------------------------------------------------
	///  - timer 5 works in timer mode
	///  - prescaler factor is 2
	///  - up/down control bit is reset
	///  - external up/down control is disabled
	///  - timer 5 run bit is reset
	///  - timer 5 remote control is disabled

	GPT12E_T5CON = 0x0000;	// load timer 5 control register
	GPT12E_T5 = 0xFFFF;		// load timer 5 register

	///  -----------------------------------------------------------------------
	///  Configuration of the GPT2 Core Timer 6:
	///  -----------------------------------------------------------------------
	///  - timer 6 works in timer mode
	///  - prescaler factor is 8
	///  - up/down control bit is reset
	///  - external up/down control is disabled
	///  - alternate output function T6OUT (P6.2) is disabled
	///  - alternate output function T6OUT (P7.0) is disabled
	///  - timer 6 output toggle latch (T6OTL) is set to 0
	///  - timer 6 run bit is reset
	///  - timer 6 is not cleared on a capture

	GPT12E_T6CON = 0x0802;	// load timer 6 control register
	GPT12E_T6 = 0x0218;		// load timer 6 register

	///  -----------------------------------------------------------------------
	///  Configuration of the GPT2 CAPREL:
	///  -----------------------------------------------------------------------
	///  - capture T5 into CAPREL is disabled
	///  - capture trigger from pin CAPIN
	///  - capure is disabled
	///  - timer 5 is not cleared on a capture
	///  - timer 5 is just captured without any correction

	GPT12E_T5CON |= 0x0000;	 // load timer 5 control register
	GPT12E_CAPREL = 0x0218;	 // load CAPREL register

	///  -----------------------------------------------------------------------
	///  Configuration of the used GPT2 Port Pins:
	///  -----------------------------------------------------------------------
	///  - P5.3 is used for  GPT12E Timer2 Count input(T3IN)

	///  -----------------------------------------------------------------------
	///  Configuration of the used GPT2 Interrupts:
	///  -----------------------------------------------------------------------
	///  timer 6 service request node configuration:
	///  - timer 6 interrupt priority level (ILVL) = 14
	///  - timer 6 interrupt group level (GLVL) = 0
	///  - timer 6 group priority extension (GPX) = 0

	GPT12E_T6IC = 0x0078;

	///  Use PEC channel 0 for GPT2 T6 INT:
	///  - normal interrupt
	///  - pointers are not modified
	///  - transfer a word
	///  - service End of PEC interrrupt by a EOP interrupt node is disabled
	///  - channel link mode is disabled

	PECC0 = 0x0000;	 // load PECC0 control register

	// USER CODE BEGIN (GPT2_Function,3)

	// USER CODE END

}  //  End of function GPT2_viCAPREL

//****************************************************************************
// @Function      void GPT2_viTmr6(void)
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT2 timer 6.
//                It is called up in the case of over or underflow of the
//                timer 6 register.
//
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
// @Date          30.09.2021
//
//****************************************************************************

// USER CODE BEGIN (Tmr6,1)

// USER CODE END

_interrupt(T6INT) void GPT2_viTmr6(void) {
	// USER CODE BEGIN (Tmr6,2)
	// Index für den Programmablauf, größer 5251 damit der Programmablauf bei Überlauf
	// der Variable RampIndex (16 Bit) nicht erneut von vorn startet
	if (rampIndex < 5251) {
		rampIndex++;
	}

	// auslesen des GPT Timer 4 Registers
	// Entspricht der Anzahl der Inkremente des Encoders in 8 ms
	inc = GPT12E_T4;
	// Berechnung der Geschwindigkeit durch Differenzbildung
	velocity = (1000 * (float)inc) / (8);
	// Umrechnung von inc/s zu 1/s
	velocity = velocity / 2048;
	// zurücksetzen des Timer 4 Registers
	GPT12E_T4 = 0;
	// USER CODE END

}  //  End of function GPT2_viTmr6

// USER CODE BEGIN (GPT2_General,10)

// USER CODE END
