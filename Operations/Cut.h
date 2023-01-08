#pragma once
#include "operation.h"
class controller;
class Cut :public operation
{
public:
    Cut(controller* pCont);
    ~Cut();
    void Execute();
    virtual void Undo() override;
    virtual void Redo() override;
};