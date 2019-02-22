#ifndef EN_DE_CRYPTION_H
#define EN_DE_CRYPTION_H

void AES_Decryption( uint8_t Mode_S, uint8_t Bit_S, uint32_t DEST_ADDR, uint32_t SRC_ADDR, uint32_t IV_ADDR, uint32_t KEYIN_ADDR, uint8_t KeyLen, uint32_t DataLen);
void AES_Encryption( uint8_t Mode_S, uint8_t Bit_S, uint32_t DEST_ADDR, uint32_t SRC_ADDR, uint32_t IV_ADDR, uint32_t KEYIN_ADDR, uint8_t KeyLen, uint32_t DataLen);

typedef enum
{
	//AES
	HW_AES_ENC = 0,
	HW_AES_DEC,
	//DES
	HW_DES_ENC = 0X04,
	HW_DES_DEC,
	//3DES
	HW_DES3_ENC = 0X0C,
	HW_DES3_DEC,
}FUNC_Mode;

typedef enum
{
    ECB = 0,
    CBC,
    CFB,
    OFB
}MODE_S;

typedef enum
{
    AES_Bit_128bit = 0,
    AES_Bit_8bit,
    AES_Bit_1bit
}AES_BIT_S;

typedef enum
{
    DES_Bit_64bit = 0,
    DES_Bit_8bit,
    DES_Bit_1bit
}DES_BIT_S;

typedef enum
{
    Key_128bit = 0,
    Key_192bit,
    Key_256bit
}KEY_LEN;



#endif //EN_DE_CRYPTION_H
