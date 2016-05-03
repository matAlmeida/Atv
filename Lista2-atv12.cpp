// g++ Lista2-atv12.cpp -o Lista2-atv12.o

#include <iostream>

using namespace std;

typedef struct
{
    string nome;
    bool jogando;

} jogador_t;

int main(int argc, char const *argv[]) {
    jogador_t jogadores[5];
    jogadores[0].nome = "maria";
    jogadores[0].jogando = true;
    jogadores[1].nome = "joao";
    jogadores[1].jogando = true;
    jogadores[2].nome = "jose";
    jogadores[2].jogando = true;
    jogadores[3].nome = "player";
    jogadores[3].jogando = true;
    jogadores[4].nome = "jovem";
    jogadores[4].jogando = true;

    jogador_t *joga;
    int playing = 0;
    int size = (sizeof(jogadores) / sizeof(jogadores[0]));
    int ingame = size;
    int numero;

    joga = &jogadores[playing];

    cin >> numero;

    for(int j = 0; j < size && (ingame > 1); j++){
        for(int i = 0; i < numero; i++)
        {
            if(playing >= size)
            {
                playing = 0;
                joga = &jogadores[playing];
                while((joga->jogando) == false)
                {
                    joga++;
                    playing++;
                }
            }

            while(!(joga->jogando)){
                joga++;
                playing++;
            }
        }

        joga->jogando = false;
        cout << "Eliminado: " << (joga->nome) << endl;
        ingame--;

        while(!(joga->jogando))
        {
            joga++;
            playing++;
        }
    }

    cout << "Campeao: " << (joga->nome) << endl;


    return 0;
}
