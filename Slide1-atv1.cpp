// g++ Slide1-atv1.cpp -o Slide1-atv1.o
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct
{
    int real, imag;
} complexo_t;

void soma(complexo_t num1, complexo_t num2, complexo_t *soma)
{
    soma->real = num1.real + num2.real;
    soma->imag = num1.imag + num2.imag;
}

double escalar(complexo_t num1, complexo_t num2)
{
    return (num1.real * num2.real) + (num1.imag * num2.imag);
}

double modulo(complexo_t num)
{
    return sqrt(pow(2, num.real) + pow(2, num.imag));
}

void produto(complexo_t num1, complexo_t num2, complexo_t *produto)
{
    produto->real = ((num1.real * num2.real) - (num1.imag * num2.imag));
    produto->b = ((num1.real * num2.imag) + (num1.imag * num2.real));
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
                    cout << "Digite o Num Complexo 1: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;
                    cout << "Digite o Num Complexo 2: " << endl << "real: ";
                    cin >> num2.real;
                    cout << "imag: ";
                    cin >> num2.imag;

                    soma(num1, num2, &s);

                    cout << endl << "Resultado: " << s.real << " + " << s.imag << "i" << endl << endl;
                    break;

            case 2: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;
                    cout << "Digite o Num Complexo 2: " << endl << "real: ";
                    cin >> num2.real;
                    cout << "imag: ";
                    cin >> num2.imag;

                    escal = escalar(num1, num2);

                    cout << endl << "Resultado: " << escal << endl << endl;
                    break;

            case 3: system("clear");
                    cout << "Digite o Num Complexo: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;

                    mod = modulo(num1);

                    cout << endl << "Resultado: " << mod << endl << endl;
                    break;

            case 4: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;
                    cout << "Digite o Num Complexo 2: " << endl << "real: ";
                    cin >> num2.real;
                    cout << "imag: ";
                    cin >> num2.imag;

                    produto(num1, num2, &prod);

                    cout << endl << "Resultado: " << prod.real << " + " << prod.imag << "i" << endl << endl;
                    break;

            case 5: system("clear");
                    cout << "Digite o Num Complexo: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;

                    quadrado(num1, &quad);

                    cout << endl << "Resultado: " << quad.real << " + " << quad.imag << "i" << endl << endl;
                    break;

            default: cout << "Opcao Invalida!!" << endl;
        }
    } while(opt != 0);
    return 0;
}
