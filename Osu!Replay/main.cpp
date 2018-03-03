#include "main.h"

int main()
{
    vm = new VisualManager();
    Initialize();
    Update();
    return 0;
}

void Initialize()
{
    vm->Initialize();
}

void Update()
{
    for (;;)
    {
        if(!vm->Update()) break;
    }
}