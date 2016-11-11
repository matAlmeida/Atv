#include "Item.h"

using namespace std;

class Jogador
{
	typedef struct _itens
	{
		Item iten;
		Item *prox;
	}Items;
	
	private:
		string nome;
		int id;
		int nmrDrinks;
		Items drinks;
	public:
		Jogador(string nome, int id);
		void beber(Item drink);
		string getNome();
		int getId();
};
