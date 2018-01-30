#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

#ifndef LIBKARLOS_H
#define LIBKARLOS_H

using namespace std;

class LibKarlos
{
public:
    LibKarlos();
    ~LibKarlos();
    double F(double x);
    double** computeInverse(double**, int n);
    double dotProduct(double*, double*, int);
    double* normlizeVector(double*, int);
    double norm(double*, int);
    double* matrixByVector(double **, double *, int, int, int);
	double** matrixsubtration(double**, double**, int);
	double** matrixByScalar(double**, double, int, int);
    double** matrixByMatrix(double**, double**, int, int, int, int);
    double** multVetorT(double*, int);
    double** houseHolder(double*, int, int);
    double** HHmethod(double**, int);
    double* getMatrixColumn(double**, int, int);
    double** transposeMatrix(double**, int);
    void getQR(double**, int);
    double** buildQ(double, double, int, int, int);
    double** QRmethod(double**, double, int);
    double MatrixNorm(double**, int);
    double** build_J(double, double, double, int, int, int);
    double ColumnsNorm(double**, int);
    double diagonalSum(double**, int);
    double** jacobiMethod(double**, double, int);
    void setR(double**);
    void setQ(double**);
    void setJ(double**);
    void setH(double**);
    double** getR();
    double** getQ();
    double** getJ();
    double** getH();
	double** getIdentity(int n);
	double* getEigenValues();
	double** getEigenVectors();
	double getEigenValue();

private:
    double *eigenValues, **eigenVectors, eigenValue, **Q, **R, **J, **H;
};

#endif // LIBKARLOS_H
