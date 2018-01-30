#ifndef GHE_P2_hpp
#define GHE_P2_hpp

#include "Integracao.hpp"

class GHE_P2 : public Integracao
{
public:
    GHE_P2(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GHE_P2_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GHE_P2_hpp */
