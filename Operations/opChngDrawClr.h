#pragma once

#include "../Operations/operation.h"

//Add ChngDrawClr operation class
class opChngDrawClr : public operation
{
public:
	opChngDrawClr(controller* pCont);
	virtual ~opChngDrawClr();

	//Add ChngGenDrawClr to the controller
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};
