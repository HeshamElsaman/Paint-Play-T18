#pragma once

#include "operation.h"

//Add palette operation class
class opPalette : public operation
{
public:
	opPalette(controller *pCont);
	virtual ~opPalette();
	
	//Add palette to the controller
	virtual void Execute() ;
	
};

