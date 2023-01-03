#include "opDeleteShape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opDeleteShape::opDeleteShape(controller* pCont) :operation(pCont)
{}
opDeleteShape::~opDeleteShape()
{}

//Execute the operation
void opDeleteShape::Execute()
{
	Graph* pGr = pControl->getGraph();
	

	ChngTr* tr = new ChngTr;
	pGr->GetSelectedShapes(tr->ShpsCh);
	//tr->ShpsChTr.push_back(circleGfxInfo);
	pGr->AddUndoChngTr(tr);

	pGr->DeleteSelectedShapes();
}

void opDeleteShape::Undo()
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

void opDeleteShape::Redo()
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