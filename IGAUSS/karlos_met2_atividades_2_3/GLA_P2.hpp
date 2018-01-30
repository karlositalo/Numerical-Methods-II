#ifndef GLA_P2_hpp
#define GLA_P2_hpp

#include "Integracao.hpp"

class GLA_P2 : public Integracao
{
public:
    GLA_P2(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GLA_P2_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GLA_P2_hpp */
