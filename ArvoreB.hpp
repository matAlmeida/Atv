// g++ -Wall -c ArvoreB.hpp -o ArvoreB.o
#include <iostream>

using namespace std;

class ArvoreB
{
	private:
		int m;
		int *chaves[];
		int nChaves;
		ArvoreB *filhos[];
		ArvoreB *raiz;
	public:
		ArvoreB(int, ArvoreB);
		void addChave(int);
		
};

ArvoreB::ArvoreB(int m, ArvoreB raiz)
{
	this->m = m;
	this->chaves = new int[m-1];
	this->filhos = new ArvoreB(m, this)[m];
	*this->raiz = raiz;
	this->nChaves = 0;
}

void ArvoreB::addChave(int chave)
{
	if(nChaves < m-1)
	{
		*this->chaves[this->nChaves] = chave;
		//sort(this->chaves);
	}
	else
	{
		
	}
}
