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
	Point P;
	Point p;

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	Graph* pGraph = pControl->getGraph();

	pUI->PrintMessage("Zooming In ");
	pUI->GetPointClicked(p.x, p.y);

	string KEY = pUI->GetSrting();
	//vector <shape*> shapes = pGraph->GetShapesVector();
	pUI->PrintMessage(" Zooming Out ");






	//Read click position


	pUI->setCrntPenWidth(stoi(KEY));



	//Getting the color clicked
	if (pGr->ShapeListStateSelected()) {
		pGr->ChangePenWidth(stoi(KEY));
	}
	else
	for (int i = 0; i < pGraph->GetShapesVector().size(); i++)
	{
		Point P; P.x = 750; P.y = 325;
		vector <Point> pts;
		double f = 1.4;
		double d, delta;
		Point comTemp; comTemp.x = 0; comTemp.y = 0;
		pGraph->GetShapesVector()[i]->getCorners(pts);
		for (int j = 0; j < pts.size(); j++)
		{
		pUI->setCrntPenWidth(stoi(KEY));
			d = sqrt(pow((pts[j].x - 750), 2) + pow((pts[j].y - 325), 2));
			delta = (f - 1) * d;
			pGraph->GetShapesVector()[i]->moveFurther(P, pts[j], delta);
			comTemp.x += pts[j].x; comTemp.y += pts[j].y;
		}
		pGraph->GetShapesVector()[i]->setCorners(pts);
		comTemp.x /= double(pts.size()); comTemp.y /= double(pts.size());
		pGraph->GetShapesVector()[i]->setCom(comTemp);
	}
	pUI->DeleteColorPalette();



}