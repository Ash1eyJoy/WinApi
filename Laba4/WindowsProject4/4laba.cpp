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
//int WINAPI _tWinMain(HINSTANCE This,		 // ���������� �������� ���������� 
//	HINSTANCE Prev, 	// � ����������� �������� ������ 0 
//	LPTSTR cmd, 		// ��������� ������ 
//	int mode) 		// ����� ����������� ����
//{
//	// ���������� �������� ���� ��������� 
//	MSG msg; 		// ��������� ��� �������� ��������� 
//	WNDCLASS wc; 	// ����� ����
//	// ����������� ������ ���� 
//	wc.hInstance = This;
//	wc.lpszClassName = WinName; 				// ��� ������ ���� 
//	wc.lpfnWndProc = WndProc; 					// ������� ���� 
//	wc.style = CS_HREDRAW | CS_VREDRAW; 			// ����� ���� 
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// ����������� ������ 
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// ����������� ������ 
//	wc.lpszMenuName = NULL; 					// ��� ���� 
//	wc.cbClsExtra = 0; 						// ��� �������������� ������ ������ 
//	wc.cbWndExtra = 0; 						// ��� �������������� ������ ���� 
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// ���������� ���� ����� ������ 
//
//
//	// ����������� ������ ����
//	if (!RegisterClass(&wc)) return 0;
//
//	// �������� ���� 
//	hWnd = CreateWindow(WinName,			// ��� ������ ���� 
//		_T("4"), 		// ��������� ���� 
//		WS_OVERLAPPEDWINDOW, 		// ����� ���� 
//		CW_USEDEFAULT,				// x 
//		CW_USEDEFAULT, 				// y	 ������� ���� 
//		CW_USEDEFAULT, 				// width 
//		CW_USEDEFAULT, 				// Height 
//		HWND_DESKTOP, 				// ���������� ������������� ���� 
//		NULL, 						// ��� ���� 
//		This, 						// ���������� ���������� 
//		NULL); 					// �������������� ���������� ��� 
//
//	ShowWindow(hWnd, mode); 				// �������� ����
//
//	//HMENU WINAPI a;
//	HMENU MainMenu = CreateMenu();
//	HMENU hPopupMenu = CreatePopupMenu();
//	HMENU hPopupMenu2 = CreatePopupMenu();
//	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu, L"&����� 1");
//	{
//		AppendMenu(hPopupMenu, MF_STRING, 1001, L"��������");
//		AppendMenu(hPopupMenu, MF_STRING, 1002, L"���������");
//	}
//	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, L"&����� 2");
//	{
//		AppendMenu(hPopupMenu2, MF_STRING, 1003, L"��������");
//		AppendMenu(hPopupMenu2, MF_STRING, 1004, L"���������");
//	}
//	SetMenu(hWnd, MainMenu);
//
//	// ���� ��������� ��������� 
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg); 		// ������� ���������� ����� ������� ������� 
//		DispatchMessage(&msg); 		// �������� ��������� ������� WndProc() 
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
//// ������� ������� ���������� ������������ ��������
//// � �������� ��������� �� ������� ��� ������� ����������
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
//	switch (message)		 // ���������� ���������
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 			// ���������� ��������� 
//	default: 			// ��������� ��������� �� ��������� 
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