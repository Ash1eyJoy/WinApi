//// WindowsProject4.cpp : Определяет точку входа для приложения.
////
//
//#include "framework.h"
//#include "WindowsProject4.h"
//
//#define MAX_LOADSTRING 100
//
//// Глобальные переменные:
//HINSTANCE hInst;                                // текущий экземпляр
//WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
//WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
//
//// Отправить объявления функций, включенных в этот модуль кода:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//                     _In_opt_ HINSTANCE hPrevInstance,
//                     _In_ LPWSTR    lpCmdLine,
//                     _In_ int       nCmdShow)
//{
//    UNREFERENCED_PARAMETER(hPrevInstance);
//    UNREFERENCED_PARAMETER(lpCmdLine);
//
//    // TODO: Разместите код здесь.
//
//    // Инициализация глобальных строк
//    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//    LoadStringW(hInstance, IDC_WINDOWSPROJECT4, szWindowClass, MAX_LOADSTRING);
//    MyRegisterClass(hInstance);
//
//    // Выполнить инициализацию приложения:
//    if (!InitInstance (hInstance, nCmdShow))
//    {
//        return FALSE;
//    }
//
//    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT4));
//
//    MSG msg;
//
//    // Цикл основного сообщения:
//    while (GetMessage(&msg, nullptr, 0, 0))
//    {
//        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//    return (int) msg.wParam;
//}
//
//
//
////
////  ФУНКЦИЯ: MyRegisterClass()
////
////  ЦЕЛЬ: Регистрирует класс окна.
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//    WNDCLASSEXW wcex;
//
//    wcex.cbSize = sizeof(WNDCLASSEX);
//
//    wcex.style          = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc    = WndProc;
//    wcex.cbClsExtra     = 0;
//    wcex.cbWndExtra     = 0;
//    wcex.hInstance      = hInstance;
//    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT4));
//    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
//    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
//    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT4);
//    wcex.lpszClassName  = szWindowClass;
//    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}
//
////
////   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
////
////   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
////
////   КОММЕНТАРИИ:
////
////        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
////        создается и выводится главное окно программы.
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
//
//   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//   if (!hWnd)
//   {
//      return FALSE;
//   }
//
//   ShowWindow(hWnd, nCmdShow);
//   UpdateWindow(hWnd);
//
//   return TRUE;
//}
//
////
////  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
////
////  WM_COMMAND  - обработать меню приложения
////  WM_PAINT    - Отрисовка главного окна
////  WM_DESTROY  - отправить сообщение о выходе и вернуться
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_COMMAND:
//        {
//            int wmId = LOWORD(wParam);
//            // Разобрать выбор в меню:
//            switch (wmId)
//            {
//            case IDM_ABOUT:
//                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//                break;
//            case IDM_EXIT:
//                DestroyWindow(hWnd);
//                break;
//            default:
//                return DefWindowProc(hWnd, message, wParam, lParam);
//            }
//        }
//        break;
//    case WM_PAINT:
//        {
//            PAINTSTRUCT ps;
//            HDC hdc = BeginPaint(hWnd, &ps);
//            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
//            EndPaint(hWnd, &ps);
//        }
//        break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//// Обработчик сообщений для окна "О программе".
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}



//
//
//
//
//
//#define WM_SETTEXT                      0x000C
//#define ID_TIMER1   1
//
//#include <Windows.h>
//#include <Windowsx.h>
//#include<tchar.h>
//#include <atlstr.h>
//
//const int x = 1200;
//const int y = 800;
//int z = 0;
//wchar_t name[128];
//HPEN MyPen;
//HBRUSH MyBrush;
//HDC dc;
//HFONT MyFont;
//BOOL bFin = true;
//HWND hWnd;
//WNDCLASS WndClass;
//MSG Msg;
//TCHAR szClassName[] = _T("FirstWindow");
//TCHAR szTitel[] = _T("Мирсонов Лаб.4");
////CString s;
////s = _T("00:05:07");
//
//TCHAR s[20]= _T("00:05:07");
//TCHAR* cvet = (TCHAR*)TEXT("0");
//DWORD fd =( GetTickCount() / 1000);
//TCHAR* f_sec = (TCHAR*)(fd);
//HANDLE hTread2;
//HANDLE hTread1;
//
//UINT WINAPI SetTimer(HWND hwnd, UINT idTimer, UINT uTimeout, TIMERPROC tmprc);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
//{
//
//	WndClass.style = CS_HREDRAW | CS_VREDRAW ;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hInstance = hInstance;
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	WndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(120,0,120));
//	WndClass.lpszMenuName = NULL;
//	WndClass.lpszClassName = szClassName;
//
//	//HWND h = FindWindow((LPCTSTR)("SecondWindow"), (LPCTSTR)("Мирсонов Лаб.2-2"));
//
//	if (!RegisterClass(&WndClass))
//	{
//		MessageBox(NULL, _T("Cannot register class"), _T("Error"), MB_OK);
//		return 0;
//	}
//
//	hWnd = CreateWindow(szClassName, szTitel, WS_OVERLAPPEDWINDOW | WM_TIMECHANGE,10,10, x, y, NULL, NULL, hInstance, NULL);
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
//
//LONG pStr;
//DWORD WINAPI MyThread1(LPVOID param)
//{
//	z = 1;
//	pStr = (WCHAR)param;
//	return 0;
//}
//
//DWORD WINAPI MyThread2(LPVOID param)
//{
//	while (bFin) {
//		InvalidateRect(hWnd, NULL, TRUE);
//		if ((TCHAR*)param == (TCHAR*)TEXT("1"))//перекрас в синий
//		{
//			MyBrush = CreateSolidBrush(RGB(0, 0, 200));
//			MyPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 200));
//		}
//		if ((TCHAR*)param == (TCHAR*)TEXT("0"))
//		{
//			MyBrush = CreateSolidBrush(RGB(0, 200, 0));
//			MyPen = CreatePen(PS_SOLID, 4, RGB(0, 200, 0));
//		}
//		Sleep(500);
//	}
//	return 0;
//}
//
//
//void CALLBACK TimerProc(HWND hwnd, UINT Msg, UINT iTimerID, DWORD dwTimer)
//{
//	z = 1;
//	//s = _T("00:05:07");
//	//CTime t;
//	SYSTEMTIME st;
//	//if (nIDEvent == 1) // Если это таймер 1
//	//{
//	//	// ...
//	//	progr.StepIt(); // Увеличить индикатор на размер шага
//	//	t = CTime::GetCurrentTime(); // Получить текущее время
//	//	s = t.Format("%H:%M:%S"); // Преобразовать его в строку вида
//	//	// "чч:мм:сс"
//	//	t.GetAsSystemTime(st); // Заполнить структуру с данными
//	//	// даты и времени
//	//	dc.TextOutW(50, 150, L" "); // "Стереть" старый текст
//	//	// Вывести текущее значение времени
//	//	dc.TextOutW(50, 150, s);
//	//	// Если текущее значение секунд кратно 5
//	//} // end if(nIDEvent == 1)
//
//	
//}
//
//UINT WINAPI SetTimer(HWND hwnd, UINT idTimer, UINT uTimeout, TIMERPROC tmprc)
//{
//	return 0;
//}
//
////void OnTimer(UINT_PTR nIDEvent)
////{
////	// TODO: Add your message handler code here and/or call default
////	CString s;
////	int z;
////	CTime t;
////	SYSTEMTIME st;
////	if (nIDEvent == 1) // Если это таймер 1
////	{
////		// ...
////		progr.StepIt(); // Увеличить индикатор на размер шага
////		t = CTime::GetCurrentTime(); // Получить текущее время
////		s = t.Format("%H:%M:%S"); // Преобразовать его в строку вида
////		// "чч:мм:сс"
////		t.GetAsSystemTime(st); // Заполнить структуру с данными
////		// даты и времени
////		dc.TextOutW(50, 150, L" "); // "Стереть" старый текст
////		// Вывести текущее значение времени
////		dc.TextOutW(50, 150, s);
////		// Если текущее значение секунд кратно 5
////		if (st.wSecond % 5 == 0)
////		{
////			OnBnClickedButton2(); // Остановить таймер 1
////		}
////	} // end if(nIDEvent == 1)
////	CDialog::OnTimer(nIDEvent);
////}
//
//unsigned timerFiresCount;
//HWND hwndView;
//
//
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hDC;
//	PAINTSTRUCT PaintStruct;
//	RECT Rect;
//	static int left, bott;
//	bool crea = false;
//	LPWSTR szText = new TCHAR[MAX_PATH];
//	HFONT hFont;
//	LONG ii = 123456;
//	//TCHAR* str1 = (TCHAR*)TEXT(fd);
//	TCHAR* str = (TCHAR*)TEXT("");
//	SYSTEMTIME st;
//	TCHAR szT[10];
//	char tmp[3], tmpS[3];
//	POINT My_Massiv[3];
//	switch (message)
//	{
//	case WM_PAINT:
//		hDC = BeginPaint(hWnd, &PaintStruct);
//		GetClientRect(hWnd, &Rect);
//		SetTextColor(hDC, RGB(205, 133, 63));
//		SetBkColor(hDC, RGB(255, 255, 255));
//		TextOutA(hDC, 50, 200, (LPCSTR)ii, -1);
//		/*if (hTread2)
//		{
//			My_Massiv[0].x = Rect.right - 300; My_Massiv[0].y = Rect.top + 120;
//			My_Massiv[1].x = Rect.right - 100; My_Massiv[1].y = Rect.top + 500;
//			My_Massiv[2].x = Rect.right - 500; My_Massiv[2].y = Rect.top + 500;
//			SelectPen(hDC, MyPen);
//			SelectBrush(hDC, MyBrush);
//			Polygon(hDC, My_Massiv, 3);
//			if (cvet == (TCHAR*)TEXT("0"))
//			{
//				cvet = (TCHAR*)TEXT("1");
//			}
//			else
//				cvet = (TCHAR*)TEXT("0");
//			//DeleteObject(MyThread2);
//		}
//		if (hTread1)
//		{
//			if (z == 1)
//			{
//				SetTextColor(hDC, RGB(rand() % 255 + 0, rand() % 255 + 0, rand() % 255 + 0));
//				SetBkColor(hDC, RGB(255, 255, 255));
//				hFont = CreateFont(0, 0, 0, 0, 0, 0, 0, 0,
//					DEFAULT_CHARSET,
//					0, 0, 0, 0,
//					L"Arial Bold");
//				SelectObject(hDC, hFont);
//				TextOutA(hDC, 50, 200, (LPCSTR)pStr, -1);
//			}
//		}
//		//if (MyThread) {                 //Только если есть поток
//			/*GetLocalTime(&st);
//			_itoa_s(st.wMinute, tmp, 10);
//			strcat_s(tmp, ":");
//			_itoa_s(st.wSecond, tmpS, 10);
//			strcat_s(tmp, tmpS);*/
//			//_tcscpy(szT, tmp);
//			//TextOut(hdc, 80, 5, (LPWSTR)tmp, strlen((LPCSTR)szT));
//			/*TextOut(hdc, 10, 50, pStr, _tcslen(pStr));*/
//		EndPaint(hWnd, &PaintStruct);
//		break;
//	case WM_CREATE:
//		//SetTimer(hWnd, ID_TIMER1, 1000, (TIMERPROC)TimerProc);
//		//CreateThread(NULL, 0, MyThread, str, 0, NULL);
//
//		break;
//	case WM_LBUTTONDOWN:
//		bFin = true;
//
//		hTread1 = CreateThread(NULL, 0, MyThread1, (LPVOID)fd, 0, NULL);
//		hTread2 = CreateThread(NULL, 0, MyThread2, cvet, 0, NULL);
//		InvalidateRect(hWnd, NULL, FALSE);
//		break;
//	case WM_RBUTTONDOWN:
//	//	MyBrush = CreateSolidBrush(RGB(0, 200, 0));
//	//	MyPen = CreatePen(PS_SOLID, 4, RGB(0, 200, 0));
//	//	InvalidateRect(hWnd, NULL, FALSE);
//		break;
//	case WM_TIMER:
//		if (wParam == ID_TIMER1)
//			InvalidateRect(hWnd, NULL, TRUE);
//		break;
//
//	case WM_DESTROY:
//		bFin = false;
//		KillTimer(hWnd, ID_TIMER1);
//		PostQuitMessage(0);
//		break;
//	default: return DefWindowProc(hWnd, message, wParam, lParam);
//		}
//		return 0;
//	}