#ifndef EXPOSIMPLES_hpp
#define EXPOSIMPLES_hpp

#include "Integracao.hpp"
#include <math.h>

class EXPOSIMPLES : public Integracao
{
public:
    EXPOSIMPLES(Funcao * f, double epsilon);
    
    virtual double integrar();
    
private:    
    Funcao *m_pIntegrando;
    double precisao;
};


#endif /* EXPOSIMPLES_hpp */
