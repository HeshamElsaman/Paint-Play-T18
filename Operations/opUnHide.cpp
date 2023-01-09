#include "opUnHide.h"
#include "../Shapes&Graph/Oval.h"

#include "../controller.h"

#include "../GUI/GUI.h"

opUnHide::opUnHide(controller* pCont) :operation(pCont)
{}
opUnHide::~opUnHide()
{}

// The mission is to Hide all the shapes of the graph
// 


//Execute the operation

void opUnHide::Execute()
{

	Point p;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->GetPointClicked(p.x, p.y);


	//vector <shape*> HiddenCards; // A new  vector for the cards on the shapes.



	vector <shape*> shapes = pGr->GetShapesVector();//Get the shapes vector
	//vector <shape*> shapes = pGr->GetShapesVector();//Get the shapes vector



	
	for (int i = 0; i < pGr->GetHiddenShapesVector().size(); i++)
	{

		if (pGr->GetHiddenShapesVector()[i]->IsSelected())
		{
			pGr->GetHiddenShapesVector()[i]->UnHide(pUI);

		shapes[i]->UnHide(pUI);
		}
		
			//shapes[i]->Hide(pUI);



		//HiddenShapes.emplace_back(pUI);


	}}

void opUnHide::Undo()
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

void opUnHide::Redo()
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







