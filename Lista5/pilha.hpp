// g++ -c pilha.hpp -o libPilha.o
#include <iostream>

template<class T>
class Pilha
{
    public:
        Pilha();
	    Pilha(T);
	    void empilha(Pilha *&, T);
        T desempilha(Pilha *&);
        bool troca(Pilha *&);
        bool ehVazio(Pilha *&);
    private:
        T obj;
        Pilha *abaixo;
};

template<class T>
Pilha<T>::Pilha()
{
    this->obj = NULL;
    this->abaixo = NULL;
}

template<class T>
Pilha<T>::Pilha(T obj)
{
    this->obj = obj;
    this->abaixo = NULL;
}

template<class T>
void Pilha<T>::empilha(Pilha *&topo, T obj)
{
    Pilha *novo = new Pilha(obj);

    novo->abaixo = topo;
    topo = novo;
}

template<class T>
T Pilha<T>::desempilha(Pilha *&topo)
{
    T obj = topo->obj;

    if(topo->abaixo != NULL)
	   topo = topo->abaixo;
    else
	   delete topo;

    return obj;
}

template<class T>
bool Pilha<T>::troca(Pilha *&topo)
{
    bool ret = false;

    if(topo->abaixo != NULL)
    {
        Pilha *aux = topo->abaixo;
        topo->abaixo = aux->abaixo;
        aux->abaixo = topo;
        topo = aux;

        delete aux;
        ret = true;
    }

    return ret;
}

template<class T>
bool Pilha<T>::ehVazio(Pilha *&topo)
{
    return topo == NULL;
}
