// g++ -Wall -c libListaSE.hpp -o libListaSE.o
#include <iostream>

template <class T>
class ListaSE
{
public:
    ListaSE(T);
    bool inserirAntes(ListaSE *&, T);
    bool inserirApos(ListaSE *&, T);
    bool remover(ListaSE *&);
    T getObj();
    ListaSE *getProx();

private:
    T obj;
    ListaSE *prox;
};

template<class T>
ListaSE<T>::ListaSE(T obj)
{
    this->obj = obj;
    this->prox = NULL;
}

template<class T>
bool ListaSE<T>::inserirAntes(ListaSE *&head, T obj)
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

template<class T>
bool ListaSE<T>::inserirApos(ListaSE *&head, T obj)
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

template<class T>
bool ListaSE<T>::remover(ListaSE *&head)
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

template<class T>
T ListaSE<T>::getObj()
{
    return this->obj;
}

template<class T>
ListaSE<T> *ListaSE<T>::getProx()
{
    return this->prox;
}
