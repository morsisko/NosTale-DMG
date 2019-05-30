#pragma once
#include <Windows.h>

//Thanks to this: http://www.unknowncheats.me/forum/1064672-post23.html

bool DataCompare(BYTE* pData, BYTE* bSig, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bSig)
	{
		if (*szMask == 'x' && *pData != *bSig)
			return false;
	}
	return (*szMask) == NULL;
}

BYTE* FindPattern(BYTE* dwAddress, DWORD dwSize, BYTE* pbSig, const char* szMask)
{
	for (DWORD i = NULL; i < dwSize; i++)
	{
		if (DataCompare(dwAddress + i, pbSig, szMask))
			return dwAddress + i;
	}
	return 0;
}