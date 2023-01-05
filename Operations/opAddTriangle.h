#pragma once
#include "operation.h"

//Add Triangle operation class
class opAddTriangle : public operation
{
public:
	opAddTriangle(controller* pCont);
	virtual ~opAddTriangle();

	//Add Triangle to the controller
	virtual void Execute();

	virtual void Undo() override;
	virtual void Redo() override;
};