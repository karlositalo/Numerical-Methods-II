#include "GLA_P2.hpp"
#include <math.h>

GLA_P2::GLA_P2(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GLA_P2::integrar()
{
    double integral = 0.0;
    
    integral += integral += GLA_P2_integracao(m_pIntegrando, 0, 0);
    
    return integral;
}

double GLA_P2::GLA_P2_integracao(Funcao * f, double a, double b)
{
	
	double x1 = 0.585786;
	double x2 = 3.41421;
	
	double w1 = 0.853553;
	double w2 = 0.146447;
	
	return (w1 * m_pIntegrando->f(x1) + w2 * m_pIntegrando->f(x2));

}
