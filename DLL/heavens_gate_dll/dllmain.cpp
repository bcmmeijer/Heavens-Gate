// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "syscalls.hpp"

#define NAKED __declspec(naked)

LPVOID		g_lpJmpRealloc = nullptr;
DWORD		old, syscall;
const char* call = nullptr;

void NAKED hk_Wow64Trampoline() {
	__asm pushad
	__asm mov syscall, eax

	call = print_syscall(syscall);
	if (call == nullptr) {
		__asm popad
		__asm jmp g_lpJmpRealloc
	}
	printf("[*] Called:\t\t%s\n", call);
	__asm popad
	__asm jmp g_lpJmpRealloc
}

const FORCEINLINE DWORD_PTR NAKED GetGateAddress() {
	__asm mov eax, dword ptr fs : [0xC0]
	__asm ret
}

const FORCEINLINE LPVOID SaveGateAddress() {
	DWORD_PTR Gate = GetGateAddress();
	g_lpJmpRealloc = VirtualAlloc(nullptr, 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (g_lpJmpRealloc == nullptr) return nullptr;
	memcpy(g_lpJmpRealloc, (void*)Gate, 9);
	return g_lpJmpRealloc;
}

const bool WriteJump(const DWORD_PTR dwWow64Address, const void* pBuffer, size_t ulSize) {
	DWORD dwOldProtect = 0;
	if (!VirtualProtect((LPVOID)dwWow64Address, ulSize, PAGE_EXECUTE_READWRITE, &dwOldProtect))
		return false;
	memcpy((void*)dwWow64Address, pBuffer, ulSize);
	if (!VirtualProtect((LPVOID)dwWow64Address, ulSize, dwOldProtect, &dwOldProtect))
		return false;
	return true;
}

const bool EnableWow64Redirect() {
	FARPROC Hook_Gate = (FARPROC)hk_Wow64Trampoline;
	if (SaveGateAddress() == nullptr) return false;
	char trampolineBytes[] =
	{
		0x68, 0xDD, 0xCC, 0xBB, 0xAA,
		0xC3,
		0xCC, 0xCC, 0xCC
	};
	memcpy(&trampolineBytes[1], &Hook_Gate, 4);
	return WriteJump(GetGateAddress(), trampolineBytes, sizeof(trampolineBytes));
}

const bool RestoreGate() {
	if (!WriteJump(GetGateAddress(), g_lpJmpRealloc, 9))
		return false;
	return VirtualFree(g_lpJmpRealloc, 0x1000, MEM_RELEASE | MEM_FREE);
}


void entry() {

	AllocConsole();
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);

	std::cout << "[*] Heavens Gate:\t0x" << (PVOID)GetGateAddress() << std::endl;
	std::cout << "[*] Hook Function:\t0x" << hk_Wow64Trampoline << std::endl;

	if (EnableWow64Redirect())
		std::cout << "[+] Enabled redirecting\n";
	else
		std::cout << "[-] Could not enabled redirecting\n";
}


BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		return CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)entry, NULL, 0, NULL));
	if (ul_reason_for_call == DLL_PROCESS_DETACH)
		return RestoreGate();
    return TRUE;
}

