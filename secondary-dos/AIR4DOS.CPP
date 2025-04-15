#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int DebugMode=0;
int TimerUpd;
double version=1.04;
int VideoMode=1; // 1: 80x25, 2: 80x50
int ColorMode=0; // 0: Monochrome, 1: 16 Colour (Default: Red & White)

double difference;
int year;
int mon;
int day;
int hour;
int min;
int sec;

//char MD='\xDB'; // map borders <-- too complex
char BG='\xDB'; // inactive regions
char FG='\xB0'; // active regions
char BD='\xB1'; // regions border
char CI='\xB2'; // inactive capital
char CA='\xFE'; // active capital
char PV='\xB0'; // inactive char (on the right)
char WN='!'; // active char (on the right)

char SpaceChr;
char SpaceChr1;

char VIst;
char ODst;
char VOst;
char POst;
char DNst;
char RIst;
char DOst;
char SUst;
char ZHst;
char TRst;
char ZKst;
char KAst;
char ZPst;
char KEst;
char IVst;
char KHst;
char KOst;
char CEst;
char KIst;
char CVst;
char LHst;
char CHst;
char LVst;
char ACst;
char MKst;
char KYst;
char TSst;

char VIch=BG;
char ODch=BG;
char VOch=BG;
char POch=BG;
char DNch=BG;
char RIch=BG;
char DOch=BG;
char SUch=BG;
char ZHch=BG;
char TRch=BG;
char ZKch=BG;
char KAch=BG;
char ZPch=BG;
char KEch=BG;
char IVch=BG;
char KHch=BG;
char KOch=BG;
char CEch=BG;
char KIch=BG;
char CVch=BG;
char LHch=BG;
char CHch=BG;
char LVch=BG;
char ACch=BG;
char MKch=BG;
char KYch=CI;
char TSch=BG;

void showCursor() {
	union REGS regs;
	regs.h.ah=0x01;
	regs.h.ch=0x06;
	regs.h.cl=0x07;
	int86(0x10,&regs,&regs);
}

void getTime() {
	time_t now;
	struct tm *tm_info;

	time(&now);
	tm_info=localtime(&now);
}

void getDate() {
	// Prepare current date and day calculation
	time_t t1, t2, t3;

	struct tm *tm_info, date1={0}, date2={0};

	time(&t1);
	tm_info=localtime(&t1);

	date1.tm_isdst=-1;
	date2.tm_isdst=-1;

	date1.tm_year=2022-1900;
	date1.tm_mon=2;
	date1.tm_mday=24;

	date2.tm_year=tm_info->tm_year;
	date2.tm_mon=tm_info->tm_mon+1;
	date2.tm_mday=tm_info->tm_mday-1;

	hour=tm_info->tm_hour;
	min=tm_info->tm_min;
	sec=tm_info->tm_sec;

	year=tm_info->tm_year+1900;
	mon=tm_info->tm_mon+1;
	day=tm_info->tm_mday;

	t2=mktime(&date1);
	t3=mktime(&date2);

	difference=difftime(t3,t2)/86400;
}

void hideCursor() {
	union REGS regs;
	regs.h.ah=0x01;
	regs.h.ch=0x20;
	regs.h.cl=0x00;
	int86(0x10,&regs,&regs);
	_setcursortype(_NOCURSOR);
}

void VIon() {
	VIst=WN;
	VIch=FG;
}

void VIoff() {
	VIst=PV;
	VIch=BG;
}

void ODon() {
	ODst=WN;
	ODch=FG;
}

void ODoff() {
	ODst=PV;
	ODch=BG;
}

void VOon() {
	VOst=WN;
	VOch=FG;
}

void VOoff() {
	VOst=PV;
	VOch=BG;
}
void POon() {
	POst=WN;
	POch=FG;
}

void POoff() {
	POst=PV;
	POch=BG;
}

void DNon() {
	DNst=WN;
	DNch=FG;
}

void DNoff() {
	DNst=PV;
	DNch=BG;
}

void RIon() {
	RIst=WN;
	RIch=FG;
}

void RIoff() {
	RIst=PV;
	RIch=BG;
}

void DOon() {
	DOst=WN;
	DOch=FG;
}

void DOoff() {
	DOst=PV;
	DOch=BG;
}

void SUon() {
	SUst=WN;
	SUch=FG;
}

void SUoff() {
	SUst=PV;
	SUch=BG;
}

void ZHon() {
	ZHst=WN;
	ZHch=FG;
}

void ZHoff() {
	ZHst=PV;
	ZHch=BG;
}

void TRon() {
	TRst=WN;
	TRch=FG;
}

void TRoff() {
	TRst=PV;
	TRch=BG;
}

void ZKon() {
	ZKst=WN;
	ZKch=FG;
}

void ZKoff() {
	ZKst=PV;
	ZKch=BG;
}

void KAon() {
	KAst=WN;
	KAch=FG;
}

void KAoff() {
	KAst=PV;
	KAch=BG;
}

void ZPon() {
	ZPst=WN;
	ZPch=FG;
}

void ZPoff() {
	ZPst=PV;
	ZPch=BG;
}

void KEon() {
	KEst=WN;
	KEch=FG;
}

void KEoff() {
	KEst=PV;
	KEch=BG;
}

void IVon() {
	IVst=WN;
	IVch=FG;
}

void IVoff() {
	IVst=PV;
	IVch=BG;
}

void KHon() {
	KHst=WN;
	KHch=FG;
}

void KHoff() {
	KHst=PV;
	KHch=BG;
}

void KOon() {
	KOst=WN;
	KOch=FG;
}

void KOoff() {
	KOst=PV;
	KOch=BG;
}

void CEon() {
	CEst=WN;
	CEch=FG;
}

void CEoff() {
	CEst=PV;
	CEch=BG;
}

void KIon() {
	KIst=WN;
	KIch=FG;
}

void KIoff() {
	KIst=PV;
	KIch=BG;
}

void CVon() {
	CVst=WN;
	CVch=FG;
}

void CVoff() {
	CVst=PV;
	CVch=BG;
}

void LHon() {
	LHst=WN;
	LHch=FG;
}

void LHoff() {
	LHst=PV;
	LHch=BG;
}

void CHon() {
	CHst=WN;
	CHch=FG;
}

void CHoff() {
	CHst=PV;
	CHch=BG;
}

void LVon() {
	LVst=WN;
	LVch=FG;
}

void LVoff() {
	LVst=PV;
	LVch=BG;
}

void ACon() {
	ACst=WN;
	ACch=FG;
}

void ACoff() {
	ACst=PV;
	ACch=BG;
}

void MKon() {
	MKst=WN;
	MKch=FG;
}

void MKoff() {
	MKst=PV;
	MKch=BG;
}

void KYon() {
	KYst=WN;
	KYch=CA;
}

void KYoff() {
	KYst=PV;
	KYch=CI;
}

void request() {
	system("HTGET.EXE -quiet http://ubilling.net.ua:80/aerialalerts/ > STATUS.GET");
} // -v for full output

void getData() {
	clrscr();
	printf("Air Alert for MS-DOS\n");
	printf("\n");
	printf("Receiving data... Normally takes about a second.\n");
	printf("Press Esc and try to refresh again if the program stucks here.\n");
	printf("\n");
	request();
	char buffer[4096];
	FILE *file=fopen("STATUS.GET","r");
	while (!file) {
		//request();
		//FILE *file=fopen("STATUS.GET","r");
		//fread(buffer,sizeof(char),4000-1,file);
		//fclose(file);
		//buffer[4000-1]='\0';
		printf("Filesystem error");
		showCursor();
		exit(EXIT_FAILURE);
	}
	fread(buffer,sizeof(char),4096-1,file);
	fclose(file);
	buffer[4096-1]='\0';

	char ACs[2];
	strncpy(ACs,buffer,1);
	ACs[1]='\0';

	if (strcmp(ACs,"{")==0) {
		ACon();
		memset(ACs,0,sizeof(ACs));
	}

	char VOs[6+1];
	strncpy(VOs,buffer+349,6+1);
	VOs[6]='\0';

	if(strcmp(VOs,"true,")==0) {
		VOon();
	} else if (strcmp(VOs,"false")==0) {
		VOoff();
	} else if (strcmp(VOs,"true,\"")==0) {
		VOon();
	} else if (strcmp(VOs,":true,")==0) {
		VOon();
	} else if (strcmp(VOs,"false,")==0) {
		VOoff();
	}

	memset(VOs,0,sizeof(VOs));

	char VIs[6+1];
	strncpy(VIs,buffer+199,6+1); // 199
	VIs[6]='\0';
	//printf("%c%c%c%c%c%c",VIs[0],VIs[1],VIs[2],VIs[3],VIs[4],VIs[5],VIs[6]);

	if(strcmp(VIs,":false")==0) {
		VIoff();
	} else if (strcmp(VIs,"\":fals")==0) {
		VIoff();
	} else if (strcmp(VIs,":true,")==0) {
		VIon();
	} else if (strcmp(VIs,"true,\"")==0) {
		VIon();
	} else if (strcmp(VIs,"false,")==0) {
		VIoff();
	} else if (strcmp(VIs,"alse,\"")==0) {
		VIoff();
	} else if (strcmp(VIs,"rue,\"c")==0) {
		VIon();
	}

	memset(VIs,0,sizeof(VIs));

	char DNs[7+1];
	strncpy(DNs,buffer+541,7+1);
	DNs[7]='\0';

	if(strcmp(DNs,"\":true,")==0) {
		DNon();
	} else if (strcmp(DNs,":true,\"")==0) {
		DNon();
	} else if (strcmp(DNs,"true,\"c")==0) {
		DNon();
	} else if (strcmp(DNs,"\":false")==0) {
		DNoff();
	} else if (strcmp(DNs,":false,")==0) {
		DNoff();
	} else if (strcmp(DNs,"false,\"")==0) {
		DNoff();
	}

	memset(DNs,0,sizeof(DNs));

	char DOs[8+1];
	strncpy(DOs,buffer+685,8+1);
	DOs[8]='\0';

	if(strcmp(DOs,"w\":false")==0) {
		DOoff();
	} else if (strcmp(DOs,"\":false,")==0) {
		DOoff();
	} else if (strcmp(DOs,":false,\"")==0) {
		DOoff();
	} else if (strcmp(DOs,"false,\"c")==0) {
		DOoff();
	} else if (strcmp(DOs,"w\":true,")==0) {
		DOon();
	} else if (strcmp(DOs,"\":true,\"")==0) {
		DOon();
	} else if (strcmp(DOs,":true,\"c")==0) {
		DOon();
	} else if (strcmp(DOs,"true,\"ch")==0) {
		DOon();
	}

	memset(DOs,0,sizeof(DOs));

	char ZHs[9+1];
	strncpy(ZHs,buffer+847,9+1);
	ZHs[9]='\0';

	if(strcmp(ZHs,"true,\"cha")==0) {
		ZHon();
	} else if (strcmp(ZHs,":true,\"ch")==0) {
		ZHon();
	} else if (strcmp(ZHs,"\":true,\"c")==0) {
		ZHon();
	} else if (strcmp(ZHs,"w\":true,\"")==0) {
		ZHon();
	} else if (strcmp(ZHs,"ow\":true,")==0) {
		ZHon();
	} else if (strcmp(ZHs,"ow\":false")==0) {
		ZHoff();
	} else if (strcmp(ZHs,"w\":false,")==0) {
		ZHoff();
	} else if (strcmp(ZHs,"\":false,\"")==0) {
		ZHoff();
	} else if (strcmp(ZHs,":false,\"c")==0) {
		ZHoff();
	} else if (strcmp(ZHs,"false,\"ch")==0) {
		ZHoff();
	}

	memset(ZHs,0,sizeof(ZHs));

	char ZKs[10+1];
	strncpy(ZKs,buffer+1015,10+1);
	ZKs[10]='\0';

	if(strcmp(ZKs,"true,\"cha")==0) {
		ZKon();
	} else if (strcmp(ZKs,"false,\"cha")==0) {
		ZKoff();
	} else if (strcmp(ZKs,"true,\"chan")==0) {
		ZKon();
	} else if (strcmp(ZKs,":false,\"ch")==0) {
		ZKoff();
	} else if (strcmp(ZKs,":true,\"cha")==0) {
		ZKon();
	} else if (strcmp(ZKs,"\":false,\"c")==0) {
		ZKoff();
	} else if (strcmp(ZKs,"\":true,\"ch")==0) {
		ZKon();
	} else if (strcmp(ZKs,"w\":false,\"")==0) {
		ZKoff();
	} else if (strcmp(ZKs,"w\":true,\"c")==0) {
		ZKon();
	} else if (strcmp(ZKs,"ow\":false,")==0) {
		ZKoff();
	} else if (strcmp(ZKs,"ow\":true,\"")==0) {
		ZKon();
	} else if (strcmp(ZKs,"now\":false")==0) {
		ZKoff();
	} else if (strcmp(ZKs,"now\":true,")==0) {
		ZKon();
	}

	memset(ZKs,0,sizeof(ZKs));

	char IVs[12+1];
	strncpy(IVs,buffer+1024+340,12+1);
	IVs[12]='\0';

	if(strcmp(IVs,"false,\"chang")==0) {
		IVoff();
	} else if (strcmp(IVs,"true,\"change")==0) {
		IVon();
	} else if (strcmp(IVs,":false,\"chan")==0) {
		IVoff();
	} else if (strcmp(IVs,":true,\"chang")==0) {
		IVon();
	} else if (strcmp(IVs,"\":false,\"cha")==0) {
		IVoff();
	} else if (strcmp(IVs,"\":true,\"chan")==0) {
		IVon();
	} else if (strcmp(IVs,"w\":false,\"ch")==0) {
		IVoff();
	} else if (strcmp(IVs,"w\":true,\"cha")==0) {
		IVon();
	} else if (strcmp(IVs,"ow\":false,\"c")==0) {
		IVoff();
	} else if (strcmp(IVs,"ow\":true,\"ch")==0) {
		IVon();
	} else if (strcmp(IVs,"now\":false,\"")==0) {
		IVoff();
	} else if (strcmp(IVs,"now\":true,\"c")==0) {
		IVon();
	} else if (strcmp(IVs,"tnow\":false,")==0) {
		IVoff();
	} else if (strcmp(IVs,"tnow\":true,\"")==0) {
		IVon();
	} else if (strcmp(IVs,"rtnow\":false")==0) {
		IVoff();
	} else if (strcmp(IVs,"rtnow\":true,")==0) {
		IVon();
	}

	memset(IVs,0,sizeof(IVs));

	char KOs[13+1];
	strncpy(KOs,buffer+1024+484,13+1);
	KOs[13]='\0';

	if(strcmp(KOs,"ertnow\":false")==0) {
		KOoff();
	} else if (strcmp(KOs,"ertnow\":true,")==0) {
		KOon();
	} else if (strcmp(KOs,"rtnow\":false,")==0) {
		KOoff();
	} else if (strcmp(KOs,"rtnow\":true,\"")==0) {
		KOon();
	} else if (strcmp(KOs,"tnow\":false,\"")==0) {
		KOoff();
	} else if (strcmp(KOs,"tnow\":true,\"c")==0) {
		KOon();
	} else if (strcmp(KOs,"now\":false,\"c")==0) {
		KOoff();
	} else if (strcmp(KOs,"now\":true,\"ch")==0) {
		KOon();
	} else if (strcmp(KOs,"ow\":false,\"ch")==0) {
		KOoff();
	} else if (strcmp(KOs,"ow\":true,\"cha")==0) {
		KOon();
	} else if (strcmp(KOs,"w\":false,\"cha")==0) {
		KOoff();
	} else if (strcmp(KOs,"w\":true,\"chan")==0) {
		KOon();
	} else if (strcmp(KOs,"\":false,\"chan")==0) {
		KOoff();
	} else if (strcmp(KOs,"\":true,\"chang")==0) {
		KOon();
	} else if (strcmp(KOs,":false,\"chang")==0) {
		KOoff();
	} else if (strcmp(KOs,":true,\"change")==0) {
		KOon();
	} else if (strcmp(KOs,"false,\"change")==0) {
		KOoff();
	} else if (strcmp(KOs,"true,\"changed")==0) {
		KOon();
	}

	memset(KOs,0,sizeof(KOs));

	char KIs[14+1];
	strncpy(KIs,buffer+1024+664,14+1);
	KIs[14]='\0';

	if(strcmp(KIs,"false,\"changed")==0) {
		KIoff();
	} else if (strcmp(KIs,"true,\"changed\"")==0) {
		KIon();
	} else if (strcmp(KIs,":false,\"change")==0) {
		KIoff();
	} else if (strcmp(KIs,":true,\"changed")==0) {
		KIon();
	} else if (strcmp(KIs,"\":false,\"chang")==0) {
		KIoff();
	} else if (strcmp(KIs,"\":true,\"change")==0) {
		KIon();
	} else if (strcmp(KIs,"w\":false,\"chan")==0) {
		KIoff();
	} else if (strcmp(KIs,"w\":true,\"chang")==0) {
		KIon();
	} else if (strcmp(KIs,"ow\":false,\"cha")==0) {
		KIoff();
	} else if (strcmp(KIs,"ow\":true,\"chan")==0) {
		KIon();
	} else if (strcmp(KIs,"now\":false,\"ch")==0) {
		KIoff();
	} else if (strcmp(KIs,"now\":true,\"cha")==0) {
		KIon();
	} else if (strcmp(KIs,"tnow\":false,\"c")==0) {
		KIoff();
	} else if (strcmp(KIs,"tnow\":true,\"ch")==0) {
		KIon();
	} else if (strcmp(KIs,"rtnow\":false,\"")==0) {
		KIoff();
	} else if (strcmp(KIs,"rtnow\":true,\"c")==0) {
		KIon();
	} else if (strcmp(KIs,"ertnow\":false,")==0) {
		KIoff();
	} else if (strcmp(KIs,"ertnow\":true,\"")==0) {
		KIon();
	} else if (strcmp(KIs,"lertnow\":false")==0) {
		KIoff();
	} else if (strcmp(KIs,"lertnow\":true,")==0) {
		KIon();
	}

	memset(KIs,0,sizeof(KIs));

	char LHs[15+1];
	strncpy(LHs,buffer+1024+814,15+1);
	LHs[15]='\0';

	if(strcmp(LHs,"alertnow\":false")==0) {
		LHoff();
	} else if (strcmp(LHs,"alertnow\":true,")==0) {
		LHon();
	} else if (strcmp(LHs,"lertnow\":false,")==0) {
		LHoff();
	} else if (strcmp(LHs,"lertnow\":true,\"")==0) {
		LHon();
	} else if (strcmp(LHs,"ertnow\":false,\"")==0) {
		LHoff();
	} else if (strcmp(LHs,"ertnow\":true,\"c")==0) {
		LHon();
	} else if (strcmp(LHs,"rtnow\":false,\"c")==0) {
		LHoff();
	} else if (strcmp(LHs,"rtnow\":true,\"ch")==0) {
		LHon();
	} else if (strcmp(LHs,"tnow\":false,\"ch")==0) {
		LHoff();
	} else if (strcmp(LHs,"tnow\":true,\"cha")==0) {
		LHon();
	} else if (strcmp(LHs,"now\":false,\"cha")==0) {
		LHoff();
	} else if (strcmp(LHs,"now\":true,\"chan")==0) {
		LHon();
	} else if (strcmp(LHs,"ow\":false,\"chan")==0) {
		LHoff();
	} else if (strcmp(LHs,"ow\":true,\"chang")==0) {
		LHon();
	} else if (strcmp(LHs,"w\":false,\"chang")==0) {
		LHoff();
	} else if (strcmp(LHs,"w\":true,\"change")==0) {
		LHon();
	} else if (strcmp(LHs,"\":false,\"change")==0) {
		LHoff();
	} else if (strcmp(LHs,"\":true,\"changed")==0) {
		LHon();
	} else if (strcmp(LHs,":false,\"changed")==0) {
		LHoff();
	} else if (strcmp(LHs,":true,\"changed\"")==0) {
		LHon();
	} else if (strcmp(LHs,"false,\"changed\"")==0) {
		LHoff();
	} else if (strcmp(LHs,"true,\"changed\":")==0) {
		LHon();
	}

	memset(LHs,0,sizeof(LHs));

	char LVs[15+1];
	strncpy(LVs,buffer+1024+964,15+1);
	LVs[15]='\0';

	if(strcmp(LVs,"false,\"changed\":")==0) {
		LVoff();
	} else if (strcmp(LVs,"true,\"changed\":\"")==0) {
		LVon();
	} else if (strcmp(LVs,":false,\"changed\"")==0) {
		LVoff();
	} else if (strcmp(LVs,":true,\"changed\":")==0) {
		LVon();
	} else if (strcmp(LVs,"\":false,\"changed")==0) {
		LVoff();
	} else if (strcmp(LVs,"\":true,\"changed\"")==0) {
		LVon();
	} else if (strcmp(LVs,"w\":false,\"change")==0) {
		LVoff();
	} else if (strcmp(LVs,"w\":true,\"changed")==0) {
		LVon();
	} else if (strcmp(LVs,"ow\":false,\"chang")==0) {
		LVoff();
	} else if (strcmp(LVs,"ow\":true,\"change")==0) {
		LVon();
	} else if (strcmp(LVs,"now\":false,\"chan")==0) {
		LVoff();
	} else if (strcmp(LVs,"now\":true,\"chang")==0) {
		LVon();
	} else if (strcmp(LVs,"tnow\":false,\"cha")==0) {
		LVoff();
	} else if (strcmp(LVs,"tnow\":true,\"chan")==0) {
		LVon();
	} else if (strcmp(LVs,"rtnow\":false,\"ch")==0) {
		LVoff();
	} else if (strcmp(LVs,"rtnow\":true,\"cha")==0) {
		LVon();
	} else if (strcmp(LVs,"ertnow\":false,\"c")==0) {
		LVoff();
	} else if (strcmp(LVs,"ertnow\":true,\"ch")==0) {
		LVon();
	} else if (strcmp(LVs,"lertnow\":false,\"")==0) {
		LVoff();
	} else if (strcmp(LVs,"lertnow\":true,\"c")==0) {
		LVon();
	} else if (strcmp(LVs,"alertnow\":false,")==0) {
		LVoff();
	} else if (strcmp(LVs,"alertnow\":true,")==0) {
		LVon();
	} else if (strcmp(LVs,"\"alertnow\":false")==0) {
		LVoff();
	} else if (strcmp(LVs,"\"alertnow\":true,")==0) {
		LVon();
	}

	memset(LVs,0,sizeof(LVs));

	char MKs[17+1];
	strncpy(MKs,buffer+2048+108,17+1);
	MKs[17]='\0';

	char YC[5]; // year char
	char MC[3]; // month char
	char FD[3]; // day char
	YC[5]='\0';
	MC[3]='\0';
	FD[3]='\0';

	sprintf(YC,"%d%d%d%d",year);
	sprintf(MC,"%d%d",mon);
	sprintf(FD,"%d%d",day);

	//printf("%c%c%c%c\n",YC[0],YC[1],YC[2],YC[3]);

	char MK0T[50];

	sprintf(MK0T,"true,\"changed\":\"%c",YC[0]);

	if(strcmp(MKs,"{\"alertnow\":false")==0) {
		MKoff();
	} else if (strcmp(MKs,"{\"alertnow\":true,")==0) {
		MKon();
	} else if (strcmp(MKs,"\"alertnow\":false,")==0) {
		MKoff();
	} else if (strcmp(MKs,"\"alertnow\":true,\"")==0) {
		MKon();
	} else if (strcmp(MKs,"alertnow\":false,\"")==0) {
		MKoff();
	} else if (strcmp(MKs,"alertnow\":true,\"c")==0) {
		MKon();
	} else if (strcmp(MKs,"lertnow\":false,\"c")==0) {
		MKoff();
	} else if (strcmp(MKs,"lertnow\":true,\"ch")==0) {
		MKon();
	} else if (strcmp(MKs,"ertnow\":false,\"ch")==0) {
		MKoff();
	} else if (strcmp(MKs,"ertnow\":true,\"cha")==0) {
		MKon();
	} else if (strcmp(MKs,"rtnow\":false,\"cha")==0) {
		MKoff();
	} else if (strcmp(MKs,"rtnow\":true,\"chan")==0) {
		MKon();
	} else if (strcmp(MKs,"tnow\":false,\"chan")==0) {
		MKoff();
	} else if (strcmp(MKs,"tnow\":true,\"chang")==0) {
		MKon();
	} else if (strcmp(MKs,"now\":false,\"chang")==0) {
		MKoff();
	} else if (strcmp(MKs,"now\":true,\"change")==0) {
		MKon();
	} else if (strcmp(MKs,"ow\":false,\"change")==0) {
		MKoff();
	} else if (strcmp(MKs,"ow\":true,\"changed")==0) {
		MKon();
	} else if (strcmp(MKs,"w\":false,\"changed")==0) {
		MKoff();
	} else if (strcmp(MKs,"w\":true,\"changed\"")==0) {
		MKon();
	} else if (strcmp(MKs,"\":false,\"changed\"")==0) {
		MKoff();
	} else if (strcmp(MKs,"\":true,\"changed\":")==0) {
		MKon();
	} else if (strcmp(MKs,":false,\"changed\":")==0) {
		MKoff();
	} else if (strcmp(MKs,":true,\"changed\":\"")==0) {
		MKon();
	} else if (strcmp(MKs,"false,\"changed\":\"")==0) {
		MKoff();
	} else if (strcmp(MKs,MK0T)==0) {
		MKon();
	}

	memset(MK0T,0,sizeof(MK0T));
	memset(MKs,0,sizeof(MKs));

	char ODs[18+1];
	strncpy(ODs,buffer+2048+246,18+1);
	ODs[18]='\0';

	char OD0F[50];
	char OD1T[50];
	char OD2T[50];
	sprintf(OD0F,"false,\"changed\":\"%c",YC[0]);
	sprintf(OD1T,"true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(OD2T,":true,\"changed\":\"%c",YC[0]);

	if(strcmp(ODs,OD0F)==0) {
		ODoff();
	} else if (strcmp(ODs,OD1T)==0) {
		ODon();
	} else if (strcmp(ODs,":false,\"changed\":\"")==0) {
		ODoff();
	} else if (strcmp(ODs,OD2T)==0) {
		ODon();
	} else if (strcmp(ODs,"\":false,\"changed\":")==0) {
		ODoff();
	} else if (strcmp(ODs,"\":true,\"changed\":\"")==0) {
		ODon();
	} else if (strcmp(ODs,"w\":false,\"changed\"")==0) {
		ODoff();
	} else if (strcmp(ODs,"w\":true,\"changed\":")==0) {
		ODon();
	} else if (strcmp(ODs,"ow\":false,\"changed")==0) {
		ODoff();
	} else if (strcmp(ODs,"ow\":true,\"changed\"")==0) {
		ODon();
	} else if (strcmp(ODs,"now\":false,\"change")==0) {
		ODoff();
	} else if (strcmp(ODs,"now\":true,\"changed")==0) {
		ODon();
	} else if (strcmp(ODs,"tnow\":false,\"chang")==0) {
		ODoff();
	} else if (strcmp(ODs,"tnow\":true,\"change")==0) {
		ODon();
	} else if (strcmp(ODs,"rtnow\":false,\"chan")==0) {
		ODoff();
	} else if (strcmp(ODs,"rtnow\":true,\"chang")==0) {
		ODon();
	} else if (strcmp(ODs,"ertnow\":false,\"cha")==0) {
		ODoff();
	} else if (strcmp(ODs,"ertnow\":true,\"chan")==0) {
		ODon();
	} else if (strcmp(ODs,"lertnow\":false,\"ch")==0) {
		ODoff();
	} else if (strcmp(ODs,"lertnow\":true,\"cha")==0) {
		ODon();
	} else if (strcmp(ODs,"alertnow\":false,\"c")==0) {
		ODoff();
	} else if (strcmp(ODs,"alertnow\":true,\"ch")==0) {
		ODon();
	} else if (strcmp(ODs,"\"alertnow\":false,\"")==0) {
		ODoff();
	} else if (strcmp(ODs,"\"alertnow\":true,\"c")==0) {
		ODon();
	} else if (strcmp(ODs,"{\"alertnow\":false,")==0) {
		ODoff();
	} else if (strcmp(ODs,"{\"alertnow\":true,\"")==0) {
		ODon();
	} else if (strcmp(ODs,":{\"alertnow\":false")==0) {
		ODoff();
	} else if (strcmp(ODs,":{\"alertnow\":true,")==0) {
		ODon();
	}

	memset(ODs,0,sizeof(ODs));

	memset(OD0F,0,sizeof(OD0F));
	memset(OD1T,0,sizeof(OD1T));
	memset(OD2T,0,sizeof(OD2T));

	char POs[19+1];
	strncpy(POs,buffer+2048+402,19+1);
	POs[19]='\0';

	char PO0T[50];
	char PO1F[50];
	char PO2T[50];
	char PO3F[50];
	char PO4T[50];
	sprintf(PO0T,"\":true,\"changed\":\"%c",YC[0]);
	sprintf(PO1F,":false,\"changed\":\"%c",YC[0]);
	sprintf(PO2T,":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(PO3F,"false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(PO4T,"true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);

	if(strcmp(POs,"\":{\"alertnow\":false")==0) {
		POoff();
	} else if (strcmp(POs,"\":{\"alertnow\":true,")==0) {
		POon();
	} else if (strcmp(POs,":{\"alertnow\":false,")==0) {
		POoff();
	} else if (strcmp(POs,":{\"alertnow\":true,\"")==0) {
		POon();
	} else if (strcmp(POs,"{\"alertnow\":false,\"")==0) {
		POoff();
	} else if (strcmp(POs,"{\"alertnow\":true,\"c")==0) {
		POon();
	} else if (strcmp(POs,"\"alertnow\":false,\"c")==0) {
		POoff();
	} else if (strcmp(POs,"\"alertnow\":true,\"ch'")==0) {
		POon();
	} else if (strcmp(POs,"alertnow\":false,\"ch")==0) {
		POoff();
	} else if (strcmp(POs,"alertnow\":true,\"cha")==0) {
		POon();
	} else if (strcmp(POs,"lertnow\":false,\"cha")==0) {
		POoff();
	} else if (strcmp(POs,"lertnow\":true,\"chan")==0) {
		POon();
	} else if (strcmp(POs,"ertnow\":false,\"chan")==0) {
		POoff();
	} else if (strcmp(POs,"ertnow\":true,\"chang")==0) {
		POon();
	} else if (strcmp(POs,"rtnow\":false,\"chang")==0) {
		POoff();
	} else if (strcmp(POs,"rtnow\":true,\"change")==0) {
		POon();
	} else if (strcmp(POs,"tnow\":false,\"change")==0) {
		POoff();
	} else if (strcmp(POs,"tnow\":true,\"changed")==0) {
		POon();
	} else if (strcmp(POs,"now\":false,\"changed")==0) {
		POoff();
	} else if (strcmp(POs,"now\":true,\"changed\"")==0) {
		POon();
	} else if (strcmp(POs,"ow\":false,\"changed\"")==0) {
		POoff();
	} else if (strcmp(POs,"ow\":true,\"changed\":")==0) {
		POon();
	} else if (strcmp(POs,"w\":false,\"changed\":")==0) {
		POoff();
	} else if (strcmp(POs,"w\":true,\"changed\":\"")==0) {
		POon();
	} else if (strcmp(POs,"\":false,\"changed\":\"")==0) {
		POoff();
	} else if (strcmp(POs,PO0T)==0) {
		POon();
	} else if (strcmp(POs,PO1F)==0) {
		POoff();
	} else if (strcmp(POs,PO2T)==0) {
		POon();
	} else if (strcmp(POs,PO3F)==0) {
		POoff();
	} else if (strcmp(POs,PO4T)==0) {
		POon();
	}

	memset(POs,0,sizeof(POs));

	memset(PO0T,0,sizeof(PO0T));
	memset(PO1F,0,sizeof(PO1F));
	memset(PO2T,0,sizeof(PO2T));
	memset(PO3F,0,sizeof(PO3F));
	memset(PO4T,0,sizeof(PO4T));

	char RIs[20+1];
	strncpy(RIs,buffer+2048+558,20+1);
	RIs[20]='\0';

	char RI0F[50];
	char RI1T[50];
	char RI2F[50];
	char RI3T[50];
	char RI4F[50];
	char RI5T[50];
	char RI6T[50];
	sprintf(RI0F,"false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(RI1T,"true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(RI2F,":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(RI3T,":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(RI4F,"\":false,\"changed\":\"%c",YC[0]);
	sprintf(RI5T,"\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(RI6T,"w\":true,\"changed\":\"%c",YC[0]);

	if(strcmp(RIs,RI0F)==0) {
		RIoff();
	} else if (strcmp(RIs,RI1T)==0) {
		RIon();
	} else if (strcmp(RIs,RI2F)==0) {
		RIoff();
	} else if (strcmp(RIs,RI3T)==0) {
		RIon();
	} else if (strcmp(RIs,RI4F)==0) {
		RIoff();
	} else if (strcmp(RIs,RI5T)==0) {
		RIon();
	} else if (strcmp(RIs,"w\":false,\"changed\":\"")==0) {
		RIoff();
	} else if (strcmp(RIs,RI6T)==0) {
		RIon();
	} else if (strcmp(RIs,"ow\":false,\"changed\":")==0) {
		RIoff();
	} else if (strcmp(RIs,"ow\":true,\"changed\":\"")==0) {
		RIon();
	} else if (strcmp(RIs,"now\":false,\"changed\"")==0) {
		RIoff();
	} else if (strcmp(RIs,"now\":true,\"changed\":")==0) {
		RIon();
	} else if (strcmp(RIs,"tnow\":false,\"changed")==0) {
		RIoff();
	} else if (strcmp(RIs,"tnow\":true,\"changed\"")==0) {
		RIon();
	} else if (strcmp(RIs,"rtnow\":false,\"change")==0) {
		RIoff();
	} else if (strcmp(RIs,"rtnow\":true,\"changed")==0) {
		RIon();
	} else if (strcmp(RIs,"ertnow\":false,\"chang")==0) {
		RIoff();
	} else if (strcmp(RIs,"ertnow\":true,\"change")==0) {
		RIon();
	} else if (strcmp(RIs,"lertnow\":false,\"chan")==0) {
		RIoff();
	} else if (strcmp(RIs,"lertnow\":true,\"chang")==0) {
		RIon();
	} else if (strcmp(RIs,"alertnow\":false,\"cha")==0) {
		RIoff();
	} else if (strcmp(RIs,"alertnow\":true,\"chan")==0) {
		RIon();
	} else if (strcmp(RIs,"\"alertnow\":false,\"ch")==0) {
		RIoff();
	} else if (strcmp(RIs,"\"alertnow\":true,\"cha")==0) {
		RIon();
	} else if (strcmp(RIs,"{\"alertnow\":false,\"c")==0) {
		RIoff();
	} else if (strcmp(RIs,"{\"alertnow\":true,\"ch")==0) {
		RIon();
	} else if (strcmp(RIs,":{\"alertnow\":false,\"")==0) {
		RIoff();
	} else if (strcmp(RIs,":{\"alertnow\":true,\"c")==0) {
		RIon();
	} else if (strcmp(RIs,"\":{\"alertnow\":false,")==0) {
		RIoff();
	} else if (strcmp(RIs,"\":{\"alertnow\":true,\"")==0) {
		RIon();
	} else if (strcmp(RIs,"c\":{\"alertnow\":false")==0) {
		RIoff();
	} else if (strcmp(RIs,"c\":{\"alertnow\":true,")==0) {
		RIon();
	}

	memset(RIs,0,sizeof(RIs));

	memset(RI0F,0,sizeof(RI0F));
	memset(RI1T,0,sizeof(RI1T));
	memset(RI2F,0,sizeof(RI2F));
	memset(RI3T,0,sizeof(RI3T));
	memset(RI4F,0,sizeof(RI4F));
	memset(RI5T,0,sizeof(RI5T));
	memset(RI6T,0,sizeof(RI6T));

	char SUs[21+1];
	strncpy(SUs,buffer+2048+696,21+1);
	SUs[21]='\0';

	char SU0T[50];
	char SU1F[50];
	char SU2T[50];
	char SU3F[50];
	char SU4T[50];
	char SU5F[50];
	char SU6T[50];
	char SU7F[50];
	char SU8T[50];
	sprintf(SU0T,"ow\":true,\"changed\":\"%c",YC[0]);
	sprintf(SU1F,"w\":false,\"changed\":\"%c",YC[0]);
	sprintf(SU2T,"w\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(SU3F,"\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(SU4T,"\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(SU5F,"\"false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(SU6T,"\"true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(SU7F,"false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(SU8T,"true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);

	if(strcmp(SUs,"4c\":{\"alertnow\":false")==0) {
		SUoff();
	} else if (strcmp(SUs,"4c\":{\"alertnow\":true,")==0) {
		SUon();
	} else if (strcmp(SUs,"c\":{\"alertnow\":false,")==0) {
		SUoff();
	} else if (strcmp(SUs,"c\":{\"alertnow\":true,\"")==0) {
		SUon();
	} else if (strcmp(SUs,"\":{\"alertnow\":false,\"")==0) {
		SUoff();
	} else if (strcmp(SUs,"\":{\"alertnow\":true,\"c")==0) {
		SUon();
	} else if (strcmp(SUs,":{\"alertnow\":false,\"c")==0) {
		SUoff();
	} else if (strcmp(SUs,":{\"alertnow\":true,\"ch")==0) {
		SUon();
	} else if (strcmp(SUs,"{\"alertnow\":false,\"ch")==0) {
		SUoff();
	} else if (strcmp(SUs,"{\"alertnow\":true,\"cha")==0) {
		SUon();
	} else if (strcmp(SUs,"\"alertnow\":false,\"cha")==0) {
		SUoff();
	} else if (strcmp(SUs,"\"alertnow\":true,\"chan")==0) {
		SUon();
	} else if (strcmp(SUs,"alertnow\":false,\"chan")==0) {
		SUoff();
	} else if (strcmp(SUs,"alertnow\":true,\"chang")==0) {
		SUon();
	} else if (strcmp(SUs,"lertnow\":false,\"chang")==0) {
		SUoff();
	} else if (strcmp(SUs,"lertnow\":true,\"change")==0) {
		SUon();
	} else if (strcmp(SUs,"ertnow\":false,\"change")==0) {
		SUoff();
	} else if (strcmp(SUs,"ertnow\":true,\"changed")==0) {
		SUon();
	} else if (strcmp(SUs,"rtnow\":false,\"changed")==0) {
		SUoff();
	} else if (strcmp(SUs,"rtnow\":true,\"changed\"")==0) {
		SUon();
	} else if (strcmp(SUs,"tnow\":false,\"changed\"")==0) {
		SUoff();
	} else if (strcmp(SUs,"tnow\":true,\"changed\":")==0) {
		SUon();
	} else if (strcmp(SUs,"now\":false,\"changed\":")==0) {
		SUoff();
	} else if (strcmp(SUs,"now\":true,\"changed\":\"")==0) {
		SUon();
	} else if (strcmp(SUs,"ow\":false,\"changed\":\"")==0) {
		SUoff();
	} else if (strcmp(SUs,SU0T)==0) {
		SUon();
	} else if (strcmp(SUs,SU1F)==0) {
		SUoff();
	} else if (strcmp(SUs,SU2T)==0) {
		SUon();
	} else if (strcmp(SUs,SU3F)==0) {
		SUoff();
	} else if (strcmp(SUs,SU4T)==0) {
		SUon();
	} else if (strcmp(SUs,SU5F)==0) {
		SUoff();
	} else if (strcmp(SUs,SU6T)==0) {
		SUon();
	} else if (strcmp(SUs,SU7F)==0) {
		SUoff();
	} else if (strcmp(SUs,SU8T)==0) {
		SUon();
	}

	memset(SUs,0,sizeof(SUs));

	memset(SU0T,0,sizeof(SU0T));
	memset(SU1F,0,sizeof(SU1F));
	memset(SU2T,0,sizeof(SU2T));
	memset(SU3F,0,sizeof(SU3F));
	memset(SU4T,0,sizeof(SU4T));
	memset(SU5F,0,sizeof(SU5F));
	memset(SU6T,0,sizeof(SU6T));
	memset(SU7F,0,sizeof(SU7F));
	memset(SU8T,0,sizeof(SU8T));

	char TRs[22+1];
	strncpy(TRs,buffer+2048+870,22+1);
	TRs[22]='\0';

	char TR0F[50];
	char TR1T[50];
	char TR2T[50];
	char TR3F[50];
	char TR4T[50];
	char TR5F[50];
	char TR6T[50];
	char TR7F[50];
	char TR8T[50];
	char TR9F[50];
	char TRAT[50];
	char TRBT[50];
	sprintf(TR0F,"false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(TR1T,"true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(TR2T,"w\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(TR3F,":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(TR4T,":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(TR5F,"\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(TR6T,"\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(TR7F,"w\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(TR8T,"w\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(TR9F,"ow\":false,\"changed\":\"%c",YC[0]);
	sprintf(TRAT,"ow\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(TRBT,"now\":true,\"changed\":\"%c",YC[0]);

	if(strcmp(TRs,TR0F)==0) {
		TRoff();
	} else if (strcmp(TRs,TR1T)==0) {
		TRon();
	} else if (strcmp(TRs,TR2T)==0) {
		TRon();
	} else if (strcmp(TRs,TR3F)==0) {
		TRoff();
	} else if (strcmp(TRs,TR4T)==0) {
		TRon();
	} else if (strcmp(TRs,TR5F)==0) {
		TRoff();
	} else if (strcmp(TRs,TR6T)==0) {
		TRon();
	} else if (strcmp(TRs,TR7F)==0) {
		TRoff();
	} else if (strcmp(TRs,TR8T)==0) {
		TRon();
	} else if (strcmp(TRs,TR9F)==0) {
		TRoff();
	} else if (strcmp(TRs,TRAT)==0) {
		TRon();
	} else if (strcmp(TRs,"now\":false,\"changed\":\"")==0) {
		TRoff();
	} else if (strcmp(TRs,TRBT)==0) {
		TRon();
	} else if (strcmp(TRs,"tnow\":false,\"changed\":")==0) {
		TRoff();
	} else if (strcmp(TRs,"tnow\":true,\"changed\":\"")==0) {
		TRon();
	} else if (strcmp(TRs,"rtnow\":false,\"changed\"")==0) {
		TRoff();
	} else if (strcmp(TRs,"rtnow\":true,\"changed\":")==0) {
		TRon();
	} else if (strcmp(TRs,"ertnow\":false,\"changed")==0) {
		TRoff();
	} else if (strcmp(TRs,"ertnow\":true,\"changed\"")==0) {
		TRon();
	} else if (strcmp(TRs,"lertnow\":false,\"change")==0) {
		TRoff();
	} else if (strcmp(TRs,"lertnow\":true,\"changed")==0) {
		TRon();
	} else if (strcmp(TRs,"alertnow\":false,\"chang")==0) {
		TRoff();
	} else if (strcmp(TRs,"alertnow\":true,\"change")==0) {
		TRon();
	} else if (strcmp(TRs,"\"alertnow\":false,\"chan")==0) {
		TRoff();
	} else if (strcmp(TRs,"\"alertnow\":true,\"chang")==0) {
		TRon();
	} else if (strcmp(TRs,"{\"alertnow\":false,\"cha")==0) {
		TRoff();
	} else if (strcmp(TRs,"{\"alertnow\":true,\"chan")==0) {
		TRon();
	} else if (strcmp(TRs,":{\"alertnow\":false,\"ch")==0) {
		TRoff();
	} else if (strcmp(TRs,":{\"alertnow\":true,\"cha")==0) {
		TRon();
	} else if (strcmp(TRs,"\":{\"alertnow\":false,\"c")==0) {
		TRoff();
	} else if (strcmp(TRs,"\":{\"alertnow\":true,\"ch")==0) {
		TRon();
	} else if (strcmp(TRs,"c\":{\"alertnow\":false,\"")==0) {
		TRoff();
	} else if (strcmp(TRs,"c\":{\"alertnow\":true,\"c")==0) {
		TRon();
	} else if (strcmp(TRs,"4c\":{\"alertnow\":false,")==0) {
		TRoff();
	} else if (strcmp(TRs,"4c\":{\"alertnow\":true,\"")==0) {
		TRon();
	} else if (strcmp(TRs,"44c\":{\"alertnow\":false")==0) {
		TRoff();
	} else if (strcmp(TRs,"44c\":{\"alertnow\":true,")==0) {
		TRon();
	}

	memset(TRs,0,sizeof(TRs));

	memset(TR0F,0,sizeof(TR0F));
	memset(TR1T,0,sizeof(TR1T));
	memset(TR2T,0,sizeof(TR2T));
	memset(TR3F,0,sizeof(TR3F));
	memset(TR4T,0,sizeof(TR4T));
	memset(TR5F,0,sizeof(TR5F));
	memset(TR6T,0,sizeof(TR6T));
	memset(TR7F,0,sizeof(TR7F));
	memset(TR8T,0,sizeof(TR8T));
	memset(TR9F,0,sizeof(TR8T));
	memset(TRAT,0,sizeof(TRAT));
	memset(TRBT,0,sizeof(TRBT));

	char KAs[23+1];
	strncpy(KAs,buffer+3072+2,23+1);
	KAs[23]='\0';

	char KA0T[30];
	char KA1F[30];
	char KA2T[30];
	char KA3F[30];
	char KA4T[30];
	char KA5F[30];
	char KA6T[30];
	char KA7F[30];
	char KA8T[30];
	char KA9F[30];
	char KAAT[30];
	char KABF[30];
	char KACT[30];

	sprintf(KA0T,"tnow\":true,\"changed\":\"%c",YC[0]);
	KA0T[23]='\0';
	sprintf(KA1F,"now\":false,\"changed\":\"%c",YC[0]);
	sprintf(KA2T,"now\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(KA3F,"ow\":false,\"changed\":%c%c",YC[0],YC[1]);
	sprintf(KA4T,"ow\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KA5F,"w\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KA6T,"w\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KA7F,"\":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KA8T,"\":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KA9F,":false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KAAT,":true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KABF,"false,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KACT,"true,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);

	if (strcmp(KAs,KA0T)==0) {
		KAon();
	} else if (strcmp(KAs,KA1F)==0) {
		KAoff();
	} else if (strcmp(KAs,KA2T)==0) {
		KAon();
	} else if (strcmp(KAs,KA3F)==0) {
		KAoff();
	} else if (strcmp(KAs,KA4T)==0) {
		KAon();
	} else if (strcmp(KAs,KA5F)==0) {
		KAoff();
	} else if (strcmp(KAs,KA6T)==0) {
		KAon();
	} else if (strcmp(KAs,KA7F)==0) {
		KAoff();
	} else if (strcmp(KAs,KA8T)==0) {
		KAon();
	} else if (strcmp(KAs,KA9F)==0) {
		KAoff();
	} else if (strcmp(KAs,KAAT)==0) {
		KAoff();
	} else if (strcmp(KAs,KABF)==0) {
		KAoff();
	} else if (strcmp(KAs,KACT)==0) {
		KAon();
	} else if (strcmp(KAs,"044c\":{\"alertnow\":false")==0) {
		KAoff();
	} else if (strcmp(KAs,"044c\":{\"alertnow\":true,")==0) {
		KAon();
	} else if (strcmp(KAs,"44c\":{\"alertnow\":false,")==0) {
		KAoff();
	} else if (strcmp(KAs,"44c\":{\"alertnow\":true,\"")==0) {
		KAon();
	} else if (strcmp(KAs,"4c\":{\"alertnow\":false,\"")==0) {
		KAoff();
	} else if (strcmp(KAs,"4c\":{\"alertnow\":true,\"c")==0) {
		KAon();
	} else if (strcmp(KAs,"c\":{\"alertnow\":false,\"c")==0) {
		KAoff();
	} else if (strcmp(KAs,"c\":{\"alertnow\":true,\"ch")==0) {
		KAon();
	} else if (strcmp(KAs,"\":{\"alertnow\":false,\"ch")==0) {
		KAoff();
	} else if (strcmp(KAs,"\":{\"alertnow\":true,\"cha")==0) {
		KAon();
	} else if (strcmp(KAs,":{\"alertnow\":false,\"cha")==0) {
		KAoff();
	} else if (strcmp(KAs,":{\"alertnow\":true,\"chan")==0) {
		KAon();
	} else if (strcmp(KAs,"{\"alertnow\":false,\"chan")==0) {
		KAoff();
	} else if (strcmp(KAs,"{\"alertnow\":true,\"chang")==0) {
		KAon();
	} else if (strcmp(KAs,"\"alertnow\":false,\"chang")==0) {
		KAoff();
	} else if (strcmp(KAs,"\"alertnow\":true,\"change")==0) {
		KAon();
	} else if (strcmp(KAs,"alertnow\":false,\"change")==0) {
		KAoff();
	} else if (strcmp(KAs,"alertnow\":true,\"changed")==0) {
		KAon();
	} else if (strcmp(KAs,"lertnow\":false,\"changed")==0) {
		KAoff();
	} else if (strcmp(KAs,"lertnow\":true,\"changed\"")==0) {
		KAon();
	} else if (strcmp(KAs,"ertnow\":false,\"changed\"")==0) {
		KAoff();
	} else if (strcmp(KAs,"ertnow\":true,\"changed\":")==0) {
		KAon();
	} else if (strcmp(KAs,"rtnow\":false,\"changed\":")==0) {
		KAoff();
	} else if (strcmp(KAs,"rtnow\":true,\"changed\":\"")==0) {
		KAon();
	} else if (strcmp(KAs,"tnow\":false,\"changed\":\"")==0) {
		KAoff();
	}

	memset(KAs,0,sizeof(KAs));

	memset(KA0T,0,sizeof(KA0T));
	memset(KA1F,0,sizeof(KA1F));
	memset(KA2T,0,sizeof(KA2T));
	memset(KA3F,0,sizeof(KA3F));
	memset(KA4T,0,sizeof(KA4T));
	memset(KA5F,0,sizeof(KA5F));
	memset(KA6T,0,sizeof(KA6T));
	memset(KA7F,0,sizeof(KA7F));
	memset(KA8T,0,sizeof(KA8T));
	memset(KA9F,0,sizeof(KA9F));
	memset(KAAT,0,sizeof(KAAT));
	memset(KABF,0,sizeof(KABF));
	memset(KACT,0,sizeof(KACT));

	char KEs[24];
	strncpy(KEs,buffer+3072+158,24);
	//KEs[24]='\0';

	char KE0F[50];
	char KE1T[50];
	char KE2F[50];
	char KE3T[50];
	char KE4F[50];
	char KE5T[50];
	char KE6F[50];
	char KE7T[50];
	char KE8F[50];
	char KE9T[50];
	char KEAF[50];
	char KEBT[50];
	char KECF[50];
	char KEDT[50];
	char KEET[50];

	sprintf(KE0F,"false,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KE1T,"true,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KE2F,":false,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KE3T,":true,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KE4F,"\":false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KE5T,"\":true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KE6F,"w\":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KE7T,"w\":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KE8F,"ow\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KE9T,"ow\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KEAF,"now\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(KEBT,"now\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KECF,"tnow\":false,\"changed\":\"%c",YC[0]);
	sprintf(KEDT,"tnow\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(KEET,"rtnow\":true,\"changed\":\"%c",YC[0]);

	if(strcmp(KEs,KE0F)==0) {
		KEoff();
	} else if (strcmp(KEs,KE1T)==0) {
		KEon();
	} else if (strcmp(KEs,KE2F)==0) {
		KEoff();
	} else if (strcmp(KEs,KE3T)==0) {
		KEon();
	} else if (strcmp(KEs,KE4F)==0) {
		KEoff();
	} else if (strcmp(KEs,KE5T)==0) {
		KEon();
	} else if (strcmp(KEs,KE6F)==0) {
		KEoff();
	} else if (strcmp(KEs,KE7T)==0) {
		KEon();
	} else if (strcmp(KEs,KE8F)==0) {
		KEoff();
	} else if (strcmp(KEs,KE9T)==0) {
		KEon();
	} else if (strcmp(KEs,KEAF)==0) {
		KEoff();
	} else if (strcmp(KEs,KEBT)==0) {
		KEon();
	} else if (strcmp(KEs,KECF)==0) {
		KEoff();
	} else if (strcmp(KEs,KEDT)==0) {
		KEon();
	} else if (strcmp(KEs,"rtnow\":false,\"changed\":\"")==0) {
		KEoff();
	} else if (strcmp(KEs,KEET)==0) {
		KEon();
	} else if (strcmp(KEs,"ertnow\":false,\"changed\":")==0) {
		KEoff();
	} else if (strcmp(KEs,"ertnow\":true,\"changed\":\"")==0) {
		KEon();
	} else if (strcmp(KEs,"lertnow\":false,\"changed\"")==0) {
		KEoff();
	} else if (strcmp(KEs,"lertnow\":true,\"changed\":")==0) {
		KEon();
	} else if (strcmp(KEs,"alertnow\":false,\"changed")==0) {
		KEoff();
	} else if (strcmp(KEs,"alertnow\":true,\"changed\"")==0) {
		KEon();
	} else if (strcmp(KEs,"\"alertnow\":false,\"change")==0) {
		KEoff();
	} else if (strcmp(KEs,"\"alertnow\":true,\"changed")==0) {
		KEon();
	} else if (strcmp(KEs,"{\"alertnow\":false,\"chang")==0) {
		KEoff();
	} else if (strcmp(KEs,"{\"alertnow\":true,\"change")==0) {
		KEon();
	} else if (strcmp(KEs,":{\"alertnow\":false,\"chan")==0) {
		KEoff();
	} else if (strcmp(KEs,":{\"alertnow\":true,\"chang")==0) {
		KEon();
	} else if (strcmp(KEs,"\":{\"alertnow\":false,\"cha")==0) {
		KEoff();
	} else if (strcmp(KEs,"\":{\"alertnow\":true,\"chan")==0) {
		KEon();
	} else if (strcmp(KEs,"c\":{\"alertnow\":false,\"ch")==0) {
		KEoff();
	} else if (strcmp(KEs,"c\":{\"alertnow\":true,\"cha")==0) {
		KEon();
	} else if (strcmp(KEs,"4c\":{\"alertnow\":false,\"c")==0) {
		KEoff();
	} else if (strcmp(KEs,"4c\":{\"alertnow\":true,\"ch")==0) {
		KEon();
	} else if (strcmp(KEs,"44c\":{\"alertnow\":false,\"")==0) {
		KEoff();
	} else if (strcmp(KEs,"44c\":{\"alertnow\":true,\"c")==0) {
		KEon();
	} else if (strcmp(KEs,"044c\":{\"alertnow\":false,")==0) {
		KEoff();
	} else if (strcmp(KEs,"044c\":{\"alertnow\":true,\"")==0) {
		KEon();
	} else if (strcmp(KEs,"u044c\":{\"alertnow\":false")==0) {
		KEoff();
	} else if (strcmp(KEs,"u044c\":{\"alertnow\":true,")==0) {
		KEon();
	}

	//printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",KEs[0],KEs[1],KEs[2],KEs[3],KEs[4],KEs[5],KEs[6],KEs[7],KEs[8],KEs[9],KEs[10],KEs[11],KEs[12],KEs[13],KEs[14],KEs[15],KEs[16],KEs[17],KEs[18],KEs[19],KEs[20],KEs[21],KEs[22],KEs[23],KEs[24]);
	//printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",KEET[0],KEET[1],KEET[2],KEET[3],KEET[4],KEET[5],KEET[6],KEET[7],KEET[8],KEET[9],KEET[10],KEET[11],KEET[12],KEET[13],KEET[14],KEET[15],KEET[16],KEET[17],KEET[18],KEET[19],KEET[20],KEET[21],KEET[22],KEET[23],KEET[24]);

	memset(KEs,0,sizeof(KEs));

	memset(KE0F,0,sizeof(KE0F));
	memset(KE1T,0,sizeof(KE1T));
	memset(KE2F,0,sizeof(KE2F));
	memset(KE3T,0,sizeof(KE3T));
	memset(KE4F,0,sizeof(KE4F));
	memset(KE5T,0,sizeof(KE5T));
	memset(KE6F,0,sizeof(KE6F));
	memset(KE7T,0,sizeof(KE7T));
	memset(KE8F,0,sizeof(KE8F));
	memset(KE9T,0,sizeof(KE9T));
	memset(KEAF,0,sizeof(KEAF));
	memset(KEBT,0,sizeof(KEBT));
	memset(KECF,0,sizeof(KECF));
	memset(KEDT,0,sizeof(KEDT));
	memset(KEET,0,sizeof(KEET));

	char KHs[25+1];
	strncpy(KHs,buffer+3072+320,25+1);
	KHs[25]='\0';

	char KH0T[50];
	char KH1F[50];
	char KH2T[50];
	char KH3F[50];
	char KH4T[50];
	char KH5F[50];
	char KH6T[50];
	char KH7F[50];
	char KH8T[50];
	char KH9F[50];
	char KHAT[50];
	char KHBF[50];
	char KHCT[50];
	char KHDF[50];
	char KHET[50];
	char KHFF[50];
	char KHGT[50];
	sprintf(KH0T,"ertnow\":true,\"changed\":\"%c",YC[0]);
	sprintf(KH1F,"rtnow\":false,\"changed\":\"%c",YC[0]);
	sprintf(KH2T,"rtnow\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(KH3F,"tnow\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(KH4T,"tnow\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KH5F,"now\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KH6T,"now\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KH7F,"ow\":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KH8T,"ow\":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KH9F,"w\":false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KHAT,"w\":true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KHBF,"\":false,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KHCT,"\":true,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KHDF,":false,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KHET,":true,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KHFF,"false,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KHGT,"true,\"changed\":\"%c%c%c%c-%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1],FD[0]);

	if(strcmp(KHs,"\u044c\":{\"alertnow\":false\'")==0) {
		KHoff();
	} else if (strcmp(KHs,"\u044c\":{\"alertnow\":true,")==0) {
		KHon();
	} else if (strcmp(KHs,"u044c\":{\"alertnow\":false,")==0) {
		KHoff();
	} else if (strcmp(KHs,"u044c\":{\"alertnow\":true,\"")==0) {
		KHon();
	} else if (strcmp(KHs,"044c\":{\"alertnow\":false,\"")==0) {
		KHoff();
	} else if (strcmp(KHs,"044c\":{\"alertnow\":true,\"c")==0) {
		KHon();
	} else if (strcmp(KHs,"44c\":{\"alertnow\":false,\"c")==0) {
		KHoff();
	} else if (strcmp(KHs,"44c\":{\"alertnow\":true,\"ch")==0) {
		KHon();
	} else if (strcmp(KHs,"4c\":{\"alertnow\":false,\"ch")==0) {
		KHoff();
	} else if (strcmp(KHs,"4c\":{\"alertnow\":true,\"cha")==0) {
		KHon();
	} else if (strcmp(KHs,"c\":{\"alertnow\":false,\"cha")==0) {
		KHoff();
	} else if (strcmp(KHs,"c\":{\"alertnow\":true,\"chan")==0) {
		KHon();
	} else if (strcmp(KHs,"\":{\"alertnow\":false,\"chan")==0) {
		KHoff();
	} else if (strcmp(KHs,"\":{\"alertnow\":true,\"chang")==0) {
		KHon();
	} else if (strcmp(KHs,":{\"alertnow\":false,\"chang")==0) {
		KHoff();
	} else if (strcmp(KHs,":{\"alertnow\":true,\"change")==0) {
		KHon();
	} else if (strcmp(KHs,"{\"alertnow\":false,\"change")==0) {
		KHoff();
	} else if (strcmp(KHs,"{\"alertnow\":true,\"changed")==0) {
		KHon();
	} else if (strcmp(KHs,"\"alertnow\":false,\"changed")==0) {
		KHoff();
	} else if (strcmp(KHs,"\"alertnow\":true,\"changed\"")==0) {
		KHon();
	} else if (strcmp(KHs,"alertnow\":false,\"changed\"")==0) {
		KHoff();
	} else if (strcmp(KHs,"alertnow\":true,\"changed\":")==0) {
		KHon();
	} else if (strcmp(KHs,"lertnow\":false,\"changed\":")==0) {
		KHoff();
	} else if (strcmp(KHs,"lertnow\":true,\"changed\":\"")==0) {
		KHon();
	} else if (strcmp(KHs,"ertnow\":false,\"changed\":\"")==0) {
		KHoff();
	} else if (strcmp(KHs,KH0T)==0) {
		KHon();
	} else if (strcmp(KHs,KH1F)==0) {
		KHoff();
	} else if (strcmp(KHs,KH2T)==0) {
		KHon();
	} else if (strcmp(KHs,KH3F)==0) {
		KHoff();
	} else if (strcmp(KHs,KH4T)==0) {
		KHon();
	} else if (strcmp(KHs,KH5F)==0) {
		KHoff();
	} else if (strcmp(KHs,KH6T)==0) {
		KHon();
	} else if (strcmp(KHs,KH7F)==0) {
		KHoff();
	} else if (strcmp(KHs,KH8T)==0) {
		KHon();
	} else if (strcmp(KHs,KH9F)==0) {
		KHoff();
	} else if (strcmp(KHs,KHAT)==0) {
		KHon();
	} else if (strcmp(KHs,KHBF)==0) {
		KHoff();
	} else if (strcmp(KHs,KHCT)==0) {
		KHon();
	} else if (strcmp(KHs,KHDF)==0) {
		KHoff();
	} else if (strcmp(KHs,KHET)==0) {
		KHon();
	} else if (strcmp(KHs,KHFF)==0) {
		KHoff();
	} else if (strcmp(KHs,KHGT)==0) {
		KHon();
	}

	memset(KHs,0,sizeof(KHs));

	memset(KH0T,0,sizeof(KH0T));
	memset(KH1F,0,sizeof(KH1F));
	memset(KH2T,0,sizeof(KH2T));
	memset(KH3F,0,sizeof(KH3F));
	memset(KH4T,0,sizeof(KH4T));
	memset(KH5F,0,sizeof(KH5F));
	memset(KH6T,0,sizeof(KH6T));
	memset(KH7F,0,sizeof(KH7F));
	memset(KH8T,0,sizeof(KH8T));
	memset(KH9F,0,sizeof(KH9F));
	memset(KHAT,0,sizeof(KHAT));
	memset(KHBF,0,sizeof(KHBF));
	memset(KHCT,0,sizeof(KHCT));
	memset(KHDF,0,sizeof(KHDF));
	memset(KHET,0,sizeof(KHET));
	memset(KHFF,0,sizeof(KHFF));
	memset(KHGT,0,sizeof(KHGT));

	char CEs[25+1];
	strncpy(CEs,buffer+3072+632,25+1);
	CEs[25]='\0';

	char CE0F[50];
	char CE1T[50];
	char CE2F[50];
	char CE3T[50];
	char CE4F[50];
	char CE5T[50];
	char CE6F[50];
	char CE7T[50];
	char CE8F[50];
	char CE9T[50];
	char CEAF[50];
	char CEBT[50];
	char CECF[50];
	char CEDT[50];
	char CEEF[50];
	char CEFT[50];
	char CEGF[50];
	char CEHT[50];
	char CEOT[50];
	sprintf(CE0F,"alse,\"changed\":\"%c%c%c%c-%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1],FD[0]);
	sprintf(CE1T,"rue,\"changed\":\"%c%c%c%c-%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1],FD[0],FD[1]);
	sprintf(CE2F,"false,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CE3T,"true,\"changed\":\"%c%c%c%c-%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1],FD[0]);
	sprintf(CE4F,":false,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CE5T,":true,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CE6F,"\":false,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(CE7T,"\":true,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CE8F,"w\":false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CE9T,"w\":true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(CEAF,"ow\":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CEBT,"ow\":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CECF,"now\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(CEDT,"now\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CEEF,"tnow\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(CEFT,"tnow\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(CEGF,"rtnow\":false,\"changed\":\"%c",YC[0]);
	sprintf(CEHT,"rtnow\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(CEOT,"ertnow\":true,\"changed\":\"%c",YC[0]);

	if(strcmp(CEs,CE0F)==0) {
		CEoff();
	} else if (strcmp(CEs,CE1T)==0) {
		CEon();
	} else if (strcmp(CEs,CE2F)==0) {
		CEoff();
	} else if (strcmp(CEs,CE3T)==0) {
		CEon();
	} else if (strcmp(CEs,CE4F)==0) {
		CEoff();
	} else if (strcmp(CEs,CE5T)==0) {
		CEon();
	} else if (strcmp(CEs,CE6F)==0) {
		CEoff();
	} else if (strcmp(CEs,CE7T)==0) {
		CEon();
	} else if (strcmp(CEs,CE8F)==0) {
		CEoff();
	} else if (strcmp(CEs,CE9T)==0) {
		CEon();
	} else if (strcmp(CEs,CEAF)==0) {
		CEoff();
	} else if (strcmp(CEs,CEBT)==0) {
		CEon();
	} else if (strcmp(CEs,CECF)==0) {
		CEoff();
	} else if (strcmp(CEs,CEDT)==0) {
		CEon();
	} else if (strcmp(CEs,CEEF)==0) {
		CEoff();
	} else if (strcmp(CEs,CEFT)==0) {
		CEon();
	} else if (strcmp(CEs,CEGF)==0) {
		CEoff();
	} else if (strcmp(CEs,CEHT)==0) {
		CEon();
	} else if (strcmp(CEs,"ertnow\":false,\"changed\":\"")==0) {
		CEoff();
	} else if (strcmp(CEs,CEOT)==0) {
		CEon();
	} else if (strcmp(CEs,"lertnow\":false,\"changed\":")==0) {
		CEoff();
	} else if (strcmp(CEs,"lertnow\":true,\"changed\":\"")==0) {
		CEon();
	} else if (strcmp(CEs,"alertnow\":false,\"changed\"")==0) {
		CEoff();
	} else if (strcmp(CEs,"alertnow\":true,\"changed\":")==0) {
		CEon();
	} else if (strcmp(CEs,"\"alertnow\":false,\"changed")==0) {
		CEoff();
	} else if (strcmp(CEs,"\"alertnow\":true,\"changed\"")==0) {
		CEon();
	} else if (strcmp(CEs,"{\"alertnow\":false,\"change")==0) {
		CEoff();
	} else if (strcmp(CEs,"{\"alertnow\":true,\"changed")==0) {
		CEon();
	} else if (strcmp(CEs,":{\"alertnow\":false,\"chang")==0) {
		CEoff();
	} else if (strcmp(CEs,":{\"alertnow\":true,\"change")==0) {
		CEon();
	} else if (strcmp(CEs,"\":{\"alertnow\":false,\"chan")==0) {
		CEoff();
	} else if (strcmp(CEs,"\":{\"alertnow\":true,\"chang")==0) {
		CEon();
	} else if (strcmp(CEs,"c\":{\"alertnow\":false,\"cha")==0) {
		CEoff();
	} else if (strcmp(CEs,"c\":{\"alertnow\":true,\"chan")==0) {
		CEon();
	} else if (strcmp(CEs,"4c\":{\"alertnow\":false,\"ch")==0) {
		CEoff();
	} else if (strcmp(CEs,"4c\":{\"alertnow\":true,\"cha")==0) {
		CEon();
	} else if (strcmp(CEs,"44c\":{\"alertnow\":false,\"c")==0) {
		CEoff();
	} else if (strcmp(CEs,"44c\":{\"alertnow\":true,\"ch")==0) {
		CEon();
	} else if (strcmp(CEs,"044c\":{\"alertnow\":false,\"")==0) {
		CEoff();
	} else if (strcmp(CEs,"044c\":{\"alertnow\":true,\"c")==0) {
		CEon();
	} else if (strcmp(CEs,"u044c\":{\"alertnow\":false,")==0) {
		CEoff();
	} else if (strcmp(CEs,"u044c\":{\"alertnow\":true,\"")==0) {
		CEon();
	} else if (strcmp(CEs,"\u044c\":{\"alertnow\":false")==0) {
		CEoff();
	} else if (strcmp(CEs,"\u044c\":{\"alertnow\":true,")==0) {
		CEon();
	} else if (strcmp(CEs,"2\u044c\":{\"alertnow\":fals")==0) {
		CEoff();
	} else if (strcmp(CEs,"2\u044c\":{\"alertnow\":true")==0) {
		CEon();
	}

	memset(CEs,0,sizeof(CEs));

	memset(CE0F,0,sizeof(CE0F));
	memset(CE1T,0,sizeof(CE1T));
	memset(CE2F,0,sizeof(CE2F));
	memset(CE3T,0,sizeof(CE3T));
	memset(CE4F,0,sizeof(CE4F));
	memset(CE5T,0,sizeof(CE5T));
	memset(CE6F,0,sizeof(CE6F));
	memset(CE7T,0,sizeof(CE7T));
	memset(CE8F,0,sizeof(CE8F));
	memset(CE9T,0,sizeof(CE9T));
	memset(CEAF,0,sizeof(CEAF));
	memset(CEBT,0,sizeof(CEBT));
	memset(CECF,0,sizeof(CECF));
	memset(CEDT,0,sizeof(CEDT));
	memset(CEEF,0,sizeof(CEEF));
	memset(CEFT,0,sizeof(CEFT));
	memset(CEGF,0,sizeof(CEGF));
	memset(CEHT,0,sizeof(CEHT));
	memset(CEOT,0,sizeof(CEOT));

	char CVs[25+1];
	strncpy(CVs,buffer+3072+632,25+1);
	CVs[25]='\0';

	char CV0T[50];
	char CV1F[50];
	char CV2T[50];
	char CV3F[50];
	char CV4T[50];
	char CV5F[50];
	char CV6T[50];
	char CV7F[50];
	char CV8T[50];
	char CV9F[50];
	char CVAT[50];
	char CVBF[50];
	char CVCT[50];
	char CVDF[50];
	char CVET[50];
	char CVFF[50];
	char CVGT[50];
	sprintf(CV0T,"ertnow\":true,\"changed\":\"%c",YC[0]);
	sprintf(CV1F,"rtnow\":false,\"changed\":\"%c",YC[0]);
	sprintf(CV2T,"rtnow\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(CV3F,"tnow\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(CV4T,"tnow\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(CV5F,"now\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(CV6T,"now\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CV7F,"ow\":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CV8T,"ow\":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CV9F,"w\":false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CVAT,"w\":true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(CVBF,"\":false,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(CVCT,"\":true,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CVDF,":false,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CVET,":true,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CVFF,"false,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CVGT,"true,\"changed\":\"%c%c%c%c-%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1],FD[0]);

	if(strcmp(CVs,"42\u044c\":{\"alertnow\":fal")==0) {
		CVoff();
	} else if (strcmp(CVs,"42\u044c\":{\"alertnow\":tru")==0) {
		CVon();
	} else if (strcmp(CVs,"2\u044c\":{\"alertnow\":fals")==0) {
		CVoff();
	} else if (strcmp(CVs,"2\u044c\":{\"alertnow\":true")==0) {
		CVon();
	} else if (strcmp(CVs,"\u044c\":{\"alertnow\":false")==0) {
		CVoff();
	} else if (strcmp(CVs,"\u044c\":{\"alertnow\":true,")==0) {
		CVon();
	} else if (strcmp(CVs,"u044c\":{\"alertnow\":false,")==0) {
		CVoff();
	} else if (strcmp(CVs,"u044c\":{\"alertnow\":true,\"")==0) {
		CVon();
	} else if (strcmp(CVs,"044c\":{\"alertnow\":false,\"")==0) {
		CVoff();
	} else if (strcmp(CVs,"044c\":{\"alertnow\":true,\"c")==0) {
		CVon();
	} else if (strcmp(CVs,"44c\":{\"alertnow\":false,\"c")==0) {
		CVoff();
	} else if (strcmp(CVs,"44c\":{\"alertnow\":true,\"ch")==0) {
		CVon();
	} else if (strcmp(CVs,"4c\":{\"alertnow\":false,\"ch")==0) {
		CVoff();
	} else if (strcmp(CVs,"4c\":{\"alertnow\":true,\"cha")==0) {
		CVon();
	} else if (strcmp(CVs,"c\":{\"alertnow\":false,\"cha")==0) {
		CVoff();
	} else if (strcmp(CVs,"c\":{\"alertnow\":true,\"chan")==0) {
		CVon();
	} else if (strcmp(CVs,"\":{\"alertnow\":false,\"chan")==0) {
		CVoff();
	} else if (strcmp(CVs,"\":{\"alertnow\":true,\"chang")==0) {
		CVon();
	} else if (strcmp(CVs,":{\"alertnow\":false,\"chang")==0) {
		CVoff();
	} else if (strcmp(CVs,":{\"alertnow\":true,\"change")==0) {
		CVon();
	} else if (strcmp(CVs,"{\"alertnow\":false,\"change")==0) {
		CVoff();
	} else if (strcmp(CVs,"{\"alertnow\":true,\"changed")==0) {
		CVon();
	} else if (strcmp(CVs,"\"alertnow\":false,\"changed")==0) {
		CVoff();
	} else if (strcmp(CVs,"\"alertnow\":true,\"changed\"")==0) {
		CVon();
	} else if (strcmp(CVs,"alertnow\":false,\"changed\"")==0) {
		CVoff();
	} else if (strcmp(CVs,"alertnow\":true,\"changed\":")==0) {
		CVon();
	} else if (strcmp(CVs,"lertnow\":false,\"changed\":")==0) {
		CVoff();
	} else if (strcmp(CVs,"lertnow\":true,\"changed\":\"")==0) {
		CVon();
	} else if (strcmp(CVs,"ertnow\":false,\"changed\":\"")==0) {
		CVoff();
	} else if (strcmp(CVs,CV0T)==0) {
		CVon();
	} else if (strcmp(CVs,CV1F)==0) {
		CVoff();
	} else if (strcmp(CVs,CV2T)==0) {
		CVon();
	} else if (strcmp(CVs,CV3F)==0) {
		CVoff();
	} else if (strcmp(CVs,CV4T)==0) {
		CVon();
	} else if (strcmp(CVs,CV5F)==0) {
		CVoff();
	} else if (strcmp(CVs,CV6T)==0) {
		CVon();
	} else if (strcmp(CVs,CV7F)==0) {
		CVoff();
	} else if (strcmp(CVs,CV8T)==0) {
		CVon();
	} else if (strcmp(CVs,CV9F)==0) {
		CVoff();
	} else if (strcmp(CVs,CVAT)==0) {
		CVon();
	} else if (strcmp(CVs,CVBF)==0) {
		CVoff();
	} else if (strcmp(CVs,CVCT)==0) {
		CVon();
	} else if (strcmp(CVs,CVDF)==0) {
		CVoff();
	} else if (strcmp(CVs,CVET)==0) {
		CVon();
	} else if (strcmp(CVs,CVFF)==0) {
		CVoff();
	} else if (strcmp(CVs,CVGT)==0) {
		CVon();
	}

	memset(CVs,0,sizeof(CVs));

	memset(CV0T,0,sizeof(CV0T));
	memset(CV1F,0,sizeof(CV1F));
	memset(CV2T,0,sizeof(CV2T));
	memset(CV3F,0,sizeof(CV3F));
	memset(CV4T,0,sizeof(CV4T));
	memset(CV5F,0,sizeof(CV5F));
	memset(CV6T,0,sizeof(CV6T));
	memset(CV7F,0,sizeof(CV7F));
	memset(CV8T,0,sizeof(CV8T));
	memset(CV9F,0,sizeof(CV9F));
	memset(CVAT,0,sizeof(CVAT));
	memset(CVBF,0,sizeof(CVBF));
	memset(CVCT,0,sizeof(CVCT));
	memset(CVDF,0,sizeof(CVDF));
	memset(CVET,0,sizeof(CVET));
	memset(CVFF,0,sizeof(CVFF));
	memset(CVGT,0,sizeof(CVGT));

	char CHs[25+1];
	strncpy(CHs,buffer+3072+800,25+1);
	CHs[25]='\0';

	char CH0T[50];
	char CH1F[50];
	char CH2T[50];
	char CH3F[50];
	char CH4T[50];
	char CH5F[50];
	char CH6T[50];
	char CH7F[50];
	char CH8T[50];
	char CH9F[50];
	char CHAT[50];
	char CHBF[50];
	char CHCT[50];
	char CHDF[50];
	char CHET[50];
	char CHFF[50];
	char CHGT[50];
	sprintf(CH0T,"ertnow\":true,\"changed\":\"%c",YC[0]);
	sprintf(CH1F,"rtnow\":false,\"changed\":\"%c",YC[0]);
	sprintf(CH2T,"rtnow\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(CH3F,"tnow\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(CH4T,"tnow\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(CH5F,"now\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(CH6T,"now\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CH7F,"ow\":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CH8T,"ow\":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CH9F,"w\":false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(CHAT,"w\":true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(CHBF,"\":false,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(CHCT,"\":true,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CHDF,":false,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CHET,":true,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CHFF,"false,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(CHGT,"true,\"changed\":\"%c%c%c%c-%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1],FD[0]);

	if(strcmp(CHs,"442\u044c\":{\"alertnow\":fa")==0) {
		CHoff();
	} else if (strcmp(CHs,"442\u044c\":{\"alertnow\":tr")==0) {
		CHon();
	} else if (strcmp(CHs,"42\u044c\":{\"alertnow\":fal")==0) {
		CHoff();
	} else if (strcmp(CHs,"42\u044c\":{\"alertnow\":tru")==0) {
		CHon();
	} else if (strcmp(CHs,"2\u044c\":{\"alertnow\":fals")==0) {
		CHoff();
	} else if (strcmp(CHs,"2\u044c\":{\"alertnow\":true")==0) {
		CHon();
	} else if (strcmp(CHs,"\u044c\":{\"alertnow\":false")==0) {
		CHoff();
	} else if (strcmp(CHs,"\u044c\":{\"alertnow\":true,")==0) {
		CHon();
	} else if (strcmp(CHs,"u044c\":{\"alertnow\":false,")==0) {
		CHoff();
	} else if (strcmp(CHs,"\u044c\":{\"alertnow\":true,\"")==0) {
		CHon();
	} else if (strcmp(CHs,"044c\":{\"alertnow\":false,\"")==0) {
		CHoff();
	} else if (strcmp(CHs,"044c\":{\"alertnow\":true,\"c")==0) {
		CHon();
	} else if (strcmp(CHs,"44c\":{\"alertnow\":false,\"c")==0) {
		CHoff();
	} else if (strcmp(CHs,"44c\":{\"alertnow\":true,\"ch")==0) {
		CHon();
	} else if (strcmp(CHs,"4c\":{\"alertnow\":false,\"ch")==0) {
		CHoff();
	} else if (strcmp(CHs,"4c\":{\"alertnow\":true,\"cha")==0) {
		CHon();
	} else if (strcmp(CHs,"c\":{\"alertnow\":false,\"cha")==0) {
		CHoff();
	} else if (strcmp(CHs,"c\":{\"alertnow\":true,\"chan")==0) {
		CHon();
	} else if (strcmp(CHs,"\":{\"alertnow\":false,\"chan")==0) {
		CHoff();
	} else if (strcmp(CHs,"\":{\"alertnow\":true,\"chang")==0) {
		CHon();
	} else if (strcmp(CHs,":{\"alertnow\":false,\"chang")==0) {
		CHoff();
	} else if (strcmp(CHs,":{\"alertnow\":true,\"change")==0) {
		CHon();
	} else if (strcmp(CHs,"{\"alertnow\":false,\"change")==0) {
		CHoff();
	} else if (strcmp(CHs,"{\"alertnow\":true,\"changed")==0) {
		CHon();
	} else if (strcmp(CHs,"\"alertnow\":false,\"changed")==0) {
		CHoff();
	} else if (strcmp(CHs,"\"alertnow\":true,\"changed\"")==0) {
		CHon();
	} else if (strcmp(CHs,"alertnow\":false,\"changed\"")==0) {
		CHoff();
	} else if (strcmp(CHs,"alertnow\":true,\"changed\":")==0) {
		CHon();
	} else if (strcmp(CHs,"lertnow\":false,\"changed\":")==0) {
		CHoff();
	} else if (strcmp(CHs,"lertnow\":true,\"changed\":\"")==0) {
		CHon();
	} else if (strcmp(CHs,"ertnow\":false,\"changed\":\"")==0) {
		CHoff();
	} else if (strcmp(CHs,CH0T)==0) {
		CHon();
	} else if (strcmp(CHs,CH1F)==0) {
		CHoff();
	} else if (strcmp(CHs,CH2T)==0) {
		CHon();
	} else if (strcmp(CHs,CH3F)==0) {
		CHoff();
	} else if (strcmp(CHs,CH4T)==0) {
		CHon();
	} else if (strcmp(CHs,CH5F)==0) {
		CHoff();
	} else if (strcmp(CHs,CH6T)==0) {
		CHon();
	} else if (strcmp(CHs,CH7F)==0) {
		CHoff();
	} else if (strcmp(CHs,CH8T)==0) {
		CHon();
	} else if (strcmp(CHs,CH9F)==0) {
		CHoff();
	} else if (strcmp(CHs,CHAT)==0) {
		CHon();
	} else if (strcmp(CHs,CHBF)==0) {
		CHoff();
	} else if (strcmp(CHs,CHCT)==0) {
		CHon();
	} else if (strcmp(CHs,CHDF)==0) {
		CHoff();
	} else if (strcmp(CHs,CHET)==0) {
		CHon();
	} else if (strcmp(CHs,CHFF)==0) {
		CHoff();
	} else if (strcmp(CHs,CHGT)==0) {
		CHon();
	}

	memset(CHs,0,sizeof(CHs));

	memset(CH0T,0,sizeof(CH0T));
	memset(CH1F,0,sizeof(CH1F));
	memset(CH2T,0,sizeof(CH2T));
	memset(CH3F,0,sizeof(CH3F));
	memset(CH4T,0,sizeof(CH4T));
	memset(CH5F,0,sizeof(CH5F));
	memset(CH6T,0,sizeof(CH6T));
	memset(CH7F,0,sizeof(CH7F));
	memset(CH8T,0,sizeof(CH8T));
	memset(CH9F,0,sizeof(CH9F));
	memset(CHAT,0,sizeof(CHAT));
	memset(CHBF,0,sizeof(CHBF));
	memset(CHCT,0,sizeof(CHCT));
	memset(CHDF,0,sizeof(CHDF));
	memset(CHET,0,sizeof(CHET));
	memset(CHFF,0,sizeof(CHFF));
	memset(CHGT,0,sizeof(CHGT));

	char KYs[25+1];
	strncpy(KYs,buffer+3072+885,25+1);
	KYs[25]='\0';

	char KY0T[50];
	char KY1F[50];
	char KY2T[50];
	char KY3F[50];
	char KY4T[50];
	char KY5F[50];
	char KY6T[50];
	char KY7F[50];
	char KY8T[50];
	char KY9F[50];
	char KYAT[50];
	char KYBF[50];
	char KYCT[50];
	char KYDF[50];
	char KYET[50];
	char KYFF[50];
	char KYGT[50];
	sprintf(KY0T,"ertnow\":true,\"changed\":\"%c",YC[0]);
	sprintf(KY1F,"rtnow\":false,\"changed\":\"%c",YC[0]);
	sprintf(KY2T,"rtnow\":true,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(KY3F,"tnow\":false,\"changed\":\"%c%c",YC[0],YC[1]);
	sprintf(KY4T,"tnow\":true,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KY5F,"now\":false,\"changed\":\"%c%c%c",YC[0],YC[1],YC[2]);
	sprintf(KY6T,"now\":true,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KY7F,"ow\":false,\"changed\":\"%c%c%c%c",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KY8T,"ow\":true,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KY9F,"w\":false,\"changed\":\"%c%c%c%c-",YC[0],YC[1],YC[2],YC[3]);
	sprintf(KYAT,"w\":true,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KYBF,"\":false,\"changed\":\"%c%c%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0]);
	sprintf(KYCT,"\":true,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KYDF,":false,\"changed\":\"%c%c%c%c-%c%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KYET,":true,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KYFF,"false,\"changed\":\"%c%c%c%c-%c%c-",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1]);
	sprintf(KYGT,"true,\"changed\":\"%c%c%c%c-%c%c-%c",YC[0],YC[1],YC[2],YC[3],MC[0],MC[1],FD[0]);

	if(strcmp(KYs,"0457\u0432\":{\"alertnow\":f")==0) {
		KYoff();
	} else if (strcmp(KYs,"0457\u0432\":{\"alertnow\":t")==0) {
		KYon();
	} else if (strcmp(KYs,"457\u0432\":{\"alertnow\":fa")==0) {
		KYoff();
	} else if (strcmp(KYs,"457\u0432\":{\"alertnow\":tr")==0) {
		KYon();
	} else if (strcmp(KYs,"57\u0432\":{\"alertnow\":fal")==0) {
		KYoff();
	} else if (strcmp(KYs,"57\u0432\":{\"alertnow\":tru")==0) {
		KYon();
	} else if (strcmp(KYs,"7\u0432\":{\"alertnow\":fals")==0) {
		KYoff();
	} else if (strcmp(KYs,"7\u0432\":{\"alertnow\":true")==0) {
		KYon();
	} else if (strcmp(KYs,"\u0432\":{\"alertnow\":false")==0) {
		KYoff();
	} else if (strcmp(KYs,"\u0432\":{\"alertnow\":true,")==0) {
		KYon();
	} else if (strcmp(KYs,"u0432\":{\"alertnow\":false,")==0) {
		KYoff();
	} else if (strcmp(KYs,"u0432\":{\"alertnow\":true,\"")==0) {
		KYon();
	} else if (strcmp(KYs,"0432\":{\"alertnow\":false,\"")==0) {
		KYoff();
	} else if (strcmp(KYs,"0432\":{\"alertnow\":true,\"c")==0) {
		KYon();
	} else if (strcmp(KYs,"432\":{\"alertnow\":false,\"c")==0) {
		KYoff();
	} else if (strcmp(KYs,"432\":{\"alertnow\":true,\"ch")==0) {
		KYon();
	} else if (strcmp(KYs,"32\":{\"alertnow\":false,\"ch")==0) {
		KYoff();
	} else if (strcmp(KYs,"32\":{\"alertnow\":true,\"cha")==0) {
		KYon();
	} else if (strcmp(KYs,"2\":{\"alertnow\":false,\"cha")==0) {
		KYoff();
	} else if (strcmp(KYs,"2\":{\"alertnow\":true,\"chan")==0) {
		KYon();
	} else if (strcmp(KYs,"\":{\"alertnow\":false,\"chan")==0) {
		KYoff();
	} else if (strcmp(KYs,"\":{\"alertnow\":true,\"chang")==0) {
		KYon();
	} else if (strcmp(KYs,":{\"alertnow\":false,\"chang")==0) {
		KYoff();
	} else if (strcmp(KYs,":{\"alertnow\":true,\"change")==0) {
		KYon();
	} else if (strcmp(KYs,"{\"alertnow\":false,\"change")==0) {
		KYoff();
	} else if (strcmp(KYs,"{\"alertnow\":true,\"changed")==0) {
		KYon();
	} else if (strcmp(KYs,"\"alertnow\":false,\"changed")==0) {
		KYoff();
	} else if (strcmp(KYs,"\"alertnow\":true,\"changed\"")==0) {
		KYon();
	} else if (strcmp(KYs,"alertnow\":false,\"changed\"")==0) {
		KYoff();
	} else if (strcmp(KYs,"alertnow\":true,\"changed\":")==0) {
		KYon();
	} else if (strcmp(KYs,"lertnow\":false,\"changed\":")==0) {
		KYoff();
	} else if (strcmp(KYs,"lertnow\":true,\"changed\":\"")==0) {
		KYon();
	} else if (strcmp(KYs,"ertnow\":false,\"changed\":\"")==0) {
		KYoff();
	} else if (strcmp(KYs,KY0T)==0) {
		KYon();
	} else if (strcmp(KYs,KY1F)==0) {
		KYoff();
	} else if (strcmp(KYs,KY2T)==0) {
		KYon();
	} else if (strcmp(KYs,KY3F)==0) {
		KYoff();
	} else if (strcmp(KYs,KY4T)==0) {
		KYon();
	} else if (strcmp(KYs,KY5F)==0) {
		KYoff();
	} else if (strcmp(KYs,KY6T)==0) {
		KYon();
	} else if (strcmp(KYs,KY7F)==0) {
		KYoff();
	} else if (strcmp(KYs,KY8T)==0) {
		KYon();
	} else if (strcmp(KYs,KY9F)==0) {
		KYoff();
	} else if (strcmp(KYs,KYAT)==0) {
		KYon();
	} else if (strcmp(KYs,KYBF)==0) {
		KYoff();
	} else if (strcmp(KYs,KYCT)==0) {
		KYon();
	} else if (strcmp(KYs,KYDF)==0) {
		KYoff();
	} else if (strcmp(KYs,KYET)==0) {
		KYon();
	} else if (strcmp(KYs,KYFF)==0) {
		KYoff();
	} else if (strcmp(KYs,KYGT)==0) {
		KYon();
	}

	memset(KYs,0,sizeof(KYs));

	memset(KY0T,0,sizeof(KY0T));
	memset(KY1F,0,sizeof(KY1F));
	memset(KY2T,0,sizeof(KY2T));
	memset(KY3F,0,sizeof(KY3F));
	memset(KY4T,0,sizeof(KY4T));
	memset(KY5F,0,sizeof(KY5F));
	memset(KY6T,0,sizeof(KY6T));
	memset(KY7F,0,sizeof(KY7F));
	memset(KY8T,0,sizeof(KY8T));
	memset(KY9F,0,sizeof(KY9F));
	memset(KYAT,0,sizeof(KYAT));
	memset(KYBF,0,sizeof(KYBF));
	memset(KYCT,0,sizeof(KYCT));
	memset(KYDF,0,sizeof(KYDF));
	memset(KYET,0,sizeof(KYET));
	memset(KYFF,0,sizeof(KYFF));
	memset(KYGT,0,sizeof(KYGT));

	char ZPs[11+1];
	strncpy(ZPs,buffer+1024+147,11+1);
	ZPs[11]='\0';

	if(strcmp(ZPs,"ow\":false,\"")==0) {
		ZPoff();
	} else if (strcmp(ZPs,"tnow\":false")==0) {
		ZPoff();
	} else if (strcmp(ZPs,"tnow\":true,")==0) {
		ZPon();
	} else if (strcmp(ZPs,"now\":false,")==0) {
		ZPoff();
	} else if (strcmp(ZPs,"now\":true,\"")==0) {
		ZPon();
	} else if (strcmp(ZPs,"w\":false,\"c")==0) {
		ZPoff();
	} else if (strcmp(ZPs,"w\":true,\"ch")==0) {
		ZPon();
	} else if (strcmp(ZPs,"\":false,\"ch")==0) {
		ZPoff();
	} else if (strcmp(ZPs,"\":true,\"cha")==0) {
		ZPon();
	} else if (strcmp(ZPs,":false,\"cha")==0) {
		ZPoff();
	} else if (strcmp(ZPs,":true,\"chan")==0) {
		ZPon();
	} else if (strcmp(ZPs,"false,\"chan")==0) {
		ZPoff();
	} else if (strcmp(ZPs,"true,\"chang")==0) {
		ZPon();
	} else if (strcmp(ZPs,"ow\":true,\"c")==0) {
		ZPon();
	}

	memset(ZPs,0,sizeof(ZPs));

	memset(buffer,0,sizeof(buffer));
	system("del STATUS.GET");
}

void drawGUI() {
	//clrscr();
	hideCursor();

	switch(TimerUpd) {
		case 15:
		case 14:
		case 13:
		case 12:
		case 11:
		case 10:
			SpaceChr='\0';
			SpaceChr1='\32';
			break;
		case 9:
		case 8:
		case 7:
		case 6:
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			SpaceChr='\0';
			SpaceChr1='\0';
			break;

	}

	getDate();
	getTime();

	gotoxy(1,1);

	// Draw GUI
	printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	printf("\xB3                                                     \xB3\xFE Air Alert for MS-DOS \xFE\xB3");
	printf("\xB3                                                     \xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4");
	printf("\xB3                              \xDC\xDC\xDC\xDC\xDC                  \xB3\Connected!\xB3Update in:%c%d%c\xB3", SpaceChr, TimerUpd, SpaceChr1);
	printf("\xB3       \xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC           \xDC\xDB\xDB\xDB%c%c%c%c\xB1\xDB                 \xC0\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4",CHch,CHch,CHch,CHch);
	printf("\xB3     \xDC\xDB%c%c%c\xB1%c%c%c\xDB\xDB\xDB\xDB\xDC\xDB\xDC\xDC \xDC\xDC\xDE\xDB%c%c%c%c%c%c\xB1%c%c\xDB                 \xB3 %c VINNS %c \xB3 %c ODESA %c \xB3",VOch,VOch,VOch,RIch,RIch,RIch,CHch,CHch,CHch,CHch,CHch,CHch,SUch,SUch,VIst,VIst,ODst,ODst);
	printf("\xB3     \xDB%c%c%c%c%c\xB1%c%c%c%c\xB1%c%c%c%c%c\xB1%c%c\xB1\xB1%c%c%c%c%c%c\xB1%c%c%c\xDB\xDC               \xB3 %c VOLYN %c \xB3 %c POLTV %c \xB3",VOch,VOch,VOch,VOch,VOch,RIch,RIch,RIch,RIch,ZHch,ZHch,ZHch,ZHch,ZHch,KOch,KOch,CHch,CHch,CHch,CHch,CHch,CHch,SUch,SUch,SUch,VOst,VOst,POst,POst);
	printf("\xB3    \xDB%c%c%c%c\xB1\xB1%c%c%c%c\xB1%c%c%c%c%c%c\xB1%c%c%c%c\xB1%c%c%c%c%c\xB1%c%c%c%c%c\xDB \xDC  \xDC\xDC        \xB3 %c DNIPR %c \xB3 %c RIVNE %c \xB3",VOch,VOch,VOch,VOch,RIch,RIch,RIch,RIch,ZHch,ZHch,ZHch,ZHch,ZHch,ZHch,KOch,KOch,KOch,KOch,CHch,CHch,CHch,CHch,CHch,SUch,SUch,SUch,SUch,SUch,DNst,DNst,RIst,RIst);
	printf("\xB3   \xDB%c\xB1\xB1\xB1\xB1%c%c%c\xB1\xB1\xB1\xB1%c%c%c%c%c%c%c\xB1%c%c%c%c\xB1\xB1%c\xB1\xB1\xB1\xB1\xB1\xB1\xB1%c\xB1\xDB%c\xDB\xDB%c%c\xDB\xDC\xDC     \xB3 %c DONES %c \xB3 %c SUMY  %c \xB3",LVch,RIch,RIch,RIch,ZHch,ZHch,ZHch,ZHch,ZHch,ZHch,ZHch,KOch,KYch,KOch,KOch,CHch,SUch,KAch,KAch,KAch,DOst,DOst,SUst, SUst);
	printf("\xB3  \xDB%c%c%c%c%c\xB1\xB1\xB1\xB1\xB1%c%c%c\xB1\xB1\xB1%c%c%c%c\xB1%c%c%c%c%c%c\xB1%c%c%c%c%c%c%c\xB1\xB1%c%c%c%c%c%c%c\xB1%c\xDB\xDC   \xB3 %c ZHYTM %c \xB3 %c TERNP %c \xB3",LVch,LVch,LVch,LVch,LVch,KHch,KHch,KHch,ZHch,ZHch,ZHch,ZHch,KOch,KOch,KOch,KOch,KOch,KOch,POch,POch,POch,POch,POch,POch,POch,KAch,KAch,KAch,KAch,KAch,KAch,KAch,LHch,ZHst,ZHst,TRst,TRst);
	printf("\xB3 \xDB%c%c%c%c\xB1\xB1%c%c%c%c\xB1%c%c%c\xB1%c%c\xB1\xB1\xB1\xB1%c%c\xB1\xB1\xB1\xB1\xB1%c\xB1\xB1%c%c%c%c%c%c%c\xB1%c%c%c%c%c\xB1%c%c%c%c\xDB\xDC \xB3 %c ZAKRP %c \xB3 %c KHARK %c \xB3",LVch,LVch,LVch,LVch,TRch,TRch,TRch,TRch,KHch,KHch,KHch,VIch,VIch,KOch,KOch,CEch,POch,POch,POch,POch,POch,POch,POch,KAch,KAch,KAch,KAch,KAch, LHch,LHch, LHch, LHch, ZKst, ZKst, KAst, KAst);
	printf("\xB3 \xDB\xB1%c\xB1\xB1%c%c\xB1%c%c%c\xB1\xB1\xB1%c\xB1%c%c%c%c%c%c\xB1\xB1%c%c%c%c%c%c%c%c\xB1\xB1\xB1\%c\xB1\xB1\xB1%c\xB1\xB1\xB1%c\xB1%c\xB1%c%c%c\xDB  \xB3 %c ZAPRH %c \xB3 %c KHESN %c \xB3",LVch,IVch,IVch,TRch,TRch,TRch,KHch,VIch,VIch,VIch,VIch,VIch,VIch,CEch,CEch,CEch,CEch,CEch,CEch,CEch,CEch,POch,DNch,KAch,DOch,LHch,LHch,LHch,ZPst,ZPst,KEst,KEst);
	printf("\xB3 \xDB%c\xB1%c%c%c\xB1%c\xB1\xB1\xB1%c%c%c\xB1%c%c%c%c%c%c%c\xB1%c%c%c%c%c\xB1\xB1\xB1\xB1%c%c%c\xB1%c%c%c%c%c%c%c\xB1%c%c%c\xB1%c%c%c\xDB \xB3 %c IVNFR %c \xB3 %c KHMEL %c \xB3",ZKch,IVch,IVch,IVch,CVch,CVch,CVch,CVch,VIch,VIch,VIch,VIch,VIch,VIch,VIch,CEch,CEch,CEch,CEch,CEch,KIch,KIch,KIch,DNch,DNch,DNch,DNch,DNch,DNch,DNch,DOch,DOch,DOch,LHch,LHch,LHch,IVst,IVst,KHst,KHst);
	printf("\xB3 \xDB%c%c\xB1%c\xB1%c%c%c%c%c%c\xDB\xDF\xDF\xDF\xDF\xDB%c%c%c\xB1%c\xB1%c\xB1\xB1\xB1%c%c%c%c%c%c\xB1%c%c%c\xB1\xB1\xB1\xB1\xB1%c%c%c%c%c\xB1%c\xDB  \xB3 %c KVOBL %c \xB3 %c CHERK %c \xB3",ZKch,ZKch,IVch,CVch,CVch,CVch,CVch,CVch,CVch,VIch,VIch,VIch,ODch,CEch,KIch,KIch,KIch,KIch,KIch,KIch,DNch,DNch,DNch,DOch,DOch,DOch,DOch,DOch,LHch,KOst,KOst,CEst,CEst);
	printf("\xB3  \xDF\xDF\xDF\xDF \xDF\xDF\xDF\xDF\xDF\xDF      \xDF\xDF\xDB%c%c%c\xB1%c%c%c\xB1\xB1\xB1\xB1%c\xB1%c%c%c\xB1%c%c%c%c%c\xB1%c%c%c\xDB\xDF\xDF   \xB3 %c KIRVH %c \xB3 %c CHRNV %c \xB3",ODch,ODch,ODch,MKch,MKch,MKch,KIch,DNch,DNch,DNch,ZPch,ZPch,ZPch,ZPch,ZPch,DOch,DOch,DOch,KIst,KIst,CVst,CVst);
	printf("\xB3                      \xDF\xDB%c%c\xB1%c%c%c%c%c%c\xB1%c\xB1\xB1\xB1%c%c%c%c%c%c%c\xB1\xDB\xDF      \xB3 %c LUHNS %c \xB3 %c CHRNH %c \xB3",ODch,ODch,MKch,MKch,MKch,MKch,MKch,MKch,KEch,ZPch,ZPch,ZPch,ZPch,ZPch,ZPch,ZPch,LHst,LHst,CHst,CHst);
	printf("\xB3                       \xDB%c%c%c\xB1%c%c%c\xB1\xB1%c%c%c%c%c\xB1%c%c\xDB\xDB\xDF\xDF\xDF        \xB3 %c LVIV  %c \xB3 %c ARCRM %c \xB3",ODch,ODch,ODch,MKch,MKch,MKch,KEch,KEch,KEch,KEch,KEch,ZPch,ZPch,LVst,LVst,ACst,ACst);
	printf("\xB3                     \xDC\xDB%c%c%c\xDB\xDF\xDF\xDB\xB1%c%c%c%c%c\xDB\xDB\xDB\xDF\xDF             \xB3 %c MYKOL %c \xB3 %c KYIVC %c \xB3",ODch,ODch,ODch,KEch,KEch,KEch,KEch,KEch,MKst, MKst, KYst, KYst);
	printf("\xB3                    \xDB%c%c%c\xDB\xDF    \xDF\xDF\xDF\xDF\xDF\xDB\xDC\xDC                \xB3           \xB3           \xB3",ODch,ODch,ODch);
	printf("\xB3                   \xDC\xDB%c\xDB\xDF        \xDC\xDB\xDB%c%c%c\xDB\xDB\xDC  \xDC\xDC\xDC       \xDA\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4",ODch,ACch,ACch,ACch);
	printf("\xB3                   \xDF\xDF\xDF          \xDF\xDF\xDF\xDB%c%c%c%c\xDB\xDB\xDF\xDB\xDB        \xB3        %02d.%02d.%04d      \xB3",ACch,ACch,ACch,ACch,day,mon,year);
	printf("\xB3                                  \xDE""%c%c""\xDB\xDF\xDF             \xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xB4",ACch,ACch);
	printf("\xB3                                  \xDF\xDF\xDF                \xB3""Day:%.0f\xB3""%02d:%02d:%02d\xB3""v.%.2f\xB3",difference,hour,min,sec,version);
	printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
}

char SetVidMode='0';
char SetColMode='0';
char TempSettings[3];

void setupSave() {
	clrscr();
	printf("Air Alert for MS-DOS\n");
	printf("Setup [3/3]\n");
	printf("\n");
	printf("Review your settings before saving:\n");
	printf("\n");
	printf("SetVidMode: %d\n", SetVidMode); // change strings (not variables) to user readable names
	printf("SetColMode: %d\n", SetColMode);
	printf("\n");

	printf("%c%c\n",SetVidMode,SetColMode);

	printf("Press ENTER to save, and ESCAPE to exit without saving.\n");
	// SAVE SETTINGS
	while(1) {
		delay(500);
		if(kbhit()) {
			switch(getch()) {
			case 27:
				exit(EXIT_SUCCESS);
				break;
			case 13:
				clrscr();
				printf("Air Alert for MS-DOS\n");
				printf("Setup [3/3]\n");
				printf("-Saving-\n");
				//SAVE SETTINGS
				char buff[3];
				FILE *file=fopen("SETTINGS.INI","r");
				while (!file) {
					//FILE *file=fopen("SETTINGS.INI","r");
					//fread(buffer,sizeof(char),4-1,file);
					//fclose(file);
					//buffer[4-1]='\0';
					fopen("SETTINGS.INI","w");
					//fprintf(file,"%d%d",SetColMode,SetVidMode);
					fclose(file);
					fopen("SETTINGS.INI","r");
					while (!file) {
						fclose(file);
						clrscr();
						printf("Air Alert for MS-DOS\n");
						printf("Setup [3/3]\n");
						printf("-Failure-\n");
						printf("\n");
						printf("Setup has failed to save your data, however upon launching\n");
						printf("the program in normal mode (not setup) it will generate default values.\n");
						printf("\n");
						printf("Try to run the setup again and if the problem persists,\n");
						printf("consider performing hard disk or floppy drive checks.\n");
						showCursor();
						exit(EXIT_FAILURE);
					}
					fread(buff,sizeof(char),3-1,file);
					buff[3]='\0';
					printf("%c%c\n", buff);
					}
					fopen("SETTINGS.INI","w");
					fread(buff,sizeof(char),3-1,file);
					buff[3]='\0';
					printf("%c%c\n", buff);
					fprintf(file,"%c%c\0",SetColMode,SetVidMode);
					fclose(file);
				// rewiew last upper 6 lines
				// make tempsettings char [2] and put variables directly at 1 or 2

				//clrscr();
				printf("Air Alert for MS-DOS\n");
				printf("Setup [3/3]\n");
				printf("-Success-\n");
				printf("\n");
				printf("Setup has saved the settings successfully.\n");
				exit(EXIT_SUCCESS);
				break;
			}
		}
	}
	exit(EXIT_SUCCESS);
}

void setup2Menu() {
	clrscr();
	printf("Air Alert for MS-DOS\n");
	printf("Setup [2/3]\n");
	printf("\n");
	printf("Select color mode:\n");
	printf("1: B&W Monochrome (Default)\n");
	printf("2: 16 Color CGA/VGA\n");
	printf("");
	while(1) {
		delay(500);
		if(kbhit()) {
			switch(getch()) {
			case 27: // esc
				exit(EXIT_SUCCESS);
				break;
			case 13: // return
				SetColMode='1'; // set B&W default
				setupSave();
				break;
			case 49: // 1
				SetColMode='1'; // B&W
				setupSave();
				break;
			case 50: // 2
				SetColMode='2'; // 16 Color
				setupSave();
				break;
			}
		}
	}
}

void setup1Menu() {
	clrscr();
	printf("Air Alert for MS-DOS\n");
	printf("Setup [1/3]\n");
	printf("\n");
	printf("Select video mode:\n");
	printf("1: 80x25 (Default)\n");
	printf("2: 80x50\n");
	printf("");
	while(1) {
		delay(500);
		if(kbhit()) {
			switch(getch()) {
			case 27:
				exit(EXIT_SUCCESS);
				break;
			case 13:
				SetVidMode='1'; // set default 80x25
				setup2Menu();
				break;
			case 49:
				SetVidMode='1'; // 80x25
				setup2Menu();
				break;
			case 50:
				SetVidMode='2'; // 80x50
				setup2Menu();
				break;
			}
		}
	}
}


void setupMenu() {
	clrscr();
	printf("Air Alert for MS-DOS\n");
	printf("Setup [0/3]\n");
	printf("\n");
	printf("To start setup press ENTER, or ESC to exit without making any changes.\n");
	while(1) {
		delay(500);
		if(kbhit()) {
			switch(getch()) {
			case 27:
				exit(EXIT_SUCCESS);
				break;
			case 13:
				clrscr();
				setup1Menu();
				break;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	for (int i=1; i<argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			clrscr();
			printf("Air Alert for MS-DOS\n");
			printf("\n");
			printf("Flags:\n-h [Shows flag list];\n");
			//printf("-s [Enter a setup menu];\n");
			printf("-v [Shows current version].\n");
			printf("\n");
			printf("Use for testing purposes only. Exposing old operating\n");
			printf("operating systems to the internet is considered highly\n");
			printf("unsafe. The app should never be used as a reliable\n");
			printf("source of information.\n");
			printf("\n");
			printf("Some regions (like Cherkasy, Zhytomyr and more) will\n");
			printf("will be highlighted only if all of their subregions\n");
			printf("have received an alert signal due to them being\n");
			printf("separated by the issuer.\n");
			printf("\n");
			printf("Make sure you have:\n");
			printf("1) mTCP config location set in autoexec.bat;\n");
			printf("Example: SET MTCPCFG = C:\\[PATH]\\[NAME]\n");
			printf("2) entered interupt value for your NIC in mTCP config;\n");
			printf("3) run DHCP.EXE to receive an IP address;\n");
			printf("(optionally) 4) set current date and time correctly;\n");
			exit(EXIT_SUCCESS);
		} else if (strcmp(argv[i], "-v") == 0) {
			printf("Air Alert for MS-DOS\n");
			printf("Version: 1.03, Released @ 20 Feb. 2025\n");
			exit(EXIT_SUCCESS);
		//} else if (strcmp(argv[i], "-d") == 0) {
		 //	DebugMode = 1;
		 //	printf("Air Alert for MS-DOS\n");
		 //	printf("Debug Mode enabled\n");
		 //	exit(EXIT_SUCCESS);
		//} else if (strcmp(argv[i], "-t") == 0) {
			// do test network
		 //	printf("Air Alert for MS-DOS\n");
		 //	printf("Network Connection Test\n");
		 //	system("ping http://google.com");
		 //	exit(EXIT_SUCCESS);
		//}
	       // RE-ENABLE FROM HERE	else if (strcmp(argv[i], "-bgmono") == 0) {
	       //		// get a symbol or its escape code
	       //		exit(EXIT_SUCCESS);
	       //	} else if (strcmp(argv[i], "-fgmono") == 0) {
	       //		// get a symbol or its escape code
	       //		exit(EXIT_SUCCESS);
	       //	} else if (strcmp(argv[i], "-bg16") == 0) {
			// get a color value 0-16
	       //		exit(EXIT_SUCCESS);
	       //	} else if (strcmp(argv[i], "-fg16") == 0) {
	       //		// get a color value 0-16
	       //		exit(EXIT_SUCCESS);
	       //	} else if (strcmp(argv[i], "-wnmono") == 0) {
	       //		// get a color value 0-4 (black, dgray, bgray, white)
	       //		exit(EXIT_SUCCESS);
	       //	} else if (strcmp(argv[i], "-wn16") == 0) {
	       //		// get a color value 0-16
	       //		exit(EXIT_SUCCESS);
		} else if (strcmp(argv[i], "-s") == 0) {
			// enter a setup mode to enter all the values
			setupMenu();
			exit(EXIT_SUCCESS);
		} else {
			printf("Air Alert for MS-DOS\n");
			printf("Unknown flag: %s. Use -h flag to view help.\n", argv[i]);
			exit(EXIT_FAILURE);
		}
	}
	VIst=FG;
	ODst=FG;
	VOst=FG;
	POst=FG;
	DNst=FG;
	RIst=FG;
	DOst=FG;
	SUst=FG;
	ZHst=FG;
	TRst=FG;
	ZKst=FG;
	KAst=FG;
	ZPst=FG;
	KEst=FG;
	IVst=FG;
	KHst=FG;
	KOst=FG;
	CEst=FG;
	KIst=FG;
	CVst=FG;
	LHst=FG;
	CHst=FG;
	LVst=FG;
	ACst=FG;
	MKst=FG;
	KYst=FG;

	//system("mode con: cols=80 lines=25");

	hideCursor();
	TimerUpd=15;
	getDate();
	if (year<2022) {
		if (mon<2) {
			if (day<24) {
		printf("Fatal error: Date is set incorrectly.\n");
		printf("Date must contain year greater than 2023.\n");
		printf("\n");
		printf("Make sure your CMOS battery is not discharged\n");
		printf("and CMOS or clock chip are working properly.\n");
		printf("\n");
		printf("It is not necessary to keep the time actual though it's being shown in menu,\n");
		printf("however the date is being used for calculation and data checks.\n");
		exit(EXIT_FAILURE);
			}
		}
	}
	getData();
	while(1) {
		delay(1000);
		TimerUpd=TimerUpd-1;
		drawGUI();
		if (TimerUpd==0) {
			getData();
			TimerUpd=15;
			drawGUI();
		}
		if (kbhit()) {
			switch (getch()) {
			case ' ':
				TimerUpd=15;
				getData();
				drawGUI();
				break;
			/*case 'q': //on
				VIon();
				drawGUI();
				break;
			case 'Q': //off
				VIoff();
				drawGUI();
				break;
			case 'w':
				ODon();
				drawGUI();
				break;
			case 'W':
				ODoff();
				drawGUI();
				break;
			case 'e':
				VOon();
				drawGUI();
				break;
			case 'E':
				VOoff();
				drawGUI();
				break;
			case 'r':
				POon();
				drawGUI();
				break;
			case 'R':
				POoff();
				drawGUI();
				break;
			case 't':
				DNon();
				drawGUI();
				break;
			case 'T':
				DNoff();
				drawGUI();
				break;
			case 'y':
				RIon();
				drawGUI();
				break;
			case 'Y':
				RIoff();
				drawGUI();
				break;
			case 'u':
				DOon();
				drawGUI();
				break;
			case 'U':
				DOoff();
				drawGUI();
				break;
			case 'i':
				SUon();
				drawGUI();
				break;
			case 'I':
				SUoff();
				drawGUI();
				break;
			case 'o':
				ZHon();
				drawGUI();
				break;
			case 'O':
				ZHoff();
				drawGUI();
				break;
			case 'p':
				TRon();
				drawGUI();
				break;
			case 'P':
				TRoff();
				drawGUI();
				break;
			case 'a':
				ZKon();
				drawGUI();
				break;
			case 'A':
				ZKoff();
				drawGUI();
				break;
			case 's':
				KAon();
				drawGUI();
				break;
			case 'S':
				KAoff();
				drawGUI();
				break;
			case 'd':
				ZPon();
				drawGUI();
				break;
			case 'D':
				ZPoff();
				drawGUI();
				break;
			case 'f':
				KEon();
				drawGUI();
				break;
			case 'F':
				KEoff();
				drawGUI();
				break;
			case 'g':
				IVon();
				drawGUI();
				break;
			case 'G':
				IVoff();
				drawGUI();
				break;
			case 'h':
				KHon();
				drawGUI();
				break;
			case 'H':
				KHoff();
				drawGUI();
				break;
			case 'j':
				KOon();
				drawGUI();
				break;
			case 'J':
				KOoff();
				drawGUI();
				break;
			case 'k':
				CEon();
				drawGUI();
				break;
			case 'K':
				CEoff();
				drawGUI();
				break;
			case 'l':
				KIon();
				drawGUI();
				break;
			case 'L':
				KIoff();
				drawGUI();
				break;
			case 'z':
				CVon();
				drawGUI();
				break;
			case 'Z':
				CVoff();
				drawGUI();
				break;
			case 'x':
				LHon();
				drawGUI();
				break;
			case 'X':
				LHoff();
				drawGUI();
				break;
			case 'c':
				CHon();
				drawGUI();
				break;
			case 'C':
				CHoff();
				drawGUI();
				break;
			case 'v':
				LVon();
				drawGUI();
				break;
			case 'V':
				LVoff();
				drawGUI();
			    	break;
			case 'b':
				ACon();
				drawGUI();
				break;
			case 'B':
				ACoff();
				drawGUI();
				break;
			case 'n':
				MKon();
				drawGUI();
				break;
			case 'N':
				MKoff();
				drawGUI();
				break;
			case 'm':
				KYon();
				drawGUI();
				break;
			case 'M':
				KYoff();
				drawGUI();
				break;*/

			//default:
			//	TimerUpd=15;
			//	getData();
			//	drawGUI();
			//	break;
			case 27: // Esc
				clrscr();
				showCursor();
				printf("Air Alert for MS-DOS\n");
				printf("Version: %.2f\n", version);
				printf("Made by KotsumeHaku\n");
				printf("\n");
				printf("Use for testing purposes only. Exposing old operating\n");
				printf("operating systems to the internet is considered highly\n");
				printf("unsafe. The app should never be used as a reliable\n");
				printf("source of information.\n");
				printf("\n");
				printf("Some regions (like Cherkasy, Zhytomyr and other) will\n");
				printf("will be highlighted only if all of their subregions\n");
				printf("have received an alert signal due to them being\n");
				printf("separated by the issuer.\n");
				printf("\n");
				printf("For more info, view Readme file in the app directory.\n");
				exit(0);
				break;
			}
			//delay(1000);
		}
		//delay(1000);

	}
	//getKey();

	clrscr();
	return 0;
}