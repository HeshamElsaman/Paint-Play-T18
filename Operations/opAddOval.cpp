#include "opAddOval.h"
#include "../Shapes&Graph/Oval.h"

#include "../controller.h"

#include "../GUI/GUI.h"

opAddOval::opAddOval(controller* pCont) :operation(pCont)
{}
opAddOval::~opAddOval()
{}

//Execute the operation
void opAddOval::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Oval: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo OvalGfxInfo;

	//get drawing, filling colors and pen width from the interface
	OvalGfxInfo.DrawClr = pUI->getCrntDrawColor();
	OvalGfxInfo.FillClr = pUI->getCrntFillColor();
	OvalGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	OvalGfxInfo.isFilled = pUI->GetFillStatus();	//default is not filled
	OvalGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Oval* R = new Oval(P1, P2, OvalGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);


	ChngTr* tr = new ChngTr;
	tr->ShpsCh.push_back(R);
	//tr->ShpsChTr.push_back(circleGfxInfo);
	pGr->AddUndoChngTr(tr);
}

void opAddOval::Undo()
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

void opAddOval::Redo()
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

