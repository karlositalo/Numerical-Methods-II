#include "EXPOSIMPLES.hpp"
#include "NC_F_P2.hpp"
#include "Funcao_G.hpp"
#include <math.h>
#include <iostream>

using namespace std;
EXPOSIMPLES::EXPOSIMPLES(Funcao *f, double epsilon)
{
    m_pIntegrando = f;
    precisao = epsilon;
}

double EXPOSIMPLES::integrar()
{   
    int a = 0;
    int b = 1;
    
    double integral_anterior;
    double integral_atual;
    
    Funcao_G *g = new Funcao_G(m_pIntegrando, a, b);

    NC_F_P2 *metodoIntegracao = new NC_F_P2(g, a, b, 1, precisao);
    integral_atual = metodoIntegracao->integrar();

    cout << "Integral atual:" <<integral_atual << endl;
    do {
    
        integral_anterior = integral_atual;
        
        a += 0.0;
        b *= 2.0;
        
        NC_F_P2 *metodoIntegracao = new NC_F_P2(g, a, b, 1, precisao);
        integral_atual = metodoIntegracao->integrar();
    
    } while (fabs(integral_anterior - integral_atual) > precisao);
    
    return integral_atual;
}
