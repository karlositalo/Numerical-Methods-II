#ifndef GLE_P1_hpp
#define GLE_P1_hpp

#include "Integracao.hpp"

class GLE_P1 : public Integracao
{
public:
    GLE_P1(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GLE_P1_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GLE_P1_hpp */
