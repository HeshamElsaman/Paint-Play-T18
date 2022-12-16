#include "opChngFillClr.h"


#include "../controller.h"

#include "../GUI/GUI.h"

opChngFillClr::opChngFillClr(controller* pCont) :operation(pCont)
{}
opChngFillClr::~opChngFillClr()
{}

//Execute the operation
void opChngFillClr::Execute()
{
	Point P;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("Change General Fill Color: Pick a color ! if you want to pick the white color click outside the palette");
	pUI->CreateColorPalette();
	
	//Read click position
	pUI->GetPalettePointClicked(P.x, P.y);


	//Getting the color clicked
	color CLR;
	pUI->GetPaletteColorClicked(P.x, P.y, CLR);
	//If the click is in the (Area) of the color palette
	if (pGr->ShapeListStateSelected()) {
		pGr->ChangeFillClr(CLR);
	}
	else
	{
		pUI->setCrntFillColor(CLR);
	}
	pUI->DeleteColorPalette();
	
}