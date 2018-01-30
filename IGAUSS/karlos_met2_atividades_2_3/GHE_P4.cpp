#include "GHE_P4.hpp"
#include <math.h>

GHE_P4::GHE_P4(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GHE_P4::integrar()
{
    double integral = 0.0;
    
    integral += integral += GHE_P4_integracao(m_pIntegrando, 0, 0);
    
    return integral;
}

double GHE_P4::GHE_P4_integracao(Funcao * f, double a, double b)
{
	
	double x1 = -(sqrt((3 + sqrt(6)) / 2));
	double x2 = -(sqrt((3 - sqrt(6)) / 2));
	double x3 = sqrt((3 - sqrt(6)) / 2);
	double x4 = sqrt((3 + sqrt(6)) / 2);
	
	double w1 = sqrt(3.141592) / (4 * (3 + sqrt(6)));
	double w2 = sqrt(3.141592) / (4 * (3 - sqrt(6)));
	double w3 = sqrt(3.141592) / (4 * (3 - sqrt(6)));
	double w4 = sqrt(3.141592) / (4 * (3 + sqrt(6)));
	
	return (w1 * m_pIntegrando->f(x1) + w2 * m_pIntegrando->f(x2) +
	        w3 * m_pIntegrando->f(x3) + w4 * m_pIntegrando->f(x4));

}
