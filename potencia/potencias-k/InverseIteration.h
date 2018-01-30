#ifndef __INVERSE_ITERATION_H__
#define __INVERSE_ITERATION_H__

#include "PowerMethod.h"
#include <string>

class InverseIteration : public PowerMethod
{
    public:
    
        InverseIteration(std::string filename) : PowerMethod(filename) {}
        virtual ~InverseIteration() {}

        void calculateEigenvalue();
};

#endif // __INVERSE_ITERATION_H__
