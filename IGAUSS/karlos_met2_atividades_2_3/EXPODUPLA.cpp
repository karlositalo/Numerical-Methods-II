#include "EXPODUPLA.hpp"
#include "NC_F_P2.hpp"
#include "Funcao_GDupla.hpp"
#include <math.h>

EXPODUPLA::EXPODUPLA(Funcao *f, double epsilon)
{
    m_pIntegrando = f;
    precisao = epsilon;
}

double EXPODUPLA::integrar()
{   
    int a = -1;
    int b = 1;
    
    double integral_anterior;
    double integral_atual;
    
    Funcao_GDupla *g = new Funcao_GDupla(m_pIntegrando, a, b);
    
    NC_F_P2 *metodoIntegracao = new NC_F_P2(g, a, b, 1, precisao);
    integral_atual = metodoIntegracao->integrar();
    
    do {
    
        integral_anterior = integral_atual;
        
        a = a * 10.0;
        b = b * 10.0;
        
        NC_F_P2 *metodoIntegracao = new NC_F_P2(g, a * 10, b * 10, 1, precisao);
        integral_atual = metodoIntegracao->integrar();
    
    } while (fabs(integral_anterior - integral_atual) > precisao);
    
    return integral_atual;
}
