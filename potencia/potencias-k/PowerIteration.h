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

#ifndef __POWER_ITERATION_H__
#define __POWER_ITERATION_H__

#include "PowerMethod.h"
#include <string>

class PowerIteration : public PowerMethod
{
    public:
    
        PowerIteration(std::string filename) : PowerMethod(filename) {}
        virtual ~PowerIteration() {}
        
        void calculateEigenvalue();
};

#endif // __POWER_ITERATION_H__
