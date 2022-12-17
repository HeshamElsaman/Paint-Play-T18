#include "Graph.h"
#include "../GUI/GUI.h"

Graph::Graph()
{
	selectedShape = nullptr;
	globalID = 1;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pFig)
{
	//Add a new shape to the shapes vector
	pFig->setID(globalID); // set the ID in shape to globalID 
	shapesList.push_back(pFig);
	if (!(pFig->IsDeleted()))
	{
		globalID++;
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	if (!(shapesList.empty()))
	{
		for (auto shapePointer : shapesList)
		{
			if (!(shapePointer->IsDeleted()))
				shapePointer->Draw(pUI);
		}
	}
}


shape* Graph::Getshape(int x, int y) const
{
	for (int i = shapesList.size()-1;i>=0;i--)
		if (shapesList[i]->isInside(x, y) && !(shapesList[i]->IsDeleted()))
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
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (!(shapePointer->IsDeleted()))
			{
				if (shapePointer->IsSelected())
				{
					shapePointer->SetDeleted(true);
					//shapePointer->SetSelected(false);
				}
			}
		}
	}
	
}

void Graph::ChangeFillClr(color clr)
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->ChngFillClr(clr);
			}
		}
	}
}

void Graph::SetSelectedFillState(bool stat)
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->SetFilled(stat);
			}
		}
	}
}

bool Graph::ShapeListStateSelected() const
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected())
			{
				return true;
			}
		}
	}
	return false;
}

void Graph::Save(ofstream& OutFile)
{
	if (!(shapesList.empty()))
	{
		OutFile << shapesList.size()<<endl;
		for (int i = 0; i < shapesList.size(); i++)
		{
			//if (!(shapesList[i])->IsDeleted())
				shapesList[i]->Save(OutFile);
		}
	}
	OutFile.close();
}

void Graph::ReleaseShapesMemory()
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			delete shapePointer; shapePointer = nullptr;
		}
	}
}