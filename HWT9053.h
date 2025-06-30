#ifndef HWT9053_h
#define HWT9053_h

#define SAVE 		0x00
#define CALSW 		0x01
#define RSW 		0x02
#define RRATE		0x03
#define BAUD 		0x04
#define AXOFFSET	0x05
#define AYOFFSET	0x06
#define AZOFFSET	0x07
#define GXOFFSET	0x08
#define GYOFFSET	0x09
#define GZOFFSET	0x0a
#define HXOFFSET	0x0b
#define HYOFFSET	0x0c
#define HZOFFSET	0x0d
#define D0MODE		0x0e
#define D1MODE		0x0f
#define D2MODE		0x10
#define D3MODE		0x11
#define D0PWMH		0x12
#define D1PWMH		0x13
#define D2PWMH		0x14
#define D3PWMH		0x15
#define D0PWMT		0x16
#define D1PWMT		0x17
#define D2PWMT		0x18
#define D3PWMT		0x19
#define IICADDR		0x1a
#define LEDOFF 		0x1b
#define GPSBAUD		0x1c

#define YYMM		0x30
#define DDHH		0x31
#define MMSS		0x32
#define MS					0x33
#define AX					0x34  //x accel
#define AY					0x35  //y accel
#define AZ					0x36  //z accel
#define GX					0x37  //gyroscope x
#define GY					0x38  //gyroscope y
#define GZ					0x39  //gyroscope z
#define HX					0x3a  //Magnetic FieldX
#define HY					0x3b  //Magnetic FieldY
#define HZ					0x3c	//Magnetic FieldZ		
#define Roll				0x3d  //X-axis angle low
#define Pitch				0x3e  //X-axis angle high 
#define Yaw					0x3f  //Y-axis angle low
#define TEMP				0x43
#define D0Status		0x41
#define D1Status		0x42
#define D2Status		0x43
#define D3Status		0x44
#define PressureL		0x45
#define PressureH		0x46
#define HeightL			0x47
#define HeightH			0x48
#define LonL				0x49
#define LonH				0x4a
#define LatL				0x4b
#define LatH				0x4c
#define GPSHeight   0x4d
#define GPSYAW      0x4e
#define GPSVL				0x4f
#define GPSVH				0x50
      
#define DIO_MODE_AIN 0
#define DIO_MODE_DIN 1
#define DIO_MODE_DOH 2
#define DIO_MODE_DOL 3
#define DIO_MODE_DOPWM 4
#define DIO_MODE_GPS 5		


struct SAcc
{
	short a[3];
	short T;
};
struct SGyro
{
	short w[3];
	short T;
};
struct SAngle
{
	long Angle[3];
	short T;
};
struct SMag
{
	short h[3];
	short T;
};
struct STemp
{
	short t[3];
};

class CJY901 
{
  public: 
	struct SAcc 		stcAcc;
	struct SGyro 		stcGyro;
	struct SAngle 		stcAngle;
	struct SMag 		stcMag;
	struct STemp 		stcTemp;

    CJY901 (); 
    void CopeSerialData(unsigned char ucData);
	void CharToShort(unsigned char cTemp[],short sTemp[],short sShortNum);
	void CharToLong(unsigned char cTemp[],long lTemp[],int iShortNum);	

  private: 
	unsigned char ucDevAddr; 
};
extern CJY901 HWT9053;
#include <Wire.h>
#endif
