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

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	vector <shape*> shapes = pGraph->GetShapesVector();


	for (int i = 0; i < shapes.size(); i++)
	{


	}
	
	


	

	pUI->PrintMessage(" Zooming In ");

	
}