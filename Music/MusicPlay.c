#include "stm32f10x.h"                  // Device header
#include "MusicData.h"
#include "Delay.h"
#include "OLED.h"

uint32_t arr;
void show_tone(uint16_t frequency);

typedef enum {
    VOLUME_OFF = 0,      // 0%低电平时间 (常高)
    VOLUME_LOW = 1,     // 25%低电平时间
    VOLUME_HIGH = 10,    // 75%低电平时间
    VOLUME_MAX = 99      // 90%低电平时间
} VolumeLevel;

VolumeLevel current_volume = VOLUME_LOW;

void Set_Volume(VolumeLevel volume)
{
    uint32_t pulse;
	   
    if (volume == VOLUME_OFF) {
        pulse = 0;  // 0%占空比 = 常高电平 (关闭)
    } else {
        pulse = arr * volume / 100;  // 计算占空比
    }
    
    TIM_SetCompare3(TIM2, pulse);
    current_volume = volume;
}

void Play_Note(uint16_t frequency, uint16_t duration)
{
    if (frequency == NOTE_REST) {
        /* 休止符：停止输出 */
        TIM_SetCompare3(TIM2, 0);
    } else {
        /* 计算ARR值设置频率 */
        arr = 1000000 / frequency - 1;
        if (arr > 0xFFFF) arr = 0xFFFF;
        
        TIM_SetAutoreload(TIM2, arr);
		
        Set_Volume(current_volume);  // 应用当前音量
        
		show_tone(frequency);        //显示当前音符
        /* 确保定时器运行 */
        TIM_Cmd(TIM2, ENABLE);
    }
    
    /* 保持音符时长 */
    Delay_ms(duration);
    
    /* 音符间短暂停顿 */ 
    TIM_SetCompare3(TIM2, 0);
    Delay_ms(30);
}

//void Play_Self(uint8_t GetNum)
//{
//	while(1)
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
//}

void Play_Haruhikage(void)
{
    uint16_t len = sizeof(Haruhikage) / sizeof(Note);

    for (int i = 0; i < len; i++) {
        Play_Note(Haruhikage[i].note, Haruhikage[i].duration);
    }
}

void show_tone(uint16_t frequency)
{
	switch (frequency)
    {
    	case 0:OLED_ShowString(0,16,"---",8);
    		break;		
    	case 131:OLED_ShowString(0,16,"-C ",8);
    		break;
    	case 139:OLED_ShowString(0,16,"-C#",8);
    		break;
    	case 147:OLED_ShowString(0,16,"-D ",8);
    		break;
    	case 156:OLED_ShowString(0,16,"-D#",8);
    		break;
    	case 165:OLED_ShowString(0,16,"-E ",8);
    		break;
    	case 175:OLED_ShowString(0,16,"-F ",8);
    		break;
    	case 185:OLED_ShowString(0,16,"-F#",8);
    		break;
    	case 196:OLED_ShowString(0,16,"-G ",8);
    		break;
    	case 208:OLED_ShowString(0,16,"-G#",8);
    		break;
    	case 220:OLED_ShowString(0,16,"-A ",8);
    		break;
    	case 233:OLED_ShowString(0,16,"-A#",8);
    		break;
    	case 247:OLED_ShowString(0,16,"-B ",8);
    		break;
    	case 262:OLED_ShowString(0,16," C ",8);
    		break;
    	case 277:OLED_ShowString(0,16," C#",8);
    		break;
    	case 294:OLED_ShowString(0,16," D ",8);
    		break;
    	case 311:OLED_ShowString(0,16," D#",8);
    		break;
    	case 330:OLED_ShowString(0,16," E ",8);
    		break;
    	case 349:OLED_ShowString(0,16," F ",8);
    		break;
    	case 370:OLED_ShowString(0,16," F#",8);
    		break;
    	case 392:OLED_ShowString(0,16," G ",8);
    		break;
    	case 415:OLED_ShowString(0,16," G#",8);
    		break;
    	case 440:OLED_ShowString(0,16," A ",8);
    		break;
    	case 466:OLED_ShowString(0,16," A#",8);
    		break;
    	case 494:OLED_ShowString(0,16," B ",8);
    		break;
    	case 523:OLED_ShowString(0,16,"+C ",8);
    		break;
    	case 554:OLED_ShowString(0,16,"+C#",8);
    		break;
    	case 587:OLED_ShowString(0,16,"+D ",8);
    		break;
    	case 622:OLED_ShowString(0,16,"+D#",8);
    		break;
    	case 659:OLED_ShowString(0,16,"+E ",8);
    		break;
    	case 698:OLED_ShowString(0,16,"+F ",8);
    		break;
    	case 750:OLED_ShowString(0,16,"+F#",8);
    		break;
    	case 784:OLED_ShowString(0,16,"+G ",8);
    		break;
    	case 831:OLED_ShowString(0,16,"+G#",8);
    		break;
    	case 880:OLED_ShowString(0,16,"+A ",8);
    		break;
    	case 932:OLED_ShowString(0,16,"+A#",8);
    		break;
    	case 988:OLED_ShowString(0,16,"+B ",8);
    		break;
		default:
    		break;
    }
	OLED_Update();
}	
