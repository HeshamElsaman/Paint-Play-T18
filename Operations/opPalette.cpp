#include "opPalette.h"
//#include "..\shapes&Graph"
#include <iostream>
#include "..\controller.h"

#include "..\GUI\GUI.h"

opPalette::opPalette(controller* pCont) :operation(pCont)
{}
opPalette::~opPalette()
{} 

//Execute the operation
void opPalette::Execute()
{
	Point P1;


	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->Colorpallete();

	pUI->PrintMessage("Color Pallete: Pick a color");


	//Read 1st corner and store in point P1
	pUI->GetSmallWindPointClicked(P1.x, P1.y);

	pUI->GetPickedColor(P1.x, P1.y);
	
	pUI->ClearStatusBar();

	

}
