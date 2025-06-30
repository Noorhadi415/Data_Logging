#include "HWT9053.h"
#include "string.h"


CJY901 ::CJY901 ()
{
}

void CJY901::CharToShort(unsigned char cTemp[],short sTemp[],short sShortNum)
{
	int i;
	for (i = 0;i<3;i++) 
		sTemp[i] = (cTemp[2*i+sShortNum]<<8)|(cTemp[2*i+sShortNum+1]&0xff);
}

void CJY901::CharToLong(unsigned char cTemp[],long lTemp[],int iShortNum)
{
	long i;
	for (i = 0;i<3;i++) 		
		lTemp[i] = (cTemp[4*i+iShortNum]<<8)|(cTemp[4*i+iShortNum+1]&0xff)|(cTemp[4*i+iShortNum+2]<<24)|(cTemp[4*i+iShortNum+3]<<16);
}
void CJY901 ::CopeSerialData(unsigned char ucData)
{
	static unsigned char ucRxBuffer[250];
	static unsigned char ucRxCnt = 0;	
	
	ucRxBuffer[ucRxCnt++]=ucData;
	if (ucRxBuffer[0]!=0x50) 
	{
		ucRxCnt=0;
		return;
	}
	//if (ucRxCnt<29) {return;}
	if (ucRxCnt<37) {return;}
	else
	{
		ucRxCnt=0;
		CharToShort(ucRxBuffer,stcAcc.a,3);
		CharToShort(ucRxBuffer,stcGyro.w,9);
		CharToShort(ucRxBuffer,stcMag.h,15);
		CharToLong(ucRxBuffer,stcAngle.Angle,21);
		CharToShort(ucRxBuffer,stcTemp.t,33);
	}
}

CJY901 HWT9053 = CJY901();