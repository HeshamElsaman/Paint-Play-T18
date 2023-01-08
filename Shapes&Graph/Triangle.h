#pragma once

#include "shape.h"

class Triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Point com;
public:

	Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int x, int y) ;
	void Rotate(double) override;
	void Move(int, int) override;
	shape* getCopy();
	void Paste(int,int);
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
};
