#include "opZoomIn.h"

#include <iostream>

#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <string>

#include "math.h"

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
	Point p;

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	vector <shape*> shapes = pGraph->GetShapesVector();
	pUI->GetPointClicked(p.x, p.y);

	//vector <shape*> shapes = pGraph->GetShapesVector();
	pUI->PrintMessage(" Zooming Out ");

	for (int i = 0; i < shapes.size(); i++)
	for (int i = 0; i < pGraph->GetShapesVector().size(); i++)
	{


		Point P; P.x = 750; P.y = 325;
		vector <Point> pts;
		double f = 0.7142857143;
		double d, delta;
		Point comTemp; comTemp.x = 0; comTemp.y = 0;
		pGraph->GetShapesVector()[i]->getCorners(pts);
		for (int j = 0; j < pts.size(); j++)
		{
			d = sqrt(pow((pts[j].x - 750), 2) + pow((pts[j].y - 325), 2));
			delta = (f - 1) * d;
			pGraph->GetShapesVector()[i]->moveFurther(P, pts[j], delta);
			comTemp.x += pts[j].x; comTemp.y += pts[j].y;
		}
		pGraph->GetShapesVector()[i]->setCorners(pts);
		comTemp.x /= double(pts.size()); comTemp.y /= double(pts.size());
		pGraph->GetShapesVector()[i]->setCom(comTemp);
	}
	
	


	

	pUI->PrintMessage(" Zooming In ");

	
}