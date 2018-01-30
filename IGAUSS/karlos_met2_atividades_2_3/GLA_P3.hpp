#ifndef GLA_P3_hpp
#define GLA_P3_hpp

#include "Integracao.hpp"

class GLA_P3 : public Integracao
{
public:
    GLA_P3(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GLA_P3_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GLA_P3_hpp */
