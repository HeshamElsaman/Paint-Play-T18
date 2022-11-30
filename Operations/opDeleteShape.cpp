#include "opDeleteShape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opDeleteShape::opDeleteShape(controller* pCont) :operation(pCont)
{}
opDeleteShape::~opDeleteShape()
{}

//Execute the operation
void opDeleteShape::Execute()
{
	Point P;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Select the shape you want to delete...");
	//Read a point and store it in point P1
	pUI->GetPointClicked(P.x, P.y);
	shape* shp = pGr->Getshape(P.x, P.y);
	//Delete the Shape
	if (shp) {
		shp->SetDeleted(false);
	}
	delete shp; shp = nullptr;
}
