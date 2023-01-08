#pragma once
#include "../Operations/operation.h"

//Add ChngDrawClr operation class
class Start : public operation
{
public:
	Start(controller* pCont);
	virtual ~Start();

	//Add ChngGenDrawClr to the controller
	virtual void Execute();

	virtual void Undo() override;
	virtual void Redo() override;
};
