#pragma once

#include "operation.h"

//Add Polygon operation class
class opAddPolygon : public operation
{
public:
	opAddPolygon(controller* pCont);
	virtual ~opAddPolygon();

	//Add polygon to the controller
	virtual void Execute();

	virtual void Undo() override;
	virtual void Redo() override;
};


