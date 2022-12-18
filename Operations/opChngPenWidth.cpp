#include "opChngPenWidth.h"

#include <iostream>

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <string>

#include "../controller.h"

#include "../GUI/GUI.h"
using namespace std;
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

	string KEY= pUI->GetSrting();
	

	
	
	

	//Read click position


		pUI->setCrntPenWidth(stoi(KEY));
		


	//Getting the color clicked
	if (pGr->ShapeListStateSelected()) {
		pGr->ChangePenWidth(stoi(KEY));
	}
	else
	{
		pUI->setCrntPenWidth(stoi(KEY));
	}
	pUI->DeleteColorPalette();



	
	
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