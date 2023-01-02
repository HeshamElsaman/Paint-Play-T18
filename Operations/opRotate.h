#pragma once

#include "operation.h"

//Delete Shape operation class
class opRotate : public operation
{
public:
	opRotate(controller* pCont);
	virtual ~opRotate();

	//Delete a Shape
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};