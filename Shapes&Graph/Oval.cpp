#include "Oval.h"

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOval to draw an oval on the screen	
	pUI->DrawOval(Corner1, Corner2, ShpGfxInfo);
}
bool Oval::isInside(int X,int Y)
{
	double cent_x = (Corner1.x + Corner2.x)/2.0;
	double cent_y = (Corner1.y + Corner2.y)/2.0;
	double axis1 = (Corner1.x - Corner2.x)/2.0;
	double axis2 = (Corner1.y - Corner2.y)/2.0;
	double relation = pow((X - cent_x), 2.0) / pow(axis1, 2.0) + pow((Y - cent_y), 2.0) / pow(axis2, 2.0);
	if (relation <=1)
		return true;
	return false;
}
