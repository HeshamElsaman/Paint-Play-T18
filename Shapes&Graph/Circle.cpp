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

	if (ShpGfxInfo.imgSticked)
	{
		
		int width = (abs(Corner1.x - Corner2.x) * (2))+5;// width -= 2 * this->ShpGfxInfo.BorderWdth;
		int length = (abs(Corner1.x - Corner2.x) * 2)+5; //length -= 2 * this->ShpGfxInfo.BorderWdth;
		int x = Corner1.x - (length/2);
		int y = (Corner1.y + (length / 2));
		pUI->StickImage(img, x, y, length, width);
	}

	if (ShpGfxInfo.IsHidden)
	{
		int d = sqrt(pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2));
		int x = Corner1.x - d;
		int y = Corner1.y - d;
		pUI->StickImage(img, x, y, 2*d, 2*d);
	}

}

void Circle::Drawdouble(GUI* pUI) const
{
	//Call Output::Drawcircle to draw a line on the screen	
	pUI->Drawcircle(Corner1, Corner2, ShpGfxInfo);

	if (ShpGfxInfo.imgSticked)
	{
		int x = (Corner1.x <= Corner2.x) ? Corner1.x : Corner2.x; x += this->ShpGfxInfo.BorderWdth;
		int y = (Corner1.y <= Corner2.y) ? Corner1.y : Corner2.y; y += this->ShpGfxInfo.BorderWdth;
		int width = abs(Corner1.x - Corner2.x); width -= 2 * this->ShpGfxInfo.BorderWdth;
		int length = abs(Corner1.y - Corner2.y); length -= 2 * this->ShpGfxInfo.BorderWdth;
		pUI->StickImage(img, x, y, length, width);
	}


}



bool Circle::isInside(int X, int Y)
{
	double radius=pow((pow((Corner2.x - Corner1.x), 2) + pow((Corner2.y - Corner1.y), 2)), 0.5);
	if (pow((pow((X - Corner1.x), 2) + pow((Y - Corner1.y), 2)), 0.5) <= radius)
		return true;
	return false;
}


void Circle::Resize(double f)
{
	double d1 = pow((pow((Corner1.x - Corner2.x), 2) + pow((Corner2.y - Corner1.y), 2)), 0.5);
	

	double delta1 = (f - 1) * d1;
	

	moveFurther(Corner1, Corner2, delta1);
	
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

void Circle::setCom(Point p)
{
	Corner1 = p;
}
Point Circle::getCom()
{
	return Corner1;
}

void Circle::Hide(GUI* lolo)
{

	ShpGfxInfo.IsHidden = true;
	img = 1;
}

void Circle::UnHide(GUI* lolo)
{

	ShpGfxInfo.IsHidden = false;
	img = 1;
}
