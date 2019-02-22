
#define BASEYEAR	2017

typedef enum 
{
	CHINESE=0,
	ENGLISH,
}LANGUAGE;

typedef enum 
{
	ARABNUM=0,//123
	TIBENUM,//Tibetan number	
}NUMTYPE;

typedef enum
{
	YEAR,
	MONTH,
	DAY,
}DATE_TYPE;

typedef enum 
{
	SYSINIT,
	SELECT_LANGUAGE,
	SELECT_DATE,
	SELECT_NUMTYPE,
	CNT_STAGE,
	RST_CNT,
	RST_SYS,
}SYSLOOP;

typedef struct
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
}SysDate;

typedef struct
{
	LANGUAGE 	language;
	NUMTYPE		numtype;
	SysDate		sysdate;
	SYSLOOP 	sysloop;
	unsigned long	totalcnt;
	unsigned char isneedinitstage;
	unsigned char isinitsys;
	unsigned char isdpd;
}SysStruct;


typedef enum
{
	NULLKEY,
	SHORTKEY,
	LONGKEY_2S,
	LONGKEY_5S,
	LONGKEY_12S,
}KEYTYPE;

typedef enum
{
	YES,
	NO,
}YN;



#define BLINK_H		100
#define BLINK_L		100

#define POWER_CNT1	1000
#define POWER_CNT2	12000

void main_loop(void);
