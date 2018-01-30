#include "GCHEB.hpp"
#include <iostream>
#include <math.h>

int num_pontos_polinomio = -1;

using namespace std;

GCHEB::GCHEB(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}

double GCHEB::integrar()
{
    double integral = 0.0;
    
    if (num_pontos_polinomio < 1) {
    
        cout << "\nDigite o numero de pontos de Chebyshev(>= 1)\n\n";
        cin >> num_pontos_polinomio;
        
    }
    
    if (m_particao >= 1)
    {
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;
        
        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;
            
            integral += GCHEB_integracao(m_pIntegrando, linf, lsup);
        }
        
        return integral;
    }
    else
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;
        
        integral = GCHEB_integracao(m_pIntegrando, m_lInf, m_lSup);
        
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
                
                integral += GCHEB_integracao(m_pIntegrando, linf, lsup);
            }
            
            
        } while (fabs(integral - oldintegral) > m_precisao);
        
        return integral;
    }
    
}

double GCHEB::GCHEB_integracao(Funcao * f, double a, double b)
{
	
	double integral = 0.0;
	int x;
	
    int i;
	for (i = 1; i <= num_pontos_polinomio; i++) {
	    
	    x = xs(((i - 0.5) * 3.141592) / num_pontos_polinomio, a, b);
	    
	    integral += m_pIntegrando->f(x) * (3.141592 / num_pontos_polinomio);
	
	}
	
	return integral;

}
