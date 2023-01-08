
#pragma once
#include "../Operations/operation.h"

//Add ChngDrawClr operation class
class opDuplicate : public operation
{
public:
	opDuplicate(controller* pCont);
	virtual ~opDuplicate();

	//Add ChngGenDrawClr to the controller
	virtual void Execute();

	virtual void Undo() override{};
	virtual void Redo() override{};
};
