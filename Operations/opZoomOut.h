#pragma once

#include "../Operations/operation.h"

class ZoomOut : public operation
{
public:
	ZoomOut(controller* pCont);
	virtual ~ZoomOut();

	//Add ZoomOut to the controller
	virtual void Execute();

};
