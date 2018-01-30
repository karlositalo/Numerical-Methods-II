#ifndef EXPODUPLA_hpp
#define EXPODUPLA_hpp

#include "Integracao.hpp"
#include <math.h>

class EXPODUPLA : public Integracao
{
public:
    EXPODUPLA(Funcao * f, double epsilon);
    
    virtual double integrar();
    
private:    
    Funcao *m_pIntegrando;
    double precisao;
};


#endif /* EXPODUPLA_hpp */
