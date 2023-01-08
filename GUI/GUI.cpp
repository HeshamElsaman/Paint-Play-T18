#include "GUI.h"
#include <iostream>

GUI::GUI()
{
	//Initialize user interface parameters
	//InterfaceMode = MODE_DRAW;


	width = 1300;
	height = 650;


	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = double(width) / DRAW_ICON_COUNT;
	MenuIconWidth = double(width) / DRAW_ICON_COUNT;

	DrawColor = BLUE;	//default Drawing color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	FillColor = BkGrndColor;	//default Filling color
	MsgColor = BLACK;		//Messages color
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames
	
	//pChooseMode = CreateWind(width, height, wx, wy);

	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");
	//setInterface();

	//pChooseMode = CreateWind(400, 450, wx, wy);

	//pChooseMode->ChangeTitle("- - - - - - - - - - Choose Mode - - - - - - - - - -");

	CreateChooseWind();
	ChangeMode();
	//CreateDrawToolBar();
	//CreatePlayToolBar();
	CreateStatusBar();
	//GetChooseModePointClicked();

}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
clicktype GUI::GetOpLastPointClicked(int& x, int& y) const
{
	x = opLastPointClicked.x;
	y = opLastPointClicked.y;
	return opLastPointClickedType;
}
clicktype GUI::GetOpLastPointClickedType() const
{
	return opLastPointClickedType;
}

void GUI::FlushMQue() const
{
	pWind->FlushMouseQueue();
}
//////////////////////////////////////////////////////////////////////////////////////////

/*void GUI::open(const char* Pictures, imagetype itThisType = JPEG)
{
	 image.Open();
}*/

/////////////////////////////////////////////////////////////////////////////////////////
int GUI::GetClickType(int x, int y) const
{
	return int(pWind->WaitMouseClick(x, y));
}
/////////////////////////////////////////////////////////////////////////////////////////

/*void GUI::draw(GUI* m)
{
	pWind->Draw
}*/






/////////////////////////////////////////////////////////////////////////////////////
keytype GUI::GetKeyPressed(char& key) const
{
	return pWind->GetKeyPress(key);
}
////////////////////////////////////////////////////////////////////////////
void GUI::StickImage(int img, int x, int y, int length, int width)
{
	string IMG = "Images\\StickingImages\\" + to_string(img) + ".jpg";
	pWind->DrawImage(IMG, x, y, width, length);
}
///////////////////////////////////////////////////////////////////////////////////
void GUI::StickImage_(int x, int y, int length, int width)
{
	string IMG = "Images\\StickingImages\\" + to_string(1) + ".jpg";
	pWind->DrawImage(IMG, x, y, width, length);
}


///////////////////////////////////////////////////////////////////////////////////////////
string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;		
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

buttonstate GUI::GetButtonState(button btn, int& iX, int& iY) const
{
	return pWind->GetButtonState(btn, iX, iY);
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation()
{
	
	int x = -1, y = -1;
	
	while (GetButtonState(LEFT_BUTTON, x, y) == BUTTON_UP && GetButtonState(RIGHT_BUTTON, x, y) == BUTTON_UP) {
		if (GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN)
		{
			opLastPointClickedType = LEFT_CLICK;
			//while(GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN) {}
			//Sleep(10);
			break;
		}
		if (GetButtonState(RIGHT_BUTTON, x, y) == BUTTON_DOWN)
		{
			opLastPointClickedType = RIGHT_CLICK;
			//while (GetButtonState(RIGHT_BUTTON, x, y) == BUTTON_DOWN) {}
			//Sleep(10);
			break;
		}
	}
	//while (GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN || GetButtonState(RIGHT_BUTTON, x, y) == BUTTON_DOWN){}

	//opLastPointClickedType = pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	
	opLastPointClicked.x = x;
	opLastPointClicked.y = y;
	
	if (InterfaceMode == MODE_DRAW && x != -1 && y != -1)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT:
				return DRAW_RECT;

			case ICON_LINE:
				return DRAW_LINE;

			case ICON_SQUARE:
				return DRAW_SQR;

			case ICON_TRI:
				return DRAW_TRI;

			case ICON_CIRC:
				return DRAW_CIRC;

			case ICON_OVAL:
				return DRAW_OVAL;

			case ICON_POLY:
				return DRAW_POLY;

			case ICON_REGPOLY:
				return DRAW_REGPOLY;

			case ICON_CFC:
				return CHNG_FILL_CLR;

			case ICON_CPC:
				return CHNG_DRAW_CLR;

			case ICON_CPW:
				return CHNG_PEN_WIDTH;

			case ICON_COPY:
				return COPY;

			case ICON_CUT:
				return CUT;

			case ICON_PASTE:
				return PASTE;

			case ICON_ROTATE:
				return ROTATE;

			case ICON_RESIZE:
				return RESIZE;

			case ICON_UNDO:
				return UNDO;

			case ICON_REDO:
				return REDO;

			case ICON_STICK_IMG:
				return STICK_IMG;
			
			case ICON_DEL:
				return DEL;

			case ICON_SAVE:
				return SAVE;

			case ICON_LOAD:
				return LOAD;

			case ICON_ZOOM_IN:
				return ZOOM_IN;

			case ICON_ZOOM_OUT:
				return ZOOM_OUT;

			case ICON_DUBLICATE:
				return DUBLICATE;
		

			case ICON_SWITCH_TO_PLAY:
				return TO_PLAY;

			case ICON_EXIT:
				return EXIT_DRAW;

			default:
				return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	//GUI is in PLAY mode
	else (InterfaceMode == MODE_PLAY && x != -1 && y != -1); {
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_HIDE:
				return HIDE;

			case ICON_UNHIDE:
				return UNHIDE;

			case ICON_START:
				return START;

			case ICON_RESTART:
				return RESTART;

			case ICON_MATCH_SHAPES:
				return MATCH_SHAPES;

			case ICON_SCRAMBLE:
				return SCRAMBLE;

			case ICON_EXIT_PLAY:
				return EXIT_PLAY;


			default:
				return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}//GUI in the PLAY mode
	//GUI in the Draw mode
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding operation
		return TO_PLAY;	//just for now. This should be updated
	

}
////////////////////////////////////////////////////
bool GUI::GetFillStatus() const
{
	return FillStatus;
}
////////////////////////////////////////////////////
void GUI::setCrntFillColor(color clr) //set current filling color
{
	FillColor = clr;
}

void GUI::setCrntDrawColor(color clr) //set current filling color
{
	DrawColor = clr;
}

void GUI::setCrntPenWidth(int s) //set current pen width
{
	PenWidth = s;
}
////////////////////////////////////////////////////
void GUI::setFillStatus(bool stat)
{
	FillStatus = stat;
}
void GUI::setSelectMode(bool S)
{
	MultiSelectMode = S;
}
void GUI::setDragMode(bool D)
{
	DragMode = D;
}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
///////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreateColorPalette()
{
	
	
	pWind->DrawImage("Images\\MenuIcons\\Menu_ColorPalette.jpg", 100,200);
	pWind->SetBuffering(0);
	pWind->SetWaitClose(false);
}

void GUI::CreateChooseWind()
{
	pChooseMode = CreateWind(500, 400, 200, 90);
	pChooseMode->ChangeTitle("Choose Your Mode");
	pChooseMode->DrawImage("DrawOrPlay.jpg", 0,0);
	//pChooseMode->SetBuffering(0);
	pChooseMode->SetWaitClose(false);
	//pChooseMode->GetMode();
}


void GUI::DeleteChooseWind()
{
	if (pChooseMode)
	{
		delete pChooseMode; pChooseMode = nullptr;
	}
}



void GUI::GetPalettePointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);
}

void GUI::ChangeMode()
{
	Point P;
	pChooseMode->WaitMouseClick(P.x, P.y);
	

	if ((P.y >= 0) && (P.y <= 400) && (P.x >= 0) && (P.x <= 250))
	{

		//InterfaceMode == MODE_PLAY;
		CreateDrawToolBar();
		DeleteChooseWind();
	}
	else
	{
		//InterfaceMode == MODE_DRAW;
		CreatePlayToolBar();
		DeleteChooseWind();
	}
}







void GUI::GetPaletteColorClicked(int x, int y, color& clr) const
{
	clr = pWind->GetColor(x, y);
}
bool GUI::getSelectMode() const
{
	return MultiSelectMode;
}
bool GUI::getDragMode() const
{
	return DragMode;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
void GUI::CreateCards()
{

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\DrawMenu\\Menu_Rect.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\DrawMenu\\Menu_Line.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\DrawMenu\\Menu_Square.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\DrawMenu\\Menu_Triangle.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\DrawMenu\\Menu_Circ.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\DrawMenu\\Oval.jpg";
	MenuIconImages[ICON_POLY] = "images\\MenuIcons\\DrawMenu\\Menu_Polygon.jpg";
	MenuIconImages[ICON_REGPOLY] = "images\\MenuIcons\\DrawMenu\\Menu_RegPolygon.jpg";
	MenuIconImages[ICON_CFC] = "images\\MenuIcons\\DrawMenu\\Menu_FillColor.jpg";
	MenuIconImages[ICON_CPC] = "images\\MenuIcons\\DrawMenu\\Menu_PenColor.jpg";
	MenuIconImages[ICON_CPW] = "images\\MenuIcons\\DrawMenu\\Menu_PenWidth.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\DrawMenu\\Menu_Copy.jpg";
	MenuIconImages[ICON_CUT] = "images\\MenuIcons\\DrawMenu\\Menu_Cut.jpg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\DrawMenu\\Menu_Paste.jpg";
	MenuIconImages[ICON_ROTATE] = "images\\MenuIcons\\DrawMenu\\Menu_Rotate90.jpg";
	MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\DrawMenu\\Menu_Resize.jpg";
	MenuIconImages[ICON_UNDO] = "images\\MenuIcons\\DrawMenu\\Menu_Undo.jpg";
	MenuIconImages[ICON_REDO] = "images\\MenuIcons\\DrawMenu\\Menu_Redo.jpg";
	MenuIconImages[ICON_STICK_IMG] = "images\\MenuIcons\\DrawMenu\\Menu_StickImage.jpg";
	MenuIconImages[ICON_DEL] = "images\\MenuIcons\\DrawMenu\\Menu_Delete.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\DrawMenu\\Menu_Save.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\DrawMenu\\Menu_Load.jpg";
	MenuIconImages[ICON_ZOOM_IN] = "images\\MenuIcons\\DrawMenu\\Menu_ZoomIn.jpg";
	MenuIconImages[ICON_ZOOM_OUT] = "images\\MenuIcons\\DrawMenu\\Menu_ZoomOut.jpg";
	MenuIconImages[ICON_SEND_TO_BACK] = "images\\MenuIcons\\DrawMenu\\Menu_SendToBack.jpg";
	MenuIconImages[ICON_DUBLICATE] = "images\\MenuIcons\\DrawMenu\\Menu_Duplicate.jpg";
	MenuIconImages[ICON_SWITCH_TO_PLAY] = "images\\MenuIcons\\DrawMenu\\Menu_Switch_To_PlayMode.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\DrawMenu\\Menu_Exit.jpg";
	
	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	if (InterfaceMode == MODE_DRAW)
	{
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(0, 0, width, ToolBarHeight);
		for (int i = 0; i < DRAW_ICON_COUNT; i++) {
			pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

		}
		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	}

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu


	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICON_START] = "images\\MenuIcons\\PlayMenu\\Start.jpg";
	MenuIconImages[ICON_HIDE] = "images\\MenuIcons\\PlayMenu\\Hide.jpg";
	MenuIconImages[ICON_UNHIDE] = "images\\MenuIcons\\PlayMenu\\Unhide.jpg";
	MenuIconImages[ICON_MATCH_SHAPES] = "images\\MenuIcons\\PlayMenu\\Match.jpg";
	MenuIconImages[ICON_SCRAMBLE] = "images\\MenuIcons\\PlayMenu\\Scramble.jpg";
	MenuIconImages[ICON_RESTART] = "images\\MenuIcons\\PlayMenu\\Restart.jpg";
	//MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\DrawMenu\\Oval.jpg";
	//MenuIconImages[ICON_POLY] = "images\\MenuIcons\\DrawMenu\\Menu_Polygon.jpg";
	//MenuIconImages[ICON_REGPOLY] = "images\\MenuIcons\\DrawMenu\\Menu_RegPolygon.jpg";
	////MenuIconImages[ICON_REGPOLY] = "images\\MenuIcons\\DrawMenu\\Menu_RegPolygon.jpg";
	////MenuIconImages[ICON_REGPOLY] = "images\\MenuIcons\\DrawMenu\\Menu_RegPolygon.jpg";
	//MenuIconImages[ICON_DEL] = "images\\MenuIcons\\DrawMenu\\Menu_Delete.jpg";
	//MenuIconImages[ICON_CFC] = "images\\MenuIcons\\DrawMenu\\Menu_FillColor.jpg";
	MenuIconImages[ICON_EXIT_PLAY] = "images\\MenuIcons\\DrawMenu\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	if (InterfaceMode == MODE_PLAY)
	{
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(0, 0, width, ToolBarHeight);
		for (int i = 0; i < PLAY_ICON_COUNT; i++) {
			pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

		}

         //Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

	}
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//////////////////////////////////////////////////////////////////////////////////////////



//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

	/*int Width = P2.x - P1.x;
	int Length= P2.y - P1.y;*/

	

}
//Drawing square by manpiulating a rectangle 
void GUI::DrawSquare(Point P1, Point P2,/* Point P3,*/ GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}
////////////////////////////////////////////////////////////////
void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo) const
{
	color DrawingClr;
	if (TriangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	
}
////////////////////////////////////////////////////////////////
void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const
{
	color DrawingClr;
	if (LineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
///////////////////////////////////////////////////////////
void GUI::Drawcircle(Point P1, Point P2, GfxInfo circleGfxInfo) const
{
	color DrawingClr;
	if (circleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, circleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (circleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	pWind->DrawCircle(P1.x, P1.y, radius, style);

}
////////////////////////////////////////////////////////
void GUI::DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const
{
	color DrawingClr;
	if (OvalGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;
	//if (P2.x < P1.x) {
	//	Point temp1 = P1;
	//	Point temp2 = P2;
	//	P1.x = temp2.x;
	//	P2.x = temp1.x;
	//}

	//if (P2.y < P1.y) {
	//	Point temp1 = P1;
	//	Point temp2 = P2;
	//	P1.y = temp2.y;
	//	P2.y = temp1.y;
	//}
	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
	/*pWind->DrawArc(P1.x, P1.y, P2.x, P2.y, 0, 180, style);
	pWind->DrawArc(P1.x, P1.y, P2.x, P2.y, 180, 360, style);*/

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::DrawPolygon(Point* verts, int vertn, GfxInfo PolygonGfxInfo) const
{
	color DrawingClr;
	if (PolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = PolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, PolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (PolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int* X = new int[vertn];
	int* Y = new int[vertn];
	for (int i = 0; i < vertn; i++) {
		X[i] = verts[i].x;
		Y[i] = verts[i].y;
	}

	pWind->DrawPolygon(X, Y, vertn, style);
	delete[] X; delete[] Y;
	X = nullptr; Y = nullptr;

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::DrawRegPolygon(Point* verts, int vertn, GfxInfo RegPolygonGfxInfo) const
{
	color DrawingClr;
	if (RegPolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RegPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RegPolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RegPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RegPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int* X = new int[vertn];
	int* Y = new int[vertn];
	for (int i = 0; i < vertn; i++) {
		X[i] = verts[i].x;
		Y[i] = verts[i].y;
	}

	pWind->DrawPolygon(X, Y, vertn, style);
	delete[] X; delete[] Y;
	X = nullptr; Y = nullptr;
}
//////////////////////////////////////////////////////////////////////////////////////////

GUI::~GUI()
{
	delete pWind;

}

