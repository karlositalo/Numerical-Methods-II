#ifndef Funcao_G_hpp
#define Funcao_G_hpp

#include "math.h"
#include "Funcao.hpp"

class Funcao_G : public Funcao
{
public:
    Funcao_G(Funcao *f, double a, double b);

    double f(double x);
private:
    Funcao *funcao;
    double pInitial;
    double pFinal;
};

#endif /* Funcao_G_hpp */
