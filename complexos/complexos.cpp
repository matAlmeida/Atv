// g++ -c complexos.cpp -o libComplexos.o

#include "complexos.h"

complexos::complexos(int real, int imag)
{
    this->real = real;
    this->imag = imag;
}

complexos::~complexos(){}

complexos& complexos::operator=(const complexos& num)
{
    real = num.real;
    imag = num.imag;
    return *this;
}

complexos complexos::operator+(const complexos& num)
{
    return complexos(real + num.real, imag + num.imag);
}

complexos complexos::operator*(const complexos& num)
{
    return complexos(((real * num.real) - (imag * num.imag)), ((real * num.imag) + (imag * num.real)));
}

double complexos::getModulo()
{
    return sqrt(pow(2, this->real) + pow(2, this->imag));
}
