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
                 
                diffy =  (iY - iYOld);
                iYOld = iY;
            }
            
        }
        if (shp)
        {
            shp->Move(diffx, diffy);
            pControl->UpdateInterface();
           
            Sleep(10);
        }
    }
    pUI->FlushMQue();
    pControl->UpdateInterface();

}