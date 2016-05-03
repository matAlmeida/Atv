// g++ Lista2-atv1.cpp -o Lista2-atv1.o
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    string *nomes, *start, *end, *now;
    string elim = "Eliminado";
    int n, participantes, x = 0;

    cout << "Entre qnt participantes: ";
    cin >> participantes;

    nomes = new string[participantes];
    start = now = &nomes[0];
    end = &nomes[participantes];

    for(int i = 0; i < participantes; i++)
    {
        cout << "Nome participante " << i+1 << ": ";
        cin >> nomes[i];
    }

    cout << "Entre com o Numero n: ";
    cin >> n;

    for(int j = 0; j < participantes - 1; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(x < participantes)
                x++;
            else
                x = 0;
        }

        now = &nomes[x];

        if(now->compare(elim) == 0)
            while(now->compare(elim) == 0){
                if(now == end)
                    now = start;
                else
                    now++;
            }

        cout << "Jogador " << *now << " foi ELIMINADO!!!" << endl;
        *now = elim;
        if(now == end)
        {
            now = start;
            x = 0;
        }
        else
        {
            now++;
            x++;
        }
    }

    for(int i = 0; i < participantes; i++)
        if(nomes[i] != elim)
            cout << "Jogador " << nomes[i] << " foi CAMPEAO!!!" << endl;

    delete[] nomes;
    return 0;
}
