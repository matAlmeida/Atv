#include <math.h>

class complexos
{
public:

    explicit complexos(int, int);
    ~complexos();

    int real, imag;

    complexos& operator=(const complexos&);
    complexos operator+(const complexos&);
    complexos operator*(const complexos&);

    double getModulo();
    int compare();
};
