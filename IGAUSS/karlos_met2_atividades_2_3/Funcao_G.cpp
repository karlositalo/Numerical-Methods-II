#include "Funcao_G.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Funcao_G::Funcao_G(Funcao *f, double a, double b)
{
    funcao = f;
    pInitial = a;
    pFinal = b;
}

double Funcao_G::f(double x)
{
 	//cout << "f(xs(x)) " << funcao->f(xs(x, pInitial, pFinal)) << endl;
    return funcao->f(xs(x, pInitial, pFinal)) * ((pFinal - pInitial) / 2) *
            (4.0 / (exp(2.0 * x) + 2.0 + exp(-2.0 * x)));
}
