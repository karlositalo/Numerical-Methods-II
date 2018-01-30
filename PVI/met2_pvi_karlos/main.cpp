#include<fstream>
#include<iostream>
#include "PVILib.h"

int main(int argc, char *argv[])
{
   
    PVILib *f;
    f = new PVILib();
    int n;
    double* v;
    n = 70;

    cout<<"FORWARD-EULER TESTE"<<endl;
    v = f->forwardEuler(0, 0, 0.05, n);
    for(int i=0;i<=n;i++)
        cout<<v[i]<<endl;

    cout<<""<<endl;
    cout<<"BACKWARD-EULER TESTE"<<endl;
    v = f->backwardEuler(1, 0, 0.01, n);
    for(int i=0;i<=n;i++)
        cout<<v[i]<<endl;

    cout<<""<<endl;
    cout<<"EULER MODIFICADO TESTE"<<endl;
    v = f->modifiedEuler(0, 0, 0.05, n);
    for(int i=0;i<=n;i++)
        cout<<v[i]<<endl;

    cout<<""<<endl;
    cout<<"R-K QUINTO GRAU TESTE"<<endl;
    v = f->rungeKuttaG5(0, 0, 0.03, n);
    for(int i=0;i<=n;i++)
        cout<<v[i]<<endl;

    cout<<""<<endl;
    cout<<"PREDITOR-CORRETOR TESTE"<<endl;
    v = f->predictorCorrector(0, 0, 0.01, n);
    for(int i=0;i<=n;i++)
        cout<<v[i]<<endl;

    

    return 0;
}
