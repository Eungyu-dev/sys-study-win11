/***
* feat : 새로운 기능에 대한 커밋
* fix : 버그 수정에 대한 커밋
* build : 빌드 관련 파일 수정에 대한 커밋
* chore : 그 외 자잘한 수정에 대한 커밋
* ci : CI관련 설정 수정에 대한 커밋
* docs : 문서 수정에 대한 커밋
* style : 코드 스타일 혹은 포맷 등에 관한 커밋
* refactor :  코드 리팩토링에 대한 커밋
* test : 테스트 코드 수정에 대한 커밋
*/

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