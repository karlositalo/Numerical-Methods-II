#include "PVILib.h"

// Construtor
PVILib::PVILib(){

}

// Destrutor
PVILib::~PVILib(){
    
}

//PVI

double PVILib::f(double t, double v){
    return 2*(0.1 - v)*(0.4-v);
}

double* PVILib::forwardEuler(double v, double ti, double h, int n){

    double *v1, *t;

    v1 = (double*)calloc((n),sizeof(double));
    t = (double*)calloc((n),sizeof(double));

    v1[0] = v;
    t[0] = ti;

    for(int i=0;i<n;i++){
        t[i+1] = t[i] + h;
        v1[i+1] = v1[i] +h*f(t[i], v1[i]);
    }

    return v1;
}

double* PVILib::backwardEuler(double v, double ti, double h, int n){

    double *v1, *t, vi1;

    v1 = (double*)calloc((n),sizeof(double));
    t = (double*)calloc((n),sizeof(double));

    v1[0] = v;
    t[0] = ti;

    for(int i=0;i<n;i++){
        t[i+1] = t[i] + h;
        vi1 = v1[i]+h*(f(t[i],v1[i]));
        v1[i+1] = v1[i] +h*f(t[i+1], vi1);
    }

    return v1;
}


double* PVILib::modifiedEuler(double v, double ti, double h, int n){

    double *v1, *t, vi1;

    v1 = (double*)calloc((n),sizeof(double));
    t = (double*)calloc((n),sizeof(double));

    v1[0] = v;
    t[0] = ti;

    for(int i=0;i<n;i++){
        t[i+1] = t[i] + h;
        vi1 = v1[i]+h*(f(t[i],v1[i]));
        v1[i+1] = v1[i] +(h/2)*(f(t[i], v1[i]) + f(t[i+1], vi1));
    }

    return v1;
}

double* PVILib::rungeKuttaG5(double vi, double ti, double h, int n){

    double *v1, *t, k1, k2, k3, k4, k5, k6;

    v1 = (double*)calloc((n),sizeof(double));
    t = (double*)calloc((n),sizeof(double));

    v1[0] = vi;
    t[0] = ti;

    for(int i=0;i<n;i++){

        t[i+1] = t[i] + h;

        k1 = h*(f(t[i], v1[i]));

        k2 = h*(f(t[i] + h/2, v1[i]) + k1/2);

        k3 = h*(f(t[i] + h/4, v1[i]) + (3*k1 + k2)/16);

        k4 = h*(f(t[i] + h/2, v1[i]) + k3/2);

        k5 = h*(f(t[i] + 3*h/4, v1[i]) + (-3*k2 + 6*k3 +9*k4)/16);

        k6 = h*(f(t[i] + h, v1[i]) + (k1 + 4*k2 + 6*k3 - 12*k4 + 8*k5)/7);

        v1[i+1] = v1[i] + (7*k1 + 32*k3 + 12*k4 + 32*k5 + 7*k6)/90;
    }

    return v1;
}

double* PVILib::predictorCorrector(double vi, double ti, double h, int n){

    double *vp, *vc, *v, t;

    vp = (double*)calloc((n),sizeof(double));
    vc = (double*)calloc((n),sizeof(double));

    t = ti;

    v = rungeKuttaG5(vi, ti, h, n);

    for(int i = 0; i<2; i++){
        t += h;
    }

    double i_p_1,i_p_0,i_s_1,i_s_2;
    double predictor;
    double corrector = 0.0;
    double oldCorrector;

    for(int i = 2; i < n ; i++){

        /*predicao */

        i_p_0 = f(t, v[i]);
        i_s_1 = f(t - h, v[i-1]);

        i_s_2 = f(t - 2*h, v[i-2] );

        //fazendo predicao
        predictor = v[i] + (h/12)*( 23*i_p_0 - 16*i_s_1 + 5*i_s_2);

        //correcao
        oldCorrector = predictor;

        do{
            i_p_1 = f(t+h,oldCorrector);

            
            corrector = v[i] + (h/12)*( 5*i_p_1 + 8*i_p_0 - i_s_1);

            oldCorrector = corrector;


        }while(fabs(oldCorrector-corrector) > 0.00000000001);

        v[i+1] = corrector;
        t += h;

    }

    return v;
}
