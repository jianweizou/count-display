
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
	HR,
	MIN,
	SEC,
}TIME_TYPE;

typedef enum 
{
	SYSINIT,
	SELECT_LANGUAGE,
	SELECT_NUMTYPE,
	CNT_STAGE,
	RST_CNT,
	RST_SYS,
	SYS_CHARGE,
}SYSLOOP;

typedef struct
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
}SysDate;
typedef struct
{
	unsigned char Hr;
	unsigned char Min;
	unsigned char Sec;
}SysTime;
typedef struct
{
	unsigned char isinitsys;
	LANGUAGE 	language;
	NUMTYPE		numtype;
	SYSLOOP 	sysloop;
	unsigned long	totalcnt;
	unsigned char isneedinitstage;
	unsigned char lastpower;
}SysStruct;
#define SysStructLen	10
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
