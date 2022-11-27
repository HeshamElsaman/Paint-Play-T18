#include "opChngGenFillClr.h"

//#include color palette definition if needed (I guess it will be needed)

#include "../controller.h"

#include "../GUI/GUI.h"

opChngGenFillClr::opChngGenFillClr(controller* pCont) :operation(pCont)
{}
opChngGenFillClr::~opChngGenFillClr()
{}

//Execute the operation
void opChngGenFillClr::Execute()
{
	Point P;

	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Change General Fill Color: Click on the color you wish from the color palette");
	//Read click position
	pUI->GetPointClicked(P.x, P.y);
	//Getting the color clicked
	
	//If the click is in the (Area) of the color palette
	
}