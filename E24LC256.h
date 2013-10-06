#ifndef _E24LC256_h
#define _E24LC256_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>

#define E24LC256_ADDR		0x50
#define E24LC256_MAXADRESS	0x7FFF
#define E24LC256_PAGESIZE	64
#define WRITE_BUFFERSIZE	30
#define READ_BUFFERSIZE		30

class E24LC256
{
private:
	byte _deviceAddr;
	int internalWrite(unsigned short addr, byte* data, byte length);
	int internalRead(unsigned short addr, byte* data, unsigned short length);
	int burstWrite(unsigned short addr, byte* data, unsigned short length);
	int burstRead(unsigned short addr, byte* data, unsigned short length);
public:
	E24LC256(byte addr);
	~E24LC256();
	
	byte read();
	byte read(unsigned short addr);
	int read(unsigned short addr, byte* data, unsigned short length);

	void write(unsigned short addr, byte data);
	int write(unsigned short addr, byte* data, unsigned short length);

	template <typename T> int readBlock(unsigned short addr, const T& data)
	{
		return read(addr, (byte*)&data, sizeof(T));
	}

	template <typename T> int writeBlock(unsigned short addr, const T& data)
	{
		return write(addr, (byte*)&data, sizeof(T));
	}
};

#endif