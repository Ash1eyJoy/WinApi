#pragma once

#include <array>
#include <Windows.h>

class Centre
{
public:
    int x;
    int y;
    int xValue;
    int yValue;
    Centre(std::array<int, 4> params, RECT rectPlace, float xDivisionValue, float yDivisionValue);
};

