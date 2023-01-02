#pragma once

#include "operation.h"

//Exit operation class
class opExit : public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit();

	//Exit
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};