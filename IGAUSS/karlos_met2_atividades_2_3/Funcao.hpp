#ifndef Funcao_hpp
#define Funcao_hpp
#include <math.h>
#include <iostream>
using namespace std;
class Funcao
{
public:
    virtual double f(double) = 0;
    
    double xs(double s, double a, double b) {
	//cout <<"tanh(s): " << tanh(s) << " " << s << endl;
	//cout <<"x(s)" << ((a + b) / 2.0) + (((b - a) / 2.0) * tanh(s)) <<endl;
        return ((a + b) / 2.0) + ((b - a) / 2.0) * tanh(s);
    }
    
    double xsdupla(double s, double a, double b) {
        return ((a + b) / 2.0) + ((b - a) / 2.0) * tanh((3.141592 / 2.0) * sinh(s));
    }
    
    double us(double s) {
        return (3.141592 * sinh(s)) / 2.0;
    }
};

#endif /* Funcao_hpp */
