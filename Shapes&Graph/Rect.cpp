#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Save(ofstream& OutFile) // the file name is Outfile
{

	OutFile << "Rect" << "  "
		<< this->ID << "  "
		<< this->Corner1.x << "  "
		<< this->Corner1.y << "  "
		<< this->Corner2.x << "  "
		<< this->Corner2.y << "   "
		<< (int)this->ShpGfxInfo.DrawClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucGreen << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucGreen << "  "
		<< (int)this->ShpGfxInfo.BorderWdth << "  " 
		<< this->IsDeleted() << "  " << endl;
	


}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
	
	if(ShpGfxInfo.imgSticked)
	{
		int x = (Corner1.x <= Corner2.x) ? Corner1.x : Corner2.x; x += this->ShpGfxInfo.BorderWdth;
		int y = (Corner1.y <= Corner2.y) ? Corner1.y : Corner2.y; y += this->ShpGfxInfo.BorderWdth;
		int width = abs(Corner1.x - Corner2.x); width -= 2 * this->ShpGfxInfo.BorderWdth;
		int length = abs(Corner1.y - Corner2.y); length -= 2 * this->ShpGfxInfo.BorderWdth;
		pUI->StickImage(img, x, y, length, width);
	}
}
bool Rect::isInside(int X, int Y)
{
	int Xmin = (Corner1.x <= Corner2.x) ? Corner1.x : Corner2.x;
	int Ymin = (Corner1.y <= Corner2.y) ? Corner1.y : Corner2.y;
	int Xmax = (Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int Ymax = (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	if (X >= Xmin && X <= Xmax && Y <= Ymax && Y >= Ymin)
	{
		return true;
	}
	return false;
}

void Rect::Rotate()
{
	Point cent, gen;
	cent.x = 0.5 * (Corner1.x + Corner2.x);
	cent.y = 0.5 * (Corner1.y + Corner2.y);
	gen = Corner1;
	Corner1.x = cos(2 * atan(1)) * (gen.x - cent.x) - sin(2 * atan(1)) * (gen.y - cent.y) + cent.x;
	Corner1.y = sin(2 * atan(1)) * (gen.x - cent.x) + cos(2 * atan(1)) * (gen.y - cent.y) + cent.y;
	gen = Corner2;
	Corner2.x = cos(2 * atan(1)) * (gen.x - cent.x) - sin(2 * atan(1)) * (gen.y - cent.y) + cent.x;
	Corner2.y = sin(2 * atan(1)) * (gen.x - cent.x) + cos(2 * atan(1)) * (gen.y - cent.y) + cent.y;
}