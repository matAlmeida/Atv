// g++ Lista3-atv2.cpp -o Lista3-atv2.o

#include <iostream>

using namespace std;

typedef struct tipo
{
    int num, denom;
    struct tipo *prox;

} tipo_t;

// void first(tipo_t *head, tipo_t *a)
// {
//     a = head;
// }

tipo_t* last(tipo_t *a){

    tipo_t *l;
    while((a -> prox) != NULL)
        l = a -> prox;

    return l;
}

tipo_t* ant(tipo_t *head, tipo_t *a)
{
    tipo_t *p;
    p = head;
    while((p -> prox) != a)
        p = p -> prox;

    return p;
}

tipo_t* succ(tipo_t *a)
{
    return a -> prox;
}

void rem(tipo_t *head, tipo_t *a)
{
    tipo_t *p;

    p = ant(head, a);
    p -> prox = a -> prox;

}

void ins(tipo_t *head, tipo_t *a, tipo_t *p)
{
    tipo_t *t;
    t = p;
    p = ant(head, p);
    p -> prox = a;
    a -> prox = t;
}

bool maior(tipo_t *a, tipo_t *b)
{
    double n1, n2;

    n1 = a -> num*1.0 / a -> denom*1.0;
    n2 = b -> num*1.0 / b -> denom*1.0;

    return n1 > n2;
}

void sortT(tipo_t *A)
{
    tipo_t *a, *k, *p, *head;
    head = A;

    a = last(A);

    while(a != head)
    {
        a = ant(head, a);
        k = a;
        rem(head, k);
        p = a;

        while(maior(k, succ(p)))
            p = succ(p);

        ins(head, a, p);
    }

}

int main(int argc, char const *argv[]) {
    tipo_t *lista, *start, *listaOrd;
    int num, denom, nplayers = 0;

    lista = new tipo_t;
    start = lista;

    cout << "Para finalizar digite \"0\" no Denominador." << endl << endl;

    cout << "Num " << nplayers+1 << ": ";
    cin >> num;
    cout << "Denom " << nplayers+1 << ": ";
    cin >> denom;

    while(denom != 0){
        nplayers++;
        lista -> num = num;
        lista -> denom = denom;
        lista -> prox = NULL;

        cout << "Num " << nplayers+1 << ": ";
        cin >> num;
        cout << "Denom " << nplayers+1 << ": ";
        cin >> denom;

        if(denom != 0)
        {
            lista -> prox = new tipo_t;
            lista = lista -> prox;
        }
    }

    lista = start;
    listaOrd = lista;

    if(nplayers != 0){
        cout << endl << "Lista na ordem de insercao: " << endl;

        for(int i = 0; i < nplayers; i++, lista = lista -> prox)
            cout << (lista -> num) << "/" << (lista -> denom) << "; ";
    }

    sortT(listaOrd);

    // for(int i = 0; i < nplayers; i++, listaOrd = listaOrd -> prox)
    //    cout << listaOrd -> num << "/" << listaOrd -> denom << "; ";

    return 0;
}
