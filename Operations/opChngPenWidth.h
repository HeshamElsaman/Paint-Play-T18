#pragma once

#include "../Operations/operation.h"

//Add ChngDrawClr operation class
class opChngPenWidth : public operation
{
public:
	opChngPenWidth(controller* pCont);
	virtual ~opChngPenWidth();

	//Add ChngGenDrawClr to the controller
	virtual void Execute();

};