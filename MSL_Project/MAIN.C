//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.C
// @Project       DAvE_config.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          29.09.2021 09:41:08
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END

//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (MAIN_General,2)
#include <math.h>
// USER CODE END

//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END

//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)
// clockwise=rechtslauf, counterclockwise=linkslauf definition einer Präprozessorvariable
#define clockwise (0)
#define counterclockwise (1)
// USER CODE END

//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END

//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END

//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)
// Frequenz des Drehfeldes in Hz
unsigned int frequency = 0;
// Größe der Sinus Wertetabelle
const unsigned int ARRAY_SIZE = 1200;
// Phasenverschiebung
unsigned int OFFSET_L1;
unsigned int OFFSET_L2;
unsigned int OFFSET_L3;
// Wertetabelle des Sinus
int table[ARRAY_SIZE];
// Index der Wertetabelle
unsigned int index;

float pi = 3.14159265359;
// Index für die Rampensteuerung Erhöhung alle 8 ms
volatile unsigned int rampIndex;
// mechanische Geschwindigkeit des Motors in Hz
volatile float velocity;
// Integralsumme des I-Reglers
int integral_sum;
// Proportionalanteil P-Regler
const float K_p = 0.05;
// Integrealanteil I-Rgler
const float K_i = 0.01;
// Verschiebung des Gleichanteils des Sinus
const unsigned int HALF_PERIODVALUE = 901;
// USER CODE END

//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END

//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)
// Funktion zur Generierung der Sinus Wertetabelle
void generateTable();
// Funktion zur Berechnung des CCU62 Period Value Registers in Abhängigkeit der Frequenz
unsigned int calculateMotorFrequency(unsigned int _frequency);
// Setzen der Phasenverschiebung für Links- und Rechtslauf, 0 = Rechtslauf 1 = Linkslauf
void setPhaseChange(int dir);
// Funktion für den PI-Regler, errechnet Stellgröße in abhängigkeit der gemessenen Geschwindigkeit
unsigned int controller(int input);
// USER CODE END

//****************************************************************************
// @Function      void MAIN_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
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

void MAIN_vInit(void) {
	// USER CODE BEGIN (Init,2)

	// USER CODE END

	//   globally disable interrupts
	PSW_IEN = 0;

	///  -----------------------------------------------------------------------
	///  Configuration of the System Clock:
	///  -----------------------------------------------------------------------
	///  - VCO clock used, input clock is connected
	///  - input frequency is 10,00 MHz
	///  - configured system frequency is 66,00 MHz

	MAIN_vUnlockProtecReg();  // unlock write security

	MAIN_vChangeFreq();	 // load PLL control register

	//   -----------------------------------------------------------------------
	//   Initialization of the Peripherals:
	//   -----------------------------------------------------------------------

	//   initializes the Parallel Ports
	IO_vInit();

	//   initializes the General Purpose Timer Unit (GPT1)
	GPT1_vInit();

	//   initializes the General Purpose Timer Unit (GPT2)
	GPT2_vInit();

	//   initializes the Capture / Compare Unit 62 (CCU62)
	CCU62_vInit();

	//   initializes the Capture / Compare Unit 63 (CCU63)
	CCU63_vInit();

	//   initializes the Analog / Digital Converter  (ADC0)
	ADC0_vInit();

	//   -----------------------------------------------------------------------
	//   Initialization of the Bank Select registers:
	//   -----------------------------------------------------------------------

	// USER CODE BEGIN (Init,3)

	// USER CODE END

	MAIN_vLockProtecReg();	// lock write security

	//   globally enable interrupts
	PSW_IEN = 1;

}  //  End of function MAIN_vInit

//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void)
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected
//                register.
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

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void) {
	uword uwPASSWORD;

	SCU_SLC = 0xAAAA;  // command 0
	SCU_SLC = 0x5554;  // command 1

	uwPASSWORD = SCU_SLS & 0x00FF;
	uwPASSWORD = (~uwPASSWORD) & 0x00FF;

	SCU_SLC = 0x9600 | uwPASSWORD;	// command 2
	SCU_SLC = 0x0000;				// command 3

}  //  End of function MAIN_vUnlockProtecReg

//****************************************************************************
// @Function      void MAIN_vLockProtecReg(void)
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to lock one protected
//                register.
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

// USER CODE BEGIN (LockProtecReg,1)

// USER CODE END

void MAIN_vLockProtecReg(void) {
	uword uwPASSWORD;

	SCU_SLC = 0xAAAA;  // command 0
	SCU_SLC = 0x5554;  // command 1

	uwPASSWORD = SCU_SLS & 0x00FF;
	uwPASSWORD = (~uwPASSWORD) & 0x00FF;

	SCU_SLC = 0x9600 | uwPASSWORD;	// command 2
	SCU_SLC = 0x1800;				// command 3; new PASSWOR is 0x00

	uwPASSWORD = SCU_SLS & 0x00FF;
	uwPASSWORD = (~uwPASSWORD) & 0x00FF;
	SCU_SLC = 0x8E00 | uwPASSWORD;	// command 4

}  //  End of function MAIN_vLockProtecReg

//****************************************************************************
// @Function      void MAIN_vChangeFreq(void)
//
//----------------------------------------------------------------------------
// @Description   This function is used to select the external crystal and
//                configure the system frequency to 80Mhz/66Mhz.
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

// USER CODE BEGIN (ChangeFreq,1)

// USER CODE END

void MAIN_vChangeFreq(void) {
	SCS_SwitchToHighPrecBandgap();

	//For application and internal application resets, the complete PLL configuration could be avoided
	//The entry from application resets and internal application reset is covered in the following differentiation
	//in int/ext clock in lock/unlocked state.

	if ((SCU_PLLSTAT & 0x0004) == 0x0004)  // fR derived from Internal clock
	{
		//Normal startup state during boot and the clock
		//has to be in the next step configured on the external crystal
		//use XTAL/VCO, count XTAL clock

		SCS_StartXtalOsc(1);	   // Starts the crystal oscillator
		SCS_SwitchSystemClock(1);  // System clock is increased to target speed (80/66 MHz)

	}

	else  // fR derived from external crystal clock
	{
		if ((SCU_PLLSTAT & 0x1009) == 0x1009)  // fR derived from external crystal clock + VCO is locked
		{
			//usually after an application reset where clock need not be configured again.
			//check K2/P/N values and decide whether these values have to be adapted based on application needs.
			NOP();
			//usually the PLL losss of Lock TRAP schould be enabled here.
		} else	//fR derived from external crystal clock + VCO is not locked

		{
			//estimate the K1 value and the current frequency
			//reduce K2/P/N values in steps so that the frequency
			//jumps is limited to 20MHz or factor of 5 whichever is minimum
			NOP();
		}
	}

}  //  End of function MAIN_vChangeFreq

//****************************************************************************
// @Function      void main(void)
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
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

// USER CODE BEGIN (Main,1)

// USER CODE END

void main(void) {
	// USER CODE BEGIN (Main,2)

	// USER CODE END

	MAIN_vInit();

	// USER CODE BEGIN (Main,3)
	// einmalige Funktionen zum herstellen des Betriebszustandes
	// generierung der Tabelle vor dem Starten der Timer
	generateTable();
	// Konfiguriert den ADC
	ADC0_vInit();
	// Starten des ADCs (externer Trigger, interrupt einschalten, Refill bit?, Kanal des ADCs)
	ADC0_vStartSeq0ReqChNum(0, 0, 1, 6);
	// Timer 12 von CCU63 starten
	CCU63_vStartTmr(CCU63_TIMER_12);
	// Timer 12 von CCU62 starten
	CCU62_vStartTmr(CCU62_TIMER_12);
	// Timer 6 von GPT2 starten
	GPT2_vStartTmr(GPT2_TIMER_6);
	// USER CODE END

	while (1) {
		// USER CODE BEGIN (Main,4)

		// one rampIndex step = 8ms, 250 steps = 2s
		// Rechtslauf zu Beginn festlegen
		if (rampIndex == 0) {
			setPhaseChange(clockwise);
		}
		// Drehzahlregelung mit Potentiometer
		if (rampIndex > 5250) {
			// lokale Variable für den ADC Messwert
			unsigned long raw;
			// lesen des ADC Werts
			raw = ADC0_uwGetResultData(RESULT_REG_0);
			// 4096 ist Auflösung des ADC, links = 0, rechts = 4096
			// Normierung des ADC Messwerts auf 25 Hz mechanisch
			frequency = controller((25 * raw) / 4096);
			// schreiben des CCU62 Schattenregisters
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			// Übernahme des Schattenregisters erlauben
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}
		// steigende Rampe Rechtslauf
		if (rampIndex < 750) {
			frequency = (rampIndex / 15);
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
			IO_vTogglePin(LED_DBG);
		}
		// Geschwindigkeit halten
		if (rampIndex < 1500 && rampIndex > 750) {
			frequency = 50;
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}
		// fallende Rampe Rechtslauf
		if (rampIndex < 2250 && rampIndex > 1500) {
			frequency = (2250 - rampIndex) / 15;
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}
		// Phasen tauschen um Drehrichtung zu ändern
		if (rampIndex == 2250) {
			setPhaseChange(counterclockwise);
		}

		// steigende Rampe Linkslauf
		if (rampIndex < 3000 && rampIndex > 2250) {
			frequency = (rampIndex - 2250) / 15;
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}
		// Geschwindigkeit halten Linkslauf
		if (rampIndex < 3750 && rampIndex > 3000) {
			frequency = 50;
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}
		// Fallende Rampe linkslauf
		if (rampIndex < 4500 && rampIndex > 3750) {
			frequency = (4500 - rampIndex) / 15;
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}
		// Gleichstrombremsen !!! anpassen des CCU62 rampIndex nicht vergessen !!!
		if (rampIndex < 5250 && rampIndex > 4500) {
			frequency = 50;
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}
		// Frequenz vor der Drehzzahlregelung auf 0 setzen
		if (rampIndex == 5250) {
			frequency = 0;
			CCU62_vSetTmrPeriod(CCU62_TIMER_12, calculateMotorFrequency(frequency));
			CCU62_vEnableShadowTransfer(CCU62_TIMER_12);
		}

		// USER CODE END
	}

}  //  End of function main

// USER CODE BEGIN (MAIN_General,10)
// Funktion zur Generierung der Wertetabelle
void generateTable() {
	double stepSize = (2 * pi) / (ARRAY_SIZE);
	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		table[i] = (int)((double)((CCU63_T12PR - 140) / 2) * sin(stepSize * i));
	}
}

// berechnet den Period Value in Abhängigkeit der Frequenz, Frequenzen < 2 Hz = 1Hz
unsigned int calculateMotorFrequency(unsigned int _frequency) {
	if (_frequency < 2) {
		frequency = 1;
		return (0xD903);
	} else {
		return (1 / ((float)_frequency * (float)ARRAY_SIZE * 0.000000015));	 //float Operation wird nicht ersetzt da Datentyp grer als long verwendet werden msste: brcuhte Wertebereich von >10^22
	}
}

// Funktion für die Phasendrehung
void setPhaseChange(int dir) {
	if (dir == clockwise) {
		OFFSET_L1 = 0;
		OFFSET_L2 = (2 * ARRAY_SIZE) / 3;
		OFFSET_L3 = ARRAY_SIZE / 3;
	}
	if (dir == counterclockwise) {
		OFFSET_L1 = 0;
		OFFSET_L2 = ARRAY_SIZE / 3;
		OFFSET_L3 = (2 * ARRAY_SIZE) / 3;
	}
}

// PI Regler
unsigned int controller(int input) {
	//Regelabweichung = mech Drehzahldifferenz
	int controller_error = input - velocity;  // velocity =^ output/ feedback
	//P-Regler
	int manipulated_variable = controller_error * K_p;
	//I-Regler
	integral_sum = integral_sum + controller_error;	 //so gehts auch: integral_sum += controller_error
	//if (integral_sum > windup){
	// }
	//P- + I-Regler
	manipulated_variable = manipulated_variable + K_i * integral_sum;
	//Vorsteuerung
	manipulated_variable += input * 2;
	//Stellgrößenbegrenzung
	if (manipulated_variable > 55) {
		manipulated_variable = 55;
	} else if (manipulated_variable < 0) {
		manipulated_variable = 1;
	}
	return (manipulated_variable);
}

// USER CODE END
