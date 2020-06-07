//#include <windows.h>
//#include <windowsx.h>
//#include <tchar.h>
//#define ID_TIMER2   2
//
//const int x = 1200;
//const int y = 800;
//static int a = 0;
//HWND hWnd;
//DWORD WINAPI Thread1(LPVOID t);
//DWORD WINAPI Thread2(LPVOID t);
//HANDLE hThread1, EventThread1;
//HANDLE hThread2, EventThread21, EventThread22;
//BOOL bFin = true;
//TCHAR szClassName[] = _T("FirstWindow");
//TCHAR szTitel[] = _T("Мирсонов Лаб.4");
//WNDCLASS WndClass;
//MSG Msg;
//HDC hdc = 0;
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//HPEN MyPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 200));
//HBRUSH MyBrush = CreateSolidBrush(RGB(0, 0, 200));
//DWORD fd;
//INT cvet = 0;
////INT fff = 1;
//INT z = 0;
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
//{
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hInstance = hInstance;
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	WndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(250, 200, 250));
//	WndClass.lpszMenuName = NULL;
//	WndClass.lpszClassName = szClassName;
//
//	if (!RegisterClass(&WndClass))
//	{
//		MessageBox(NULL, _T("Cannot register class"), _T("Error"), MB_OK);
//		return 0;
//	}
//
//	hWnd = CreateWindow(szClassName, szTitel, WS_OVERLAPPEDWINDOW, 10, 10, x, y, NULL, NULL, hInstance, NULL);
//
//	if (!hWnd)
//	{
//		MessageBox(NULL, _T("Cannot create window"), _T("Error"), MB_OK);
//		return 0;
//	}
//
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	while (GetMessage(&Msg, NULL, 0, 0))
//	{
//		DispatchMessage(&Msg);
//	}
//	return Msg.wParam;
//}
//
//DWORD WINAPI Thread1(LPVOID t)
//{
//	int k = 0;
//	while (1)
//	{
//		WaitForSingleObject(EventThread1, INFINITE);
//
//
//		if (hThread1 && z == 0)//вывод количества секунд, прошедших с запуска системы
//		{
//			fd = (GetTickCount() / 1000);//////////////!!!!!!!!!!!!!!!!!!!!!!!!
//			wsprintf(szBuff, L"%d", fd);
//			while (szBuff[i] != NULL)
//			{
//				lengthOfSec++;
//				i++;
//			}
//			while (k < 50 * lengthOfSec && k != -1)//вывод цифр разными цветами
//			{
//				if (l == 0)
//					SetTextColor(hdc, RGB(255, 0, 0));
//				else if (l == 1)
//					SetTextColor(hdc, RGB(255, 165, 0));
//				else if (l == 2)
//					SetTextColor(hdc, RGB(0, 255, 0));
//				else if (l == 3)
//					SetTextColor(hdc, RGB(0, 165, 255));
//				else if (l == 4)
//					SetTextColor(hdc, RGB(128, 0, 128));
//				else SetTextColor(hdc, RGB(rand() % 255 + 0, rand() % 255 + 0, rand() % 255 + 0));
//				szBuff1[0] = szBuff[l];
//				TextOut(hdc, Rect.left + 50 + k, Rect.top + 300, szBuff1, 1);
//				k = k + 50;
//				l++;
//				if (k == 50 * lengthOfSec) k = -1;
//			}
//		}
//
//		if (hdc)
//		{
//			if (a == 1)
//			{
//				HBRUSH hBrush9;
//				hBrush9 = CreateSolidBrush(RGB(220, 0, 0));
//				SelectObject(hdc, hBrush9);
//				Ellipse(hdc, rand() % 400 + 0, rand() % 500 + 0, rand() % 400 + 0, rand() % 500 + 0);
//				InvalidateRect(hWnd, NULL, FALSE);
//			}
//			if (a == 2)
//			{
//				HBRUSH hBrush9;
//				hBrush9 = CreateSolidBrush(RGB(220, 0, 0));
//				SelectObject(hdc, hBrush9);
//				Ellipse(hdc, rand() % 400 + 0, rand() % 500 + 0, rand() % 400 + 0, rand() % 500 + 0);
//				InvalidateRect(hWnd, NULL, FALSE);
//				a = 0;
//			}
//
//		}
//
//		SetEvent(EventThread21);
//	}
//}
//
//DWORD WINAPI Thread2(LPVOID t)
//{
//	while (1)
//	{
//		WaitForSingleObject(EventThread21, INFINITE);
//
//		if (hdc)
//		{
//			HBRUSH hBrush9;
//			hBrush9 = CreateSolidBrush(RGB(220, 0, 0));
//			SelectObject(hdc, hBrush9);
//			Ellipse(hdc, 500, 500, 500, 500);
//			InvalidateRect(hWnd, NULL, FALSE);
//		}
//
//		SetEvent(EventThread22);
//	}
//}
//
//
//
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
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
//	switch (message)
//	{
//	case WM_CREATE:
//		SetTimer(hWnd, ID_TIMER2, 2000, NULL);
//		//	hThread1 = CreateThread(NULL, 0, Thread1, NULL, 0, &idThread);
//	case WM_TIMER:
//		if (wParam == ID_TIMER2)
//		{
//			InvalidateRect(hWnd, NULL, TRUE);
//			z = 1;
//		}
//		break;
//	case WM_LBUTTONDOWN://приостановка потоков
////SuspendThread(hThread1);
////SetTimer(hWnd, ID_TIMER2, INFINITE, NULL);
//
//		a++;
//		InvalidateRect(hWnd, NULL, false);
//		//GetClientRect(hWnd, &Rect);
//		//FillRect(hdc, &Rect, (HBRUSH)CreateSolidBrush(RGB(190, 0, 190)));
//		//ReleaseDC(hWnd, hdc);
//		//MessageBox(hWnd, TEXT("Потоки приостановлены!!!\nВозобновить по нажатию правой кнопки мыши"), TEXT("Остановка потоков"), MB_ICONINFORMATION);
//		break;
//	case WM_RBUTTONDOWN://возобновление работы потоков
//		ResumeThread(hThread1);
//		SetTimer(hWnd, ID_TIMER2, 2000, NULL);
//		MessageBox(hWnd, TEXT("Потоки снова запущены!!!"), TEXT("Возобновление работы потоков"), MB_ICONINFORMATION);
//		break;
//	case WM_PAINT:
//	{
//		SetEvent(EventThread1);
//		WaitForSingleObject(EventThread22, INFINITE);
//
//		PAINTSTRUCT ps;
//		const HDC hdc1 = BeginPaint(hWnd, &ps);
//
//		//BitBlt(hdc1, 0, 0, Wx, Wy, hdc, 0, 0, SRCCOPY);
//
//		EndPaint(hWnd, &ps);
//		return TRUE;
//	}
//
//	case WM_DESTROY:
//		bFin = FALSE;
//		TerminateThread(hThread1, 0);
//		DeleteObject(hThread1);
//		PostQuitMessage(0);
//		break;
//	default: return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
//
//
//
//
// 