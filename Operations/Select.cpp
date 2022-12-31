#include "..\controller.h"
#include "Select.h"
#include "..\GUI\GUI.h"
opSelect::opSelect(controller* pCont):operation(pCont) {};
opSelect::~opSelect() {};
void opSelect::Execute()
{
	Point P1;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	if (pUI->getSelectMode()==false) {
		pUI->GetOpLastPointClicked(P1.x, P1.y);
		shape* shape1 = pGr->Getshape(P1.x, P1.y);
		shape* shape2 = pGr->GetSelectedShape();
		if (shape1)
		{
			pGr->setShapeListStateSelected();
			shape1->SetSelected(true);
			pGr->SetSelectedShape(shape1);


		}
		else
		{
			pGr->setShapeListStateSelected();
			pGr->SetSelectedShape(nullptr);
		}
	}
	else if (pUI->getSelectMode() == true)
	{
		pUI->GetOpLastPointClicked(P1.x, P1.y);
		shape* shape1 = pGr->Getshape(P1.x, P1.y);
		if (shape1)
		{
			shape1->SetSelected(true);
		}
	}
	
	
}