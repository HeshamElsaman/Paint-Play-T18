#include "opChngFillClr.h"


#include "../controller.h"

#include "../GUI/GUI.h"

opChngFillClr::opChngFillClr(controller* pCont) :operation(pCont)
{}
opChngFillClr::~opChngFillClr()
{}

//Execute the operation
void opChngFillClr::Execute()
{
	Point P;
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(P.x, P.y);
	Graph* pGr = pControl->getGraph();
	pUI->FlushMQue();
	pUI->PrintMessage("Change General Fill Color: Pick a color ! if you want to pick the white color click outside the palette");
	pUI->CreateColorPalette();
	
	//Read click position
	pUI->GetPalettePointClicked(P.x, P.y);

	// check if point in the range of color palatte window --> do something,  else close pallate without doing anything.
	//Getting the color clicked
	color CLR;
	pUI->GetPaletteColorClicked(P.x, P.y, CLR);
	

	if (P.x > 350 && P.y > 250)
	{
		if (pGr->ShapeListStateSelected()) {
			GfxInfo ctr;
			ChngTr* tr = new ChngTr;
			pGr->GetSelectedShapes(tr->ShpsCh);
			for (shape* shpPointer : tr->ShpsCh)
			{
				ctr.isFilled = shpPointer->IsFilled();
				ctr.FillClr = shpPointer->GetFillClr();
				tr->ShpsChTr.push_back(ctr);
			}
			pGr->AddUndoChngTr(tr);
			
			pGr->SetSelectedFillState(false);
		}
		else
		{
			pUI->setFillStatus(false);
			pControl->PopUndo();
		}
	}
	else
	{
		if (pGr->ShapeListStateSelected()) {
			GfxInfo ctr;
			ChngTr* tr = new ChngTr;
			pGr->GetSelectedShapes(tr->ShpsCh);
			for (shape* shpPointer : tr->ShpsCh)
			{
				ctr.isFilled = shpPointer->IsFilled();
				ctr.FillClr = shpPointer->GetFillClr();
				tr->ShpsChTr.push_back(ctr);
			}
			pGr->AddUndoChngTr(tr);
			
			pGr->ChangeFillClr(CLR);
		}
		else
		{
			pUI->setFillStatus(true);
			pUI->setCrntFillColor(CLR);
			pControl->PopUndo();
		}
	}
	


	
	
}


void opChngFillClr::Undo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* un = pGr->PopUndoChngTr();
	color tempClr1; bool filler;
	if (un) {
		for (int i = 0; i < (un->ShpsCh).size(); i++) {
			filler = (un->ShpsCh)[i]->IsFilled();
			if(filler) tempClr1 = (un->ShpsCh)[i]->GetFillClr();
			(un->ShpsCh)[i]->SetFilled(((un->ShpsChTr)[i]).isFilled);
			if(((un->ShpsChTr)[i]).isFilled) (un->ShpsCh)[i]->ChngFillClr(((un->ShpsChTr)[i]).FillClr);
			(un->ShpsChTr)[i].isFilled = filler;
			(un->ShpsChTr)[i].FillClr = tempClr1;
		}
		pGr->AddRedoChngTr(un);
	}
}

void opChngFillClr::Redo()
{
	Graph* pGr = pControl->getGraph();
	ChngTr* re = pGr->PopRedoChngTr();
	color tempClr1; bool filler;
	if (re) {
		for (int i = 0; i < (re->ShpsCh).size(); i++) {
			filler = (re->ShpsCh)[i]->IsFilled();
			if(filler) tempClr1 = (re->ShpsCh)[i]->GetFillClr();
			(re->ShpsCh)[i]->SetFilled(((re->ShpsChTr)[i]).isFilled);
			if (((re->ShpsChTr)[i]).isFilled) (re->ShpsCh)[i]->ChngFillClr(((re->ShpsChTr)[i]).FillClr);
			(re->ShpsChTr)[i].isFilled = filler;
			(re->ShpsChTr)[i].FillClr = tempClr1;
		}
		pGr->AddUndoChngTr(re);
	}
}