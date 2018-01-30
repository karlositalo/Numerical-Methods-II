#ifndef GCHEB_hpp
#define GCHEB_hpp

#include "Integracao.hpp"

class GCHEB : public Integracao
{
public:
    GCHEB(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GCHEB_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GCHEB_hpp */
