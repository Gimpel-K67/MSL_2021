//****************************************************************************
// @Module        Capture / Compare Unit 63 (CCU63)
// @Filename      CCU63.H
// @Project       DAvE_config.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains all function prototypes and macros for 
//                the CCU63 module.
//
//----------------------------------------------------------------------------
// @Date          27.09.2021 18:18:20
//
//****************************************************************************

// USER CODE BEGIN (CCU63_Header,1)

// USER CODE END



#ifndef _CCU63_H_
#define _CCU63_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CCU63_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CCU63_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies CCU63 timer 12
#define CCU63_TIMER_12 12

//   This parameter identifies CCU63 timer 13
#define CCU63_TIMER_13 13

//   This parameter identifies CCU63 channel 0
#define CCU63_CHANNEL_0 0

//   This parameter identifies CCU63 channel 1
#define CCU63_CHANNEL_1 1

//   This parameter identifies CCU63 channel 2
#define CCU63_CHANNEL_2 2

//   This parameter identifies CCU63 channel 3
#define CCU63_CHANNEL_3 3


// USER CODE BEGIN (CCU63_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CCU63_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU63_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU63_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CCU63_vInit(void);


// USER CODE BEGIN (CCU63_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         CCU63_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected CCU63 timer. The timer 
//                continues counting from where it stopped. 
//                
//                The following definitions for TimerNr are available: 
//                CCU63_TIMER_12
//                CCU63_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU63 timer to be started
//
//----------------------------------------------------------------------------
// @Date          27.09.2021
//
//****************************************************************************

#define CCU63_vStartTmr(TimerNr) CCU63_vStartTmr_##TimerNr()
#define CCU63_vStartTmr_CCU63_TIMER_12() CCU63_TCTR4 |= 0x0002
#define CCU63_vStartTmr_CCU63_TIMER_13() CCU63_TCTR4 |= 0x0200


//****************************************************************************
// @Macro         CCU63_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CCU63 timer. The content of 
//                the timer register remains unchanged. 
//                
//                The following definitions for TimerNr are available: 
//                CCU63_TIMER_12
//                CCU63_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU63 timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          27.09.2021
//
//****************************************************************************

#define CCU63_vStopTmr(TimerNr) CCU63_vStopTmr_##TimerNr()
#define CCU63_vStopTmr_CCU63_TIMER_12() CCU63_TCTR4 |= 0x0001
#define CCU63_vStopTmr_CCU63_TIMER_13() CCU63_TCTR4 |= 0x0100


//****************************************************************************
// @Macro         CCU63_vEnableShadowTransfer(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro enables the transfer from the shadow registers 
//                to the actual CCU63 registers.
//                
//                The following definitions for TimerNr are available: 
//                CCU63_TIMER_12
//                CCU63_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU63 timer to be used
//
//----------------------------------------------------------------------------
// @Date          27.09.2021
//
//****************************************************************************

#define CCU63_vEnableShadowTransfer(TimerNr) CCU63_vEnableShadowTransfer_##TimerNr()
#define CCU63_vEnableShadowTransfer_CCU63_TIMER_12() CCU63_TCTR4 |= 0x0040
#define CCU63_vEnableShadowTransfer_CCU63_TIMER_13() CCU63_TCTR4 |= 0x4000


//****************************************************************************
// @Macro         CCU63_vLoadChannelShadowRegister(ChName, Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the selected CCU63 channel shadow register 
//                with the parameter Value. 
//                
//                The following definitions are available for RegName: 
//                CCU63_CHANNEL_0 .. CCU63_CHANNEL_3 (see @Defines in header 
//                file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ChName: 
//                Name of the CCU63 channel to be loaded
// @Parameters    Value: 
//                16-bit Value with which the CCU63 shadow register is to be 
//                loaded
//
//----------------------------------------------------------------------------
// @Date          27.09.2021
//
//****************************************************************************

#define CCU63_vLoadChannelShadowRegister(ChName, Value) CCU63_vLoadChannelShadowRegister_##ChName(Value)
#define CCU63_vLoadChannelShadowRegister_CCU63_CHANNEL_0(Value) CCU63_CC60SR = Value
#define CCU63_vLoadChannelShadowRegister_CCU63_CHANNEL_1(Value) CCU63_CC61SR = Value
#define CCU63_vLoadChannelShadowRegister_CCU63_CHANNEL_2(Value) CCU63_CC62SR = Value
#define CCU63_vLoadChannelShadowRegister_CCU63_CHANNEL_3(Value) CCU63_CC63SR = Value


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CCU63_NodeI0_INT    0x3C


// USER CODE BEGIN (CCU63_Header,9)

// USER CODE END


#endif  // ifndef _CCU63_H_
