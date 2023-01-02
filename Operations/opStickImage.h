#pragma once
#include "../Operations/operation.h"



//Add Image To A shape operation class
class opStickImage : public operation
{
public:
	opStickImage(controller* pCont);
	virtual ~opStickImage();
	void Open();
	void Draw(GUI*);

	//Add Image To A shape to the controller
	virtual void Execute();

	virtual void Undo() override {}
	virtual void Redo() override {}
};