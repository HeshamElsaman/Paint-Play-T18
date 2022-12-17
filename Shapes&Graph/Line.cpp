#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Line::~Line()
{}

void Line::Save(ofstream& OutFile)
{

	OutFile << "Line" << "  "
		<< this->ID << "  "
		<< this->Corner1.x << "  "
		<< this->Corner1.y << "  "
		<< this->Corner2.x << "  "
		<< this->Corner2.y << "   "
		<< (int)this->ShpGfxInfo.DrawClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucGreen << "  "
		<< "No fill color" << "  "
		<< (int)this->ShpGfxInfo.BorderWdth << "  "
		<<this->IsDeleted() << "  " << endl;
}


void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo);
}
bool Line::isInside(int X, int Y)
{
	double m = double((Corner2.y - Corner1.y)) / (Corner2.x - Corner1.x);
	double b = Corner2.y - m * Corner2.x;
	int Xmin = (Corner1.x <= Corner2.x) ? Corner1.x : Corner2.x;
	int Ymin= (Corner1.y <= Corner2.y) ? Corner1.y : Corner2.y;
	int Xmax=(Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int Ymax= (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	if (X >= Xmin && X <= Xmax && Y<=Ymax && Y>=Ymin)
	{
		if (Y <= m * X + b + (ShpGfxInfo.BorderWdth)+10 && Y >= m * X + b - (ShpGfxInfo.BorderWdth)-10)
			return true;
		return false;
	}
	return false;
}