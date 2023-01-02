#pragma once

#include "../Operations/operation.h"

//Add Oval operation class
class opAddOval : public operation
{
public:
	opAddOval(controller* pCont);
	virtual ~opAddOval();

	//Add oval to the controller
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};

