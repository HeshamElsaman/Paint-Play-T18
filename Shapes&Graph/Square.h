#pragma once

#include "shape.h"

class Square : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	Point com;
public:
	
	Square(Point P1, Point P2, /*Point P3,*/ GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y);
	void Rotate(double) override;
	void Move(int, int) override;
	shape* getCopy();
	void Paste(int, int) ;
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
};

