#include "opStart.h"

#include <iostream>

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <string>

#include "math.h"

#include "../controller.h"

#include "../GUI/GUI.h"
using namespace std;


using namespace std;
Start::Start(controller* pCont) :operation(pCont)
{}
Start::~Start()
{}

//Execute the operation
void Start::Execute()
{
	Point p;

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	pUI->GetPointClicked(p.x, p.y);

	//vector <shape*> shapes = pGraph->GetShapesVector();
	pUI->PrintMessage(" start Game ");

	
}

void Start::Undo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* un = pGr->PopUndoChngTr();
	if (un) {
		for (shape* shpPointer : un->ShpsCh) {
			shpPointer->SetDeleted(0);
			shpPointer->SetSelected(1);
			pGr->AddSelectedShape(shpPointer);
		}
		pGr->AddRedoChngTr(un);
	}

}

void Start::Redo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* re = pGr->PopRedoChngTr();
	if (re) {

		for (shape* shpPointer : re->ShpsCh) {
			shpPointer->SetDeleted(1);
			shpPointer->SetSelected(0);
		}
		pGr->ClearSelectedShapes();

		pGr->AddUndoChngTr(re);
	}
}