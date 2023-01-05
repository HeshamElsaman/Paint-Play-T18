#pragma once
#include "../Operations/operation.h"



class SendToBack : public operation
{
public:
	SendToBack(controller* pCont);
	virtual ~SendToBack();

	//Add SendToBack to the controller
	virtual void Execute();

};