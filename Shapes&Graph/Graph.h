#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	


//To trace the undo/redo operations
struct ChngTr
{
	//for the multiple-actions case
	vector <shape*> ShpsCh;				//to get the changed shapes
	vector <int> ids;					//to get the id of the changed shapes
	vector <GfxInfo> ShpsChTr;			//to trace the changes
	vector <int> imgs;					//to record the sticked images for each shape
	int x_displacement;
	int y_displacement;
	double ResizeFactor;

	//most probably won't be needed
	vector <int> vNUMs;					//to get the numbers of vertices
	vector <vector <Point>> MultiVerts;	//to record the exact vertices
};



//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	vector <shape*> selectedShapes;	//pointer to the currently selected shape
	vector <ChngTr*> cUndo;
	vector <ChngTr*> cRedo;
	int shpnum;					//to record the number of undeleted shapes
public:
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void AddUndoChngTr(ChngTr*);
	ChngTr* PopUndoChngTr();
	void AddRedoChngTr(ChngTr*);
	ChngTr* PopRedoChngTr();
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
	void Rotate90(double);
	void ReleaseShapesMemory();

	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
};
