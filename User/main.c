#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "OLED.h"
#include "Delay.h"
#include "button4_4.h"
#include "menu.h"
#include "Timer.h"
#include "PWM.h"
#include "MusicPlay.h"
#include "MusicData.h"

uint8_t Mode=0;
uint8_t GetNum;

int main(){
	
	Timer_Init();
	Key_Init();
	OLED_Init();
	PWM_Init();
	Button4_4_Init();
	
	TIM_SetCompare3(TIM2, 0);
	
    if(Mode==0)
	{	
		while(1)
		{		
	
	    static int menu;
		menu =Menu();
		if(menu==1){menu1();}
//		if(menu==2){}
//		if(menu==3){}
		
		}	

	}
	
//	if(Mode==1)
//	{
//		uint8_t Octave=5;
//		while(1)
//		{		
//			switch(GetNum){
//				case 8:Play_Note(NOTE_C4,Q);break;
//				case 9:Play_Note(NOTE_D4,Q);break;
//				case 10:Play_Note(NOTE_E4,Q);break;
//				case 11:Play_Note(NOTE_F4,Q);break;
//				case 12:Play_Note(NOTE_G4,Q);break;
//				case 13:Play_Note(NOTE_A4,Q);break;
//				case 14:Play_Note(NOTE_B4,Q);break;
//				case 15:Play_Note(NOTE_C5,Q);break;
//				default:break;	
//			}
//		}

//	}
}

	void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
//		if(Button4_4_Scan()!=-1)
//		{
//		GetNum=Button4_4_Scan();
//		}
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
