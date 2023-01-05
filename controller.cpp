#include "controller.h"
#include "Operations/opAddRect.h"
#include "Operations/opAddOval.h"
#include "Operations/opAddLine.h"
#include "Operations/opAddTriangle.h"
#include "Operations/opAddSquare.h"
#include "Operations/opAddCircle.h"
#include "Operations/opAddPolygon.h"
#include "Operations/opAddRegPolygon.h"
#include "Operations/opStickImage.h"
#include "Operations/Select.h"
#include "Operations/opChngFillClr.h"
#include "Operations/opChngDrawClr.h"
#include "Operations/opChngPenWidth.h"
#include "Operations/opDeleteShape.h"
#include "Operations/opUndo.h"
#include "Operations/opRedo.h"
#include "Operations/opRotate.h"
#include "Operations/opSave.h"
#include "Operations/opZoomIn.h"
#include "Operations/opZoomOut.h"
#include "Operations/opSendToBack.h"
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
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DRAW_SQR:
			pOp = new opAddSquare(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DRAW_TRI:
			pOp = new opAddTriangle(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DRAW_LINE:
			pOp = new opAddLINE(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DRAW_OVAL:
			pOp = new opAddOval(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DRAW_POLY:
			pOp = new opAddPolygon(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DRAW_REGPOLY:
			pOp = new opAddRegPolygon(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case CHNG_FILL_CLR:
			pOp = new opChngFillClr(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case CHNG_DRAW_CLR :
			pOp = new opChngDrawClr(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case CHNG_PEN_WIDTH:
			pOp = new opChngPenWidth(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case STICK_IMG:
			pOp = new opStickImage(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case DEL:
			pOp = new opDeleteShape(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case ROTATE:
			pOp = new opRotate(this);
			sUndo.push(pOp);
			ClearRedo();
			break;

		case UNDO:
			pOp = new opUndo(this);
			break;

		case REDO:
			pOp = new opRedo(this);
			break;

		case DRAWING_AREA:
			if (pGUI->GetOpLastPointClickedType() == RIGHT_CLICK)
				pGUI->setSelectMode(!(pGUI->getSelectMode()));
			else if (pGUI->GetOpLastPointClickedType() == LEFT_CLICK)
				pOp = new opSelect(this);
			break;


		case SAVE:
			pOp = new opSave(this);
			break;

		case ZOOM_IN:
			pOp = new ZoomIn(this);
			break;

		case ZOOM_OUT:
			pOp = new ZoomOut(this);
			break;

		case SEND_TO_BACK:
			pOp = new SendToBack(this);
			break;

		case TO_PLAY:
			pOp = new opChngToPlayMode(this);
			break;

		case EXIT_DRAW:
			pOp = new opExit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//////////////////////////////////////////////////////////////////////////////////////
void controller::UnDo()
{
	if (!(sUndo.empty())) {
		sRedo.push(sUndo.top());
		(sUndo.top())->Undo();
		sUndo.pop();
	}
}

void controller::ReDo()
{
	if (!(sRedo.empty())) {
		sUndo.push(sRedo.top());
		(sRedo.top())->Redo();
		sRedo.pop();
	}
}

void controller::PopUndo()
{
	delete sUndo.top(); sUndo.top() = nullptr; sUndo.pop();
}

void controller::ClearRedo()
{
	while (!(sRedo.empty())) {
		delete sRedo.top(); sRedo.top() = nullptr;
		sRedo.pop();
	}
}
//////////////////////////////////////////////////////////////////////////////////////
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
	
	while (!(sUndo.empty())) {
		delete sUndo.top(); sUndo.top() = nullptr;
		sUndo.pop();
	}
	while (!(sRedo.empty())) {
		delete sRedo.top(); sRedo.top() = nullptr;
		sRedo.pop();
	}
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
			/*
			delete pOpr;	//operation is not needed any more ==> delete it
			*/
			pOpr = nullptr;
			
		}

		//Update the interface
		UpdateInterface();

	} while ((OpType != EXIT_DRAW) && (OpType != EXIT_PLAY));

}