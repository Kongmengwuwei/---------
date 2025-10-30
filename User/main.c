#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "OLED.h"
#include "Delay.h"
#include "button4_4.h"
#include "menu.h"
#include "Timer.h"
#include "PWM.h"
#include "MusicPlay.h"


int main(){
	
//	Timer_Init();
//	Key_Init();
	OLED_Init();
	PWM_Init();
	
	OLED_Printf(1,1,8,"为什么要演奏...");
	OLED_Update();
		 
//	int menu2;
	
	while(1)
	{		
		Play_Haruhikage_Song();
//		Test_Volume();
//		menu2 =menu1();
//		if(menu2==1){}
//		if(menu2==2){}
//		if(menu2==3){}
//		if(menu2==4){}
		
		Delay_ms(1000);
	}
}


//void TIM1_UP_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
//	{
//		Key_Tick();
//		
//		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
//	}
//}
