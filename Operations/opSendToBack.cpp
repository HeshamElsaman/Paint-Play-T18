#include "opSendToBack.h"
#include "../Shapes&Graph/Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"


using namespace std;



SendToBack::SendToBack(controller* pCont) :operation(pCont)
{}
SendToBack::~SendToBack()
{}

//Execute the operation
void SendToBack::Execute()
{
	//Point P;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Send to Back ");
	//shape* pSH;

	pGr->Addshape(pGr->GetSelectedShape());

	

	//string KEY = pUI->GetSrting();
}