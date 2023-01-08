#include "Copy.h"
#include "../Shapes&Graph/Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"
Copy::Copy(controller* pCont):operation(pCont){}
Copy::~Copy() {};
void Copy::Execute()
{
	
	Graph* pGr = pControl->getGraph();
	//pGr->getClipboard().clear();
	
	pGr->opCopy();
	
	//pGr->DeleteSelectedShapes();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("The shape was copied!");

}
 void Copy::Undo() {}
 void Copy::Redo() {}