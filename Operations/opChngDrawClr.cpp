#include "opChngDrawClr.h"


#include "../controller.h"

#include "../GUI/GUI.h"

opChngDrawClr::opChngDrawClr(controller* pCont) :operation(pCont)
{}
opChngDrawClr::~opChngDrawClr()
{}

//Execute the operation
void opChngDrawClr::Execute()
{
	Point P;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("Change General Draw Color: Pick a color ! if you want to pick the white color click outside the palette");
	pUI->CreateColorPalette();

	//Read click position
	pUI->GetPalettePointClicked(P.x, P.y);


	//Getting the color clicked
	color CLR;
	pUI->GetPaletteColorClicked(P.x, P.y, CLR);
	//If the click is in the (Area) of the color palette
	if (pGr->ShapeListStateSelected()) {
		GfxInfo ctr;
		ChngTr* tr = new ChngTr;
		pGr->GetSelectedShapes(tr->ShpsCh);
		for (shape* shpPointer : tr->ShpsCh)
		{
			ctr.DrawClr = shpPointer->GetDrawClr();
			tr->ShpsChTr.push_back(ctr);
		}
		pGr->AddUndoChngTr(tr);

		pGr->ChangeDrawClr(CLR);
	}
	else
	{
		pUI->setCrntDrawColor(CLR);
		pControl->PopUndo();
	}
	pUI->DeleteColorPalette();

}

void opChngDrawClr::Undo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* un = pGr->PopUndoChngTr();
	color tempClr1, tempClr2;
	if (un) {
		for (int i = 0; i < (un->ShpsCh).size(); i++) {
			tempClr1 = (un->ShpsCh)[i]->GetDrawClr();
			tempClr2 = ((un->ShpsChTr)[i]).DrawClr;
			(un->ShpsCh)[i]->ChngDrawClr(tempClr2);
			(un->ShpsChTr)[i].DrawClr = tempClr1;
		}
		pGr->AddRedoChngTr(un);
	}
}

void opChngDrawClr::Redo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* re = pGr->PopRedoChngTr();
	color tempClr;
	if (re) {
		for (int i = 0; i < (re->ShpsCh).size(); i++) {
			tempClr = (re->ShpsCh)[i]->GetDrawClr();
			(re->ShpsCh)[i]->ChngDrawClr(((re->ShpsChTr)[i]).DrawClr);
			(re->ShpsChTr)[i].DrawClr = tempClr;
		}
		pGr->AddUndoChngTr(re);
	}
}