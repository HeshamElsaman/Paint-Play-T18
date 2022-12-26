#include "opUndo.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opUndo::opUndo(controller* pCont) :operation(pCont)
{}
opUndo::~opUndo()
{}

//Execute the operation
void opUndo::Execute()
{
	pControl->UNDO();
}
