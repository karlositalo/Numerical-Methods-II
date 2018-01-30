#include "GHE_P2.hpp"
#include <math.h>

GHE_P2::GHE_P2(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GHE_P2::integrar()
{
    double integral = 0.0;
    
    integral += integral += GHE_P2_integracao(m_pIntegrando, 0, 0);
    
    return integral;
}

double GHE_P2::GHE_P2_integracao(Funcao * f, double a, double b)
{
	
	double x1 = -(sqrt(2.0) / 2.0);
	double x2 = sqrt(2.0) / 2.0;
	
	double w1 = sqrt(3.141592) / 2;
	double w2 = sqrt(3.141592) / 2;
	
	return (w1 * m_pIntegrando->f(x1) + w2 * m_pIntegrando->f(x2));

}
