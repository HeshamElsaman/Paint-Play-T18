#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	com.x = 0.5 * (Corner1.x + Corner2.x);
	com.y = 0.5 * (Corner1.y + Corner2.y);
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


void Line::Rotate(double theta = 2 * atan(1))
{
	Point gen;
	gen = Corner1;
	Corner1.x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
	Corner1.y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
	gen = Corner2;
	Corner2.x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
	Corner2.y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
}

void Line::Resize(double f)
{
	double d1 = pow((pow((Corner1.x - com.x), 2) + pow((com.y - Corner1.y), 2)), 0.5);
	double d2 = pow((pow((Corner2.x - com.x), 2) + pow((com.y - Corner2.y), 2)), 0.5);

	double delta1 = (f - 1) * d1;
	double delta2 = (f - 1) * d2;

	moveFurther(com, Corner1, delta1);
	moveFurther(com, Corner2, delta2);
}


void Line::Move(int dx, int dy)
{
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
	com.x += dx;
	com.y += dy;
}
shape* Line::getCopy()
{
	return new Line(Corner1, Corner2, ShpGfxInfo);
}


void Line::setCorners(vector <Point> pts)
{
	Corner1 = pts[0];
	Corner2 = pts[1];
}
void Line::getCorners(vector <Point>& pts)
{
	pts.push_back(Corner1);
	pts.push_back(Corner2);
}