#include "Polygon.h"

PolyGon::PolyGon(Point* P_, int vertNum, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	VertNum = vertNum;
	Verts = new Point[VertNum];
	if (!Verts) { exit(-1); }
	for (int i = 0; i < vertNum; i++) { Verts[i].x = P_[i].x; Verts[i].y = P_[i].y; }
}

PolyGon::~PolyGon()
{}

void PolyGon::Draw(GUI* pUI) const
{
	//Call Output::DrawPolygon to draw a polygon on the screen	
	pUI->DrawPolygon(Verts, VertNum, ShpGfxInfo);
}