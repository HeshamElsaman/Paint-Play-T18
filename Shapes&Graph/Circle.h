#pragma once

#include "shape.h"

class Circle : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	
	Circle(Point P1, Point P2, GfxInfo shapeGfxInfo);
	Circle() {}
	virtual ~Circle();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y);
	void Rotate(double) override {}
	void Resize(double) override;
	void Move(int, int) override;
	shape* getCopy();
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
};

