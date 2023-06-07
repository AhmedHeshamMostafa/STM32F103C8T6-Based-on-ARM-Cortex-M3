#include"LIB/STD_TYPES.h"
#include"LIB/BIT_MATH.h"
#include"LIB/Delay_int.h"
#include"MCAL/MSysTick/MSystick_int.h"
#include"MCAL/MNVIC/MNVIC_int.h"
#include"MCAL/MRCC/MRCC_int.h"
#include"MCAL/MGPIO/MGPIO_int.h"
#include"MCAL/MEXTI/MEXTI_int.h"
#include"MCAL/UART/UART_int.h"
//#include"MCAL/DMA/DMA_int.h"


UART_cfg UART1 = {.channel = CH1,
				  .UARTClk = 16000000,
                  .baudRate = 9600,
                  .charLength = CHAR_9BIT,
                  .parity = ODD_PARITY,
                  .stopBits = STP_BITS1};


int main(void)
{
	MRCC_u8InitSysClk();
	MRCC_BoolEnablePerClk(GPIOA);

	MGPIO_u8CfgPinMode(PA, PIN8, ALTERNATE_FN);
	//MGPIO_u8CfgOutPin(PA, PIN8, OUT_PUSH_PULL, OUT_HIGH_SPEED);
	MGPIO_u8CfgPinMode(PA, PIN9, ALTERNATE_FN);
	//MGPIO_u8CfgOutPin(PA, PIN9, OUT_PUSH_PULL, OUT_HIGH_SPEED);
	MGPIO_u8CfgPinMode(PA, PIN10, ALTERNATE_FN);
	//MGPIO_u8CfgInPin(PA, PIN10,  IN_PULL_UP);
	MGPIO_u8SetAF(PA, PIN8, USART1_OR_2);
	MGPIO_u8SetAF(PA, PIN9, USART1_OR_2);
	MGPIO_u8SetAF(PA, PIN10, USART1_OR_2);

	MRCC_BoolEnablePerClk(USART1);
	MUART_BoolInit(&UART1);

	/*MUART_BoolSendChar(&UART1, 'e');
	MUART_BoolSendChar(&UART1, 'N');
	MUART_BoolSendChar(&UART1, '9');*/
	//WriteOnDR(&UART1);

//	u8 dataArr1[] = "A0h0m0e0d";
//	u8 dataArr2[] = "H0e0s0h0a0m";

	while(1)
	{

		//MUART_BoolSendArr(&UART1, dataArr1, 5);
		MUART_BoolSendByte(&UART1, 0b10100011);
		//MUART_BoolSendArr(&UART1, dataArr2, 6);

/*
		MUART_BoolSendChar(&UART1, 'e');
		MUART_BoolSendChar(&UART1, 'N');
		MUART_BoolSendChar(&UART1, '9');
*/

	}

	return 0;
}





//u8 G_u8StartFlag = 0;
//u32 G_u32ButtonReadings[50] = {0};
//u8 G_counter = 0;
//u8 G_u8Data;
//
//
//void sysTickCallBack(void);
//
//
//int main(void)
//{
//	MRCC_u8InitSysClk();
//	MRCC_BoolEnablePerClk(GPIOA);
//	MRCC_BoolEnablePerClk(SYSCFG);
//
//	MGPIO_u8CfgPinMode(PA, PIN0, INPUT);
//	MGPIO_u8CfgInPin (PA, PIN0, IN_PULL_UP);
//
//
//	MSysTick_vSetCallBack(sysTickCallBack);
//	MEXTI_u8SetHWInterrupt(PA, PIN0, FALLINGEDGE);
//
//	MNVIC_BoolEnablePerINT(EXTI0);
//
//
//
//
//	while(1)
//	{
//
//	}
//
//	return 0;
//}
//
//
//
//
//void sysTickCallBack(void)
//{
//
//
//	for(u8 L_u8FrameIdx = 0; L_u8FrameIdx < 8; L_u8FrameIdx++)
//	{
//		if(((G_u32ButtonReadings[17+L_u8FrameIdx])>=2000) && ((G_u32ButtonReadings[17+L_u8FrameIdx])<=2400))
//		{
//			G_u8Data &= ~(1<<L_u8FrameIdx);
//		}
//
//		else if(((G_u32ButtonReadings[17+L_u8FrameIdx])>=4000) && ((G_u32ButtonReadings[17+L_u8FrameIdx])<=4600))
//		{
//			G_u8Data |= (1<<L_u8FrameIdx);
//		}
//	}
//}
//
//
//
//void EXTI0_IRQHandler(void)
//{
//
//	if(G_u8StartFlag == 0)
//	{
//		G_u8StartFlag = 1;
//		 MSysTick_BoolSetIntervalSingle(15000*2);
//	}
//
//	else
//	{
//		G_u32ButtonReadings[G_counter] = MSysTick_u32GetElapsedTime();
//		MSysTick_BoolSetIntervalSingle(15000*2);
//		G_counter++;
//	}
//
//	MEXTI_BoolClrPending(EXTIL0);
//}


//void fnforISR(void);
//
//u32 arr0[500] = {2};
//u32 arr1[500] = {0};
//u32 arr2[500] = {4};
//u32 arr3[500] = {0};
//
//int main(void)
//{
//	MRCC_u8InitSysClk();
//	MRCC_BoolEnablePerClk(GPIOA);
//	MRCC_BoolEnablePerClk(DMA2);
//
//	MGPIO_u8CfgPinMode(PA, PIN0, OUTPUT);
//	MGPIO_u8CfgPinMode(PA, PIN2, OUTPUT);
//	//MGPIO_u8CfgPinMode(PA, PIN5, OUTPUT);
//	MGPIO_u8CfgOutPin (PA, PIN0, OUT_PUSH_PULL, OUT_LOW_SPEED);
//	MGPIO_u8CfgOutPin (PA, PIN2, OUT_PUSH_PULL, OUT_LOW_SPEED);
//	//MGPIO_u8CfgOutPin (PA, PIN5, OUT_PUSH_PULL, OUT_LOW_SPEED);
//
//	DMA2_S0_setCallBack(fnforISR);
//
//	MNVIC_BoolEnablePerINT(DMA2STREAM0);
//
//	DMA2_vInit();
//
//
//	DMA2_CfgStream(0, 0, arr0, arr1, 0b10, 500);
//
//	for(u16 L_arrIndex=0; L_arrIndex<500; L_arrIndex++)
//	{
//		arr3[L_arrIndex] = arr2[L_arrIndex];
//	}
//
//	//MGPIO_u8WritePinVal (PA, PIN2, HIGH);
//
//
//
//
//	while(1)
//	{
//		//MGPIO_u8WritePinVal (PA, PIN2, HIGH);
//	}
//
//	return 0;
//}
//
//
//void fnforISR(void)
//{
//	static u8 L_flag = 0;
//
//	if(L_flag == 0)
//	{
//		//MGPIO_u8WritePinVal (PA, PIN0, LOW);
//			//BoolDelay_us(1000000);
//
//			MGPIO_u8WritePinVal (PA, PIN0, LOW);
//			//BoolDelay_us(1000000);
//			//for(u32 i = 0; i < 1000000; i++);
//			MGPIO_u8WritePinVal (PA, PIN0, HIGH);
//
//			DMA2_vDisableINT();
//	}
//
//	L_flag++;
//
//
//}
//
//
//






//#include"LIB/STD_TYPES.h"
//#include"LIB/Delay_int.h"
//#include"MCAL/MSysTick/MSysTick_int.h"
//#include"MCAL/MRCC/MRCC_int.h"
//#include"MCAL/MGPIO/MGPIO_int.h"
//
//
//int main(void)
//{
//	MRCC_u8InitSysClk();
//	MRCC_BoolEnablePerClk(GPIOA);
//
//	MGPIO_u8CfgPinMode(PA, PIN2, OUTPUT);
//	MGPIO_u8CfgOutPin (PA, PIN2, OUT_PUSH_PULL, OUT_LOW_SPEED);
//
//	while(TRUE)
//	{
//		MGPIO_u8WritePinVal (PA, PIN2, HIGH);
//		BoolDelay_us(250000);
//
//		MGPIO_u8WritePinVal (PA, PIN2, LOW);
//		BoolDelay_us(250000);
//	}
//
//	return 0;
//}


