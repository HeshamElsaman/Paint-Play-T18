#pragma once

#include "operation.h"

//Add Square operation class
class opAddSquare : public operation
{
public:
	opAddSquare(controller *pCont);
	virtual ~opAddSquare();
	
	//Add square to the controller
	virtual void Execute() ;
	
};

