#include "opPaste.h"
#include "../Shapes&Graph/Graph.h"
#include "../controller.h"
opPaste::opPaste(controller* pCont) :operation(pCont) {};
opPaste::~opPaste() {};
void opPaste::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	
	
	int size,x, y;
	pUI->GetPointClicked(x, y);
	pUI->GetPointClicked(x, y);
	//size=pGr->getClipboard().size();
	do
	{
		
		pUI->GetPointClicked(x, y);
		pGr->getPaste(x, y, size);
		pControl->UpdateInterface();
		

	} while (size != 0);
	pUI->PrintMessage("Select a point to draw!");
}
void opPaste::Undo() {};
void opPaste::Redo() {};
