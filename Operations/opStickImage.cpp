#include "opStickImage.h"

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include "../controller.h"

#include "../GUI/GUI.h"


opStickImage::opStickImage(controller* pCont) :operation(pCont)
{}
opStickImage::~opStickImage()
{}

//Execute the operation
void opStickImage::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	Point P; pUI->GetPointClicked(P.x, P.y);

	pUI->PrintMessage("Choose an Image: Enter A Number for the Image");

	

	string KEY = pUI->GetSrting();
	//pUI->open();
	//pUI->Open()
	//pUI->drawImage(stoi(KEY));

	//Draw(pUI);
	if (pGr->ShapeListStateSelected())
	{
		pGr->StickImg(stoi(KEY));
	}



}