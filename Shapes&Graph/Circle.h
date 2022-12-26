#pragma once

#include "shape.h"

class Circle : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	
	Circle(Point P1, Point P2, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y);
	void Rotate() override {}
};

