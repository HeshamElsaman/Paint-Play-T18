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
	Graph* pGr = pControl->getGraph();
	shape* shp = pGr->GetSelectedShape();
	//Delete the Shape
	if (shp) {
		shp->SetDeleted(true);
	}
}
