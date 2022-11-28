#pragma once

#include "shape.h"

class PolyGon : public shape
{
private:
	int VertNum;
	Point* Verts = nullptr;
public:
	PolyGon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~PolyGon();
	virtual void Draw(GUI* pUI) const;
};

