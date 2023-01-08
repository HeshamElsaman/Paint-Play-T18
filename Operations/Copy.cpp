#include "Copy.h"
#include "../Shapes&Graph/Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"
Copy::Copy(controller* pCont):operation(pCont){}
Copy::~Copy() {};
void Copy::Execute()
{

	Graph* pGr = pControl->getGraph();
	pGr->Copy();

}
 void Copy::Undo() {}
 void Copy::Redo() {}