#pragma once

#include "operation.h"

//Delete Shape operation class
class opDeleteShape : public operation
{
public:
	opDeleteShape(controller* pCont);
	virtual ~opDeleteShape();

	//Delete a Shape
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};