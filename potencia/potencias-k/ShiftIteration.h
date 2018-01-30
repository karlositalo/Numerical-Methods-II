/*********************************************/
/*                                           */
/*  2014, Fortaleza, Ceara                   */
/*                                           */
/*  UNIVERSIDADE FEDERAL DO CEARA            */
/*  CURSO DE COMPUTACAO                      */
/*  METODOS NUMERICOS II                     */
/*  PROFESSORA: Emanuele Marques dos Santos  */
/*                                           */
/*  Paulo Bruno de Sousa Serafim    354086   */
/*                                           */
/*********************************************/

#ifndef __SHIFT_ITERATION_H__
#define __SHIFT_ITERATION_H__

#include "PowerMethod.h"
#include <string>

class ShiftIteration : public  PowerMethod
{
    public:
    
        ShiftIteration(std::string filename) : PowerMethod(filename) {}
        virtual ~ShiftIteration() {}

        void calculateEigenvalue();
};

#endif // __SHIFT_ITERATION_H__
