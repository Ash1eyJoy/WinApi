
#include "stdafx.h"
#include "figs.h"
#include <commctrl.h>
#include <Commdlg.h>
#include <vector>
#include <windowsx.h>

#define MAX_LOADSTRING 100


HINSTANCE hInst;								
TCHAR szTitle[MAX_LOADSTRING];					
TCHAR szWindowClass[MAX_LOADSTRING];			

HWND htextBox2, htextBox1;

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	HACCEL hAccelTable;


	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_FIGS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FIGS));

	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}




ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FIGS));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	//wcex.hbrBackground = CreateSolidBrush(RGB(153, 255, 153));
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_FIGS);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

HMENU menu1;


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; 

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   CreateWindow( L"STATIC", L"Ширина", WS_CHILD | WS_VISIBLE, 12,38,46,13, hWnd, 0,0, NULL );
    htextBox1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"50", 
        WS_CHILD | WS_VISIBLE, 74,38,90,20, hWnd, (HMENU)0, NULL, NULL);

   CreateWindow( L"STATIC", L"Высота", WS_CHILD | WS_VISIBLE, 12,64,45,13, hWnd, 0,0, NULL );
    htextBox2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"30", 
        WS_CHILD | WS_VISIBLE, 74,64,90,20, hWnd, (HMENU)0, NULL, NULL);


	menu1 = CreatePopupMenu();

	AppendMenu( menu1, 0, IDM_COLOR, L"Цвет" );

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

int mode = 0;

struct TFig
{
	int typ;
	int x, y, w, h;
};

std::vector<TFig*> figs;

COLORREF back = RGB(153,255,153);
HBRUSH backBr = CreateSolidBrush( back );


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
	
		switch (wmId)
		{
		case IDM_ELLIPSE:
			mode = 0;
			break;
		case IDM_RECT:
			mode = 1;
			break;
		case IDM_TRI:
			mode = 2;
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDM_COLOR:
			{
				DWORD dColors[3]={255,222,222};

				CHOOSECOLOR cc;
				cc.Flags=CC_RGBINIT|CC_FULLOPEN;
				cc.hInstance=NULL;
				cc.hwndOwner=hWnd;
				cc.lCustData=0L;
				cc.lpCustColors=dColors;
				cc.lpfnHook=NULL;
				cc.lpTemplateName= (LPWSTR)NULL;
				cc.lStructSize=sizeof(cc);
				cc.rgbResult=back;

				if (ChooseColor(&cc))
				{
					back = cc.rgbResult;
					backBr = CreateSolidBrush( back );
					InvalidateRect( hWnd, NULL, TRUE );
				}
			}
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			wchar_t wbuf[100];
			TFig *f = new TFig();

			f->x = GET_X_LPARAM( lParam );
			f->y = GET_Y_LPARAM( lParam );

			GetWindowText( htextBox1, wbuf, 100 );
			swscanf( wbuf, L"%d", &f->w );
			GetWindowText( htextBox2, wbuf, 100 );
			swscanf( wbuf, L"%d", &f->h );

			f->typ = mode;
			figs.push_back( f );

			InvalidateRect( hWnd, NULL, TRUE );
		}
		break;
	case WM_RBUTTONDOWN:
		{
			POINT pt;

			pt.x = GET_X_LPARAM( lParam );
			pt.y = GET_Y_LPARAM( lParam );

			ClientToScreen(hWnd, &pt);

			TrackPopupMenu( menu1, 0, pt.x, pt.y, 0, hWnd, NULL );
		}
		break;
	case WM_ERASEBKGND:
		hdc = (HDC) wParam; 
		GetClientRect(hWnd, &rc);
		FillRect( hdc, &rc, backBr );
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		for( int i = 0; i < figs.size(); i++ )
		{
			TFig *f = figs[i];

			if (f->typ == 0)
				Ellipse( hdc, f->x, f->y, f->x + f->w, f->y + f->h );
			if (f->typ == 1)
				Rectangle( hdc, f->x, f->y, f->x + f->w, f->y + f->h );
			if (f->typ == 2)
			{
				MoveToEx( hdc, f->x + f->w / 2, f->y, NULL );
				LineTo( hdc, f->x + f->w, f->y + f->h );
				LineTo( hdc, f->x, f->y + f->h );
				LineTo( hdc, f->x + f->w / 2, f->y );
			}
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
