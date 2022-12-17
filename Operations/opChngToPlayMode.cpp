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
	Point P;

	GUI* pUI = pControl->GetUI();
	//Graph* pGr = pControl->getGraph();

	//pUI->PrintMessage("Change The Mode To Play Mode:");

	//char KEY;

	//pUI->GetKeyPressed(KEY);

	//Read click position


	pUI->CreatePlayToolBar();

	//Getting the color clicked




	
}