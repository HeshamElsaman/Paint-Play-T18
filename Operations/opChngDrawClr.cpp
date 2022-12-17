#include "opChngDrawClr.h"


#include "../controller.h"

#include "../GUI/GUI.h"

opChngDrawClr::opChngDrawClr(controller* pCont) :operation(pCont)
{}
opChngDrawClr::~opChngDrawClr()
{}

//Execute the operation
void opChngDrawClr::Execute()
{
	Point P;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("Change General Draw Color: Pick a color ! if you want to pick the white color click outside the palette");
	pUI->CreateColorPalette();

	//Read click position
	pUI->GetPalettePointClicked(P.x, P.y);


	//Getting the color clicked
	color CLR;
	pUI->GetPaletteColorClicked(P.x, P.y, CLR);
	//If the click is in the (Area) of the color palette
	if (pGr->ShapeListStateSelected()) {
		pGr->ChangeDrawClr(CLR);
	}
	else
	{
		pUI->setCrntDrawColor(CLR);
	}
	pUI->DeleteColorPalette();

}