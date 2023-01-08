#include "Polygon.h"

using namespace std;

PolyGon::PolyGon(Point* P_, int vertNum, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
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

PolyGon::~PolyGon()
{}

void PolyGon::Save(ofstream& OutFile)
{
    OutFile << "Polygon" << "  "
        << this->ID << "  ";
    for (int i = 0; i < VertNum; i++)
    {
        OutFile << this->Verts[i].x << "  " << this->Verts[i].y << "  ";
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

void PolyGon::Draw(GUI* pUI) const
{
	//Call Output::DrawPolygon to draw a polygon on the screen	
	pUI->DrawPolygon(Verts, VertNum, ShpGfxInfo);
}


void PolyGon::Drawdouble(GUI* pUI) const
{
    //Call Output::DrawPolygon to draw a polygon on the screen	
    pUI->DrawPolygon(Verts, VertNum, ShpGfxInfo);
}

double PolyGon::polyGonArea()
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
bool PolyGon::isInside(int X, int Y)
{
    double triarea = 0.0;
    int j = VertNum - 1;
    double dist1, dist2, dist3, S;
    for (int i = 0; i < VertNum; i++)
    {
        dist1 = sqrt(pow(X - Verts[j].x, 2) + pow(Y - Verts[j].y, 2));
        dist2 = sqrt(pow(X - Verts[i].x, 2) + pow(Y - Verts[i].y, 2));
        dist3 = sqrt(pow(Verts[i].x - Verts[j].x, 2) + pow(Verts[i].y - Verts[j].y, 2));
        S = 0.5 * (dist1 + dist2 + dist3);
        triarea += sqrt(S * (S - dist1) * (S - dist2) * (S - dist3));
        j = i;
    }
    if (triarea <= this->polyGonArea())
    {
        
        return true;
    }
    return false;
}

void PolyGon::Rotate(double theta = 2 * atan(1))
{
    Point gen;
    for (int i = 0; i < VertNum; i++)
    {
        gen = Verts[i];
        Verts[i].x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
        Verts[i].y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
    }
}

void PolyGon::Resize(double f)
{
    double d, delta;
    for (int i = 0; i < VertNum; i++)
    {
        d = sqrt(pow((Verts[i].x - com.x), 2) + pow((com.y - Verts[i].y), 2));
        delta = (f - 1) * d;
        moveFurther(com, Verts[i], delta);
    }
}


void PolyGon::Move(int dx, int dy)
{
    com.x += dx;
    com.y += dy;
    for (int i = 0; i < VertNum; i++)
    {
        Verts[i].x += dx;
        Verts[i].y += dy;
    }
}

shape* PolyGon::getCopy()
{
    return new PolyGon(Verts, VertNum, ShpGfxInfo);
}


void PolyGon::setCorners(vector <Point> pts)
{
    for (int i = 0; i < VertNum; i++)
    {
        Verts[i] = pts[i];
    }
}
void PolyGon::getCorners(vector <Point>& pts)
{
    for (int i = 0; i < VertNum; i++)
    {
        pts.push_back(Verts[i]);
    }
}

void PolyGon::setCom(Point p)
{
    com = p;
}
Point PolyGon::getCom()
{
    return com;
}

void PolyGon::Hide(GUI* lolo)
{
    ShpGfxInfo.IsHidden = true;
    img = 1;
}

void PolyGon::UnHide(GUI* lolo)
{
    ShpGfxInfo.IsHidden = false;
    img = 1;
}