#include "opZoomIn.h"

#include <iostream>

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <string>

#include "../controller.h"

#include "../GUI/GUI.h"
using namespace std;


using namespace std;
ZoomIn::ZoomIn(controller* pCont) :operation(pCont)
{}
ZoomIn::~ZoomIn()
{}





//Execute the operation
void ZoomIn::Execute()
{
/*
	GUI* pUI = pControl->GetUI();

	Point P;
	P.x = pUI->GetMo();
	P.y = 150;

	pUI->PrintMessage(" Zooming In ");

	float fOffsetX = P.x;
	float fOffsetY = P.y;

	float fScaleX = 1.0f;
	float fScaleY = 1.0f;

	float fStartPanX = 0.0f;
	float fStartPanY = 0.0f;

	float fSelectedCellX = 0.0f;
	float fSelectedCellY = 0.0f;


	void WorldToScreen(float fWorldX, float fWorldY, int& nScreenX, int& nScreenY)
	{
		nScreenX = (int)((fWorldX - fOffsetX) * fScaleX);
		nScreenY = (int)((fWorldY - fOffsetY) * fScaleY);
	}

	// Convert coordinates from Screen Space --> World Space
	; void ScreenToWorld(int nScreenX, int nScreenY, float& fWorldX, float& fWorldY)
	{
		fWorldX = ((float)nScreenX / fScaleX) + fOffsetX;
		fWorldY = ((float)nScreenY / fScaleY) + fOffsetY;
	}
	;
	

	

	




	operationType s=pUI->GetUseroperation();
	if (s == ZOOM_IN)
	{




	}

	

	

	

*/
}