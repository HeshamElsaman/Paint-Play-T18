#pragma once

#include "DEFS.h"
#include "Shapes&Graph\Graph.h"
#include "GUI\GUI.h"
#include <stack>

class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{

	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	stack <operation*> sUndo;
	stack <operation*> sRedo;

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void UnDo(); //Undo an operation
	void ReDo(); //Redo an operation
	void PopUndo(); //for the operations not wanted to be recorded to remove themselves
	void ClearRedo();
	void Run();
	
	Graph* getGraph() const;
	
	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	

};

