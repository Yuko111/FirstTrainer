#include "ASC.h"
#include <iostream>
#include <stdexcept>

ASC::ASC() {

	Ammo_Adr = 0x004637E9;
	Health_Adr = 0x0042CA5E;
	Armor_Adr = 0x00463378;


}


void ASC::SearchAndOpenHandleProcess() {

	HWND hWnd = 0;

	while (hWnd == NULL) {

	system("cls");
	std::cout << "Oyun bekleniyor..." << std::endl;
	hWnd = FindWindowA(NULL,"AssaultCube");   // Program Pencere İsmi Arama.
	Sleep(1000);
	}

	DWORD process_id = 0;

	GetWindowThreadProcessId(hWnd, &process_id); // Program İşlem Kimliği alma.

	if (process_id == 0)
		throw std::runtime_error("Pencere işlem kimliği alınamadı.");
	
	 hndle = OpenProcess(PROCESS_ALL_ACCESS, false, process_id);   // Tüm yetkiler ile aç.

	if (!hndle)
		throw std::runtime_error("İşlem açılamadı.");

	
}

void ASC::getIncreaseValueToNop()const {

	WriteProcessMemory(hndle, (LPVOID)Ammo_Adr, ModAmmo, sizeof(ModAmmo), NULL); // Ammo
	WriteProcessMemory(hndle, (LPVOID)Health_Adr, ModHealth, sizeof(ModHealth), NULL); //HEALTH
	WriteProcessMemory(hndle, (LPVOID)Armor_Adr, ModArmor, sizeof(ModArmor), NULL); // ARMOR

}

ASC::~ASC() {

	Ammo_Adr = NULL, Health_Adr = NULL; Armor_Adr = NULL;
}
