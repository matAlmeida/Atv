#pragma once
#include <iostream>
#include "libCoord.h"

class ListaSE
{
public:
    ListaSE(Coordenada);
    bool inserirAntes(ListaSE *&, Coordenada);
    bool inserirApos(ListaSE *&, Coordenada);
    bool remover(ListaSE *&);
    Coordenada getObj();
    ListaSE *getProx();

private:
    Coordenada obj;
    ListaSE *prox;
};
