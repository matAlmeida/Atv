// g++ -Wall -c libCoord.cpp -o libCoord.o
#include "libCoord.h"

Coordenada::Coordenada()
{
    this -> x = 0;
    this -> y = 0;
}

Coordenada::Coordenada(int x, int y)
{
    this -> x = x;
    this -> y = y;
}

double Coordenada::getDistancia(Coordenada coord2)
{
    return sqrt(pow(2, (this -> x) - coord2.x) + pow(2, (this -> y) - coord2.y));
}

bool Coordenada::isColinear(Coordenada coord2, Coordenada coord3)
{
    return ((((this -> x) == coord2.x) == coord3.x) || (((this -> y) == coord2.y) == coord3.y));
}

bool Coordenada::isTriangulo(Coordenada coord2, Coordenada coord3)
{
    return !(this -> isColinear(coord2, coord3));
}

double Coordenada::getArea(Coordenada coord2, Coordenada coord3)
{
    if(!(this -> isTriangulo(coord2, coord3)))
        return 0.0;
    else
    {
        return (this -> laplace(coord2, coord3))/2;
    }
}

int Coordenada::laplace(Coordenada coord2, Coordenada coord3)
{
    int a1, b1, c1;
    int a2, b2, c2;

    a1 = ((this -> x) * coord2.y);
    b1 = ((this -> y) * coord3.x);
    c1 = (coord2.x * coord3.y);

    a2 = (coord3.x * coord2.y);
    b2 = (coord3.y * (this -> x));
    c2 = (coord2.x * (this -> y));

    return abs((a1+b1+c1) - (a2+b2+c2));
}

int Coordenada::getX()
{
    return this -> x;
}

int Coordenada::getY()
{
    return this -> y;
}
