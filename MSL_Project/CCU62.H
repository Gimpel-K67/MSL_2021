//****************************************************************************
// @Module        Capture / Compare Unit 62 (CCU62)
// @Filename      CCU62.H
// @Project       DAvE_config.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains all function prototypes and macros for 
//                the CCU62 module.
//
//----------------------------------------------------------------------------
// @Date          29.09.2021 09:41:09
//
//****************************************************************************

// USER CODE BEGIN (CCU62_Header,1)

// USER CODE END



#ifndef _CCU62_H_
#define _CCU62_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CCU62_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CCU62_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies CCU62 timer 12
#define CCU62_TIMER_12 12

//   This parameter identifies CCU62 timer 13
#define CCU62_TIMER_13 13

//   This parameter identifies CCU62 channel 0
#define CCU62_CHANNEL_0 0

//   This parameter identifies CCU62 channel 1
#define CCU62_CHANNEL_1 1

//   This parameter identifies CCU62 channel 2
#define CCU62_CHANNEL_2 2

//   This parameter identifies CCU62 channel 3
#define CCU62_CHANNEL_3 3


// USER CODE BEGIN (CCU62_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CCU62_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU62_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU62_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CCU62_vInit(void);


// USER CODE BEGIN (CCU62_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         CCU62_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected CCU62 timer. The timer 
//                continues counting from where it stopped. 
//                
//                The following definitions for TimerNr are available: 
//                CCU62_TIMER_12
//                CCU62_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU62 timer to be started
//
//----------------------------------------------------------------------------
// @Date          29.09.2021
//
//****************************************************************************

#define CCU62_vStartTmr(TimerNr) CCU62_vStartTmr_##TimerNr()
#define CCU62_vStartTmr_CCU62_TIMER_12() CCU62_TCTR4 |= 0x0002
#define CCU62_vStartTmr_CCU62_TIMER_13() CCU62_TCTR4 |= 0x0200


//****************************************************************************
// @Macro         CCU62_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CCU62 timer. The content of 
//                the timer register remains unchanged. 
//                
//                The following definitions for TimerNr are available: 
//                CCU62_TIMER_12
//                CCU62_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU62 timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          29.09.2021
//
//****************************************************************************

#define CCU62_vStopTmr(TimerNr) CCU62_vStopTmr_##TimerNr()
#define CCU62_vStopTmr_CCU62_TIMER_12() CCU62_TCTR4 |= 0x0001
#define CCU62_vStopTmr_CCU62_TIMER_13() CCU62_TCTR4 |= 0x0100


//****************************************************************************
// @Macro         CCU62_vSetTmrPeriod(TimerNr, Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the period register of the selected CCU62 
//                timer.
//                
//                Note: Call the macro CCU62_vEnableShadowTransfer() to 
//                enable the shadow transfer.
//                The following definitions for TimerNr are available: 
//                CCU62_TIMER_12
//                CCU62_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU62 timer to be used
// @Parameters    Value: 
//                16-bit Value with which the CCU62 timer reload register is 
//                to be loaded
//
//----------------------------------------------------------------------------
// @Date          29.09.2021
//
//****************************************************************************

#define CCU62_vSetTmrPeriod(TimerNr, Value) CCU62_vSetTmrPeriod_##TimerNr(Value)
#define CCU62_vSetTmrPeriod_CCU62_TIMER_12(Value) CCU62_T12PR = Value
#define CCU62_vSetTmrPeriod_CCU62_TIMER_13(Value) CCU62_T13PR = Value


//****************************************************************************
// @Macro         CCU62_vEnableShadowTransfer(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro enables the transfer from the shadow registers 
//                to the actual CCU62 registers.
//                
//                The following definitions for TimerNr are available: 
//                CCU62_TIMER_12
//                CCU62_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU62 timer to be used
//
//----------------------------------------------------------------------------
// @Date          29.09.2021
//
//****************************************************************************

#define CCU62_vEnableShadowTransfer(TimerNr) CCU62_vEnableShadowTransfer_##TimerNr()
#define CCU62_vEnableShadowTransfer_CCU62_TIMER_12() CCU62_TCTR4 |= 0x0040
#define CCU62_vEnableShadowTransfer_CCU62_TIMER_13() CCU62_TCTR4 |= 0x4000


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CCU62_NodeI0_INT    0x38


// USER CODE BEGIN (CCU62_Header,9)

// USER CODE END


#endif  // ifndef _CCU62_H_
