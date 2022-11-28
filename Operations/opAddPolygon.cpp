#include "opAddPolygon.h"
#include "../shapes&Graph/Polygon.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddPolygon::opAddPolygon(controller* pCont) :operation(pCont)
{}
opAddPolygon::~opAddPolygon()
{}

//Execute the operation
void opAddPolygon::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	
	int vertnum = 0;
	//getting the number of successive clicks
	int click = 0;
	int z = 0, p = 0;
	pUI->PrintMessage("New Polygon: Specify the number of vertices using RightClicks followed by a LeftClick");
	do
	{
		click = pUI->GetClickType(z, p);
		if (click == 2) vertnum++;
	} while (click == 2);

	if (vertnum >= 3) {
		Point* verts = new Point[vertnum];
		pUI->ClearStatusBar();
		for (int i = 0; i < vertnum; i++) {
			pUI->PrintMessage("Click at vertix " + to_string(i + 1));
			//Read the vertix and store it in point verts[i]
			pUI->GetPointClicked(verts[i].x, verts[i].y);
			string msg = "Vertix " + to_string(i + 1) + " is at (" + to_string(verts[i].x) + ", " + to_string(verts[i].y) + ")";
			pUI->PrintMessage(msg);
			//Sleep(500);
		}
		pUI->ClearStatusBar();
		//Preapre all polygon parameters
		GfxInfo PolygonGfxInfo;

		//get drawing, filling colors and pen width from the interface
		PolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
		PolygonGfxInfo.FillClr = pUI->getCrntFillColor();
		PolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


		PolygonGfxInfo.isFilled = false;	//default is not filled
		PolygonGfxInfo.isSelected = false;	//defualt is not selected


		//Create a Polygon with the above parameters
		PolyGon* P = new PolyGon(verts, vertnum, PolygonGfxInfo);
		delete[] verts; verts = nullptr;

		//Get a pointer to the graph
		Graph* pGr = pControl->getGraph();

		//Add the rectangle to the list of shapes
		pGr->Addshape(P);
	}
	else {
		string msg = "NOT A POLYGON!";
		pUI->PrintMessage(msg);
	}
}
