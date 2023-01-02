#pragma once

#include "operation.h"

//Add Regular Polygon operation class
class opAddRegPolygon : public operation
{
public:
	opAddRegPolygon(controller* pCont);
	virtual ~opAddRegPolygon();

	//Add regular polygon to the controller
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};