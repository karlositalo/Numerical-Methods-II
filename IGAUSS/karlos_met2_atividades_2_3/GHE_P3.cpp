#include "GHE_P3.hpp"
#include <math.h>

GHE_P3::GHE_P3(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GHE_P3::integrar()
{
    double integral = 0.0;
    
    integral += integral += GHE_P3_integracao(m_pIntegrando, 0, 0);
    
    return integral;
}

double GHE_P3::GHE_P3_integracao(Funcao * f, double a, double b)
{
	
	double x1 = -(sqrt(6) / 2);
	double x2 = 0;
	double x3 = sqrt(6) / 2;
	
	double w1 = sqrt(3.141592) / 6;
	double w2 = (2 * sqrt(3.141592)) / 3;
	double w3 = sqrt(3.141592) / 6;
	
	return (w1 * m_pIntegrando->f(x1) + w2 * m_pIntegrando->f(x2) +
	        w3 * m_pIntegrando->f(x3));

}
