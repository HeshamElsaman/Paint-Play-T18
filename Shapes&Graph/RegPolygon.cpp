#include "RegPolygon.h"
#include <iostream>
using namespace std;

RegPolygon::RegPolygon(Point* P_, int vertNum, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	VertNum = vertNum;
	Verts = new Point[VertNum];
	if (!Verts) { exit(-1); }
	for (int i = 0; i < vertNum; i++) { Verts[i].x = P_[i].x; Verts[i].y = P_[i].y; }
    com.x = 0; com.y = 0;
    for (int i = 0; i < VertNum; i++)
    {
        com.x += Verts[i].x;
        com.y += Verts[i].y;
    }
    com.x /= double(VertNum);
    com.y /= double(VertNum);
}

RegPolygon::~RegPolygon()
{}

void RegPolygon::Save(ofstream& OutFile)
{
    OutFile << "RegPolygon" << "  "
        << this->ID << "  ";
    for (int i = 0; i < VertNum; i++)
    {
        OutFile << Verts[i].x << "  " << Verts[i].y << "  ";
    }
    OutFile
        << (int)this->ShpGfxInfo.DrawClr.ucRed << "  "
        << (int)this->ShpGfxInfo.DrawClr.ucBlue << "  "
        << (int)this->ShpGfxInfo.DrawClr.ucGreen << "  "
        << (int)this->ShpGfxInfo.FillClr.ucRed << "  "
        << (int)this->ShpGfxInfo.FillClr.ucBlue << "  "
        << (int)this->ShpGfxInfo.FillClr.ucGreen << "  "
        << (int)this->ShpGfxInfo.BorderWdth << "  " 
        << this->IsDeleted() << "  " << endl;
}

void RegPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegPolygon to draw a RegPolygon on the screen	
	pUI->DrawRegPolygon(Verts, VertNum, ShpGfxInfo);
}
double RegPolygon::polygonArea()
{
    
    // Initialize area
    double area = 0.0;

    // Calculate value of shoelace formula
    int j = VertNum - 1;
    for (int i = 0; i < VertNum; i++)
    {
        area += (Verts[j].x + Verts[i].x) * (Verts[j].y - Verts[i].y);
        j = i;  // j is previous vertex to i
    }

    return abs(area / 2.0);
}
bool RegPolygon::isInside(int X, int Y)
{
    double triarea = 0.0;
    int j = VertNum - 1;
    double dist1, dist2, dist3,S;
    for (int i = 0; i < VertNum; i++)
    {
        dist1 = sqrt(pow(X - Verts[j].x, 2) + pow(Y - Verts[j].y, 2));
        dist2 = sqrt(pow(X - Verts[i].x, 2) + pow(Y - Verts[i].y, 2));
        dist3 = sqrt(pow(Verts[i].x - Verts[j].x, 2) + pow(Verts[i].y - Verts[j].y, 2));
        S = 0.5 * (dist1 + dist2 + dist3);
        triarea += sqrt(S * (S - dist1) * (S - dist2) * (S - dist3));
        j = i;
    }
    if (triarea <= this->polygonArea())
    {
        return true;
    }
    return false;
}

void RegPolygon::Rotate(double theta = 2 * atan(1))
{
    Point gen;
    for (int i = 0; i < VertNum; i++)
    {
        gen = Verts[i];
        Verts[i].x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
        Verts[i].y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
    }
}


void RegPolygon::Move(int dx, int dy)
{
    com.x += dx;
    com.y += dy;
    for (int i = 0; i < VertNum; i++)
    {
        Verts[i].x += dx;
        Verts[i].y += dy;
    }
}

shape* RegPolygon::getCopy()
{
    return new RegPolygon(Verts,VertNum, ShpGfxInfo);
}


void RegPolygon::setCorners(vector <Point> pts)
{
    for (int i = 0; i < VertNum; i++)
    {
        Verts[i] = pts[i];
    }
}
void RegPolygon::getCorners(vector <Point>& pts)
{
    for (int i = 0; i < VertNum; i++)
    {
        pts.push_back(Verts[i]);
    }
}