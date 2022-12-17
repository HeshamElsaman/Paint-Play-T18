#include "opExit.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit::~opExit()
{}

//Execute the operation
void opExit::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	///////////////////
	//SAVE each shape//
	///////////////////
	pGr->ReleaseShapesMemory();
}
