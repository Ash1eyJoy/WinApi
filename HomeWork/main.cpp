#include <Windows.h>
#include <tchar.h>
#include <math.h>

#include "utils.h"
#include "resource.h"
#include "Centre.h"

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("Graph");
std::array<HWND, 4> hWndEdit = std::array<HWND, 4>();
std::array<int, 4> params = std::array<int, 4>();  // stores the initial values of the axis boundaries

int WINAPI _tWinMain(HINSTANCE This,
                     HINSTANCE prev,
                     LPTSTR cmd,
                     int mode)
{
    HWND hWnd;
    MSG msg;

    if (!RegClass(WndProc, This, WinName, RGB(240, 240, 240)))
        return 0;

    //Make Window
    hWnd = CreateWindow(WinName,
                        _T("Задание интервалов"),
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        WIDTH,
                        HEIGHT,
                        HWND_DESKTOP,
                        NULL,
                        This,
                        NULL);
    if (!hWnd)
        return 0;
    ShowWindow(hWnd, mode);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT paintStruct;
    RECT rectPlace;  // The area of the window to be redrawn
    static HWND hwndBuildButton;  // the button by pressing which the graph is built

    switch (message)
    {
    case WM_CREATE:
        {
            hwndBuildButton = CreateWindowEx(WS_EX_STATICEDGE,
                                             L"Button",
                                             L"Построить",
                                             WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                             WIDTH / 2 - BUILD_BUTTON_WIDTH / 2,
                                             3 * HEIGHT / 4 - BUILD_BUTTON_HEIGHT,
                                             BUILD_BUTTON_WIDTH,
                                             BUILD_BUTTON_HEIGHT,
                                             hWnd,
                                             (HMENU)BUILD_BUTTON_ID,
                                             (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
                                             NULL);
            hWndEdit[0] = CreateEdit(X1_EDIT_ID, hWnd, -10, 50 + AXIS_LABEL_WIDTH, 80);
            hWndEdit[1] = CreateEdit(X2_EDIT_ID, hWnd, 10, 50 + AXIS_LABEL_WIDTH + EDIT_WIDTH + 5, 80);
            hWndEdit[2] = CreateEdit(Y1_EDIT_ID, hWnd, -10, 50 + AXIS_LABEL_WIDTH, 120);
            hWndEdit[3] = CreateEdit(Y2_EDIT_ID, hWnd, 10, 50 + AXIS_LABEL_WIDTH + EDIT_WIDTH + 5, 120);

            CreateLabel(hWnd, L"0.1*ln(a)*sin(2.5*a)*4*cos(5.5*pow(a,2))", 40, 40, AXIS_LABEL_WIDTH);
            CreateLabel(hWnd, L"         Интервал оси X:", 40, 80, AXIS_LABEL_WIDTH);
            CreateLabel(hWnd, L"         Интервал оси Y:", 40, 120, AXIS_LABEL_WIDTH);
        }

    case WM_COMMAND:
        {
            if (LOWORD(wParam) == BUILD_BUTTON_ID) {
                params = GetAxesLimits(hWndEdit);
                if (CheckCorrectParams(params)) {
                    DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DlgProc), 0);
                } else {
                    MessageBox(hWnd, _T("Введены неверные параметры!"), _T("Ошибка"), MB_ICONERROR);
                }
            }
            break;
        }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC         hDeviceContext;
    PAINTSTRUCT paintStruct;
    RECT        rectPlace;

    switch (message) {
    case WM_PAINT: {
        hDeviceContext = BeginPaint(hWnd, &paintStruct);
        GetClientRect(hWnd, &rectPlace);

        int xAxisRange = params[1] - params[0];
        int yAxisRange = params[3] - params[2];
        float xDivisionValue = xAxisRange / static_cast<float>(AXES_DIVISOR_VALUE);
        float yDivisionValue = yAxisRange / static_cast<float>(AXES_DIVISOR_VALUE);

        Centre centr(params, rectPlace, xDivisionValue, yDivisionValue);
        DrawCoord(hDeviceContext, rectPlace, xDivisionValue, yDivisionValue, centr, hWnd, params);
        DrawGraph(hDeviceContext, rectPlace, xDivisionValue, yDivisionValue, centr, params);

        break;
    }

    case WM_CLOSE:
        EndDialog(hWnd, 0);
        return FALSE;

    default:
        break;
    }
    return FALSE;
}