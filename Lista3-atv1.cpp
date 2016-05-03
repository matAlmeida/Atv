// g++ Lista3-atv1.cpp -o Lista3-atv1.o

#include <iostream>

using namespace std;

typedef struct st_player
{
    string name;
    struct st_player *next;

} player_t;

int main(int argc, char const *argv[]) {
    player_t *p, *start, *remover;
    string name;
    int n, nplayers = 1, op = 1;

    p = new player_t;
    start = p;

    cout << "\"0\" pra continuar, \"1\" para adicionar jogadores" << endl;

    while(op != 0){
        cout << "jogador " << nplayers << ": ";
        cin >> p->name;
        cout << "adicionar mais jogadores? ";
        cin >> op;
        cout << endl;
        if(op != 0)
        {
            nplayers++;
            p->next = new player_t;
            p = p->next;
        }
    }

    p->next = start;
    p = start;

    cout << "n: ";
    cin >> n;

    for(int j = 0; j < nplayers - 1; j++){
        for(int i; i < n-1; i++)
            p = p->next;

            remover = p->next;
            p->next = remover->next;
            delete remover;
            p = p->next;
    }

    cout << "ganhador: " << p->name << endl;

    delete p;

    return 0;
}
