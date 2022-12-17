#include "Triangle.h"
#include<iostream>

Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
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