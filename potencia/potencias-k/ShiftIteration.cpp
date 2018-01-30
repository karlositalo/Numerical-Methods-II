#include "ShiftIteration.h"
#include <iostream>
#include <cmath>

void ShiftIteration::calculateEigenvalue()
{
    unsigned int k = 1;
    double oldEvalue, pivot, zVector[order], A[order][order];
    
    // initialize eigenvector and auxiliary vector Z
    for (unsigned int i = 0; i < order; ++i)
    {
        evector.push_back(1);
        zVector[i] = 0;
    }
    
    // assign the values in matrix to A and print the matrix
    std::cout << "\033[0;32mMatriz A:\033[0m\n";
    
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {         
            A[i][j] = matrix[i*order + j];
            std::cout << matrix[i*order + j] << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

	// create upper triangular matrix
    for (unsigned int m = 0; m < order-1; ++m)
    {
	    for (unsigned int i = m+1; i < order; ++i)
	    {
		    pivot = -A[i][m] / A[m][m];
		    A[i][m] = 0.0;

		    for (unsigned int j = m+1; j < order; ++j)
		    {
			    A[i][j] += pivot * A[m][j];
		    }

		    evector[i] += pivot * evector[m];
	    }
    }

	// back substitutions
	zVector[order-1] = evector[order-1] / A[order-1][order-1];

	for (int i = order-2; i >= 0; --i)
	{        
		double sum = 0;

		for (unsigned int j = i+1; j < order; ++j)
		{
			sum += zVector[j] * A[i][j];
		}

		zVector[i] = (evector[i] - sum) / A[i][i];
	}
    
    evalue = 0;
    
    // reload matrix in A
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {         
            A[i][j] = matrix[i*order + j];
        }
    }
    
    // calculate next vector Q
    double norm = 0;
    
    for (unsigned int i = 0; i < order; ++i)
    {
        norm += zVector[i]*zVector[i];
    }
    
    norm = sqrt(norm);
    
    for (unsigned int i = 0; i < order; ++i)
    {
        evector[i] = zVector[i]/norm;
    }
    
        
    // main loop
    do
    {
        oldEvalue = evalue;        
        
        // create upper triangular matrix
	    for (unsigned int m = 0; m < order-1; ++m)
	    {
		    for (unsigned int i = m+1; i < order; ++i)
		    {
			    pivot = -A[i][m] / A[m][m];
			    A[i][m] = 0.0;

			    for (unsigned int j = m+1; j < order; ++j)
			    {
				    A[i][j] += pivot * A[m][j];
			    }

			    evector[i] += pivot * evector[m];
		    }
	    }

	    // back substitutions
	    zVector[order-1] = evector[order-1] / A[order-1][order-1];

	    for (int i = order-2; i >= 0; --i)
	    {
		    double sum = 0;

		    for (unsigned int j = i+1; j < order; ++j)
		    {
			    sum += zVector[j] * A[i][j];
		    }

		    zVector[i] = (evector[i] - sum) / A[i][i];
	    }
   
        // calculate next vector Q
        double norm = 0;
        
        for (unsigned int i = 0; i < order; ++i)
        {
            norm += zVector[i]*zVector[i];
        }
        
        norm = sqrt(norm);
        
        for (unsigned int i = 0; i < order; ++i)
        {
            evector[i] = zVector[i]/norm;
        }
    
        // reload matrix in A
        for (unsigned int i = 0; i < order; ++i)
        {
            for (unsigned int j = 0; j < order; ++j)
            {         
                A[i][j] = matrix[i*order + j];
            }
        }
    
        // calculate the multiplication of the matrices A and Q
        double AQ[order];
        
        for (unsigned int i = 0; i < order; ++i)
        {
            AQ[i] = 0;
            
            for (unsigned int j = 0; j < order; ++j)
            {
                AQ[i] += A[i][j]*evector[i];
            }
        }
        
        // calculate samllest absolute eigenvalue
        evalue = 0;
        
        for (unsigned int i = 0; i < order; ++i)
        {
            evalue += evector[i]*AQ[i];
        }
        
        evalue = 1.0 / evalue;
        
        
        // print results
        std::cout << "k = " << k << '\n' << "\033[0;31mUnit Eigenvector:\033[0m\n";
    
        for (unsigned int i = 0; i < order; ++i)
        {            
            std::cout << evector[i] << '\n';
        }
        
        std::cout << "\033[0;33mEigenvalue: \033[0m" << evalue << "\n\n";
        
        ++k;
    }
    while ( std::abs(evalue - oldEvalue) > error );
    
    
    // reprint matrix for convenience
    std::cout << "\033[0;32mMatriz A:\033[0m\n";   
    
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {         
            std::cout << matrix[i*order + j] << '\t';
        }
        std::cout << '\n';
    }
    
    std::cout << '\n';
}
