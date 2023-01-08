#include "opScramble.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

opScramble::opScramble(controller* pCont) :operation(pCont)
{}
opScramble::~opScramble()
{}

//Execute the operation
void opScramble::Execute()
{
	GUI* pUI = pControl->GetUI();
	//pUI->FlushMQue();
	Point P; pUI->GetPointClicked(P.x, P.y);
	

	srand(time(NULL));
	Graph* pGr = pControl->getGraph();
	//GUI* pUI = pControl->GetUI();
	//int a = rand() % 500; int b = rand() % 100;
	 //pGr->GetShpnum();
	
	
	if (pGr->GetShpnum() != 0)
	{
		int sq_n = sqrt(pGr->GetShpnum());
		int a = pGr->grid();
		//pGr->ToOnePixel();
		for (int i = 0; i < pGr->getshapelist().size(); i++)
		{
			
			if (!(pGr->getshapelist()[i]->IsDeleted()))
			{
				pGr->getshapelist()[i]->Resize(a/2);
				int x = (i % sq_n) * a;
				int y = ((i / sq_n) * a) + 56;
				pGr->getshapelist()[i]->Move(a * (rand() % sq_n) + 1, a* (rand() % sq_n)+1);
			}

		}
		
	}
}
