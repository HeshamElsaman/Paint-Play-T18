#include "..\controller.h"
#include "opSave.h"
#include "..\GUI\GUI.h"
#include <fstream>
#include <iostream>
opSave::opSave(controller* pCont):operation(pCont) {};

opSave::~opSave() {};

void opSave::Execute()
{
	GUI* pUI = pControl->GetUI();
	Point P; pUI->GetPointClicked(P.x, P.y);
	// to write in a file
	ofstream OutFile;
	pUI->PrintMessage("Saving.....Enter file name by pressing on the keyboard then press Enter ");

	// to get the keypresses from the user
	OutFile.open("SampleGraphs\\" + pUI->GetSrting() + ".txt");

	Graph* pGr = pControl->getGraph();

	pGr->Save(OutFile);

	pUI->PrintMessage("Done");
	

}