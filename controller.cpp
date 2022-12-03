#include "controller.h"
#include "Operations\opAddRect.h"
#include "Operations\opAddOval.h"
#include "Operations\opAddLine.h"
#include "Operations\opAddSquare.h"
#include "Operations\opAddCircle.h"
#include "Operations\opAddPolygon.h"
#include "Operations\opAddRegPolygon.h"
#include "Operations\opChngGenFillClr.h"
#include "Operations\opPalette.h"


//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_SQR:
			pOp = new opAddSquare(this);
			break;

		case DRAW_LINE:
			pOp = new opAddLINE(this);
			break;
		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;

		case DRAW_OVAL:
			pOp = new opAddOval(this);
			break;

		case DRAW_POLY:
			pOp = new opAddPolygon(this);
			break;

		case DRAW_REGPOLY:
			pOp = new opAddRegPolygon(this);
			break;

		case CHNG_GEN_FILL_CLR:
			pOp = new opChngGenFillClr(this);
			break;

		case Pallete:
			pOp = new opPalette(this);
			break;

		case EXIT:
			///create Exitoperation here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}