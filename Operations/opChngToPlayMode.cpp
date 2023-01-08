#include "opChngToPlayMode.h"

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include "../controller.h"

#include "../GUI/GUI.h"

opChngToPlayMode::opChngToPlayMode(controller* pCont) :operation(pCont)
{}
opChngToPlayMode::~opChngToPlayMode()
{}

//Execute the operation
void opChngToPlayMode::Execute()
{
	
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	Point P; pUI->GetPointClicked(P.x, P.y);
	//Graph* pGr = pControl->getGraph();

	//pUI->PrintMessage("Change The Mode To Play Mode:");

	//char KEY;

	//pUI->GetKeyPressed(KEY);

	//Read click position
	pGr->ToOnePixel();
	for (int i = 0; i < pGr->getshapelist().size(); i++)
	{
		pGr->getshapelist()[i]->Resize(pGr->grid() / 2);
	}
	
	pUI->CreatePlayToolBar();

	//Getting the color clicked




	
}