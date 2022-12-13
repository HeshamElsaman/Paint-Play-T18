#pragma once

#include "shape.h"

class RegPolygon : public shape
{
private:
	int VertNum;
	Point* Verts = nullptr;
public:
	RegPolygon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y) { return 0; };
};

