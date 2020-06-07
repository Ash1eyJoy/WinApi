#ifndef UTILS_H
#define UTILS_H

#include <Windows.h>
#include <tchar.h>
#include <sstream>
#include <string>
#include <array>

#include "Centre.h"

#define FORMULA(x) 0.1*log(x)*sin(2.5*x)*4*cos(5.5*pow(x,2))
//#define FORMULA(x) (abs(cos(x*45)*5))/pow(abs(x), 0.7)-5

#define HEIGHT              300
#define WIDTH               400
#define BUILD_BUTTON_HEIGHT  40
#define BUILD_BUTTON_WIDTH  100
#define EDIT_HEIGHT          20
#define EDIT_WIDTH           60
#define AXIS_LABEL_WIDTH    146
#define IDD_DIALOG1         101

#define BUILD_BUTTON_ID 1
#define X1_EDIT_ID      2
#define X2_EDIT_ID      3
#define Y1_EDIT_ID      4
#define Y2_EDIT_ID      5
#define LABEL_ID        6

#define FONT_SIZE          30
#define AXES_DIVISOR_VALUE 10
#define AWAY_FROM_EDGE     30

#define BLACK RGB (  0,   0,   0)
#define GREY  RGB (211, 211, 211)
#define RED   RGB (255, 255,   0)
#define WHITE RGB (255, 255, 255)

#endif

BOOL RegClass(WNDPROC, HINSTANCE, LPCTSTR, UINT);
std::array<int, 4> GetAxesLimits(std::array<HWND, 4> hWndEdit);
BOOL CheckCorrectParams(std::array<int, 4>);
HWND CreateEdit(int ID, HWND parent, int initValue, int xIndent, int yIndent);
HWND CreateLabel(HWND parent, std::wstring initValue, int xIndent, int yIndent, int width);
void DrawCoord(HDC hDeviceContext, RECT rectPlace, float xDivisionValue, float yDivisionValue, Centre centr, HWND parent, std::array<int, 4> params);
void DrawGraph(HDC hDeviceContext, RECT rectPlace, float xDivisionValue, float yDivisionValue, Centre centr, std::array<int, 4> params);
