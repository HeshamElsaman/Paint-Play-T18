#include "opAddLine.h"
#include "..\shapes&Graph\Line.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddLINE::opAddLINE(controller * pCont):operation(pCont)
{}
opAddLINE::~opAddLINE()
{} 

//Execute the operation
void opAddLINE::Execute() 
{
	
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New LINE: Click at first point");
	//Read 1st point and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second point";
	pUI->PrintMessage(msg);
	//Read 2nd point and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all line parameters
	GfxInfo LINEGfxInfo;
	
	//get drawing, filling colors and pen width from the interface
	LINEGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LINEGfxInfo.FillClr = pUI->getCrntFillColor();
	LINEGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	LINEGfxInfo.isFilled = false;	//default is not filled
	LINEGfxInfo.isSelected = false;	//defualt is not selected


	//Create a line with the above parameters
	Line  *L=new Line(P1, P2, LINEGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the line to the list of shapes
	pGr->Addshape(L);


	ChngTr* tr = new ChngTr;
	tr->ShpsCh.push_back(L);
	//tr->ShpsChTr.push_back(circleGfxInfo);
	pGr->AddUndoChngTr(tr);
}

void opAddLINE::Undo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* un = pGr->PopUndoChngTr();
	if (un) {
		for (shape* shpPointer : un->ShpsCh) {
			shpPointer->SetDeleted(1);
		}
		pGr->AddRedoChngTr(un);
	}

}

void opAddLINE::Redo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* re = pGr->PopRedoChngTr();
	if (re) {
		for (shape* shpPointer : re->ShpsCh) {
			shpPointer->SetDeleted(0);
		}
		pGr->AddUndoChngTr(re);
	}
}

