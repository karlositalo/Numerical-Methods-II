#ifndef Funcao_06_hpp
#define Funcao_06_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_06 : public Funcao
{
public:
    double f(double x)
    {
        return (x/tan(x));
    }
};


#endif /* Funcao_05_hpp */
