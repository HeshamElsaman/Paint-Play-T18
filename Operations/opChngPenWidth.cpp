#include "opChngPenWidth.h"

#include <iostream>

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <string>

#include "../controller.h"

#include "../GUI/GUI.h"
using namespace std;
opChngPenWidth::opChngPenWidth(controller* pCont) :operation(pCont)
{}
opChngPenWidth::~opChngPenWidth()
{}

//Execute the operation
void opChngPenWidth::Execute()
{
	Point P;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("Change General PenWidth: Pick a Number for the PenWidth");

	string KEY= pUI->GetSrting();
	

	
	
	

	//Read click position


		pUI->setCrntPenWidth(stoi(KEY));
		


	//Getting the color clicked
	if (pGr->ShapeListStateSelected()) {
		GfxInfo ctr;
		ChngTr* tr = new ChngTr;
		pGr->GetSelectedShapes(tr->ShpsCh);
		for (shape* shpPointer : tr->ShpsCh)
		{
			ctr.BorderWdth = shpPointer->GetPenWidth();
			tr->ShpsChTr.push_back(ctr);
		}
		pGr->AddUndoChngTr(tr);
		
		pGr->ChangePenWidth(stoi(KEY));
	}
	else
	{
		pUI->setCrntPenWidth(stoi(KEY));
		pControl->PopUndo();
	}
	pUI->DeleteColorPalette();



	
	
	//If the click is in the (Area) of the color palette
	/*if (pGr->ShapeListStateSelected()) {
		pGr->ChangeDrawClr(CLR);
	}
	else
	{
		pUI->setCrntDrawColor(CLR);
	}
	pUI->DeleteColorPalette();*/

}


void opChngPenWidth::Undo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* un = pGr->PopUndoChngTr();
	int wdth;
	if (un) {
		for (int i = 0; i < (un->ShpsCh).size(); i++) {
			wdth = (un->ShpsCh)[i]->GetPenWidth();
			(un->ShpsCh)[i]->ChngPenWidth(((un->ShpsChTr)[i]).BorderWdth);
			(un->ShpsChTr)[i].BorderWdth = wdth;
		}
		pGr->AddRedoChngTr(un);
	}
}

void opChngPenWidth::Redo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* re = pGr->PopRedoChngTr();
	int wdth;
	if (re) {
		for (int i = 0; i < (re->ShpsCh).size(); i++) {
			wdth = (re->ShpsCh)[i]->GetPenWidth();
			(re->ShpsCh)[i]->ChngPenWidth(((re->ShpsChTr)[i]).BorderWdth);
			(re->ShpsChTr)[i].BorderWdth = wdth;
		}
		pGr->AddUndoChngTr(re);
	}
}