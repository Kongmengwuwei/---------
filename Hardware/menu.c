#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Key.h"
#include "button4_4.h"
#include "MusicPlay.h"

int Menu(void){
	
	static uint8_t Flag =1;
	OLED_Clear();
	OLED_ShowImage(118,0,10,8,Volume_3);
	OLED_Printf(0,0,8,"音乐列表");
	OLED_Printf(0,16,8,"春日影");
	OLED_Update();

	while(1){
		
		if (Button4_4_Scan()==1){//上升
			Flag--;
			if(Flag==0)Flag=3;
		}
		if (Button4_4_Scan()==2){//下降
			Flag++;
			if(Flag==4)Flag=1;
		}
		if (Button4_4_Scan()==3){//确认
			return Flag;
		}

		switch(Flag){

		}
	}
	
}

int menu1(void){
	
	OLED_Clear();
	OLED_ShowImage(118,0,10,8,Volume_3);
	OLED_Printf(0,0,8,"春日影");
	OLED_Printf(0,48,8,"为什么要演奏...");
	OLED_Update();
	
	Play_Haruhikage();
	
	return 0;	
}
