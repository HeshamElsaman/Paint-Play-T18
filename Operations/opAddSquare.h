#pragma once

#include "operation.h"

//Add Circle operation class
class opAddSquare : public operation
{
public:
	opAddSquare(controller *pCont);
	virtual ~opAddSquare();
	
	//Add circle to the controller
	virtual void Execute() ;
	
};

