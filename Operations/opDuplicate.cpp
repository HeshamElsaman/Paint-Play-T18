#include "opDuplicate.h"
#include "../Shapes&Graph/Oval.h"

#include "../controller.h"

#include "../GUI/GUI.h"

opDuplicate::opDuplicate(controller* pCont) :operation(pCont)
{}
opDuplicate::~opDuplicate()
{}

// The mission is to Hide all the shapes of the graph
// 


//Execute the operation

void opDuplicate::Execute()
{

	Point p;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->GetPointClicked(p.x, p.y);

	//vector <shape*> HideCards; // A new  vector for the cards on the shapes.

	 // A new  vector for the cards on the shapes.


	vector <shape*> shapes = pGr->GetShapesVector();//Get the shapes vector

	//Get the shapes vector


	for (int i = 0; i < shapes.size(); i++)
	{

		for (int i = 0; i < pGr->GetShapesVector().size(); i++)
		{
			shape* shp;

			shapes[i]->Drawdouble(pUI);
			shp = pGr->GetShapesVector()[i];//->Draw(pUI);

			shp = shp->getCopy();
			//pGr->GetNewShapesList().
			pGr->GetNewShapesList().push_back(shp);

			pGr->GetNewShapesList()[i]->Move(50, 10);

			//HideCards.emplace_back(pUI);


		}
	}


}

//void opDuplicate::Undo()
//{
//	Graph* pGr = pControl->getGraph();
//	ChngTr* un = pGr->PopUndoChngTr();
//	if (un) {
//		for (shape* shpPointer : un->ShpsCh) {
//			shpPointer->SetDeleted(0);
//			shpPointer->SetSelected(1);
//			pGr->AddSelectedShape(shpPointer);
//		}
//		pGr->AddRedoChngTr(un);
//	}
//
//}
//
//void opDuplicate::Redo()
//{
//	Graph* pGr = pControl->getGraph();
//	ChngTr* re = pGr->PopRedoChngTr();
//	if (re) {
//
//		for (shape* shpPointer : re->ShpsCh) {
//			shpPointer->SetDeleted(1);
//			shpPointer->SetSelected(0);
//		}
//		pGr->ClearSelectedShapes();
//
//		pGr->AddUndoChngTr(re);
//	}
//}
