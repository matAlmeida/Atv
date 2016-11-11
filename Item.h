using namespace std;

class Item
{
private:
	string nome;
	int id;
public:
	Item(string nome, int id);
	string getNome();
	int getId();
};
