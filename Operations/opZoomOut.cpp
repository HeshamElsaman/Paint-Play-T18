#include "opZoomOut.h"

#include <iostream>

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <string>

#include "../controller.h"

#include "../GUI/GUI.h"
using namespace std;


using namespace std;
ZoomOut::ZoomOut(controller* pCont) :operation(pCont)
{}
ZoomOut::~ZoomOut()
{}

//Execute the operation
void ZoomOut::Execute()
{
	Point p;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	Graph* pGraph = pControl->getGraph();

	pUI->PrintMessage("Zooming In ");
	pUI->GetPointClicked(p.x, p.y);

	//vector <shape*> shapes = pGraph->GetShapesVector();
	pUI->PrintMessage(" Zooming Out ");

	
	for (int i = 0; i < pGraph->GetShapesVector().size(); i++)
	{
		Point P; P.x = 750; P.y = 325;
		double f = 0.714285714;
		double d, delta, dx, dy;
		Point comTemp; comTemp.x = 0; comTemp.y = 0;
		Point before;
		comTemp = pGraph->GetShapesVector()[i]->getCom();
		before = comTemp;
		d = sqrt(pow(750 - comTemp.x, 2) + pow(325 - comTemp.y, 2));
		delta = (f - 1) * d;
		pGraph->GetShapesVector()[i]->moveFurther(P, comTemp, delta);
		dx = comTemp.x - before.x; dy = comTemp.y - before.y;

		pGraph->GetShapesVector()[i]->Move(dx, dy);
		pGraph->GetShapesVector()[i]->Resize(f);
	}
	



}