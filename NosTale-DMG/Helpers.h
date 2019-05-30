#pragma once
#include <Windows.h>

//Thanks to: https://www.unknowncheats.me/forum/c-and-c/67884-mid-function-hook-big-deal.html
void MakeJMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
{
	DWORD dwOldProtect, dwBkup, dwRelAddr;
	VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	dwRelAddr = (DWORD)(dwJumpTo - (DWORD)pAddress) - 5;
	*pAddress = 0xE9;
	*((DWORD *)(pAddress + 0x1)) = dwRelAddr;
	for (DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;

	VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
}