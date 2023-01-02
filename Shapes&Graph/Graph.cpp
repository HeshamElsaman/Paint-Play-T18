#include "Graph.h"
#include "../GUI/GUI.h"

Graph::Graph()
{
	shpnum = 0;
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
	shapesList.push_back(pFig);
	pFig->setID(shapesList.size()); // set the ID in shape to globalID 
	/*if (!(pFig->IsDeleted()))
	{
		globalID++;
	}*/
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI)
{
	int num = 0;
	pUI->ClearDrawArea();
	if (!(shapesList.empty()))
	{
		for (int i = 0; i < shapesList.size(); i++)
		{
			/*if (((shapesList[i])->getID()) != (i + 1)) {
				(shapesList[i])->setID(i + 1);
			}*/

			if (!(shapesList[i]->IsDeleted()))
			{
				shapesList[i]->Draw(pUI);
				num++;
			}
		}
	}
	if (shpnum != num) shpnum = num;
}


shape* Graph::Getshape(int x, int y) const
{
	for (int i = shapesList.size()-1; i >= 0; i--)
		if (shapesList[i]->isInside(x, y) && !(shapesList[i]->IsDeleted()))
		{
			return shapesList[i];
		}
		

	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}


void Graph::GetSelectedShapes(vector <shape*>& slctdshps) const
{
	slctdshps = selectedShapes;
}
void Graph::AddSelectedShape(shape* shp)
{
	selectedShapes.push_back(shp);
}
void Graph::ClearSelectedShapes()
{
	if (!(selectedShapes.empty()))
	{
		int num = selectedShapes.size();
		for (int i = num - 1; i >= 0; i--)
		{
			selectedShapes[i] = nullptr; selectedShapes.pop_back();
		}
	}
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

void Graph::ChangeDrawClr(color clr)
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->ChngDrawClr(clr);
			}
		}
	}
}
void Graph::ChangePenWidth(int num)
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->ChngPenWidth(num);
			}
		}
	}
}
void Graph::setShapeListStateSelected()
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			shapePointer->SetSelected(false);
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
	int temporalID = 0;
	int actualID;
	if (!(shapesList.empty()))
	{
		OutFile << shpnum << endl;
		for (int i = 0; i < shapesList.size(); i++)
		{
			if (!((shapesList[i])->IsDeleted()))
			{
				temporalID++;
				actualID = shapesList[i]->getID();
				shapesList[i]->setID(temporalID);
				shapesList[i]->Save(OutFile);
				shapesList[i]->setID(actualID);
			}
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

void Graph::StickImg(int img)
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->SetImgSticked(true);
				shapePointer->SetImgSticked(img);
			}
		}
	}
}

void Graph::Rotate90()
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->Rotate();
			}
		}
	}
}