#pragma once

#include "shape.h"

class PolyGon : public shape
{
private:
	int VertNum;
	Point* Verts = nullptr;
	Point com;
public:
	PolyGon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~PolyGon();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y) ;
	double polyGonArea();
	void Rotate(double) override;
	void Resize(double) override;
	void Move(int, int) override;
	void ToOnePixel() override;
	shape* getCopy();
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
};

