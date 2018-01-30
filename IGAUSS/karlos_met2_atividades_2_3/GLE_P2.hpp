#ifndef GLE_P2_hpp
#define GLE_P2_hpp

#include "Integracao.hpp"

class GLE_P2 : public Integracao
{
public:
    GLE_P2(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GLE_P2_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GLE_P2_hpp */
