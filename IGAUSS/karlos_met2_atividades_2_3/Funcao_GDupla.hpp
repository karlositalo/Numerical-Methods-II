#ifndef Funcao_G_hpp
#define Funcao_G_hpp

#include "math.h"
#include "Funcao.hpp"

class Funcao_GDupla : public Funcao
{
public:
    Funcao_GDupla(Funcao *f, double a, double b);

    double f(double x);
private:
    Funcao *funcao;
    double pInitial;
    double pFinal;
};

#endif /* Funcao_GDupla_hpp */
