//
//  Funcao_5.hpp
//  IntegracaoNumerica
//
//  karlos
//

#ifndef Funcao_05_hpp
#define Funcao_05_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_05 : public Funcao
{
public:
    double f(double x)
    {
        return (x/tan(x));
    }
};


#endif /* Funcao_05_hpp */
