#include "RegPolygon.h"

RegPolygon::RegPolygon(Point* P_, int vertNum, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	VertNum = vertNum;
	Verts = new Point[VertNum];
	if (!Verts) { exit(-1); }
	for (int i = 0; i < vertNum; i++) { Verts[i].x = P_[i].x; Verts[i].y = P_[i].y; }
}

RegPolygon::~RegPolygon()
{}

void RegPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegPolygon to draw a RegPolygon on the screen	
	pUI->DrawRegPolygon(Verts, VertNum, ShpGfxInfo);
}