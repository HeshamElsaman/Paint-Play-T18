#include "..\controller.h"
#include "opDrag.h"
#include "..\GUI\GUI.h"
#include <cstdlib>
#include<Windows.h>

opDrag::opDrag(controller* pCont):operation(pCont) {};
opDrag::~opDrag() {};
void opDrag::Execute()
{
    GUI* pUI = pControl->GetUI();

    Graph* pGr = pControl->getGraph();
    shape* shp= NULL;
    bool bDragging = false;

    int iX = 0;
    int iY = 0;
    int iXOld = 0;
    int iYOld = 0;
    int diffx = 0;
    int diffy = 0;

    char cKeyData;
    
    
    int x_displaced = 0;
    int y_displaced = 0;


    // Loop until there escape is pressed
    while (pUI->GetButtonState(RIGHT_BUTTON, iX, iY) == BUTTON_DOWN/*pUI->GetKeyPressed(cKeyData) != ESCAPE*/)
    {
        if (bDragging == false) {
            if (pUI->GetButtonState(RIGHT_BUTTON, iX, iY) == BUTTON_DOWN) {
                shp = pGr->Getshape(iX, iY);
                if (shp)
                {
                    bDragging = true;
                    iXOld = iX; iYOld = iY;
                }
            }
        }
        else {
            if (pUI->GetButtonState(RIGHT_BUTTON, iX, iY) == BUTTON_UP ) {
                bDragging = false;
                break;
            }
            else 
            {
                diffx = (iX - iXOld);
                iXOld = iX;
                
                x_displaced += diffx;
                
                diffy =  (iY - iYOld);
                iYOld = iY;
                
                y_displaced += diffy;
            }
            
        }
        if (shp)
        {
            shp->Move(diffx, diffy);
            pControl->UpdateInterface();
           
            Sleep(8);
        }
    }
    if(shp)
    {
        ChngTr* tr = new ChngTr;
        //pGr->GetSelectedShapes(tr->ShpsCh);
        //tr->ShpsChTr.push_back(circleGfxInfo);
        pGr->AddUndoChngTr(tr);
        (tr->ShpsCh).push_back(shp);
        tr->x_displacement = x_displaced;
        tr->y_displacement = y_displaced;
    }
    pUI->FlushMQue();
    pControl->UpdateInterface();

}



void opDrag::Undo()
{
    Graph* pGr = pControl->getGraph();
    ChngTr* un = pGr->PopUndoChngTr();
    int x_dis, y_dis;
    if (un) {
        x_dis = -1 * (un->x_displacement); y_dis = -1 * (un->y_displacement);
        for (shape* shpPointer : un->ShpsCh) {
            shpPointer->Move(x_dis, y_dis);
        }
        un->x_displacement *= -1; un->y_displacement *= -1;
        pGr->AddRedoChngTr(un);
    }

}

void opDrag::Redo()
{
    Graph* pGr = pControl->getGraph();
    ChngTr* re = pGr->PopRedoChngTr();
    int x_dis, y_dis;
    if (re) {
        x_dis = -1 * (re->x_displacement); y_dis = -1 * (re->y_displacement);
        for (shape* shpPointer : re->ShpsCh) {
            shpPointer->SetDeleted(1);
        }
        re->x_displacement *= -1; re->x_displacement *= -1;
        pGr->AddUndoChngTr(re);
    }
}