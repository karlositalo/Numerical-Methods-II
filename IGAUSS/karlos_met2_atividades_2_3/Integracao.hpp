#ifndef Integracao_hpp
#define Integracao_hpp

#include "Funcao.hpp"


class Integracao
{
public:
    
    virtual double integrar() = 0;
    
    double xs(double s, double a, double b) {
    	
    	return ((a + b) / 2) + ((b - a) / 2) * s;
    	
    }
    
};

#endif /* Integracao_hpp */
