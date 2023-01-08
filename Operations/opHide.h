#pragma once
#include "../Operations/operation.h"

//Add ChngDrawClr operation class
class opHide : public operation
{
public:
	opHide(controller* pCont);
	virtual ~opHide();

	
	 void Execute();

	virtual void Undo() override;
	virtual void Redo() override;
	
};
