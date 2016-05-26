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
    if(this -> laplace(coord2, coord3) == 0)
        return 1;
    else
        return 0;
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
    int ret;

    a1 = ((this -> x) * coord2.y); // 0
    b1 = ((this -> y) * coord3.x); // 10
    c1 = (coord2.x * coord3.y);    // 1

    a2 = (coord3.x * coord2.y);    // 6
    b2 = (coord3.y * (this -> x)); // 0
    c2 = (coord2.x * (this -> y)); // 5

    ret = (a1+b1+c1) - (a2+b2+c2);
    if(ret >= 0 )
        return ret;
    else
        return ret * (-1);
}

int Coordenada::getX()
{
    return this -> x;
}

int Coordenada::getY()
{
    return this -> y;
}

void Coordenada::setX(int x)
{
    this -> x = x;
}

void Coordenada::setY(int y)
{
    this -> y = y;
}
