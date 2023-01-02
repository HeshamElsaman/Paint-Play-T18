#pragma once

#include "../Operations/operation.h"

//Add ChngFillClr operation class
class opChngFillClr : public operation
{
public:
	opChngFillClr(controller* pCont);
	virtual ~opChngFillClr();

	//Add ChngGenFillClr to the controller
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};
