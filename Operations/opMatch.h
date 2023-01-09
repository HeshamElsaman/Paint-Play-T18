#pragma once

#include "../Operations/operation.h"

class opMatch : public operation
{
public:
	opMatch(controller* pCont);
	virtual ~opMatch();

	//Add ZoomOut to the controller
	void Execute();
	virtual void Undo() override {}
	virtual void Redo() override {}
};
