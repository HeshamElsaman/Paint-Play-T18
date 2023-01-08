#include "opHide.h"
#include "../Shapes&Graph/Oval.h"

#include "../controller.h"

#include "../GUI/GUI.h"

opHide::opHide(controller* pCont) :operation(pCont)
{}
opHide::~opHide()
{}

// The mission is to Hide all the shapes of the graph


//Execute the operation

void opHide::Execute()
{

	
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	
	//vector <shape*> shapes = pGr->GetShapesVector();//Get the shapes vector

	
	for (int i = 0; i < pGr->GetShapesVector().size(); i++)
	{
		pGr->GetShapesVector()[i]->Hide(pUI);

		pGr->GetHiddenShapesVector().push_back(pGr->GetShapesVector()[i]);

	}




}

void opHide::Undo()
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

void opHide::Redo()
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
