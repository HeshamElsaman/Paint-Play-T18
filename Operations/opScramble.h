#pragma once

#include "operation.h"

//Delete Shape operation class
class opScramble : public operation
{
public:
	opScramble(controller* pCont);
	virtual ~opScramble();

	//Delete a Shape
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};