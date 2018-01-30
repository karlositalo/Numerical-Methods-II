#include "GLA_P3.hpp"
#include <math.h>

GLA_P3::GLA_P3(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GLA_P3::integrar()
{
    double integral = 0.0;
    
    integral += integral += GLA_P3_integracao(m_pIntegrando, 0, 0);
    
    return integral;
}

double GLA_P3::GLA_P3_integracao(Funcao * f, double a, double b)
{
	
	double x1 = 0.415775;
	double x2 = 2.29428;
	double x3 = 6.28995;
	
	double w1 = 0.711093;
	double w2 = 0.278518;
	double w3 = 0.0103893;
	
	return (w1 * m_pIntegrando->f(x1) + w2 * m_pIntegrando->f(x2) +
	        w3 * m_pIntegrando->f(x3));

}
