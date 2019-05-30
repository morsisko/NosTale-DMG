#pragma once
#include <Windows.h>

//C++ structures generated using ReClass.NET by KN4CK3R
class TObject
{
public:
	BYTE pad_0000[4]; //0x0000
}; //Size: 0x0004

class TPersistant : public TObject
{
public:

}; //Size: 0x0004

class TStrings : public TPersistant
{
public:
	BYTE pad_0004[12]; //0x0004
}; //Size: 0x0010

class TStringList : public TStrings
{
public:
	char** m_pData; //0x0010
	DWORD m_iSize; //0x0014

	char* Get(int i)
	{
		if (i < 0 || i >= m_iSize)
			return 0;

		return m_pData[i * 2];
	}
}; //Size: 0x0018

class TNosRevCmdList : public TObject
{
public:
	BYTE pad_0004[4]; //0x0004
	TStringList* m_pStringList; //0x0008
}; //Size: 0x000C

class TNTClient : public TObject
{
public:
	BYTE pad_0004[48]; //0x0004
	TNosRevCmdList* m_pNosRevCmdList; //0x0034
}; //Size: 0x0038