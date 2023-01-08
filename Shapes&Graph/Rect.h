#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	Point com;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	virtual void Drawdouble(GUI* pUI) const;
	bool isInside(int X, int Y);
	void Rotate(double) override;
	void Move(int, int) override;
	void Resize(double) override;
	void ToOnePixel() override;
	shape* getCopy();
	void Paste(int, int) ;
	void setCorners(vector <Point>) override;
	void getCorners(vector <Point>&) override;
	void setCom(Point);
	Point getCom();
	//Point GetCenter(GUI*);
	vector <Point*> GetPoints()const;
	void Hide(GUI*) /*override*/;
	void UnHide(GUI*);
	//void UnHide(GUI* pUI) /*override*/;
	//void Duplicate(GUI* pUI)/*override*/;
};

