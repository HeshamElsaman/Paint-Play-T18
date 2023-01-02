#pragma once
#include "../Shapes&Graph/Shape.h"

class Oval : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point com;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y) ;
	void Rotate() override;
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
};

