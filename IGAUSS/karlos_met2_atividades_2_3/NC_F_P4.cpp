#include "NC_F_P4.hpp"
#include <math.h>

NC_F_P4::NC_F_P4(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double NC_F_P4::integrar()
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
            
            integral += NC_F_P4_integracao(m_pIntegrando, linf, lsup);
        }
        
        return integral;
    }
    else
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;
        
        integral = NC_F_P4_integracao(m_pIntegrando, m_lInf, m_lSup);
        
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
                
                integral += NC_F_P4_integracao(m_pIntegrando, linf, lsup);
            }
            
            
        } while (fabs(integral - oldintegral) > m_precisao);
        
        return integral;
    }
    
}

double NC_F_P4::NC_F_P4_integracao(Funcao * f, double a, double b)
{
	double h = (b - a) / 4;
	double coef_h = 2.0 / 45.0;
	
	return (coef_h * h) * (7.0*m_pIntegrando->f(a) +
			32.0*m_pIntegrando->f(a+h) + 12.0*m_pIntegrando->f(a+2.0*h) +
			32.0*m_pIntegrando->f(a+3.0*h) + 7.0*m_pIntegrando->f(b));
}
