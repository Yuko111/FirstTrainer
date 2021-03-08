#ifndef _ASC_H_
#define _ASC_H_
#include <Windows.h>
class ASC {

public:
	
	ASC();
	void SearchAndOpenHandleProcess();
	void getIncreaseValueToNop()const;
	~ASC();
private:
	HANDLE hndle;
	DWORD Ammo_Adr;
	DWORD Health_Adr;
	DWORD Armor_Adr;
	const BYTE ModAmmo[2] = {0x90,0x90};
	const BYTE ModHealth[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	const BYTE ModArmor[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };

};
