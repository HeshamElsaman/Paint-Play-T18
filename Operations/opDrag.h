#pragma once

#include "operation.h"

//Add Select operation class
class opDrag : public operation
{
public:
	opDrag(controller* pCont);
	virtual ~opDrag();

	//Add select to the controller
	virtual void Execute();
	virtual void Undo() override {}
	virtual void Redo() override {}
};