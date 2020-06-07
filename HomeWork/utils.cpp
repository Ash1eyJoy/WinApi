#include "utils.h"
#include <sstream>
#include <tchar.h>
using namespace std;

    BOOL RegClass(WNDPROC wndProc, HINSTANCE hI, LPCTSTR winName, UINT backgroundColor) {
        WNDCLASS wc;

        wc.hInstance = hI;
        wc.lpszClassName = winName;
        wc.lpfnWndProc = wndProc;
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.lpszMenuName = NULL;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hbrBackground = CreateSolidBrush(backgroundColor);

        if (!RegisterClass(&wc)) return false;
        return true;
}

    array<int, 4> GetAxesLimits(array<HWND, 4> hWndEdit) {
        array<int, 4> params = array<int, 4>();
        TCHAR tmp[8];
        for (int i = 0; i < 4; i++) {
            GetWindowText(hWndEdit[i], (LPWSTR)tmp, 8);
            params[i] = _ttoi(tmp);
        }
        return params;
}

BOOL CheckCorrectParams(array<int, 4> params) {
    if (params[0] >= params[1] || params[2] >= params[3]) return false;
    return true;
}

HWND CreateEdit(int ID, HWND parent, int initValue, int xIndent, int yIndent) {
    std::wstring initValueStr = std::to_wstring(initValue);
    return CreateWindowEx(WS_EX_STATICEDGE,
                          L"Edit",
                          initValueStr.c_str(),
                          WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE,
                          xIndent,
                          yIndent,
                          EDIT_WIDTH,
                          EDIT_HEIGHT,
                          parent,
                          (HMENU)ID,
                          (HINSTANCE)GetWindowLong(parent, GWL_HINSTANCE),
                          NULL);
}

HWND CreateLabel(HWND parent, std::wstring initValue, int xIndent, int yIndent, int width) {
    return CreateWindow(TEXT("STATIC"),
                        initValue.c_str(),
                        WS_VISIBLE | WS_CHILD,
                        xIndent,
                        yIndent,
                        width,
                        EDIT_HEIGHT, 
                        parent,
                        (HMENU)LABEL_ID,
                        (HINSTANCE)GetWindowLong(parent, GWL_HINSTANCE),
                        NULL);
}

void DrawCoord(HDC hDeviceContext, RECT rectPlace, float xDivisionValue, float yDivisionValue, Centre centr, HWND parent,
    array<int, 4> params) {
    HPEN pen = CreatePen(PS_SOLID, 2, BLACK);
    SelectObject(hDeviceContext, pen);
    MoveToEx(hDeviceContext, 0, centr.y, NULL);
    LineTo(hDeviceContext, rectPlace.right, centr.y);
    MoveToEx(hDeviceContext, centr.x, 0, NULL);
    LineTo(hDeviceContext, centr.x, rectPlace.bottom);

    pen = CreatePen(PS_SOLID, 1, RGB(0, 150, 150));
    SelectObject(hDeviceContext, pen);

    for (int i = 0; i <= AXES_DIVISOR_VALUE; i++) {
        MoveToEx(hDeviceContext, AWAY_FROM_EDGE + i * (rectPlace.right - AWAY_FROM_EDGE * 2) / AXES_DIVISOR_VALUE,
            AWAY_FROM_EDGE, NULL);
        LineTo(hDeviceContext, AWAY_FROM_EDGE + i * (rectPlace.right - AWAY_FROM_EDGE * 2) / AXES_DIVISOR_VALUE,
            rectPlace.bottom - AWAY_FROM_EDGE);
        wstring s = to_wstring(floor((params[0] + xDivisionValue * i) * 100) / 100);
        if (i == 0 || i == AXES_DIVISOR_VALUE) CreateLabel(parent, s, 15 + i * (rectPlace.right - AWAY_FROM_EDGE * 2) /
            AXES_DIVISOR_VALUE, centr.y - AWAY_FROM_EDGE, 30);
    }

    for (int i = 0; i <= AXES_DIVISOR_VALUE; i++) {
        if (i == AXES_DIVISOR_VALUE / 2) i++;
        MoveToEx(hDeviceContext, AWAY_FROM_EDGE, AWAY_FROM_EDGE + i * (rectPlace.bottom - AWAY_FROM_EDGE * 2) /
            AXES_DIVISOR_VALUE, NULL);
        LineTo(hDeviceContext, rectPlace.right - AWAY_FROM_EDGE, AWAY_FROM_EDGE + i * (rectPlace.bottom - AWAY_FROM_EDGE * 2) /
            AXES_DIVISOR_VALUE);
        wstring s = to_wstring(floor((params[3] - yDivisionValue * i) * 100) / 100);
        if (i == 0 || i == AXES_DIVISOR_VALUE) CreateLabel(parent, s, centr.x, AWAY_FROM_EDGE + i * (rectPlace.bottom -
            AWAY_FROM_EDGE * 2) / AXES_DIVISOR_VALUE, 30);
        }
}

void DrawGraph(HDC hDeviceContext, RECT rectPlace, float xDivisionValue, float yDivisionValue, Centre centr,
    array<int, 4> params) {
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    SelectObject(hDeviceContext, pen);
    float xValuePerPixel = abs(xDivisionValue / ((rectPlace.right - AWAY_FROM_EDGE * 2) / AXES_DIVISOR_VALUE));
    float yValuePerPixel = abs(yDivisionValue / ((rectPlace.bottom - AWAY_FROM_EDGE * 2) / AXES_DIVISOR_VALUE));
    int xCoord = centr.x + (0 - centr.xValue) / xValuePerPixel + params[0] / xValuePerPixel;
    int yCoord = centr.y - (0 - centr.yValue) / yValuePerPixel - FORMULA(params[0]) / yValuePerPixel;
    MoveToEx(hDeviceContext, xCoord, yCoord, NULL);

    for (double i = params[0]; i <= params[1]; i += xValuePerPixel) {
        double res = FORMULA(i);
        int xCoord = centr.x + (0 - centr.xValue) / xValuePerPixel + i / xValuePerPixel;
        int yCoord = centr.y - (0 - centr.yValue) / yValuePerPixel - res / yValuePerPixel;
        if (xCoord >= 0 && xCoord <= rectPlace.right && yCoord >= 0 && yCoord <= rectPlace.bottom)
            LineTo(hDeviceContext, xCoord, yCoord);
        MoveToEx(hDeviceContext, xCoord, yCoord, NULL);
        }
}