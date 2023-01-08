#include "opUnHide.h"
#include "../Shapes&Graph/Oval.h"

#include "../controller.h"

#include "../GUI/GUI.h"

opUnHide::opUnHide(controller* pCont) :operation(pCont)
{}
opUnHide::~opUnHide()
{}

// The mission is to Hide all the shapes of the graph
// 


//Execute the operation

void opUnHide::Execute()
{

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();


	//vector <shape*> HiddenCards; // A new  vector for the cards on the shapes.



	vector <shape*> shapes = pGr->GetShapesVector();//Get the shapes vector



	for (int i = 0; i <= shapes.size(); i++)
	{


		shapes[i]->Hide(pUI);



		//HiddenShapes.emplace_back(pUI);


	}}







