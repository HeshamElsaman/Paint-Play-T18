#include "opZoomOut.h"

#include <iostream>

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <string>

#include "../controller.h"

#include "../GUI/GUI.h"
using namespace std;


using namespace std;
ZoomOut::ZoomOut(controller* pCont) :operation(pCont)
{}
ZoomOut::~ZoomOut()
{}

//Execute the operation
void ZoomOut::Execute()
{
	Point P;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("Zooming In ");

	string KEY = pUI->GetSrting();






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



}