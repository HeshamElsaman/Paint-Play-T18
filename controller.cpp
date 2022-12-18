#include "controller.h"
#include "Operations/opAddRect.h"
#include "Operations/opAddOval.h"
#include "Operations/opAddLine.h"
#include "Operations/opAddTriangle.h"
#include "Operations/opAddSquare.h"
#include "Operations/opAddCircle.h"
#include "Operations/opAddPolygon.h"
#include "Operations/opAddRegPolygon.h"
//#include "Operations/opAddImage.h"
#include "Operations/Select.h"
#include "Operations/opChngFillClr.h"
#include "Operations/opChngDrawClr.h"
#include "Operations/opChngPenWidth.h"
#include "Operations/opDeleteShape.h"
#include "Operations/opSave.h"
#include "Operations/opChngToPlayMode.h"
#include "Operations/opExit.h"


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

		case DRAW_TRI:
			pOp = new opAddTriangle(this);
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

		case CHNG_FILL_CLR:
			pOp = new opChngFillClr(this);
			break;

		case CHNG_DRAW_CLR :
			pOp = new opChngDrawClr(this);
			break;

		case CHNG_PEN_WIDTH:
			pOp = new opChngPenWidth(this);
			break;

		case DEL:
			pOp = new opDeleteShape(this);
			break;

		case DRAWING_AREA:
			pOp = new opSelect(this);
			break;


		case SAVE:
			pOp = new opSave(this);
			break;

		case TO_PLAY:
			pOp = new opChngToPlayMode(this);

			break;

		case EXIT:
			/*
			//The (SAVE) action shall be added to this operation
			*/
			
			pOp = new opExit(this);
		
			
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