#include <windows.h>

#include <fstream>

#include <mmsystem.h>

#pragma comment(lib, "winmm")

const wchar_t ClassName[] = L"Window2";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)

{

	HDC hdc;

	PAINTSTRUCT ps;

	HWND find = FindWindow(L"Window", L"FW1");

	switch (msg)

	{

	case WM_USER + 1: {

		MessageBox(0, L"Вы нажали на первое окно", L"Проверка", MB_OK | MB_ICONERROR);

	}

					return 0;

	case WM_USER + 2: {
		STARTUPINFOW si = { 0 };
		PROCESS_INFORMATION pi = { 0 };
		CreateProcessW(L"C:\\Windows\\System32\\calc.exe", NULL, 0, 0, 0, 0, 0, 0, &si, &pi);

		Sleep(rand() % 1000);

		HWND hCalc = FindWindowW(L"Калькулятор", 0);
		HWND edit = FindWindowExW(hCalc, 0, L"Edit", 0);
		
	}return 0;

	case WM_LBUTTONUP: {

		exit(EXIT_FAILURE); }

	case WM_RBUTTONUP:

		exit(EXIT_FAILURE);

		return 0;

	case WM_CLOSE:

		DestroyWindow(hwnd);

		break;

	case WM_DESTROY:

		PostQuitMessage(0);

		break;

	default:

		return DefWindowProc(hwnd, msg, wParam, lParam);

	}

	return 0;

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{

	WNDCLASSEX wc;

	HWND hwnd;

	MSG Msg;

	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = 0;

	wc.lpfnWndProc = WndProc;

	wc.cbClsExtra = 0;

	wc.cbWndExtra = 0;

	wc.hInstance = hInstance;

	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = CreateSolidBrush(RGB(205, 105, 0));

	wc.lpszMenuName = NULL;

	wc.lpszClassName = ClassName;

	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))

	{

		MessageBox(NULL, L"Window Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);

		return 0;

	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, ClassName, L"FW2", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 700, 500, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)

	{

		MessageBox(NULL, L"Window Creation Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);

		return 0;

	}

	ShowWindow(hwnd, nCmdShow);

	UpdateWindow(hwnd);

	while (GetMessage(&Msg, NULL, 0, 0) > 0)

	{

		TranslateMessage(&Msg);

		DispatchMessage(&Msg);

	}

	return Msg.wParam;

}