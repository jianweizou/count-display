/*********************************************************************
Object Describe	:	FAT File System
Chip			:
File Name		:	fs_api.h
Write By		:	Candy Hu
Compiler version:
Copy Right		: 	(C) Copyrigt 2009 by Sonix Technology Co., Ltd.
						All rights reserved!
Function Describe	:	File system API functions
	Define global functions and types to be used by an application using the file system.
	This file needs to be included by any modul using the file system.
----------------------------------------------------------------------
Modification History:
----------------------------------------------------------------------
Date :			Author:		Modification :
2011.09.19		Candy		First version

----------------------------------------------------------------------
Known problems or limitations with current version
----------------------------------------------------------------------
None.
---------------------------END-OF-HEADER-----------------------------
*********************************************************************/


#ifndef _FS_API_H_
#define _FS_API_H_

//--------------------------------------------------------------------
//		Include Section
//--------------------------------------------------------------------
//#include "fs_port.h"
//--------------------------------------------------------------------
//		  Define global data types
//--------------------------------------------------------------------
typedef unsigned short	FS_u16;			// Unsigned 16 bit quantity                          
typedef signed   short	FS_i16;			// Signed   16 bit quantity                           
typedef unsigned int	FS_u32;			// Unsigned 32 bit quantity                           
typedef signed   int	FS_i32;			// Signed   32 bit quantity

typedef unsigned short	FS_size_t;		//Unsigned 16 bit quantity

typedef char			FS_Char;		//Char 16 bit quantity
typedef unsigned char	FS_uChar;		//Unsigned char 16 bit quantity
typedef signed   char	FS_iChar;		//Signed char 16 bit quantity

#define __GENERIC  
typedef  __GENERIC FS_Char *	FS_pChar;	//Pointer of char 16 bit quantiry

#define HEAD 1
#define MIDDLE 2

#define BIT0			0x01
#define BIT1			0x02
#define BIT2			0x04
#define BIT3			0x08
#define BIT4			0x10
#define BIT5			0x20
#define BIT6			0x40
#define BIT7			0x80
#define BIT8			0x0100
#define BIT9			0x0200
#define BIT10			0x0400
#define BIT11			0x0800
#define BIT12			0x1000
#define BIT13			0x2000
#define BIT14			0x4000
#define BIT15			0x8000
#define BIT16			0x010000
#define BIT17			0x020000
#define BIT18			0x040000
#define BIT19			0x080000
#define BIT20			0x100000
#define BIT21			0x200000
#define BIT22			0x400000
#define BIT23			0x800000
#define BIT24			0x01000000
#define BIT25			0x02000000
#define BIT26			0x04000000
#define BIT27			0x08000000
#define BIT28			0x10000000
#define BIT29			0x20000000
#define BIT30			0x40000000
#define BIT31			0x80000000
//--------------------------------------------------------------------
//		File System Configure
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//			Number of file handles
//	Set the maximum number of simultaneously open files in your system.
//	Please be aware, that the file system requires one FS_FILE structure for each
//open file.
//--------------------------------------------------------------------
#define FS_FILE_MAXOPEN			6		// Maximum number of file handles

//--------------------------------------------------------------------
//			Directory functions support
//	Enables directory functions FS_DirOpen, FS_DirRead, FS_DirClose, FS_DirRewind,
//FS_DirCreate, FS_DirRemove.
//--------------------------------------------------------------------
#define FS_POSIX_DIR_SUPPORT	1		// Directory support
#if FS_POSIX_DIR_SUPPORT
	#define FS_DIR_MAXOPEN		4		// Maximum number of directory handles
#endif

//--------------------------------------------------------------------
//			FAT File System Support Device Type Define
//--------------------------------------------------------------------
#define FS_MAX_DEV 				3       // SDCard, XtraRom, SDCard2

//--------------------------------------------------------------------
//			FAT File System Layer defines
//--------------------------------------------------------------------
#define FS_FAT_FAST_MODE		1		// =0: Normal Fast Mode; =1: Multi Mode
#define FS_FAT_USE_WRITE		1		// Enable/disable write functions of the FS system.
#define FS_FAT_USE_CREATE		1		// Enable/disable create functions of the FS system.
#define FS_FAT_USE_DELETE		1		// Enable/disable delete functions of the FS system.
#define FS_FAT_USE_FATLIST		1		// Enable/disable check all FAT chain for free cluster.
#define	FS_FAT_USE_SHORTCUT		0//1		// Enable/disable seek file use short-cut functions.
#define FS_FAT_USE_ID_OPEN		1		// Enable/disable open file by DirID and FileID.
#define FS_FAT_SDCARD_OFFSET	1       // FAT access SDCard sector will add "g_AllHiddenSectorNum" offset
#define FS_FAT_SDCARD_CAPACITY	1	//get sd card capacity

//	Define the information of Seek Short Cut function.
//	This define only used when FS_FAT_USE_SHORTCUT == 1.
#define	FS_SC_BLOCK_BIT			25		//One block size is 2^n (25 means 32MB).
#define FS_MAX_SC_POINT			128		//Max points of file FAT chain.(=4GB/32MB)

//--------------------------------------------------------------------
//		Constants define
//--------------------------------------------------------------------
// File system version
#define FS_VERSION				0x00000001UL	// 0.00.01

// Global error codes
#define FS_ERR_OK				(FS_i16)0x0000
#define FS_ERR_EOF				(FS_i16)0xfff0
#define FS_ERR_DISKFULL			(FS_i16)0xffe0
#define FS_ERR_INVALIDPAR		(FS_i16)0xffd0
#define FS_ERR_WRITEONLY		(FS_i16)0xffc0
#define FS_ERR_READONLY			(FS_i16)0xffb0
#define FS_ERR_READERROR		(FS_i16)0xffa0
#define FS_ERR_WRITEERROR		(FS_i16)0xff90
#define FS_ERR_DISKCHANGED		(FS_i16)0xff80
#define FS_ERR_CLOSE			(FS_i16)0xff70

// Global constants
#define FS_SEEK_SET				0
#define FS_SEEK_CUR				1
#define FS_SEEK_END				2

// Device type
#define FS_SDCARD0               0
#define FS_XROM                 1
#define FS_SDCARD1              2

// Device state
#define FS_MEDIA_ISNOTPRESENT	0
#define FS_MEDIA_ISPRESENT		1
#define FS_MEDIA_STATEUNKNOWN	2

// File types
#define FS_FAT_ATTR_READ_ONLY	0x01
#define FS_FAT_ATTR_HIDDEN		0x02
#define FS_FAT_ATTR_SYSTEM		0x04
#define FS_FAT_ATTR_VOLUME_ID	0x08
#define FS_FAT_ATTR_LONG_NAME	0x0F
#define FS_FAT_ATTR_DIRECTORY	0x10
#define FS_FAT_ATTR_ARCHIVE		0x20
#define FS_FAT_LONG_NAME_MASK	0x3F

// FAT Type
#define FS_FAT_TYPE_16			0
#define FS_FAT_TYPE_32			1

// Definde the maximum size of a directory and file name.
// In FAT file system, eatch entry have 13 character for long name.(DSP char is 16-bit)
// So the direcotry name buffer size should be the multiple of 13.
#define FS_FAT_LONG_NAME_CHARS	13		//One entry can save 13 unicode character of the long name.
#define FS_FAT_LONG_NAME_MAXENT	20		//Long name max entry number.
#define FS_DIRNAME_MAX			(FS_FAT_LONG_NAME_CHARS * FS_FAT_LONG_NAME_MAXENT)


#define FS_FAT_DENTRY_SIZE		32
#define FS_FAT_DENTRY_BIT		5
#define FS_FAT_SHORT_NAME_LEN	12		//Short name string length. (Including string end '\0')

//	This define maybe no use in the future, because it can be read from device driver.
#define FS_FAT_SEC_SIZE			0x200	//Set this size according by the device sector size or page size

//	This define only used when user choose Multi Mode.
#define FS_MULTI_HEAD			0		//Multi read/write flag -- HEAD
#define FS_MULTI_MIDDLE			1		//Multi read/write flag -- MIDDLE

//--------------------------------------------------------------------
//		Global data types
//--------------------------------------------------------------------
//File types
typedef union {
	FS_u16 Value;
	struct {
		FS_u16 mode_r:1;		//mode READ
		FS_u16 mode_w:1;		//mode WRITE
		FS_u16 mode_a:1;		//mode APPEND
		FS_u16 mode_c:1;		//mode CREATE
		FS_u16 mode_b:1;		//mode BINARY
		FS_u16 mode_d:1;		//mode DELETE
		FS_u16 :0;
	} Bit;
} FS_OPEN_MODE;

typedef struct {
    FS_u16 DevIndex;            //SDCard_1 or SDCard_2 or XtraROM
	FS_u32 DirStart;			//File's directory first cluster
	FS_u32 DirIndex;			//The index of entry of file in file's directory
	FS_u32 FirstClust;			//File's first cluster NO.
	FS_u32 CurClust;			//File's current cluster, used by FAT FSL only
	FS_i32 EOFClust;			//File's EOF cluster, used by FAT FSL only
	FS_u32 FilePos;				//Current position in file
	FS_u32 Size;				//Size of file
	FS_i16 Error;				//Error code
	FS_u16 Inuse;				//handle in use mark
	FS_u16 FileAttr;			//File Attribute
	FS_OPEN_MODE Mode;			//File open mode

	//For seek file short-cut functions.
#if FS_FAT_USE_SHORTCUT
	FS_u32	ShortCut[FS_MAX_SC_POINT];		//Save short-cut point start cluster number.
#endif	//FS_FAT_USE_SHORTCUT
} FS_FILE;

// For FAT pre-scan and multi access flag
typedef struct {

#if FS_FAT_USE_FATLIST
    FS_u16* pFATListBuf;        //point to FAT List Table buffer address
    FS_u16  FATListSz;          //FAT List Table buffer size
    FS_u16  FATListMappingSecNum;//One bit of FAT List data is mapping to FAT sector numbers(2 power of n).
#endif

    FS_i32  LastUsedClust;      //Save last used cluster, for saving search free cluster time.
    FS_u16  MultiRW_Fg;		    //Multi read/write flag for multi mode.
	FS_u16  MultiRW_LastFP;		//which file pointer is the last one using multi-access to access this device
} FS_DISK_INFO;

// Directory types
#if FS_POSIX_DIR_SUPPORT
typedef struct {
	FS_u32  Dir1stClust;		//To be POSIX conform
	FS_Char DirName[FS_DIRNAME_MAX];
	FS_u16  DirAttr;			//FAT only. Contains the "DIR_Attr" field of an entry.
} FS_DIRENT;

typedef struct {
	FS_DIRENT  DirEntry;		// Cunrrent directory entry
    FS_u16 DevIndex;			//Device index NO.
	FS_u32 DirStart;			//File's directory start cluster NO.
	FS_u32 DirIndex;			//The index of entry of directory in the upper directory.
	FS_u32 FirstClust;			//File's first cluster NO.
	FS_u32 CurClust;			//File's current cluster
	FS_u32 LastClust;			//File's last cluster
	FS_i32 EOFClust;			//File's EOF cluster
	FS_i32 DirPos;				//Current position in directory
	FS_u32 Size;				//Size of directory
	FS_i16 Error;				//Error code
	FS_u16 Inuse;				//handle in use mark
} FS_DIR;
#endif	//FS_POSIX_DIR_SUPPORT

//FAT BPB struct
typedef struct {
	FS_u16	BytePerSec;			//Byte per sector
	FS_u16	SecPerClus;			//Sector per cluster
	FS_u16	RsvdSecCnt;			//Reserve sector for BPB
	FS_u16	NumFATs;			//Number of FAT table
	FS_u16	RootEntCnt;			//Number of root dir entries
	FS_u16	TotSec16;			//FAT16 total sector number(RSVD+FAT+ROOT+DATA < 64K)
	FS_u16	FATSz16;			//FAT16 FAT sector number
	FS_u32	TotSec32;			//FAT32 total sector number(RSVD+FAT+ROOT+DATA >= 64K)
	FS_u32	FATSz32;			//FAT32 FAT sector number
	FS_u32	RootClus;			//FAT32 root dir first cluster
	FS_u16	ExtFlags;			//FAT32 FAT mirroring flag
	FS_u16	FSInfo;				//FAT32 FSInfo sector number
	FS_u16	Signature;			//0xAA55

//Unit RSVD, FAT, root, data start address (logic block address)
//Use this struct to reduce calculate time.
	FS_u16	Type;				//FAT type: FAT16 or FAT32
	FS_u16	SecSzBit;			//Sector size bit (if sector size is 512 = 2 ^ 9, so SecSzBit = 9)
	FS_u16	ClusSzBit;			//Cluster size bit (if sector size is 32K = 2 ^ 15, so ClusSzBit = 15)
	FS_u16	ClusSecBit;			//Sector per cluster bit
	FS_u32	BPBStart;			//BPB start sector
	FS_u32	FATStart;			//FAT start sector
	FS_u32	FAT2Start;			//FAT2 start sector
	FS_u32	RootStart;			//Root directory start sector
	FS_u32	DataStart;			//Data area start sector
} FS_FAT_BPB_TYPE;

//FAT directory entry struct
typedef struct {
//	FS_uChar	Data[16];		//FAT director entry length is 32 byte
		FS_u16	Data[16];		//FAT director entry length is 32 byte
} FS_FAT_ENTRY_TYPE;

//FS API open mode type struct
typedef struct {
	FS_pChar name;				//Open mode name
	FS_OPEN_MODE mode;			//Open mode value
} _FS_MODE_TYPE;

//--------------------------------------------------------------------
//		Global data and function declaration
//--------------------------------------------------------------------
extern FS_FAT_BPB_TYPE FS_FAT_BPB[];	//Device and unit BPB table
extern FS_DISK_INFO FS_FAT_DISK_INFO[];
extern FS_u16 FS_DataBuf[];			//Read or write data buffer define (size == one sector size)
extern const FS_pChar _FS_DEVICE_TYPE[];
extern FS_u16 FS_SDCard0_Speed;
extern FS_u16 FS_SDCard1_Speed;
extern FS_u16 DIR_NTRes;
extern FS_u16 FS_RestoreFATChain;

//--------------------------------------------------------------------
//		File I/O functions
//--------------------------------------------------------------------
//---------------------------------------------------------------
//Function:		FS_FOpen
//Description:	Opens an existing file or creates a new file depending on parameters.
//Input:		pFileName	--	Fully qualified file name.
//				pMode		--	Mode for opening the file.
//Output:
//Return:		It returns the address of a FS_FILE structure, if the file could be
//			opened in the requested mode. In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_FILE *FS_FOpen(FS_pChar pFileName, FS_pChar pMode);

//---------------------------------------------------------------
//Function: 	FS_FClose
//Description:	Close an open file and free the file handle.
//Input:		pFile	--	The handle address of the FS_FILE structure.
//Output:
//Return:		Close operation succeed return > 0. In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_u16 FS_FClose(FS_FILE *pFile);

#if	FS_FAT_USE_ID_OPEN
//---------------------------------------------------------------
//Function:		FS_FGetFileEntry
//Description:	Get file's directory start cluster and FDT entry index in folder. (File must be opened.)
//Input:		pFile	--	File handle pointer.
//				pDirIdx	--	Return directory start cluster.
//				pFileIdx--	Return FDT index of file.
//Output:
//Return:		=0: Can get file FDT entry.
//				>0: Action fail.
//Others:
//---------------------------------------------------------------
FS_u16 FS_FGetFileEntry(FS_FILE *pFile, FS_u32 *pDirIdx, FS_u32 *pFileIdx);

//---------------------------------------------------------------
//Function:		FS_FOpenID
//Description:	Opens an existing file by directory start cluster and FDT entry index.
//Input:		DevIdx  --  Which device is assigned
//              DirIdx	--	Directory start cluster which file in.
//				FileIdx	--	FDT index of file.
//				pMode	--	Mode for opening the file.
//Output:
//Return:		It returns the address of a FS_FILE structure, if the file could be
//			opened in the requested mode. In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_FILE *FS_FOpenID(FS_u16 DevIdx, FS_u32 DirIdx, FS_u32 FileIdx, FS_pChar pMode);

//---------------------------------------------------------------
//Function:		FS_FGetNameByID
//Description:	Get a existing file name by directory start cluster and FDT entry index.
//Input:		DevIdx  --  Which device is assigned
//              pName	--	Pointer of file name array buffer.
//				DirIdx	--	Directory start cluster which file in.
//				FileIdx	--	FDT index of file.
//Output:
//Return:		=0: Action ok.
//				=1: Get ID error.
//				=2: Read FDT entry error.
//Others:
//---------------------------------------------------------------
FS_u16 FS_FGetNameByID(FS_u16 DevIdx, FS_Char *pName, FS_u32 DirIdx, FS_u32 FileIdx);
#endif	//FS_FAT_USE_ID_OPEN

//---------------------------------------------------------------
//Function: 	FS_FReadSingleSec
//Description:	Reads data from an open file. Only for multiple of sector size read.
//Input:		pData	--	Pointer to a data buffer for storing data transferred from file.
//				pFile	--	Pointer to a data structure of type FS_FILE.
//Output:
//Return:		Number of elements transferred. In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_u16 FS_FReadSector(FS_u16 *pData, FS_FILE *pFile);

#if FS_FAT_USE_WRITE
//---------------------------------------------------------------
//Function: 	FS_FWriteSector
//Description:	Writes data to an open file.
//Input:		pData	--	Pointer to a data buffer for storing data transferred from file.
//				pFile	--	Pointer to a data structure of type FS_FILE.
//Output:
//Return:		Number of elements written. In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_u16 FS_FWriteSector(FS_u16 *pData, FS_FILE *pFile);
#endif //FS_FAT_USE_WRITE

#if	FS_FAT_USE_DELETE
//---------------------------------------------------------------
//Function: 	FS_FRemove
//Description:	Removes file from the device.
//Input:		pFileName	--	Fully qualified file name.
//Output:
//Return:		==1		--	File remove ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_FRemove(FS_pChar pFileName);
#endif	//FS_FAT_USE_DELETE

//--------------------------------------------------------------------
//		File pointer handling
//--------------------------------------------------------------------

//---------------------------------------------------------------
//Function: 	FS_FSeek
//Description:	Sets current position of the file pointer.
//Input:		pFile	--	Pointer to a data structure of type FS_FILE.
//				Offset	--	Offset for setting the file pointer position.
//				Whence	--	Mode for positioning file pointer.
//						(FS_SEEK_SET, FS_SEEK_CUR, FS_SEEK_END)
//Output:
//Return:		==1		--	File seek ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_FSeek(FS_FILE *pFile, FS_i32 Offset, FS_u16 Whence);

//---------------------------------------------------------------
//Function: 	FS_FTell
//Description:	Returns current position of the file pointer.
//Input:		pFile		--	Pointer to a data structure of type FS_FILE.
//Output:
//Return:		Current position of file pointer in the file. On failure the return value is -1.
//Others:
//---------------------------------------------------------------
FS_i32 FS_FTell(FS_FILE *pFile);


//--------------------------------------------------------------------
//		I/O error handling
//--------------------------------------------------------------------

//---------------------------------------------------------------
//Function: 	FS_FError
//Description:	Returns current error status of a file.
//Input:		pFile		--	Pointer to a data structure of type FS_FILE.
//Output:
//Return:		Returns value not equal to FS_ERR_OK in case a file operation caused an error.
//Others:
//---------------------------------------------------------------
FS_i16 FS_FError(FS_FILE *pFile);

//---------------------------------------------------------------
//Function: 	FS_ClearErr
//Description:	Clears the error status of a file.
//Input:		pFile		--	Pointer to a data structure of type FS_FILE.
//Output:
//Return:		==1		--	Ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_ClearErr(FS_FILE *pFile);


//--------------------------------------------------------------------
//		Directory functions
//--------------------------------------------------------------------
#if FS_POSIX_DIR_SUPPORT

//---------------------------------------------------------------
//Function: 	FS_OpenDir
//Description:	Opens an existing directory for reading.
//Input:		pDirName	--	Fully qualified directory name.
//Output:
//Return:		Returns the address of an FS_DIR data structure if the directory could be opened.
//				In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_DIR *FS_DirOpen(FS_pChar pDirName);

//---------------------------------------------------------------
//Function: 	FS_CloseDir
//Description:	This functions closes a directory referred by parameter pDir
//Input:		pDir	--	Pointer to a data structure of type FS_DIR.
//Output:
//Return:		==1		--	Directory close ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_DirClose(FS_DIR *pDir);

//---------------------------------------------------------------
//Function: 	FS_ReadDir
//Description:	Reads next directory entry in directory.
//Input:		pDir	--	Pointer to a data structure of type FS_DIR.
//Output:
//Return:		Returns a pointer to a directory entry.
//				If there is no more entry in the directory or in case of any error, 0 is returned.
//Others:
//---------------------------------------------------------------
FS_DIRENT *FS_DirRead(FS_DIR *pDir);

//---------------------------------------------------------------
//Function: 	FS_RewindDir
//Description:	This function sets pointer for reading the next directory entry to the first entry in the directory.
//Input:		pDir	--	Pointer to a data structure of type FS_DIR.
//Output:
//Return:		==1		--	Action ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_DirRewind(FS_DIR *pDir);

#if FS_FAT_USE_CREATE
//---------------------------------------------------------------
//Function: 	FS_CreateDir
//Description:	Creates a new directory.
//Input:		pDirName	--	Fully qualified directory name.
//Output:
//Return:		Returns the address of an FS_DIR data structure if the directory could be created.
//				In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_DIR *FS_DirCreate(FS_pChar pDirName);
#endif	//FS_FAT_USE_CREATE

#if FS_FAT_USE_DELETE
//---------------------------------------------------------------
//Function: 	FS_RemoveDir
//Description:	Deletes a directory. The directory must empty, otherwise the operation is failed.
//Input:        pDirName	--	Fully qualified directory name.
//Output:
//Return:		Returns 1, if the directory has been successfully removed.
//				In case of any error the return value is 0.
//Others:
//---------------------------------------------------------------
FS_u16 FS_DirRemove(FS_pChar pDirName);
#endif	//FS_FAT_USE_DELETE

//---------------------------------------------------------------
//Function: 	FS_DirSearchExt
//Description:	Searh the same ext. file of "pExtName" in pDir directory, and return how many files can searched.
//Input:		pDir		--	Pointer to a data structure of type FS_DIR.
//				pExtName	--	Pointer of the ext. name.
//Output:
//Return:		>= 0	--	The number of file that can searched.
//				<0		--	In case of any error.
//Others:		Directory handle DirPos will point to the end of the directory.
//---------------------------------------------------------------
FS_i16 FS_DirSearchExt(FS_DIR *pDir, FS_pChar pExtName);

//---------------------------------------------------------------
//Function: 	FS_DirGetExtFile
//Description:	Get the FileNum'th  file which have ext. name the same as pExtName in directory of pDir.
//Input:		pDir		--	Pointer to a data structure of type FS_DIR.
//				FileNum		--	The index of file. (1~n)
//				pExtName	--	Pointer of the ext. name.
//Output:
//Return:		Returns a pointer to a directory entry.
//				If there is no more entry in the directory or in case of any error, 0 is returned.
//Others:		Directory handle DirPos will point to the next entry of the returned entry.
//---------------------------------------------------------------
FS_DIRENT *FS_DirGetExtFile(FS_DIR *pDir, FS_u16 FileNum, FS_pChar pExtName);

#endif	//FS_POSIX_DIR_SUPPORT


//--------------------------------------------------------------------
//		File system control functions
//--------------------------------------------------------------------
//---------------------------------------------------------------
//Function: 	FS_Init
//Description:	Initial file system and read the system parameter from the device.
//Input:     SW=0: SDCARD0->P1
//           SW=1: SDCARD0->P3
//Output:
//Return:		== 0		--	Ok.
//				== 1		--	No Card Inside
//				== 2		--  SDCard or XROM Init OK, but Non FAT
//				== 3 		--  SDCard Init Fail
//Others:
//---------------------------------------------------------------
FS_u16 FS_Init(void);

//---------------------------------------------------------------
//Function: 	FS_Init2
//Description:	Initial file system to support SDCard2
//Input:        None
//Output:
//Return:		==0		--	Ok.
//				==1		--	Device initial fail.
//				==2		--	Can't read BPB table.
//Others:       Users need to execute FS_Init() before call FS_Init2()
//---------------------------------------------------------------
FS_u16 FS_Init2(void);

#if FS_FAT_USE_FATLIST
//---------------------------------------------------------------
//Function: 	FS_PreScanFAT
//Description:	Check FAT free cluster
//Input:		DevIdx  ==1  -- SDCard
//						==2  -- SDCard2
//              pData    -- Pointer to a data buffer for storing pre-scan FAT table.
//              BufferSz -- The pBuffer size
//Output:
//Return:		==1		--	Ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_PreScanFAT(FS_u16 DevIdx, FS_u16* pData, FS_u16 BufferSz);
#endif //FS_FAT_USE_FATLIST

//---------------------------------------------------------------
//Function: 	FS_Exit
//Description:	Stop the file system.
//Input:
//Output:
//Return:		==1		--	Ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_Exit(void);

//---------------------------------------------------------------
//Function: 	FS_DirectReadSector
//Description:	Read one phycial sector by Cluster No. and Offset.
//Input:		DevIdx  --  Which device is assigned
//              ulClust --	Cluster index for read action.
//				uiOffset--	Sector offset of the cluster.
//				pBuf	--	Data buffer for read action.
//Output:
//Return:		==1		--	Ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_DirectReadSector(FS_u16 DevIdx, FS_u32 ulClust ,FS_u16 uiOffset, FS_u16 *pBuf);

//---------------------------------------------------------------
//Function: 	FS_DirectWriteSector
//Description:	Write one phycial sector by Cluster No. and Offset.
//Input:		DevIdx  --  Which device is assigned
//              ulClust --	Cluster index for read action.
//				uiOffset--	Sector offset of the cluster.
//				pBuf	--	Data buffer for read action.
//Output:
//Return:		==1		--	Ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_DirectWriteSector(FS_u16 DevIdx, FS_u32 ulClust ,FS_u16 uiOffset, FS_u16 *pBuf);

//---------------------------------------------------------------
//Function: 	FS_SetFileAttribute
//Description:	Modify Open file attribute and update to device
//Input:		pFile	--	Pointer to a data structure of type FS_FILE.
//				Attr    --  Only can modify file attribute Bit1~Bit0
//							Bit0 -- FS_FAT_ATTR_READ_ONLY
//							Bit1 -- FS_FAT_ATTR_HIDDEN
//Output:
//Return:		==1		--	Ok.
//				==0		--	An error has occured.
//Others:
//---------------------------------------------------------------
FS_u16 FS_SetFileAttribute(FS_FILE *pFile, FS_u16 Attr);

FS_u16 FS_FAT_ReadBPB(FS_u16 DevIdx);

#if FS_FAT_SDCARD_CAPACITY
FS_u16 FS_FAT_ReadBPB(FS_u16 DevIdx);
FS_u32 FS_GetRemainCapacity(FS_u16 DevIdx);
FS_u32 FS_PreScanRemainCapacity(FS_u16 DevIdx);
FS_u32 FS_GetTotalCapacity(FS_u16 DevIdx);
#endif

#endif	// _FS_API_H_


