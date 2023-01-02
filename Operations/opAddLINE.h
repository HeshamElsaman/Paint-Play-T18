#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddLINE: public operation
{
public:
	opAddLINE(controller *pCont);
	virtual ~opAddLINE();
	
	//Add line to the controller
	virtual void Execute() ;
	
	virtual void Undo() override {}
	virtual void Redo() override {}
};

