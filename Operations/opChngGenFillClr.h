#pragma once

#include "../Operations/operation.h"

//Add ChngGenFillClr operation class
class opChngGenFillClr : public operation
{
public:
	opChngGenFillClr(controller* pCont);
	virtual ~opChngGenFillClr();

	//Add ChngGenFillClr to the controller
	virtual void Execute();

};
