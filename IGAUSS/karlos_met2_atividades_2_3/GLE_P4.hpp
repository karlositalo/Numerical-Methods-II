#ifndef GLE_P4_hpp
#define GLE_P4_hpp

#include "Integracao.hpp"

class GLE_P4 : public Integracao
{
public:
    GLE_P4(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GLE_P4_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GLE_P4_hpp */
