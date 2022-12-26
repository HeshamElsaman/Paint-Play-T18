#pragma once

#include "shape.h"

class Square : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	//Point Corner3;
public:
	
	Square(Point P1, Point P2, /*Point P3,*/ GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y);
	void Rotate() override {};
};

