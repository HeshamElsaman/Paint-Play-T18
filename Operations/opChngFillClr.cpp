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
	

	if (P.x > 350 && P.y > 250)
	{
		if (pGr->ShapeListStateSelected()) {
			pGr->SetSelectedFillState(false);
		}
		else
		{
			pUI->setFillStatus(false);
		}
	}
	else
	{
		if (pGr->ShapeListStateSelected()) {
			pGr->ChangeFillClr(CLR);
		}
		else
		{
			pUI->setCrntFillColor(CLR);
		}
	}
	


	pUI->DeleteColorPalette();
	
}