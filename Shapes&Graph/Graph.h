#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	vector <shape*> selectedShapes;	//pointer to the currently selected shape
	int shpnum;					//to record the number of undeleted shapes
public:
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI);			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	void GetSelectedShapes(vector <shape*>&) const;		//Modifies a vector of pointers to the currently selected shapes
	void AddSelectedShape(shape*);
	void ClearSelectedShapes();
	void DeleteSelectedShapes();
	void ChangeFillClr(color);
	void SetSelectedFillState(bool);
	void ChangeDrawClr(color);
	void setShapeListStateSelected();
	bool ShapeListStateSelected() const;
	void StickImg(int);
	void ChangePenWidth(int num);
	void Rotate90();
	void ReleaseShapesMemory();

	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
};
