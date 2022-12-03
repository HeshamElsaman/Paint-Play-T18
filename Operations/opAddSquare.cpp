#include "opAddSquare.h"
#include "..\shapes&Graph\Square.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"
#include <cmath>

opAddSquare::opAddSquare(controller * pCont):operation(pCont)
{}
opAddSquare::~opAddSquare()
{} 

//Execute the operation
void opAddSquare::Execute()
{
	
	Point P1;
	Point P2;
	Point P3;
	/*int SideLength;*/
;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	

	/*string msg = "Second corner is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
	msg += " ... The side length of the square is (" + to_string(SideLength)+ ")" ;
	pUI->PrintMessage(msg);*/

	pUI->PrintMessage("Click at the point where you want the square to be centred ");

	pUI->GetPointClicked(P3.x, P3.y);

	pUI->ClearStatusBar();

	//Preapre all circle parameters
	GfxInfo SquareGfxInfo;
	
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquareGfxInfo.FillClr = pUI->getCrntFillColor();
	SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	SquareGfxInfo.isFilled = false;	//default is not filled
	SquareGfxInfo.isSelected = false;	//defualt is not selected


	//Create a circle with the above parameters
	Square *S=new Square(P1, P2, P3, SquareGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the circle to the list of shapes
	pGr->Addshape(S);

}
