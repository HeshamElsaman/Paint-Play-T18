#pragma once

#include "../Operations/operation.h"

class ZoomIn : public operation
{
public:
	ZoomIn(controller* pCont);
	virtual ~ZoomIn();

	//Add ZoomIn to the controller
	
	virtual void Execute();
	virtual void Undo() override {}
	virtual void Redo() override {}
};

