
#define OLED_CMD  0	
#define OLED_DATA 0x40	

#define OLED_WIDTH	64
#define OLED_HIGHT	32

unsigned char OLED_Init(void);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_CLS_Windows(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1);
void Draw_BMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1,unsigned char * BMP);
