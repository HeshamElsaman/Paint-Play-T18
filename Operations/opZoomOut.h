#pragma once

#include "../Operations/operation.h"

class ZoomOut : public operation
{
public:
	ZoomOut(controller* pCont);
	virtual ~ZoomOut();

	//Add ZoomOut to the controller
	void Execute();
	virtual void Undo() override {}
	virtual void Redo() override {}
};
