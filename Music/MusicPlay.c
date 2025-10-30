#include "stm32f10x.h"                  // Device header
#include "MusicData.h"
#include "Delay.h"
#include "OLED.h"

uint32_t arr;

typedef enum {
    VOLUME_OFF = 0,      // 0%低电平时间 (常高)
    VOLUME_LOW = 10,     // 25%低电平时间
    VOLUME_MEDIUM = 50,  // 50%低电平时间  
    VOLUME_HIGH = 75,    // 75%低电平时间
    VOLUME_MAX = 90      // 90%低电平时间
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
        
        /* 确保定时器运行 */
        TIM_Cmd(TIM2, ENABLE);
    }
    
    /* 保持音符时长 */
    Delay_ms(duration);
    
    /* 音符间短暂停顿 */ 
    TIM_SetCompare3(TIM2, 0);
    Delay_ms(30);
}

void Play_Haruhikage_Song(void)
{
    uint16_t len = sizeof(Haruhikage) / sizeof(Note);
    
    for (int i = 0; i < len; i++) {
        Play_Note(Haruhikage[i].note, Haruhikage[i].duration);
    }
}

void Test_Volume(void)
{
    uint16_t test_freq = NOTE_A4;  // 440Hz  

    Set_Volume(VOLUME_OFF);
    Play_Note(test_freq, 1000);
   
    Set_Volume(VOLUME_LOW);
    Play_Note(test_freq, 1000);
   
    Set_Volume(VOLUME_MEDIUM);
    Play_Note(test_freq, 1000);  

    Set_Volume(VOLUME_HIGH);
    Play_Note(test_freq, 1000); 

    Set_Volume(VOLUME_MAX);
    Play_Note(test_freq, 1000);
    
}
