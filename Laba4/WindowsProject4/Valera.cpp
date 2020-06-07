#include <tchar.h>
#include <string>
#include <atlstr.h>
#include <fstream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#pragma intrinsic(__rdtsc)


using namespace std;

static int widht, hight, r;
static HWND hWnd;
static HDC hdc;
static PAINTSTRUCT ps;
//static HANDLE hThread2;
//static BOOL fin1 = true;
int i = 0;
wstring time;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
RECT rect;
TCHAR WinName[] = _T("MainFrame");

//DWORD WINAPI Thread2(LPVOID);

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWnd;		// Дескриптор главного окна программы 
	MSG msg; 		// Структура для хранения сообщения 
	WNDCLASS wc; 	// Класс окна
	// Определение класса окна 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 				// Имя класса окна 
	wc.lpfnWndProc = WndProc; 					// Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wc.lpszMenuName = NULL; 					// Нет меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("Каркас Windows-приложения"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	ShowWindow(hWnd, mode); 				// Показать окно

	HMENU MainMenu = CreateMenu();
	HMENU hPopupMenu = CreatePopupMenu();
	HMENU hPopupMenu2 = CreatePopupMenu();
	HMENU hPopupMenu3 = CreatePopupMenu();
	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu, L"&Поток 1");
	{
		AppendMenu(hPopupMenu, MF_STRING, 1001, L"Включить");
		AppendMenu(hPopupMenu, MF_STRING, 1002, L"Выключить");
	}
	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, L"&Поток 2");
	{
		AppendMenu(hPopupMenu2, MF_STRING, 1003, L"Включить");
		AppendMenu(hPopupMenu2, MF_STRING, 1004, L"Выключить");
	}
	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu3, L"&Поток 3");
	{
		AppendMenu(hPopupMenu3, MF_STRING, 1005, L"Включить");
		AppendMenu(hPopupMenu3, MF_STRING, 1006, L"Выключить");
	}
	SetMenu(hWnd, MainMenu);

	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
}

HANDLE hThread1;
HANDLE hThread2;
HANDLE hThread3;
DWORD WINAPI Thread1(LPVOID t);
DWORD WINAPI Thread2(LPVOID t);
DWORD WINAPI Thread3(LPVOID t);

int a = 0;
BOOL fin1 = true;
BOOL fin2 = true;
BOOL fin3 = true;


// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)		 // Обработчик сообщений
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break; 			// Завершение программы 
	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);

	case WM_SIZE:
	{
		RECT rc;
		GetClientRect(hWnd, &rc);
		hight = rc.bottom;
		widht = rc.right;
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case 1001:
		{
			fin1 = true;
			hThread1 = CreateThread(NULL, 0, Thread1, hWnd, 0, NULL);
			break;
		}
		case 1002:
		{
			TerminateThread(hThread1, 0);
			CloseHandle(hThread1);
			fin1 = FALSE;
			break;
		}
		case 1003:
		{
			fin2 = TRUE;
			hThread2 = CreateThread(NULL, 0, Thread2, hWnd, 0, NULL);
			break;
		}
		case 1004:
		{
			TerminateThread(hThread2, 0);
			CloseHandle(hThread2);
			fin2 = FALSE;
			break;
		}
		case 1005:
		{
			fin3 = TRUE;
			hThread3 = CreateThread(NULL, 0, Thread3, hWnd, 0, NULL);
			break;
		}
		case 1006:
		{
			TerminateThread(hThread3, 0);
			CloseHandle(hThread3);
			fin3 = FALSE;
			break;
		}
		}
	}
	return 0;
}

DWORD WINAPI Thread1(LPVOID t)
{
	RECT rect;
	int f = 0;
	int g = 0;
	int d = 0;
	int k = 0;
	int h = 0;
	while (fin1)
	{
		GetWindowRect(HWND(t), &rect);
		HDC hdc = GetDC(HWND(t));
		HBRUSH hBrush;
		hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		//hBrush = CreateSolidBrush(RGB(200, 200, 200));

		SelectObject(hdc, hBrush);

		if (f == 0)
		{

			Ellipse(hdc, 50, 50, 250, 250);
			Sleep(3000);
			InvalidateRect(HWND(t), 0, TRUE);
			Sleep(100);
			f = 1;
			if (i != 0)
				i++;
		}
		if (f == 1)
		{

			Ellipse(hdc, 450, 50, 700, 300);
			Sleep(3000);
			InvalidateRect(HWND(t), 0, TRUE);
			Sleep(100);
			f = 0;
			i++;
		}
	}
	return (0);


}

DWORD WINAPI Thread2(LPVOID t)
{
	GetWindowRect(HWND(t), &rect);
	HDC hdc = GetDC(HWND(t));
	SetTextColor(hdc, RGB(255, 0, 0));
	SetTextAlign(hdc, TA_BOTTOM);
	SYSTEMTIME lpSystemTime;
	LOGFONT lgf;
	HFONT fn;
	memset(&lgf, 0, sizeof(LOGFONT));
	lgf.lfHeight = 72;
	StrCpy(lgf.lfFaceName, _T("OCR A Extended"));
	fn = CreateFontIndirect(&lgf);
	SelectObject(hdc, fn);
	while (fin2) {
		GetLocalTime(&lpSystemTime);
		wstring a = to_wstring(lpSystemTime.wHour) + L":" + to_wstring(lpSystemTime.wMinute) + L":" + to_wstring(lpSystemTime.wSecond);
		TextOutW(hdc, widht / 2 - 160, hight - (hight / 4), a.c_str(), 8);
		time = a;
		Sleep(10);
	}
	return 0;
}

DWORD WINAPI Thread3(LPVOID t)
{
	GetWindowRect(HWND(t), &rect);
	HDC hdc = GetDC(HWND(t));
	fstream write;
	write.open("C:\\winapi\\stats.txt");

	while (fin3)
	{
		write << "Колво изменений: " << i << endl;
		string s2(time.begin(), time.end());
		write << s2 << endl;
		Sleep(15000);

	}
	return 0;
}