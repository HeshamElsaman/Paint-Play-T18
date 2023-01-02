#include "Square.h"

Square::Square(Point P1, Point P2,/*Point P3,*/ GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	com.x = 0.5 * (Corner1.x + Corner2.x);
	com.y = 0.5 * (Corner1.y + Corner2.y);
}

Square::~Square()
{}

void Square::Save(ofstream& OutFile) // the file name is Outfile
{
	OutFile << "SQR" << "  "
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

void Square::Draw(GUI* pUI) const
{
	//Call Output::Drawcircle to draw a line on the screen	
	pUI->DrawSquare(Corner1, Corner2, /*Corner3,*/ ShpGfxInfo);

}
bool Square::isInside(int X, int Y)
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

void Square::Rotate()
{
	Point gen;
	gen = Corner1;
	Corner1.x = cos(2 * atan(1)) * (gen.x - com.x) - sin(2 * atan(1)) * (gen.y - com.y) + com.x;
	Corner1.y = sin(2 * atan(1)) * (gen.x - com.x) + cos(2 * atan(1)) * (gen.y - com.y) + com.y;
	gen = Corner2;
	Corner2.x = cos(2 * atan(1)) * (gen.x - com.x) - sin(2 * atan(1)) * (gen.y - com.y) + com.x;
	Corner2.y = sin(2 * atan(1)) * (gen.x - com.x) + cos(2 * atan(1)) * (gen.y - com.y) + com.y;
}


void Square::setCorners(vector <Point> pts)
{
	Corner1 = pts[0];
	Corner2 = pts[1];
}
void Square::getCorners(vector <Point>& pts)
{
	pts.push_back(Corner1);
	pts.push_back(Corner2);
}