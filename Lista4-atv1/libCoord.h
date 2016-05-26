#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Coordenada
{
public:
    Coordenada();
    Coordenada(int, int);

    double getDistancia(Coordenada);
    bool isColinear(Coordenada, Coordenada);
    bool isTriangulo(Coordenada, Coordenada);
    double getArea(Coordenada, Coordenada);
    int getX();
    int getY();
    void setX(int);
    void setY(int);

private:
    int x, y;
    int laplace(Coordenada, Coordenada);
};
