#include "opChngPenWidth.h"

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include "../controller.h"

#include "../GUI/GUI.h"

opChngPenWidth::opChngPenWidth(controller* pCont) :operation(pCont)
{}
opChngPenWidth::~opChngPenWidth()
{}

//Execute the operation
void opChngPenWidth::Execute()
{
	Point P;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("Change General PenWidth: Pick a Number for the PenWidth");

	char KEY;
	
	pUI->GetKeyPressed(KEY);

	//Read click position


		pUI->setCrntPenWidth((int)KEY);


	//Getting the color clicked


	
	
	//If the click is in the (Area) of the color palette
	/*if (pGr->ShapeListStateSelected()) {
		pGr->ChangeDrawClr(CLR);
	}
	else
	{
		pUI->setCrntDrawColor(CLR);
	}
	pUI->DeleteColorPalette();*/

}