#include "Cut.h"
#include "../Shapes&Graph/Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"
Cut::Cut(controller* pCont) :operation(pCont) {}
Cut::~Cut() {};
void Cut::Execute()
{

    Graph* pGr = pControl->getGraph();

    pGr->opCut();

    GUI* pUI = pControl->GetUI();
    pUI->PrintMessage("The shape was cut!");
}
void Cut::Undo() {}
void Cut::Redo() {}