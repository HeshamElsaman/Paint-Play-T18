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
	shape* selectedShape=NULL;	//pointer to the currently selected shape
public:
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	shape* GetSelectedShape() const;		//Returns a pointer to the currently selected shape
	void SetSelectedShape(shape*) ;
	void DeleteSelectedShapes();
	void ChangeFillClr(color);
	void SetSelectedFillState(bool);
	void ChangeDrawClr(color);
	bool ShapeListStateSelected() const;
	void StickImg(int);
	void ReleaseShapesMemory();

	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
};
