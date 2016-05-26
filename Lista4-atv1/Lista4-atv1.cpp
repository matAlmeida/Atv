// g++ -Wall libCoord.o libListaSECoord.o Lista4-atv1.cpp -o Lista4-atv1.o
#include "libCoord.h"
#include "libListaSECoord.h"

int main(int argc, char const *argv[]) {

    char op;
    int i = 0, x, y;
    int xa, xb, xc, ya, yb, yc;
    double menor = 0;
    bool ret;
    Coordenada coord;
    Coordenada coorda, coordb, coordc;
    Coordenada coordM1, coordM2;
    ListaSE *lista = NULL;
    ListaSE *head = NULL;
    ListaSE *att = NULL;
    ListaSE *comp = NULL;

    //----------------------Distancia

    cout << "Comparar distancia 2 pontos a e b: " << endl << "Digite o (X) da coordenada (a): ";
    cin >> xa;
    cout << "Digite (Y) da coordenada (a): ";
    cin >> ya;
    coorda = Coordenada(xa, ya);
    cout << "Digite (X) da coodenada (b): ";
    cin >> xb;
    cout << "Digite (Y) da coordenada (b): ";
    cin >> yb;
    coordb = Coordenada(xb, yb);

    cout << endl << "A distancia entre os pontos a e b eh: " << coorda.getDistancia(coordb) << endl;

    //-----------------------Colinear + Triangulo

    cout << "Descobrir se 3 pontos a, b e c são colineares, ou formam um triangulo: " << endl << "Digite o (X) da coordenada (a): ";
    cin >> xa;
    cout << "Digite (Y) da coordenada (a): ";
    cin >> ya;
    coorda = Coordenada(xa, ya);
    cout << "Digite (X) da coodenada (b): ";
    cin >> xb;
    cout << "Digite (Y) da coordenada (b): ";
    cin >> yb;
    coordb = Coordenada(xb, yb);
    cout << "Digite (X) da coodenada (c): ";
    cin >> xc;
    cout << "Digite (Y) da coordenada (c): ";
    cin >> yc;
    coordc = Coordenada(xc, yc);

    if(coorda.isColinear(coordb, coordc))
        cout << "Os pontos a, b e c sao colineares!" << endl;
    else
        cout << "Os pontos a, b e c nao sao colineares, logo eles formam um Tringulo!" << endl;

    //--------------------------

    cout << "Pressione ENTER para continuar, X para sair..." << endl;
    op = cin.get();
    if(!(op == 'x') && !(op == 'X'))
    {
        do {
            i++;
            cout << "Digite o (X) da coordenada " << i << ":";
            cin >> x;
            cout << "Digite o (Y) da coordenada " << i << ":";
            cin >> y;
            coord = Coordenada(x, y);
            if(i == 1)
            {
                lista = new ListaSE(coord);
                head = lista;
            }
            else
            {
                ret = lista->inserirApos(lista, coord);
                if(!ret)
                {
                    cout << "ERRO!!" << endl;
                    return -1;
                }
                else
                    lista = lista->getProx();
            }

            cout << "Pressione ENTER para continuar, X para sair..." << endl;
            cin.ignore();
            op = cin.get();
        } while(!(op == 'x') && !(op == 'X'));
    }

    if(head != NULL)
    {
        att = head;
        for(int j = 0; j <= i && (att->getProx() != NULL); j++)
        {
            cout << "("<< att->getObj().getX() << ", " << att->getObj().getY() << ")" << ", ";
            att = att->getProx();
        }
        cout << endl;

        att = head;
        comp = att->getProx();
        menor = att->getObj().getDistancia(comp->getObj());
        coordM1 = att->getObj();
        coordM2 = comp->getObj();
        for(int w = i; w > 0 && (att->getProx() != NULL); w--)
        {
            for(int j = 0; j <= i && (comp->getProx() != NULL); j++)
            {
                comp = comp->getProx();
                if(att->getObj().getDistancia(comp->getObj()) < menor)
                {
                    menor = att->getObj().getDistancia(comp->getObj());
                    coordM1 = att->getObj();
                    coordM2 = comp->getObj();
                }
            }
            if((att->getProx() != NULL) &&(att->getProx()->getProx() != NULL))
            {
                att = att->getProx();
                comp = att->getProx();
                if(att->getObj().getDistancia(comp->getObj()) < menor)
                {
                    menor = att->getObj().getDistancia(comp->getObj());
                    coordM1 = att->getObj();
                    coordM2 = comp->getObj();
                }
            }
            else
                break;
        }

        cout << "Os pontos mais proximos da lista são: (" << coordM1.getX() << ", " << coordM1.getY() << ") e (" << coordM2.getX() << ", " << coordM2.getY() << ")" << endl;

    }

    return 0;
}
