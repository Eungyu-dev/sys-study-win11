#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#include <iostream>
#include <string>

#define DIR_LEN MAX_PATH+1

/***
* TCHAR과 같은 T 자료형 사용하는 이유: 아스키코드와 유니코드의 동시 호환성을 위해서 사용
*/
int _tmain(int argc, TCHAR* argv[]) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (argc != 2)
	{
		_tprintf(_T("Usage: %s [cmdline]\n"), argv[0]);
		return -1;
	}

	int r;
	if (r = CreateProcess(
		NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	)) {
		printf("%d\n", r);
		printf("CreateProcess failed (%d).\n", GetLastError());
		return -2;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}