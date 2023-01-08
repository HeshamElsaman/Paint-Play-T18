#pragma once
#include "operation.h"
class controller;
class Copy:public operation
{
public:
	Copy(controller* pCont);
	~Copy();
	void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};

