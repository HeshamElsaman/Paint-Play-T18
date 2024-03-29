#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

int shape::getID()
{
	return ID;
}

void shape::setID(int id)
{
	this->ID = id;
}

void shape::SetDeleted(bool s)
{
	ShpGfxInfo.isDeleted = s;
}

bool shape::IsDeleted() const
{
	return ShpGfxInfo.isDeleted;
}

void shape::SetFilled(bool s)
{
	ShpGfxInfo.isFilled = s;
}

bool shape::IsFilled() const
{
	return ShpGfxInfo.isFilled;
}

void shape::SetImgSticked(bool s)
{
	ShpGfxInfo.imgSticked = s;
}

bool shape::IsImgSticked() const
{
	return ShpGfxInfo.imgSticked;
}

void shape::SetImgSticked(int img_)
{
	img = img_;
}

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

color shape::GetDrawClr() const
{
	return ShpGfxInfo.DrawClr;
}

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

color shape::GetFillClr() const
{
	return ShpGfxInfo.FillClr;
}

void shape::ChngPenWidth(int c)
{
	ShpGfxInfo.BorderWdth = c;
}

int shape::GetPenWidth() const
{
	return ShpGfxInfo.BorderWdth;
}

void shape::moveFurther(const Point& cm, Point& v, double delta)
{
	double slope = double(v.y - cm.y) / (v.x - cm.x);
	if (cm.x < v.x && cm.y < v.y) {
		v.x = v.x + delta * cos(atan(slope));
		v.y = v.y + delta * sin(atan(slope));
	}
	else if (cm.x > v.x && cm.y > v.y) {
		v.x = v.x - delta * cos(atan(slope));
		v.y = v.y - delta * sin(atan(slope));
	}
	else if (cm.x < v.x && cm.y > v.y) {
		v.x = v.x + delta * cos(atan(-slope));
		v.y = v.y - delta * sin(atan(-slope));
	}
	else if (cm.x > v.x && cm.y < v.y) {
		v.x = v.x - delta * cos(atan(-slope));
		v.y = v.y + delta * sin(atan(-slope));
	}
	else if (cm.x == v.x)
	{
		if (cm.y < v.y)
		{
			v.y = v.y + delta;
		}
		else
		{
			v.y = v.y - delta;
		}
	}
	else if (cm.y == v.y)
	{
		if (cm.x < v.x)
		{
			v.x = v.x + delta;
		}
		else
		{
			v.x = v.x - delta;
		}
	}

}
