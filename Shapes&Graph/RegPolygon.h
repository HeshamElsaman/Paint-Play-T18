#pragma once

#include "shape.h"

class RegPolygon : public shape
{
private:
	int VertNum;
	Point* Verts = nullptr;
	Point com;
public:
	RegPolygon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	virtual void Drawdouble(GUI* pUI) const;
	bool isInside(int X, int Y) ;
	double polygonArea();
	void Rotate(double) override;
	void Resize(double) override;
	void Move(int, int) override;
	void ToOnePixel() override;
	shape* getCopy();
	void Paste(int, int) ;
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
	void setCom(Point);
	Point getCom();
	void Hide(GUI*);
	void UnHide(GUI*);
};

