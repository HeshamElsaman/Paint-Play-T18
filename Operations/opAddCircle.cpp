#include "opAddCircle.h"
#include "..\shapes&Graph\Circle.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddCircle::opAddCircle(controller * pCont):operation(pCont)
{}
opAddCircle::~opAddCircle()
{} 

//Execute the operation
void opAddCircle::Execute()
{
	
	Point P1;
	Point P2;

	int radius;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Circle: Click at the first point (centre) ");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all circle parameters
	GfxInfo circleGfxInfo;
	
	//get drawing, filling colors and pen width from the interface
	circleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	circleGfxInfo.FillClr = pUI->getCrntFillColor();
	circleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	circleGfxInfo.isFilled = pUI->GetFillStatus();	//default is not filled
	circleGfxInfo.isSelected = false;	//defualt is not selected


	//Create a circle with the above parameters
	Circle *C=new Circle(P1, P2, circleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the circle to the list of shapes
	pGr->Addshape(C);

}
