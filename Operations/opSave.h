#pragma once

#include "operation.h"

//Add save operation class
class opSave : public operation
{
public:
	opSave(controller* pCont);
	virtual ~opSave();
	//Add save to the controller
	virtual void Execute();

};