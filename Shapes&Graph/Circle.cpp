#include "Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::Drawcircle to draw a line on the screen	
	pUI->Drawcircle(Corner1, Corner2, ShpGfxInfo);



}