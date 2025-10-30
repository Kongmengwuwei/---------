#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Key.h"

int menu1(void){
	
	static uint8_t Flag =1;

	while(1){
		
		if (Key_Check(KEY_1,KEY_SINGLE)){//上升
			Flag--;
			if(Flag==0)Flag=4;
		}
		if (Key_Check(KEY_2,KEY_SINGLE)){//下降
			Flag++;
			if(Flag==5)Flag=1;
		}
		if (Key_Check(KEY_3,KEY_UP)){//确认
			OLED_Clear();
			return Flag;
		}

		switch(Flag){

		}
	}
	
}
