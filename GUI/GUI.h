#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
	bool isDeleted = false;		//true if the shape is deleted
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_LINE,
		ICON_SQUARE,
		ICON_CIRC,		//Circle icon in menu
		ICON_TRI,
		ICON_OVAL,
		ICON_POLY,
		ICON_REGPOLY,
		ICON_CFC,
		ICON_CPC,
		ICON_CPW,
		ICON_COPY,
		ICON_CUT,
		ICON_PASTE,
		ICON_UNDO,
		ICON_REDO,
		ICON_STICK_IMG,
		ICON_DEL,
		ICON_SAVE,
		ICON_LOAD,
		//TODO: Add more icons names here
		ICON_SWITCH_TO_PLAY,
		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here
		//ICON_HIDE,		//Recangle icon in menu
		//ICON_UNHIDE,
		//ICON_MATCH_SHAPES,
		ICON_START,		//Circle icon in menu
		//ICON_RESTART,
		

		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	bool FillStatus = false; //General Fill Status
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color PickedColor;		// Picked color from the pallete
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed


	Point opLastPointClicked;
	window* pWind;

	window* pPalette = nullptr; // pointer for color pallete window only
	window* pChooseMode = nullptr;
	

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;
	void GetOpLastPointClicked(int& x, int& y) const;
	bool GetFillStatus() const;
	//Get coordinate where user clicks
	int GetClickType(int x, int y) const;

	void GetKeyPressed(char&) const;


	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation(); //Read the user click and map to an operation
	//void GetPalettePointClicked(int& x, int& y) const;
	void GetPaletteColorClicked(int x, int y, color&) const;
	void GetPalettePointClicked(int& x, int& y) const;
	void ChangeMode();
	void setCrntFillColor(color); //set current filling color
	void setFillStatus(bool);
	void setCrntDrawColor(color);
	void setCrntPenWidth(int);

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorPalette();
	void DeleteColorPalette();
	

	void CreateChooseWind();
	void DeleteChooseWind();

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	

	//void FlushKeyQueue();
	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawSquare(Point P1, Point P2,/*Point P3,*/ GfxInfo SquareGfxInfo) const;  //Draw a square
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo) const;
	void DrawOval(Point P1, Point P2, GfxInfo RectGfxInfo) const;
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const;  //Draw a line
	void Drawcircle(Point P1, Point P2, GfxInfo circleGfxInfo) const;  //Draw a circle
	void DrawPolygon(Point* verts, int vertn, GfxInfo PolygonGfxInfo) const;
	//void DrawImage(Point* verts, int vertn, GfxInfo Image) const;
	void DrawRegPolygon(Point* verts, int vertn, GfxInfo RegPolygonGfxInfo) const;


	///Make similar functions for drawing all other shapes.
	
	

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~GUI();
};

