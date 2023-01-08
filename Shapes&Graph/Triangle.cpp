#include "Triangle.h"
#include<iostream>

Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	com.x = (Corner1.x + Corner2.x + Corner3.x) / 3.0;
	com.y = (Corner1.y + Corner2.y + Corner3.y) / 3.0;
}

Triangle::~Triangle()
{}

void Triangle::Save(ofstream& OutFile) // the file name is Outfile
{
	OutFile << "TRI" << "  "
		<< this->ID << "  "
		<< this->Corner1.x << "  "
		<< this->Corner1.y << "  "
		<< this->Corner2.x << "  "
		<< this->Corner2.y << "   "
		<< this->Corner3.x << "  "
		<< this->Corner3.y << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucGreen << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucGreen << "  "
		<< (int)this->ShpGfxInfo.BorderWdth << "  " 
		<< this->IsDeleted() << "  " << endl;

}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, Corner3, ShpGfxInfo);

	if (ShpGfxInfo.imgSticked)
	{
		if ((Corner1.x > Corner2.x) && (Corner2.x > Corner3.x)&&(Corner1.y>Corner2.y)&&(Corner2.y > Corner3.y))
		{
			int x = (Corner1.x <= Corner2.x) ? Corner1.x : Corner2.x;
			int y = (Corner1.y <= Corner2.y) ? Corner1.y : Corner2.y;
			int width = abs(Corner1.x - Corner2.x);
			int length = abs(Corner1.y - Corner2.y);
			pUI->StickImage(img, x, y, length, width);

		}

		if ((Corner2.x > Corner3.x) && (Corner3.x > Corner1.x) && (Corner2.y > Corner3.y) && (Corner3.y > Corner1.y))
		{
			int x = (Corner2.x <= Corner3.x) ? Corner2.x : Corner3.x;
			int y = (Corner2.y <= Corner3.y) ? Corner2.y : Corner3.y;
			int width = abs(Corner2.x - Corner3.x);
			int length = abs(Corner2.y - Corner3.y);
			pUI->StickImage(img, x, y, length, width);

		}

	}

	if (ShpGfxInfo.IsHidden)
	{
		Point Ps[3] = { Corner1, Corner2, Corner3 };
		int x_min = Corner1.x, y_min = Corner1.y, x_max = 0, y_max = 0;
		for (int i = 0; i < 3; i++) {
			if (Ps[i].x >= x_max) {
				x_max = Ps[i].x;
			}
			if (Ps[i].y >= y_max) {
				y_max = Ps[i].y;
			}
			if (Ps[i].x <= x_min) {
				x_min = Ps[i].x;
			}
			if (Ps[i].y <= y_min) {
				y_min = Ps[i].y;
			}
		}
		pUI->StickImage(img, x_min, y_min, abs(y_max - y_min)+5, abs(x_max - x_min)+5);
	}

}

void Triangle::Drawdouble(GUI* pUI) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
}

bool Triangle::isInside(int X, int Y)
{
	int side1= pow((pow((Corner2.x - Corner1.x), 2) + pow((Corner2.y - Corner1.y), 2)), 0.5);
	int side2= pow((pow((Corner2.x - Corner3.x), 2) + pow((Corner2.y - Corner3.y), 2)), 0.5);
	int side3= pow((pow((Corner3.x - Corner1.x), 2) + pow((Corner3.y - Corner1.y), 2)), 0.5);
	int s = (side1 + side2 + side3) / 2;
	double triarea = sqrt(s * (s - side1) * (s - side2) * (s - side3));
	int inSide1= pow((pow((X - Corner1.x), 2) + pow((Y - Corner1.y), 2)), 0.5);
	int inSide2= pow((pow((X - Corner2.x), 2) + pow((Y - Corner2.y), 2)), 0.5);
	int inSide3= pow((pow((X - Corner3.x), 2) + pow((Y - Corner3.y), 2)), 0.5);
	int s1 = (inSide1 + inSide2 + side1)/2;
	int s2 = (inSide2 + inSide3 + side2) / 2;
	int s3= (inSide3 + inSide1 + side3) / 2;
	double area1= sqrt(s1 * (s1 - inSide1) * (s1 - inSide2) * (s1 - side1));
	double area2 = sqrt(s2 * (s2 - inSide2) * (s2 - inSide3) * (s2 - side2));
	double area3 = sqrt(s3 * (s3 - inSide3) * (s3 - inSide1) * (s3 - side3));
	if ((area1 + area2 + area3) <= triarea) {
		cout << (area1 + area2 + area3) << endl << triarea<<endl<<endl;
		return true;
		
	}
	return false;

}

void Triangle::Rotate(double theta = 2 * atan(1))
{
	Point gen;
	gen = Corner1;
	Corner1.x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
	Corner1.y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
	gen = Corner2;
	Corner2.x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
	Corner2.y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
	gen = Corner3;
	Corner3.x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
	Corner3.y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
}

void Triangle::Resize(double f)
{
	double d1 = pow((pow((Corner1.x - com.x), 2) + pow((com.y - Corner1.y), 2)), 0.5);
	double d2 = pow((pow((Corner2.x - com.x), 2) + pow((com.y - Corner2.y), 2)), 0.5);
	double d3 = pow((pow((Corner3.x - com.x), 2) + pow((com.y - Corner3.y), 2)), 0.5);

	double delta1 = (f - 1) * d1;
	double delta2 = (f - 1) * d2;
	double delta3 = (f - 1) * d3;

	moveFurther(com, Corner1, delta1);
	moveFurther(com, Corner2, delta2);
	moveFurther(com, Corner3, delta3);
}

void Triangle::Move(int dx, int dy)
{
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
	Corner3.x += dx;
	Corner3.y += dy;
	com.x += dx;
	com.y += dy;
}
shape* Triangle::getCopy()
{
	return new Triangle(Corner1, Corner2,Corner3, ShpGfxInfo);
}


void Triangle::setCorners(vector <Point> pts)
{
	Corner1 = pts[0];
	Corner2 = pts[1];
	Corner3 = pts[2];
}
void Triangle::getCorners(vector <Point>& pts)
{
	pts.push_back(Corner1);
	pts.push_back(Corner2);
	pts.push_back(Corner3);
}

void Triangle::setCom(Point p)
{
	com = p;
}
Point Triangle::getCom()
{
	return com;
}

void Triangle::Hide(GUI* lolo)
{

	ShpGfxInfo.IsHidden = true;
	img = 1;
}

void Triangle::UnHide(GUI* lolo)
{

	ShpGfxInfo.IsHidden = false;
	img = 1;
}