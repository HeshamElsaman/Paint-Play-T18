#include "Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Circle::~Circle()
{}

void Circle::Save(ofstream& OutFile)
{
	OutFile << "Circle" << "  "
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

void Circle::Draw(GUI* pUI) const
{
	//Call Output::Drawcircle to draw a line on the screen	
	pUI->Drawcircle(Corner1, Corner2, ShpGfxInfo);



}
bool Circle::isInside(int X, int Y)
{
	double radius=pow((pow((Corner2.x - Corner1.x), 2) + pow((Corner2.y - Corner1.y), 2)), 0.5);
	if (pow((pow((X - Corner1.x), 2) + pow((Y - Corner1.y), 2)), 0.5) <= radius)
		return true;
	return false;
}


void Circle::Move(int dx, int dy)
{
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
}

shape* Circle::getCopy()
{
	return new Circle(Corner1, Corner2, ShpGfxInfo);
}



void Circle::setCorners(vector <Point> pts)
{
	Corner1 = pts[0];
	Corner2 = pts[1];
}
void Circle::getCorners(vector <Point>& pts)
{
	pts.push_back(Corner1);
	pts.push_back(Corner2);
}