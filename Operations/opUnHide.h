
#pragma once
#include "../Operations/operation.h"

//Add ChngDrawClr operation class
class opUnHide : public operation
{
public:
	opUnHide(controller* pCont);
	virtual ~opUnHide();

	//Add ChngGenDrawClr to the controller
	virtual void Execute();

	//virtual void Undo() override;
	//virtual void Redo() override;
};
