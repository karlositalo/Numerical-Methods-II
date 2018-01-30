#include "GLA_P4.hpp"
#include <math.h>

GLA_P4::GLA_P4(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GLA_P4::integrar()
{
    double integral = 0.0;
    
    integral += integral += GLA_P4_integracao(m_pIntegrando, 0, 0);
    
    return integral;
}

double GLA_P4::GLA_P4_integracao(Funcao * f, double a, double b)
{
	
	double x1 = 0.32255;
	double x2 = 1.74576;
	double x3 = 4.53662;
	double x4 = 9.39507;
	
	double w1 = 0.603154;
	double w2 = 0.357419;
	double w3 = 0.038888;
	double w4 = 0.000540;
	
	return (w1 * m_pIntegrando->f(x1) + w2 * m_pIntegrando->f(x2) +
	        w3 * m_pIntegrando->f(x3) + w4 * m_pIntegrando->f(x4));

}
