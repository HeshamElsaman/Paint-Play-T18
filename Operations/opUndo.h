#pragma once

#include "operation.h"

//Delete Shape operation class
class opUndo : public operation
{
public:
	opUndo(controller* pCont);
	virtual ~opUndo();

	//Delete a Shape
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};