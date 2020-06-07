//#include <windows.h>
//#include <windowsx.h>
//#include <tchar.h>
//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <xstring>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")
//#include <wchar.h>
//#define DIV 1024
//#define WIDTH 7
////#pragma warning(disable:4996)
////long start = 0;
//long current = 0;
//int start, end;
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//WCHAR szBuff[15];
//TCHAR WinName[] = _T("MainFrame");
//HWND hWnd;
//int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
//	HINSTANCE Prev, 	// В современных системах всегда 0 
//	LPTSTR cmd, 		// Командная строка 
//	int mode) 		// Режим отображения окна
//{
//	// Дескриптор главного окна программы 
//	MSG msg; 		// Структура для хранения сообщения 
//	WNDCLASS wc; 	// Класс окна
//	// Определение класса окна 
//	wc.hInstance = This;
//	wc.lpszClassName = WinName; 				// Имя класса окна 
//	wc.lpfnWndProc = WndProc; 					// Функция окна 
//	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
//	wc.lpszMenuName = NULL; 					// Нет меню 
//	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
//	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 
//
//
//	// Регистрация класса окна
//	if (!RegisterClass(&wc)) return 0;
//
//	// Создание окна 
//	hWnd = CreateWindow(WinName,			// Имя класса окна 
//		_T("4"), 		// Заголовок окна 
//		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
//		CW_USEDEFAULT,				// x 
//		CW_USEDEFAULT, 				// y	 Размеры окна 
//		CW_USEDEFAULT, 				// width 
//		CW_USEDEFAULT, 				// Height 
//		HWND_DESKTOP, 				// Дескриптор родительского окна 
//		NULL, 						// Нет меню 
//		This, 						// Дескриптор приложения 
//		NULL); 					// Дополнительной информации нет 
//
//	ShowWindow(hWnd, mode); 				// Показать окно
//
//	//HMENU WINAPI a;
//	HMENU MainMenu = CreateMenu();
//	HMENU hPopupMenu = CreatePopupMenu();
//	HMENU hPopupMenu2 = CreatePopupMenu();
//	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu, L"&Поток 1");
//	{
//		AppendMenu(hPopupMenu, MF_STRING, 1001, L"Включить");
//		AppendMenu(hPopupMenu, MF_STRING, 1002, L"Выключить");
//	}
//	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, L"&Поток 2");
//	{
//		AppendMenu(hPopupMenu2, MF_STRING, 1003, L"Включить");
//		AppendMenu(hPopupMenu2, MF_STRING, 1004, L"Выключить");
//	}
//	SetMenu(hWnd, MainMenu);
//
//	// Цикл обработки сообщений 
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
//		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
//	}
//	return 0;
//}
//HANDLE hThread1;
//HANDLE hThread2;
//DWORD WINAPI Thread1(LPVOID t);
//DWORD WINAPI Thread2(LPVOID t);
//
//int a = 0;
//BOOL fin1 = true;
//BOOL fin2 = true;
//
//// Оконная функция вызывается операционной системой
//// и получает сообщения из очереди для данного приложения
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	
//		PAINTSTRUCT ps;
//	HDC hdc;
//	RECT Rect;
//	WCHAR szBuff[15];
//	WCHAR szBuff1[1];
//	POINT My_Massiv[3];
//	HFONT hFont;
//	INT lengthOfSec = 0;
//	INT i = 0;
//	INT l = 0;
//	INT k = 0;
//	static int a = 0;
//	
//	switch (message)		 // Обработчик сообщений
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 			// Завершение программы 
//	default: 			// Обработка сообщения по умолчанию 
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	case WM_COMMAND:
//		switch (wParam)
//		{
//		case 1001:
//		{
//			fin1 = true;
//			hThread1 = CreateThread(NULL, 0, Thread1, hWnd, 0, NULL);
//			break;
//		}
//		case 1002:
//		{
//			TerminateThread(hThread1, 0);
//			CloseHandle(hThread1);
//			fin1 = FALSE;
//			break;
//		}
//		case 1003:
//		{
//			fin2 = TRUE;
//			hThread2 = CreateThread(NULL, 0, Thread2, hWnd, 0, NULL);
//			break;
//		}
//		case 1004:
//		{
//			TerminateThread(hThread2, 0);
//			CloseHandle(hThread2);
//			fin2 = FALSE;
//			break;
//		}
//		}
//	}
//	return 0;
//}
//
//DWORD WINAPI Thread1(LPVOID t)
//{
//	RECT rect;
//	int f = 0;
//	int g = 0;
//	int d = 0;
//	int k = 0;
//	int h = 0;
//	while (fin1)
//	{
//		GetWindowRect(HWND(t), &rect);
//		HDC hdc = GetDC(HWND(t));
//		HBRUSH hBrush;
//		//hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
//		hBrush = CreateSolidBrush(RGB(200, 200, 200));
//
//		SelectObject(hdc, hBrush);
//	
//		//Ellipse(hdc, 50, 50, 250, 250);
//		//Sleep(2000);
//		//InvalidateRect(hWnd, NULL, TRUE);
//		if (f == 0)
//		{
//			
//			Pie(hdc, 50, 50, 250, 250, 125, 125, 250, 250);
//			Sleep(3000);
//			InvalidateRect(HWND(t), 0, TRUE);
//			Sleep(100);
//			f = 1;
//		}
//		if (f == 1)
//		{
//			
//			Pie(hdc, 270, 270, 330, 330, 250, 250, 350, 350);
//			Sleep(3000);
//            InvalidateRect(HWND(t), 0, TRUE);
//			Sleep(100);
//			f = 0;
//		}
//	}
//	return (0);
//
//
//}
//
//DWORD WINAPI Thread2(LPVOID t)
//{
//	{
//		CRITICAL_SECTION flag;
//	EnterCriticalSection(&flag);
//	end = timeGetTime();
//	HDC h = GetDC(hWnd);
//
//	WCHAR  hah[12];
//	wsprintf(hah, TEXT("vaue = %d"), end - start);
//	TextOut(h, 10, 300, hah, 12);
//
//	//DeleteObject(hPen);
//	LeaveCriticalSection(&flag);
//
//	TerminateThread(Thread2, NULL);
//
//	return 0;
//
//	}
//		
//
//	
//	return 0;
//}