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
	// to write in a file
	ofstream OutFile;
	pUI->PrintMessage("Saving.....Enter file name by pressing on the keyboard then press Enter ");

	// to get the keypresses from the user
	OutFile.open("D:\\C++\\0 project\\fixed\\Paint-Play-T18\\playmode save\\" +pUI->GetSrting() + ".txt");

	Graph* pGr = pControl->getGraph();

	pGr->Save(OutFile);

	pUI->PrintMessage("Done");
	

}