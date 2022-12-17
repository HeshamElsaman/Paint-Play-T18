#include <math.h>
#include "opAddRegPolygon.h"
#include "../shapes&Graph/RegPolygon.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddRegPolygon::opAddRegPolygon(controller* pCont) :operation(pCont)
{}
opAddRegPolygon::~opAddRegPolygon()
{}

//Execute the operation
void opAddRegPolygon::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	int vertnum = 0;
	//getting the number of successive clicks
	/*int click = 0;
	int z = 0, p = 0;
	pUI->PrintMessage("New RegPolygon: Specify the number of vertices using RightClicks followed by a LeftClick");
	do
	{
		click = pUI->GetClickType(z, p);
		if (click == 2) vertnum++;
	} while (click == 2);*/
	pUI->PrintMessage("New Regular Polygon: Specify the number of vertices");
	vertnum = stoi(pUI->GetSrting());

	//Calculating the Side Length, Central Angle, and the Radius of the Inscribing Circle
	string msg = "Click at two points to get their distance as your Side Length...";
	msg += "Click at the first...";
	pUI->PrintMessage(msg);
	Point P1, P2, cent;
	pUI->GetPointClicked(P1.x,P1.y);
	pUI->ClearStatusBar();
	msg = "Click at the second";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(P2.x, P2.y);
	double Sidelength = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	double theta = 2.0 * (atan(1.0) * 4.0) / double(vertnum);
	int R = int(Sidelength / (sqrt(2 - (2 * cos(theta)))));
	pUI->ClearStatusBar();

	//Get the Center of the Regular Polygon
	msg = "Click at the point desired to be your centre...";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(cent.x, cent.y);
	pUI->ClearStatusBar();


	if (vertnum >= 3 && Sidelength != 0) {
		Point* verts = new Point[vertnum];
		
		//Generating the other points of the Regular Polygon
		Point next;
		double theta_ = 0;
		int x, y;
		if (vertnum % 2 == 0) {
			//theta_ = 0;
			next.y = cent.y;
			next.x = cent.x + R;
			for (int i = 0; i < vertnum; i++) {
				theta_ += theta;
				x = cos(theta_) * (next.x - cent.x) - sin(theta_) * (next.y - cent.y) + cent.x;
				y = sin(theta_) * (next.x - cent.x) + cos(theta_) * (next.y - cent.y) + cent.y;
				verts[i].x = x;
				verts[i].y = y;
			}
		}
		else {
			//theta_ = 0;
			next.x = cent.x;
			next.y = cent.y - R;
			for (int i = 0; i < vertnum; i++) {
				theta_ += theta;
				x = cos(theta_) * (next.x - cent.x) - sin(theta_) * (next.y - cent.y) + cent.x;
				y = sin(theta_) * (next.x - cent.x) + cos(theta_) * (next.y - cent.y) + cent.y;
				verts[i].x = x;
				verts[i].y = y;
			}
		}
		
		//Preapre all RegPolygon parameters
		GfxInfo RegPolygonGfxInfo;

		//get drawing, filling colors and pen width from the interface
		RegPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
		RegPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
		RegPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


		RegPolygonGfxInfo.isFilled = pUI->GetFillStatus();	//default is not filled
		RegPolygonGfxInfo.isSelected = false;	//defualt is not selected


		//Create a Regular Polygon with the above parameters
		RegPolygon* rP = new RegPolygon(verts, vertnum, RegPolygonGfxInfo);
		delete[] verts; verts = nullptr;

		//Get a pointer to the graph
		Graph* pGr = pControl->getGraph();

		//Add the regular polygon to the list of shapes
		pGr->Addshape(rP);
	}
	else {
		string msg = "NOT A POLYGON!";
		pUI->PrintMessage(msg);
	}
}
