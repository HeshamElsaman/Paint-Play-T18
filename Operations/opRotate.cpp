#include "opRotate.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opRotate::opRotate(controller* pCont) :operation(pCont)
{}
opRotate::~opRotate()
{}

//Execute the operation
void opRotate::Execute()
{
	Graph* pGr = pControl->getGraph();
	if (pGr->ShapeListStateSelected()) {
		ChngTr* tr = new ChngTr;
		pGr->GetSelectedShapes(tr->ShpsCh);
		//tr->ShpsChTr.push_back(circleGfxInfo);
		pGr->AddUndoChngTr(tr);

		pGr->Rotate90(2 * atan(1));
	}
}

void opRotate::Undo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* un = pGr->PopUndoChngTr();
	if (un) {
		for (shape* shpPointer : un->ShpsCh) {
			shpPointer->Rotate(2 * atan(-1));
		}
		pGr->AddRedoChngTr(un);
	}

}

void opRotate::Redo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* re = pGr->PopRedoChngTr();
	if (re) {
		for (shape* shpPointer : re->ShpsCh) {
			shpPointer->Rotate(2 * atan(1));
		}
		pGr->AddUndoChngTr(re);
	}
}