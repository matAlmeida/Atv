// g++ Slide1-atv1.cpp -o Slide1-atv1.o
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct
{
    int a, b;
} complexo_t;

void soma(complexo_t num1, complexo_t num2, complexo_t *soma)
{
    soma->a = num1.a + num2.a;
    soma->b = num1.b + num2.b;
}

double escalar(complexo_t num1, complexo_t num2)
{
    return (num1.a * num2.a) + (num1.b * num2.b);
}

double modulo(complexo_t num)
{
    return sqrt(pow(2, num.a) + pow(2, num.b));
}

void produto(complexo_t num1, complexo_t num2, complexo_t *produto)
{
    produto->a = ((num1.a * num2.a) - (num1.b * num2.b));
    produto->b = ((num1.a * num2.b) + (num1.b * num2.a));
}

void quadrado(complexo_t num, complexo_t *quadrado)
{
    produto(num, num, quadrado);
}

int main(int argc, char const *argv[]) {

    int opt;
    double escal, mod;
    complexo_t num1, num2, s, prod, quad;

    do {
        cout << "Calculadora de Numeros Complexos" << endl;
        cout << "<1> Soma" << endl << "<2> Escalar" << endl << "<3> Modulo" << endl << "<4> Produto" << endl << "<5> Quadrado" << endl << "<0> Sair" << endl;
        cout << endl << "Escolha uma opcao: ";
        cin >> opt;
        switch (opt) {
            case 0: break;

            case 1: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "a: ";
                    cin >> num1.a;
                    cout << "b: ";
                    cin >> num1.b;
                    cout << "Digite o Num Complexo 2: " << endl << "a: ";
                    cin >> num2.a;
                    cout << "b: ";
                    cin >> num2.b;

                    soma(num1, num2, &s);

                    cout << endl << "Resultado: " << s.a << " + " << s.b << "i" << endl << endl;
                    break;

            case 2: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "a: ";
                    cin >> num1.a;
                    cout << "b: ";
                    cin >> num1.b;
                    cout << "Digite o Num Complexo 2: " << endl << "a: ";
                    cin >> num2.a;
                    cout << "b: ";
                    cin >> num2.b;

                    escal = escalar(num1, num2);

                    cout << endl << "Resultado: " << escal << endl << endl;
                    break;

            case 3: system("clear");
                    cout << "Digite o Num Complexo: " << endl << "a: ";
                    cin >> num1.a;
                    cout << "b: ";
                    cin >> num1.b;

                    mod = modulo(num1);

                    cout << endl << "Resultado: " << mod << endl << endl;
                    break;

            case 4: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "a: ";
                    cin >> num1.a;
                    cout << "b: ";
                    cin >> num1.b;
                    cout << "Digite o Num Complexo 2: " << endl << "a: ";
                    cin >> num2.a;
                    cout << "b: ";
                    cin >> num2.b;

                    produto(num1, num2, &prod);

                    cout << endl << "Resultado: " << prod.a << " + " << prod.b << "i" << endl << endl;
                    break;

            case 5: system("clear");
                    cout << "Digite o Num Complexo: " << endl << "a: ";
                    cin >> num1.a;
                    cout << "b: ";
                    cin >> num1.b;

                    quadrado(num1, &quad);

                    cout << endl << "Resultado: " << quad.a << " + " << quad.b << "i" << endl << endl;
                    break;

            default: cout << "Opcao Invalida!!" << endl;
        }
    } while(opt != 0);
    return 0;
}
