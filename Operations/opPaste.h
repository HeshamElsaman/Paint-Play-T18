#pragma once
#include "operation.h"
class controller;
class opPaste:public operation
{
public:
	opPaste(controller* pCont);
	~opPaste();
	void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};

