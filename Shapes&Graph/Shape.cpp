#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

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

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

void shape::ChngPenWidth(int c)
{
	ShpGfxInfo.BorderWdth = c;
}

