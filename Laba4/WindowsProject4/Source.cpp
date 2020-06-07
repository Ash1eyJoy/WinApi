//#include <windows.h>
//#include <windowsx.h>
//#include <tchar.h>
//#include <stdio.h>
//#include <string>
//#include <wchar.h>
//#include <iostream> 
//#include <cmath>
//#define DIV 1024
//#define WIDTH 7
////#pragma warning(disable:4996)
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HDC dc;
//TCHAR WinName[] = _T("MainFrame");
//HWND hWnd;
//int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
//	HINSTANCE Prev, 	// В современных системах всегда 0 
//	LPTSTR cmd, 		// Командная строка 
//	int mode) 		// Режим отображения окна
//{
//			// Дескриптор главного окна программы 
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
//	SetTimer(hWnd, 1, USER_TIMER_MINIMUM, NULL); //частота обновления типа
//	
//	while (GetMessage(&msg, NULL, 0, 0) > 0)
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return msg.wParam;
//}
//
//
//void czCreateMenu(HWND hwnd)
//{
//	HMENU MainMenu = CreateMenu();
//	HMENU hPopupMenu1 = CreatePopupMenu();
//	HMENU hPopupMenu2 = CreatePopupMenu();
//	HMENU hPopupMenu2_1 = CreatePopupMenu();
//	HMENU hPopupMenu3 = CreatePopupMenu();
//	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu1, L"&Файл");
//	{
//		AppendMenu(hPopupMenu1, MF_STRING, 103, L"Сохранить как...");
//		AppendMenu(hPopupMenu1, MF_SEPARATOR, 0, L"");
//		AppendMenu(hPopupMenu1, MF_STRING, 104, L"Выход");
//	}
//	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, L"&Вид");
//	{
//		AppendMenu(hPopupMenu2, MF_STRING | MF_POPUP, (UINT)hPopupMenu2_1, L"&Цвет");
//		{
//			AppendMenu(hPopupMenu2_1, MF_STRING, 201, L"Черный");
//			AppendMenu(hPopupMenu2_1, MF_STRING, 202, L"Синий");
//			AppendMenu(hPopupMenu2_1, MF_STRING, 203, L"Зеленый");
//			AppendMenu(hPopupMenu2_1, MF_STRING, 204, L"Красный");
//		}
//	}
//	AppendMenu(MainMenu, MF_STRING, 300, L"&Заново");
//	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu3, L"&Помощь");
//	{
//		AppendMenu(hPopupMenu3, MF_STRING, 401, L"&Справка");
//	}
//	SetMenu(hwnd, MainMenu);
//}
//
//int Calc(HDC dc, int W, int H, double Ph)
//{
//	double NUM = 0;
//	Rectangle(dc, -1, -1, W + 1, H + 1);
//	for (int k = 1; k < 50; k = k + 2)
//	{
//		NUM += cos(k * 0.01 * Ph) * sin(k / 2) / k;
//	}
//	MoveToEx(dc, 0, H * (0.5 + 0.45 * NUM), NULL);
//	NUM = NUM * 4 / 3.14;
//	for (int i = 0; i < W; i++)
//	{
//		NUM = 0;
//		for (int k = 1; k < 50; k = k + 2)
//		{
//			NUM += cos(k * 0.02 * (Ph + i)) * sin(k / 2) / k;
//		}
//		NUM = NUM * 4 / 3.14;
//		LineTo(dc, i, H * (0.5 + 0.45 * NUM));
//	}
//	return 0;
//}
//
//
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	int wmId, wmEvent;
//	static bool Move = true;
//	static int Phase = 0, Width, Height;
//	HPEN hPen;
//	switch (message)
//	{
//	case WM_LBUTTONDOWN:
//		break;
//	case WM_RBUTTONDOWN:
//		Move = !Move;

//		break;
//	case WM_TIMER:
//		if (Move)
//			Phase++;
//		else
//			break;
//	case WM_PAINT:
//		Calc(dc, Width, Height, Phase);
//		break;
//	case WM_SIZE:
//		Width = LOWORD(lParam), Height = HIWORD(lParam);
//		break;
//	case WM_KEYDOWN:
//		if (wParam != VK_ESCAPE)
//			break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	
//	}
//	return DefWindowProc(hWnd, message, wParam, lParam);
//}
//
////void SaveScreen(HWND hWnd)
////{
////	OPENFILENAME openFile;
////	TCHAR szPath[MAX_PATH];
////	TCHAR szFile[MAX_PATH];
////	ZeroMemory(&openFile, sizeof(OPENFILENAME));
////	openFile.lStructSize = sizeof(OPENFILENAME);
////	szFile[0] = '\0';
////	openFile.hwndOwner = hWnd;
////	openFile.lpstrFile = szFile;
////	openFile.nMaxFile = sizeof(szFile) / sizeof(*szFile);
////	openFile.lpstrFilter = L"Растровое изображение (*.bmp)\0*.bmp\0";
////	openFile.lpstrDefExt = L"*.bmp";
////	if (TRUE == bFirstSave)
////	{
////
////		if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYPICTURES, NULL, 0, szPath)))
////		{
////
////			openFile.lpstrInitialDir = szPath;
////		}
////	}
////
////	if (GetSaveFileName(&openFile) == TRUE)
////	{
////
////		UpdateWindow(hWnd);
////		save(hWnd, openFile);
////		bFirstSave = FALSE;
////	}
////	else
////	{
////
////	}
////}
//
//bool save(HWND hWnd, OPENFILENAME openFile)
//{
//
//	HDC hdcScreen;
//	HDC hdcWindow;
//	HDC hdcMemDC = NULL;
//	HBITMAP hbmScreen = NULL;
//	BITMAP bmpScreen;
//	hdcScreen = GetDC(NULL);
//	hdcWindow = GetDC(hWnd);
//	hdcMemDC = CreateCompatibleDC(hdcWindow);
//	if (!hdcMemDC)
//	{
//		MessageBox(hWnd, L"CreateCompatibleDC has failed", L"Failed", MB_OK);
//		//goto done;
//	}
//
//	RECT rcClient;
//	GetClientRect(hWnd, &rcClient);
//
//	hbmScreen = CreateCompatibleBitmap(hdcWindow, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top);
//	if (!hbmScreen)
//	{
//		MessageBox(hWnd, L"CreateCompatibleBitmap Failed", L"Failed", MB_OK);
//		//goto done;
//	}
//	SelectObject(hdcMemDC, hbmScreen);
//
//	if (!BitBlt(hdcMemDC, 0, 0, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top, hdcWindow, 0, 0, SRCCOPY))
//	{
//		MessageBox(hWnd, L"BitBlt has failed", L"Failed", MB_OK);
//		//goto done;
//	}
//	GetObject(hbmScreen, sizeof(BITMAP), &bmpScreen);
//	BITMAPFILEHEADER bmfHeader;
//	BITMAPINFOHEADER bi;
//	bi.biSize = sizeof(BITMAPINFOHEADER);
//	bi.biWidth = bmpScreen.bmWidth;
//	bi.biHeight = bmpScreen.bmHeight;
//	bi.biPlanes = 1;
//	bi.biBitCount = 32;
//	bi.biCompression = BI_RGB;
//	bi.biSizeImage = 0;
//	bi.biXPelsPerMeter = 0;
//	bi.biYPelsPerMeter = 0;
//	bi.biClrUsed = 0;
//	bi.biClrImportant = 0;
//	DWORD dwBmpSize = ((bmpScreen.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmpScreen.bmHeight;
//	HANDLE hDIB = GlobalAlloc(GHND, dwBmpSize);
//	char* lpbitmap = (char*)GlobalLock(hDIB);
//	GetDIBits(hdcWindow, hbmScreen, 0, (UINT)bmpScreen.bmHeight, lpbitmap, (BITMAPINFO*)& bi, DIB_RGB_COLORS);
//	HANDLE hFile = CreateFile(openFile.lpstrFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//	DWORD dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
//	bmfHeader.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER);
//	bmfHeader.bfSize = dwSizeofDIB;
//	bmfHeader.bfType = 0x4D42;
//	DWORD dwBytesWritten = 0;
//	WriteFile(hFile, (LPSTR)& bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
//	WriteFile(hFile, (LPSTR)& bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
//	WriteFile(hFile, (LPSTR)lpbitmap, dwBmpSize, &dwBytesWritten, NULL);
//	GlobalUnlock(hDIB);
//	GlobalFree(hDIB);
//	CloseHandle(hFile);
//done:
//	DeleteObject(hbmScreen);
//	DeleteObject(hdcMemDC);
//	ReleaseDC(NULL, hdcScreen);
//	ReleaseDC(hWnd, hdcWindow);
//	return TRUE;
//}