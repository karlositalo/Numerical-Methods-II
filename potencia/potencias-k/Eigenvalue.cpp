#include "Eigenvalue.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

Eigenvalue::Eigenvalue(std::string filename)
{
    std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);
    
    // reads order
    file >> order;
    
    if (order < 2)
    {
        std::cout << "Matriz incorreta. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }
    
    // reads matrix
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {
            double temp;
            file >> temp;
            
            matrix.push_back(temp);
        }
    }
    
    // reads error tolerance
    file >> error;
    
    if (error <= 0)
    {
        std::cout << "Erro invalido, escolha valor maior que 0. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }
    
    // change matrix
    file >> mi;
    
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {
            if (i == j)
            
            matrix[i*order + j] -= mi;
        }
    }
}
