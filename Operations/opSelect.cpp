#include "..\controller.h"
#include "opSelect.h"
#include "..\GUI\GUI.h"
#include <Windows.h>

opSelect::opSelect(controller* pCont):operation(pCont) {};
opSelect::~opSelect() {};
void opSelect::Execute()
{
	Point P1;
	GUI* pUI = pControl->GetUI();
	
	/*Point P;
	pUI->GetPointClicked(P.x, P.y);*/
	

	Graph* pGr = pControl->getGraph();
	pUI->GetOpLastPointClicked(P1.x, P1.y);
	
	if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
	{
		shape* shape1 = pGr->Getshape(P1.x, P1.y);
		if (shape1)
		{
			shape1->SetSelected(true);
			pGr->AddSelectedShape(shape1);
		}
	}
	else {
		shape* shape1 = pGr->Getshape(P1.x, P1.y);

		if (shape1)
		{
			pGr->setShapeListStateSelected();
			pGr->ClearSelectedShapes();
			shape1->SetSelected(true);
			pGr->AddSelectedShape(shape1);


		}
		else
		{
			pGr->setShapeListStateSelected();
			pGr->ClearSelectedShapes();
		}
	}
	pUI->FlushMQue();
	pControl->UpdateInterface();
}