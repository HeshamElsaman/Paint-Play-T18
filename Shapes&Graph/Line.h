#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	Point com;
public:
	Line(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Line();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	virtual void Drawdouble(GUI* pUI) const;
	bool isInside(int X, int Y);
	void Rotate(double) override;
	void Resize(double) override;
	void Move(int, int) override;
	shape* getCopy();
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
	void setCom(Point);
	Point getCom();
	void Hide(GUI*);
	void UnHide(GUI*);
};

