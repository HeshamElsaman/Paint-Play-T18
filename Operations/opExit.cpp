#include "opExit.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"
#include <fstream>



opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit::~opExit()
{}

//Execute the operation
void opExit::Execute()
{
	ofstream restoreshapes;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("If you want to save type the file name / or just exit by pressing ESCAPE ");
	// to get the keypresses from the user
	string fileName = pUI->GetSrting();
	if(fileName !="")
		restoreshapes.open(fileName + ".txt");

	pGr->Save(restoreshapes);
	pGr->ReleaseShapesMemory();
}
