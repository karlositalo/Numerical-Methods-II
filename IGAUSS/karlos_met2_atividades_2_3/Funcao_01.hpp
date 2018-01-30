#ifndef Funcao_01_hpp
#define Funcao_01_hpp

#include "Funcao.hpp"

class Funcao_01 : public Funcao
{
public:
    double f(double x)
    {
        return (x/tan(x));
    }
};

#endif /* Funcao_01_hpp */
