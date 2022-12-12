#include "..\controller.h"
#include "Select.h"
#include "..\GUI\GUI.h"
opSelect::opSelect(controller* pCont):operation(pCont) {};
opSelect::~opSelect() {};
void opSelect::Execute()
{
	Point P1;
	GUI* pUI = pControl->GetUI();
	pUI->GetOpLastPointClicked(P1.x, P1.y);
	Graph* pGr = pControl->getGraph();
	shape* shape1 = pGr->Getshape(P1.x, P1.y);
	shape* shape2 = pGr->GetSelectedShape();
	if (shape1)
	{
		if (shape2)
			shape2->SetSelected(false);
		shape1->SetSelected(true);
		pGr->SetSelectedShape(shape1);
		
		
	}
	else
	{
		if (shape2)
			shape2->SetSelected(false);
	}
	
	
}