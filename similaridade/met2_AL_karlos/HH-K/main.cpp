#include<fstream>
#include<iostream>
#include "LibKarlos.h"

int main(int argc, char *argv[])
{
    
    LibKarlos *f;
    f = new LibKarlos();
    double **A, **T, e;
    int n;
    ifstream lermatrix, lerTolerancia;
    ofstream file;

    lermatrix.open("matrix.txt");
 
    lerTolerancia.open("tolerancia.txt");
    file.open("resultados.txt");

    lermatrix >> n;
    lerTolerancia >> e;

    

    A = (double**)malloc(n*sizeof(double*));

    for(int i=0;i<n;i++){
       
        A[i] = (double*)calloc(n,sizeof(double));
        for(int j=0; j<n; j++){
            lermatrix >> A[i][j];
        }
    }

    file<<"Metodo Householder"<<endl;
    cout<<"Metodo Householder"<<endl;
    
	cout<<"matrix Entrada: "<<endl;
    file<<"matrix Entrada: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"|";
        file<<"|";
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
            file<<A[i][j]<<" ";
        }
        cout<<"|"<<endl;
        file<<"|"<<endl;
    }
    
    

    
    T = f->HHmethod(A, n);
    cout<<"matrix TriDiagonal: "<<endl;
    file<<"matrix TriDiagonal: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"|";
        file<<"|";
        for(int j=0;j<n;j++){
            cout<<T[i][j]<<" ";
            file<<T[i][j]<<" ";
        }
        cout<<"|"<<endl;
        file<<"|"<<endl;
    }

	double **J;
    J = f->getH();
    cout<<"matrix Householder: "<<endl;
    file<<"matrix Householder: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"|";
        file<<"|";
        for(int j=0;j<n;j++){
            cout<<J[i][j]<<" ";
            file<<J[i][j]<<" ";
        }
        cout<<"|"<<endl;
        file<<"|"<<endl;
    }
    

    file.close();

    cout<<"Gravado com sucesso em 'resultados.txt'"<<endl;


    return 0;
}
