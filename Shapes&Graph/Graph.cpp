#include "Graph.h"
#include "../GUI/GUI.h"

Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	
	for (auto shapePointer : shapesList)
	{	
		if (!(shapePointer->IsDeleted()))
			shapePointer->Draw(pUI);
	}
}


shape* Graph::Getshape(int x, int y) const
{
	for (int i = shapesList.size()-1;i>=0;i--)
		if (shapesList[i]->isInside(x, y))
		{
			return shapesList[i];
		}
		

	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}


shape* Graph::GetSelectedShape() const
{
	return selectedShape;
}
void Graph::SetSelectedShape(shape* shp)
{
	selectedShape = shp;
}

void Graph::DeleteSelectedShapes()
{
	for (shape* shapePointer : shapesList)
	{
		if (!(shapePointer->IsDeleted()))
		{
			if(shapePointer->IsSelected())
			{
				shapePointer->SetDeleted(true);
			}
		}
	}
}