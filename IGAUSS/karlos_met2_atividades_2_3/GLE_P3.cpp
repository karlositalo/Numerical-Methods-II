#include "GLE_P3.hpp"
#include <math.h>

GLE_P3::GLE_P3(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GLE_P3::integrar()
{
    double integral = 0.0;
    
    if (m_particao >= 1)
    {
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;
        
        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;
            
            integral += GLE_P3_integracao(m_pIntegrando, linf, lsup);
        }
        
        return integral;
    }
    else
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;
        
        integral = GLE_P3_integracao(m_pIntegrando, m_lInf, m_lSup);
        
        do
        {
            oldintegral = integral;
            integral    = 0.0;
            
            N = N*2;
            
            step = (m_lSup - m_lInf)/N;
            
            for (int i = 0; i < N; i++)
            {
                linf = m_lInf + i*step;
                lsup = linf   + step;
                
                integral += GLE_P3_integracao(m_pIntegrando, linf, lsup);
            }
            
            
        } while (fabs(integral - oldintegral) > m_precisao);
        
        return integral;
    }
    
}

double GLE_P3::GLE_P3_integracao(Funcao * f, double a, double b)
{
	
	double x1 = xs(-(sqrt(15) / 5), a, b);
	double x2 = xs(0, a, b);
	double x3 = xs((sqrt(15) / 5), a, b);
	
	double w1 = 5.0 / 9.0;
	double w2 = 8.0 / 9.0;
	double w3 = 5.0 / 9.0;
	
	return ((b - a) / 2) * (w1 * m_pIntegrando->f(x1) + w2 * m_pIntegrando->f(x2) +
			w3 * m_pIntegrando->f(x3));

}
