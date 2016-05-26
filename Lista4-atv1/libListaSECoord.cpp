// g++ -Wall -c libListaSECoord.cpp -o libListaSECoord.o
#include "libListaSECoord.h"

ListaSE::ListaSE(Coordenada obj)
{
    this->obj = obj;
    this->prox = NULL;
}

bool ListaSE::inserirAntes(ListaSE *&head, Coordenada obj)
{
    bool ret = false;
    ListaSE *novo = new ListaSE(obj);
    ListaSE *ant;

    if(novo != NULL)
    {
        novo->prox = this;
        if(this == head)
            head = novo;
        else
        {
            ant = head;
            while(ant->prox != this)
                ant = ant->prox;
            ant->prox = novo;
        }
        ret = true;
    }

    return ret;
}

bool ListaSE::inserirApos(ListaSE *&head, Coordenada obj)
{
    bool ret = false;
    ListaSE *novo = new ListaSE(obj);

    if(novo != NULL)
    {
        if((this->prox) == NULL)
            this->prox = novo;
        else
        {
            novo->prox = this->prox;
            this->prox = novo;
        }

        ret = true;
    }

    return ret;
}

bool ListaSE::remover(ListaSE *&head)
{
    bool ret = false;
    ListaSE *ant;

    if((this == head) && (this->prox == NULL))
        head = NULL;
    else
    {
        if(this == head)
            head = this->prox;
        else
        {
            ant = head;
            while(ant->prox != this)
                ant = ant->prox;
            ant->prox = this->prox;
        }
    }

    ret = true;
    delete this;
    return ret;
}

Coordenada ListaSE::getObj()
{
    return this->obj;
}

ListaSE *ListaSE::getProx()
{
    return this->prox;
}
