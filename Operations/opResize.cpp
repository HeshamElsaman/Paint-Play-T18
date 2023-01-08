#include "opResize.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"
#include <string>

opResize::opResize(controller* pCont) :operation(pCont)
{}
opResize::~opResize()
{}

//Execute the operation
void opResize::Execute()
{
	
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	if (pGr->ShapeListStateSelected()) {
		ChngTr* tr = new ChngTr;
		pGr->GetSelectedShapes(tr->ShpsCh);
		//tr->ShpsChTr.push_back(circleGfxInfo);
		pUI->PrintMessage("Enter the rescaling value ");
		string a = pUI->GetSrting();
		double resize = stod(a);
		pGr->AddUndoChngTr(tr);
		tr->ResizeFactor = resize;
		pGr->Resize(resize);
	}
}

void opResize::Undo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* un = pGr->PopUndoChngTr();
	double resize;
	if (un) {
		resize = 1.0 / (un->ResizeFactor);
		for (shape* shpPointer : un->ShpsCh) {
			shpPointer->Resize(resize);
		}
		un->ResizeFactor = resize;
		pGr->AddRedoChngTr(un);
	}

}

void opResize::Redo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* re = pGr->PopRedoChngTr();
	double resize;
	if (re) {
		resize = 1.0 / (re->ResizeFactor);
		for (shape* shpPointer : re->ShpsCh) {
			shpPointer->Resize(resize);
		}
		re->ResizeFactor = resize;
		pGr->AddUndoChngTr(re);
	}
}
