DWORD WINAPI MainThread(LPVOID lpArguments)
{
	// Load core
	
	while (!GetAsyncKeyState(VK_END))
		std::this_thread::sleep_for(std::chrono::milliseconds(350));

	// Unload

	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(lpArguments), EXIT_SUCCESS);
}

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hInstance);

	if (dwReason == DLL_PROCESS_ATTACH)
		if (const HANDLE hMain = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hInstance, 0, 0))
			CloseHandle(hMain);

	return true;
}