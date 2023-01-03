#include "opAddTriangle.h"
#include "..\shapes&Graph\Triangle.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddTriangle::opAddTriangle(controller* pCont) :operation(pCont)
{}
opAddTriangle::~opAddTriangle()
{}

//Execute the operation
void opAddTriangle::Execute()
{

	Point P1;
	Point P2;
	Point P3;

	//int radius;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at the first point (centre) ");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	
	msg = "second point is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
	msg += " ... Click at Third corner";
	pUI->PrintMessage(msg);
    //Read the third point P3
	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();




	//Preapre all circle parameters
	GfxInfo TriangleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pUI->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	TriangleGfxInfo.isFilled = pUI->GetFillStatus();	//default is not filled
	TriangleGfxInfo.isSelected = false;	//defualt is not selected


	//Create a circle with the above parameters
	Triangle* C = new Triangle(P1, P2, P3, TriangleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the circle to the list of shapes
	pGr->Addshape(C);

	ChngTr* tr = new ChngTr;
	tr->ShpsCh.push_back(C);
	//tr->ShpsChTr.push_back(circleGfxInfo);
	pGr->AddUndoChngTr(tr);
}

void opAddTriangle::Undo()
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

void opAddTriangle::Redo()
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
