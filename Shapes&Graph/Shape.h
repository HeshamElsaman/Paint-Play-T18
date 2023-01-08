#pragma once
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <fstream>
#include <cmath>
#include <vector>


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	int img;
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	shape() {}
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected

	int getID(); // get the ID to be used in Graph
	void setID(int id); // set ID 

	void SetDeleted(bool s);	//delete/restore the shape
	bool IsDeleted() const;	//check whether fig is deleted

	void SetFilled(bool s);
	bool IsFilled() const;

	void SetImgSticked(bool s);
	void SetImgSticked(int img_);
	bool IsImgSticked() const;

	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	virtual void Drawdouble(GUI* pUI) const = 0;


	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	color GetDrawClr() const;
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	color GetFillClr() const;
	void ChngPenWidth(int c);	   //changes the shape's Pen Width
	int GetPenWidth() const;
	virtual bool isInside(int X,int Y) = 0;
	

	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	

	virtual void setCorners(vector <Point>) = 0;
	virtual void getCorners(vector <Point>&) = 0;

	//virtual Point GetCenter() = 0;   //   to get the points of the shape4

	
	


	virtual void Rotate(double) = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar

	virtual void Hide(GUI*) = 0;
	/*virtual*/ //void UnHide(GUI* pUI) /*= 0*/;

	

	//To replicate this operation (code depends on operation type)
	/*virtual*/ //void Duplicate(GUI* PUI) /*= 0*/;
	
};

