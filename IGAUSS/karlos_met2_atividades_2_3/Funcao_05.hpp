#ifndef Funcao_05_hpp
#define Funcao_05_hpp

#include "Funcao.hpp"
#include <math.h>

class Funcao_05 : public Funcao
{
public:
    double f(double x)
    {
        return sqrt(1.0 + (1.0 / x));
    }
};

#endif /* Funcao_05_hpp */
