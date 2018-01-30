#include "Funcao_GDupla.hpp"
#include <math.h>

Funcao_GDupla::Funcao_GDupla(Funcao *f, double a, double b)
{
    funcao = f;
    pInitial = a;
    pFinal = b;
}

double Funcao_GDupla::f(double x)
{
    return funcao->f(xsdupla(x, pInitial, pFinal)) * ((pFinal - pInitial) / 2) *
            ((3.141592 * (exp(x) + exp(-x))) / (exp(2 * us(x)) + 2.0 +
                    exp(-2 * us(x))));
}
