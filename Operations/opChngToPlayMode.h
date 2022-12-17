#pragma once
#include "../Operations/operation.h"

//Add ChngDrawClr operation class
class opChngToPlayMode : public operation
{
public:
	opChngToPlayMode(controller* pCont);
	virtual ~opChngToPlayMode();

	//Add ChngGenDrawClr to the controller
	virtual void Execute();

};
