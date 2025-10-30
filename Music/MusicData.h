#ifndef __MUSICDATA_H
#define __MUSICDATA_H

// 音符结构体
typedef struct {
    uint16_t note;      // 音符频率
    uint16_t duration;  // 持续时间
} Note;

/******************************
 * 音符频率定义 (Hz)
 ******************************/
// 休止符
#define NOTE_REST 0

// 第2八度 (低音)
#define NOTE_C2   65
#define NOTE_CS2  69
#define NOTE_D2   73
#define NOTE_DS2  78
#define NOTE_E2   82
#define NOTE_F2   87
#define NOTE_FS2  93
#define NOTE_G2   98
#define NOTE_GS2  104
#define NOTE_A2   110
#define NOTE_AS2  117
#define NOTE_B2   123

// 第3八度 (低音)
#define NOTE_C3   131
#define NOTE_CS3  139
#define NOTE_D3   147
#define NOTE_DS3  156
#define NOTE_E3   165
#define NOTE_F3   175
#define NOTE_FS3  185
#define NOTE_G3   196
#define NOTE_GS3  208
#define NOTE_A3   220
#define NOTE_AS3  233
#define NOTE_B3   247

// 第4八度 (中音) - 中央C所在八度
#define NOTE_C4   262
#define NOTE_CS4  277
#define NOTE_D4   294
#define NOTE_DS4  311
#define NOTE_E4   330
#define NOTE_F4   349
#define NOTE_FS4  370
#define NOTE_G4   392
#define NOTE_GS4  415
#define NOTE_A4   440
#define NOTE_AS4  466
#define NOTE_B4   494

// 第5八度 (高音)
#define NOTE_C5   523
#define NOTE_CS5  554
#define NOTE_D5   587
#define NOTE_DS5  622
#define NOTE_E5   659
#define NOTE_F5   698
#define NOTE_FS5  740
#define NOTE_G5   784
#define NOTE_GS5  831
#define NOTE_A5   880
#define NOTE_AS5  932
#define NOTE_B5   988

// 第6八度 (高音)
#define NOTE_C6   1047
#define NOTE_CS6  1109
#define NOTE_D6   1175
#define NOTE_DS6  1245
#define NOTE_E6   1319
#define NOTE_F6   1397
#define NOTE_FS6  1480
#define NOTE_G6   1568
#define NOTE_GS6  1661
#define NOTE_A6   1760
#define NOTE_AS6  1865
#define NOTE_B6   1976



/******************************
 * 节奏定义 (ms)
 ******************************/
#define BPM 97  // 曲速
#define Q 60000/BPM     // 四分音符
#define H 2*Q             // 二分音符
#define E Q/2             // 八分音符
#define S Q/4             // 十六分音符
#define W 4*Q             // 全音符

// 附点音符
#define ED (uint16_t)(E*1.5)    // 附点八分音符
#define QD (uint16_t)(Q*1.5)    // 附点四分音符
#define HD (uint16_t)(H*1.5)    // 附点二分音符




/******************************
 * 《春日影》乐谱
 ******************************/
// 主歌部分
static const Note Haruhikage[] = {
	//前奏
    {NOTE_E5, Q}, {NOTE_D5, E}, {NOTE_C5, Q},{NOTE_D5, E},
    {NOTE_E5, ED}, {NOTE_F5, S}, {NOTE_E5, E},{NOTE_D5, QD},
    {NOTE_E5, Q}, {NOTE_D5, E}, {NOTE_C5, Q},{NOTE_D5, E},
    {NOTE_E5, ED}, {NOTE_F5, S}, {NOTE_E5, E},{NOTE_D5, QD},{NOTE_C4, S},{NOTE_D4, S},

    //主歌
    {NOTE_E4, E}, {NOTE_E4, E}, {NOTE_D4, E},{NOTE_F4, E}, {NOTE_E4, E}, {NOTE_D4, E},
    {NOTE_D4, E}, {NOTE_D4, E}, {NOTE_C4, S},{NOTE_C4, S}, {NOTE_F4, E}, {NOTE_E4, E},{NOTE_D4, E},
    {NOTE_D4, Q}, {NOTE_C4, S}, {NOTE_D4, S}, {NOTE_E4, QD},
    
//	//副歌部分
//    {NOTE_E5, Q}, {NOTE_D5, Q}, {NOTE_C5, Q}, {NOTE_B4, Q},
//    {NOTE_A4, H}, {NOTE_REST, E},
//    {NOTE_A4, Q}, {NOTE_B4, Q}, {NOTE_C5, H},
//    {NOTE_B4, Q}, {NOTE_A4, Q}, {NOTE_G4, H},
//    
//    {NOTE_E4, Q}, {NOTE_G4, Q}, {NOTE_A4, H},
//    {NOTE_E4, Q}, {NOTE_G4, Q}, {NOTE_A4, H},
//    {NOTE_G4, Q}, {NOTE_A4, Q}, {NOTE_B4, Q}, {NOTE_C5, Q},
//    {NOTE_D5, H}, {NOTE_E5, H},
//	{NOTE_E5, Q}, {NOTE_D5, Q}, {NOTE_C5, Q}, {NOTE_B4, Q},
//    {NOTE_A4, HD}, {NOTE_REST, E},
//    {NOTE_A4, Q}, {NOTE_B4, Q}, {NOTE_C5, HD},
//    {NOTE_REST, E},
//    
//    {NOTE_B4, Q}, {NOTE_A4, Q}, {NOTE_G4, Q}, {NOTE_FS4, Q},
//    {NOTE_E4, HD}, {NOTE_REST, E},
//    {NOTE_E4, Q}, {NOTE_FS4, Q}, {NOTE_G4, HD},
//    {NOTE_REST, E},
//    
//    {NOTE_A4, Q}, {NOTE_G4, Q}, {NOTE_FS4, Q}, {NOTE_E4, Q},
//    {NOTE_D4, HD}, {NOTE_REST, E},
//    {NOTE_D4, Q}, {NOTE_E4, Q}, {NOTE_FS4, H},
//    {NOTE_G4, H},
//    
//    {NOTE_E4, Q}, {NOTE_G4, Q}, {NOTE_A4, H},
//    {NOTE_E4, Q}, {NOTE_G4, Q}, {NOTE_A4, H},
//    {NOTE_G4, Q}, {NOTE_A4, Q}, {NOTE_B4, Q}, {NOTE_C5, Q},
//    {NOTE_D5, Q}, {NOTE_E5, Q}, {NOTE_D5, H}, {NOTE_C5, H},
//	
//	//结尾部分
//	{NOTE_C5, Q}, {NOTE_B4, Q}, {NOTE_A4, H},
//    {NOTE_G4, Q}, {NOTE_A4, Q}, {NOTE_B4, H},
//    {NOTE_A4, Q}, {NOTE_G4, Q}, {NOTE_FS4, H},
//    {NOTE_E4, Q}, {NOTE_FS4, Q}, {NOTE_G4, H},
//    
//    {NOTE_A4, Q}, {NOTE_G4, Q}, {NOTE_FS4, Q}, {NOTE_E4, Q},
//    {NOTE_D4, HD}, {NOTE_E4, HD},
//	
//    {NOTE_REST, W}
};

#define SONG_LENGTH (sizeof(Haruhikage) / sizeof(Note))

#endif
