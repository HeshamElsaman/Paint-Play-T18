#pragma once
#include "operation.h"
class opResize : public operation
{

public:
	opResize(controller* pCont);
	virtual ~opResize();
	
	//Add save to the controller
	virtual void Execute();

	virtual void Undo() override;
	virtual void Redo() override;
};


