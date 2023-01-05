#pragma once

#include "../Operations/operation.h"

class ZoomIn : public operation
{
public:
	ZoomIn(controller* pCont);
	virtual ~ZoomIn();

	//Add ZoomIn to the controller
	/*void WorldToScreen(float fWorldX, float fWorldY, int& nScreenX, int& nScreenY);
	bool OnUserCreate();*/
	virtual void Execute();

};

