#include "opRedo.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opRedo::opRedo(controller* pCont) :operation(pCont)
{}
opRedo::~opRedo()
{}

//Execute the operation
void opRedo::Execute()
{
	
	GUI* pUI = pControl->GetUI();
	Point P; pUI->GetPointClicked(P.x, P.y);

	pControl->ReDo();
}
