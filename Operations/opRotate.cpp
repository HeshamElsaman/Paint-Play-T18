#include "opRotate.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opRotate::opRotate(controller* pCont) :operation(pCont)
{}
opRotate::~opRotate()
{}

//Execute the operation
void opRotate::Execute()
{
	Graph* pGr = pControl->getGraph();
	if (pGr->ShapeListStateSelected()) {
		pGr->Rotate90();
	}
}
