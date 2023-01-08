#include "Graph.h"
#include "../GUI/GUI.h"
#include <iostream>
using namespace std;

Graph::Graph()
{
	shpnum = 0;
}

Graph::~Graph()
{
	if (!(Clipboard.empty()))
	{
		for (shape* shapePointer : Clipboard)
		{
			delete shapePointer; shapePointer = nullptr;
		}
		Clipboard.clear();
	}
	if(!(cUndo.empty()))
	{
		for (auto opPointer : cUndo) {
			delete opPointer; opPointer = nullptr;
		}
	}
	if (!(cRedo.empty()))
	{
		for (auto opPointer : cRedo) {
			delete opPointer; opPointer = nullptr;
		}
	}
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pFig)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pFig);
	pFig->setID(shapesList.size()); // set the shape ID to the size of the shapes list 
	/*if (!(pFig->IsDeleted()))
	{
		globalID++;
	}*/
}



////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
void Graph::AddshapesToBack()
{
	//Add a new shape to the first of shapes vector
	shape* shp = nullptr;//vector <shape*> hamo;
	int i = shapesList.size() - 1;
	bool run = false;
	for(;i >= 0;i--)
	{
		if(shapesList[i]->IsSelected() && !(shapesList[i]->IsDeleted()))
		{
			shp = shapesList[i];
			shapesList.erase(shapesList.begin() + i);
			shapesList.insert(shapesList.begin(), shp);
			run = !run;
		}
		if (shapesList[i]->getID() == 1)
		{
			if (shapesList[i]->IsSelected() && !(shapesList[i]->IsDeleted()))
			{
				shp = shapesList[i];
				shapesList.erase(shapesList.begin() + i);
				shapesList.insert(shapesList.begin(), shp);
			}
			break;
		}
		else if (run)
		{
			i++;
			run = !run;
		}
	}
	shp = nullptr;

}
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI)
{
	int num = 0;
	pUI->ClearDrawArea();
	if (!(shapesList.empty()))
	{
		for (int i = 0; i < shapesList.size(); i++)
		{
			if (((shapesList[i])->getID()) != (i + 1)) {
				(shapesList[i])->setID(i + 1);
			}

			if (!(shapesList[i]->IsDeleted()))
			{
				shapesList[i]->Draw(pUI);
				num++;
			}
		}
	}
	if (!(newshapesList.empty()))
	{
		for (int i = 0; i < newshapesList.size(); i++)
		{
			/*if (((shapesList[i])->getID()) != (i + 1)) {
				(shapesList[i])->setID(i + 1);
			}*/

			if (!(newshapesList[i]->IsDeleted()))
			{
				newshapesList[i]->Draw(pUI);
				//num++;
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

shape* Graph::GetSelectedShape(vector <shape*>& slctdshps) const
{
	for (int i = 0; i <= slctdshps.size(); i++)
	{
		if (slctdshps[i]->IsSelected())
		{
			return slctdshps[i];
		}
	}

}

vector <shape*> Graph::GetShapesVector() const
{
	return shapesList;
}

vector <shape*> Graph::GetHiddenShapesVector()const
{
	return HiddenShapes;
}

vector <shape*>& Graph::GetNewShapesList()
{
	return newshapesList;
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
					shapePointer->SetSelected(false);
				}
			}
		}
	}
	ClearSelectedShapes();
	
}
vector <shape*> Graph::getClipboard()
{
	return Clipboard;
}
void Graph::opCopy()
{
	if (!(Clipboard.empty()))
	{
		for (shape* shapePointer : Clipboard)
		{
			delete shapePointer; shapePointer = nullptr;
		}
		Clipboard.clear();
	}
	
	for (auto shapePointer : shapesList)
	{
		if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
		{
			Clipboard.push_back(shapePointer->getCopy());
			//shapesList.erase(find(shapesList.begin(), shapesList.end(), shapePointer));
			
		}
		
	}
}
void Graph::opCut()
{
	
	{
		if (!(shapesList.empty()))
		{
			for (int i = 0; i < shapesList.size(); i++) {
				if (shapesList[i]->IsSelected()) {
					Clipboard.push_back(shapesList[i]);
					shapesList.erase(find(shapesList.begin(), shapesList.end(), shapesList[i]));
				}
			}
		}
	}
}

void Graph::getPaste(int x,int y,int& size)
{
	if (Clipboard.size() == 0)
	{
		size = 0; return;
	}
	
	Clipboard.back()->Paste(x,y);
	
	shapesList.push_back(Clipboard.back());

	Clipboard.pop_back();
	size = Clipboard.size();
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

/*void Graph::Load(ofstream& OutFile)
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
}*/




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



vector <shape*> Graph::getshapelist() const
{
	return shapesList;
}

int Graph::GetShpnum() const
{
	return shpnum;
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

void Graph::Rotate90(double theta = 2 * atan(1))
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->Rotate(theta);
			}
		}
	}
}

void Graph::Resize(double scale)
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (shapePointer->IsSelected() && !(shapePointer->IsDeleted()))
			{
				shapePointer->Resize(scale);
			}
		}
	}
}

void Graph::ToOnePixel()
{
	if (!(shapesList.empty()))
	{
		for (shape* shapePointer : shapesList)
		{
			if (!(shapePointer->IsDeleted()))
			{
				shapePointer->ToOnePixel();
			}
		}
	}
}

int Graph::grid()
{
	int sq_n = sqrt(shpnum);
	int a = ((630 - 50 - 56) / sq_n);
	return a;
}


void Graph::AddUndoChngTr(ChngTr* cu)
{
	cUndo.push_back(cu);
}
ChngTr* Graph::PopUndoChngTr()
{
	ChngTr* cu;
	if (!(cUndo.empty())) {
		cu = *(cUndo.rbegin());
		cUndo.pop_back();
		return cu;
	}
	return nullptr;
}
void Graph::AddRedoChngTr(ChngTr* cr)
{
	cRedo.push_back(cr);
}
ChngTr* Graph::PopRedoChngTr()
{
	ChngTr* cr;
	if (!(cRedo.empty())) {
		cr = *(cRedo.rbegin());
		cRedo.pop_back();
		return cr;
	}
	return nullptr;
}