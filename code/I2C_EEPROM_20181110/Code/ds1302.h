
#define READ	1
#define WRITE	0

#define YEAR_BASE	0x2000



typedef struct
{
	unsigned char sec;
	unsigned char min;
	unsigned char hr;
	unsigned char date;
	unsigned char month;
	unsigned char day;
	unsigned short year;
}TIME_INFO;
extern void readtimer(TIME_INFO* time);
extern void writetimer(TIME_INFO* time);
extern void ds1303_update_hr(unsigned char hr);
extern void ds1303_update_min(unsigned char min);
extern void ds1303_update_sec(unsigned char sec);
extern void ds1302_dpd(unsigned char dpd);