#include "Centre.h"
#include "utils.h"

Centre::Centre(std::array<int, 4> params, RECT rectPlace, float xDivisionValue, float yDivisionValue) {
	xValue = 0;
	yValue = 0;
	if (params[0] <= 0 && params[1] > 0) {
		float i = (-1) * params[0] / xDivisionValue;
		x = AWAY_FROM_EDGE + i * (rectPlace.right - AWAY_FROM_EDGE * 2) / AXES_DIVISOR_VALUE;
	}
	if (params[0] <= 0 && params[1] <= 0) {
		x = rectPlace.right - AWAY_FROM_EDGE;
		xValue = params[1];
	}
	if (params[0] >= 0 && params[1] >= 0) {
		x = AWAY_FROM_EDGE;
		xValue = params[0];
	}

	if (params[2] <= 0 && params[3] > 0) {
		float i = (-1) * params[2] / yDivisionValue;
		y = AWAY_FROM_EDGE + i * (rectPlace.bottom - AWAY_FROM_EDGE * 2) / AXES_DIVISOR_VALUE;
	}
	if (params[2] <= 0 && params[3] <= 0) {
		y = AWAY_FROM_EDGE;
		yValue = params[3];
	}
	if (params[2] >= 0 && params[3] >= 0) {
		y = rectPlace.bottom - AWAY_FROM_EDGE;
		yValue = params[2];
	}
	return;
}