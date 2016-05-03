// g++ Slide1-atv2.cpp -o Slide1-atv2.o
#include <iostream>

using namespace std;

typedef struct
{
    int num, denom;

} racional_t;

int compare(racional_t num1, racional_t num2)
{
    double n1, n2;

    n1 = num1.num*1.0 / num1.denom*1.0;
    n2 = num2.num*1.0 / num2.denom*1.0;

    return n1 - n2;
    //num1 == num2 0
    // num1 > num2 -1
    // num1 < num2 1

}

void sort(racional_t* vec, racional_t* mai, racional_t* men, int tam)
{
    racional_t maior, menor;
    int compara;
    tam--;

    maior = vec[0];
    menor = vec[0];

    for(int i = 1; i <= tam; i++)
    {
        compara = compare(vec[i], maior);
        if(compara == -1)
            maior = vec[i];
        else
        if(compara == 1){
            compara = compare(vec[i], menor);
            if(compara == 1)
                menor = vec[i];
        }

    }

    *mai = maior;
    *men = menor;

}

int main(int argc, char const *argv[]) {

    int tam;
    racional_t *vRacionais;
    racional_t maior, menor;

    cout << "Digite a quantidade de numeros racionais (minimo 2): ";
    cin >> tam;
    if(tam < 2)
        tam = 2;

    vRacionais = new racional_t[tam - 1];
    if(vRacionais == NULL)
	{
		cout << "Error" << endl;
		return -1;
	}

    for (int i = 1; i <= tam; i++)
    {
        cout << endl << "Numerador " << i << ": ";
        cin >> vRacionais[i-1].num;
        cout << "Denominador " << i << ": ";
        cin >> vRacionais[i-1].denom;
    }

    sort(vRacionais, &maior, &menor, tam);

    cout << endl << "Maior numero: " << maior.num << "/" << maior.denom << endl;
    cout << "Menor numero: " << menor.num << "/" << menor.denom << endl;

    delete[] vRacionais;
    return 0;
}
