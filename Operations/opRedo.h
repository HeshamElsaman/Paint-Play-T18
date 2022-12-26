#pragma once

#include "operation.h"

//Delete Shape operation class
class opRedo : public operation
{
public:
	opRedo(controller* pCont);
	virtual ~opRedo();

	//Delete a Shape
	virtual void Execute();

};