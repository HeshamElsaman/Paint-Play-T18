#include "opMatch.h"
#include <iostream>
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include <string>
#include "math.h"
#include "../controller.h"
#include "../Shapes&Graph/Circle.h"
#include "../Shapes&Graph/Rect.h"
#include "../Shapes&Graph/Oval.h"
#include "../Shapes&Graph/Square.h"
#include "../Shapes&Graph/Triangle.h"
#include "../Shapes&Graph/Polygon.h"
#include "../Shapes&Graph/Line.h"


#include "../GUI/GUI.h"
using namespace std;


using namespace std;
opMatch::opMatch(controller* pCont) :operation(pCont)
{}
opMatch::~opMatch()
{}

//Execute the operation
void opMatch::Execute()
{
	Graph* pGr = pControl->getGraph();
	vector <shape*> match;
	pGr->GetSelectedShapes(match);

	//pGr->UnHide(shapeselected)
	string typeOneStr = "";
	if (dynamic_cast<Circle*> (match[0])) typeOneStr = "Circle";
	else if (dynamic_cast<Line*> (match[0])) typeOneStr = "Line";
	else if (dynamic_cast<Square*> (match[0])) typeOneStr = "Square";
	else if (dynamic_cast<Rect*> (match[0])) typeOneStr = "Rectangle";
	else if (dynamic_cast<Oval*> (match[0])) typeOneStr = "Oval";
	else if (dynamic_cast<PolyGon*> (match[0])) typeOneStr = "PolyGon";
	//pGr->UnHide(shapeselected)
	string typeTwoStr = "";
	if (dynamic_cast<Circle*> (match[1])) typeTwoStr = "Circle";
	else if (dynamic_cast<Line*> (match[1])) typeTwoStr = "Line";
	else if (dynamic_cast<Square*> (match[1])) typeTwoStr = "Square";
	else if (dynamic_cast<Rect*> (match[1])) typeTwoStr = "Rectangle";
	else if (dynamic_cast<Oval*> (match[1])) typeTwoStr = "Oval";
	else if (dynamic_cast<PolyGon*> (match[1])) typeTwoStr = "PolyGon";


	if (typeTwoStr == typeOneStr)
	{
		pGr->DeleteSelectedShapes();
	}
	else
	{
		//pGr->Hide();
	}
}