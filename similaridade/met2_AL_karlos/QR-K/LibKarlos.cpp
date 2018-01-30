#include "LibKarlos.h"

// Construtor
LibKarlos::LibKarlos(){
    eigenValue=0;
}

// Destrutor
LibKarlos::~LibKarlos(){
    
}


double** LibKarlos::computeInverse(double **matrix, int n){
    int i, j, w;
    double pivot, op, **matrix2, **inverse;

    inverse = (double**)malloc(n*sizeof(double*));

    for(i=0;i<n;i++)
        inverse[i] = (double*)calloc(n,sizeof(double));

    matrix2 = (double**)malloc(n*sizeof(double*));

    for(i=0;i<n;i++)
        matrix2[i] = (double*)calloc(n,sizeof(double));

    for(i=0;i<n;i++)
        inverse[i][i] = 1;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            matrix2[i][j] = matrix[i][j];
    }

    for (i=0;i<n;i++){//i linha atual, j coluna
        pivot = matrix2[i][i];
        if(pivot != 1){
            for(j=0;j<n;j++){
                matrix2[i][j] = matrix2[i][j]/pivot;
                inverse[i][j] = inverse[i][j]/pivot;
            }
        }

        //w irá percorrer as linhas
        for(w=0;w<n;w++){
            if(w != i){
                op = matrix2[w][i]; //i como linha
                for(j=0;j<n;j++){

                    matrix2[w][j] = matrix2[w][j]-(op*(matrix2[i][j]));
                    inverse[w][j] = inverse[w][j]-(op*(inverse[i][j]));

                }
            }
        }
    }
    return inverse;
}


double LibKarlos::dotProduct(double *v1, double *v2, int n){
    double v=0;

    for(int i=0;i<n;i++)
        v += v1[i]*v2[i];

    return v;
}


double* LibKarlos::normlizeVector(double *v, int n){

    double module=0, *v1;

    v1 = (double*)calloc((n),sizeof(double));

    for(int i=0;i<n;i++){
        module += pow(v[i],2);
    }
    module = sqrt(module);

    for(int i=0;i<n;i++){
        v1[i] = v[i]/module;
    }

    return v1;
}


double LibKarlos::norm(double *v, int n){

    double module=0;

    for(int i=0;i<n;i++){
        module += pow(v[i],2);
    }
    module = sqrt(module);

    return module;
}


double* LibKarlos::matrixByVector(double **m1, double *v, int tam1i, int tam1j, int tam2i){

    int i, w;
    double *v2;

    v2 = (double*)calloc((tam1i),sizeof(double*));

    if(tam1j==tam2i){
        for(w=0;w<tam1i;w++){
            for(i=0;i<tam2i;i++) {
                v2[w] += (m1[w][i])*(v[i]);
            }
        }
    }

    return v2;
}


double** LibKarlos::matrixsubtration(double **m1, double **m2, int tam){

    double **m3;

    m3 = (double**)malloc((tam)*sizeof(double*));

    for(int i=0;i<tam;i++)
        m3[i] = (double*)calloc((tam),sizeof(double));

    for(int w=0;w<tam;w++){
        for(int i=0;i<tam;i++) {
            m3[w][i] = (m1[w][i])-(m2[w][i]);
        }
    }
    return m3;
}


double** LibKarlos::matrixByScalar(double **m1, double esc, int tam1i, int tam1j){

    double **m2;

    m2 = (double**)calloc((tam1j),sizeof(double));

    for(int i=0;i<tam1j;i++)
        m2[i] = (double*)calloc((tam1j),sizeof(double));

    for(int w=0;w<tam1i;w++){
        for(int i=0;i<tam1j;i++){
            m2[w][i] = m1[w][i]*esc;
        }
    }


    return m2;
}



double** LibKarlos::matrixByMatrix(double **m1, double **m2, int tam1i, int tam1j, int tam2i, int tam2j){

    int i, j, w;
    double **m3;

    
    m3 = (double**)malloc((tam1i)*sizeof(double*));

    for(i=0;i<tam1i;i++)
        m3[i] = (double*)calloc((tam2j),sizeof(double));

    if(tam1j==tam2i){

        for(w=0;w<tam1i;w++){
            for(i=0;i<tam1j;i++) {
                for(j=0;j<tam2j;j++){
                    m3[w][j] += (m1[w][i])*(m2[i][j]);
                    if(fabs(m3[w][j])<e)
                        m3[w][j] = 0;
                }
            }
        }
    }
    return m3;
}

double** LibKarlos::multVetorT(double *m1, int tam){

    int j, w;
    double **m3;

    m3 = (double**)malloc((tam)*sizeof(double*));

    for(int i=0;i<tam;i++)
        m3[i] = (double*)calloc((tam),sizeof(double));


    for(w=0;w<tam;w++){
        for(j=0;j<tam;j++){
            m3[w][j] += (m1[w])*(m1[j]);
        }
    }

    return m3;
}


double** LibKarlos::houseHolder(double *colh, int h, int tam){
    double **Q, **I, **VT, *N, *v, *nb, *n;

    v = (double*)calloc((tam),sizeof(double));

    for(int i=h+1;i<tam;i++){
        v[i] = colh[i];
    }

    N = v;

    if(v[h+1] > 0){
        N[h+1] = N[h+1] + norm(v, tam);

    }
    else{
        N[h+1] = N[h+1] - norm(v, tam);
    }

    nb = normlizeVector(N, tam);
    n = (double*)calloc((tam),sizeof(double));

    for(int i=h+1;i<tam;i++){
        n[i] = nb[i];
    }

    I = getIdentity(tam);
    VT = matrixByScalar(multVetorT(n, tam), 2, tam, tam);

    Q = matrixsubtration(I, VT, tam);

    return Q;
}

double** LibKarlos::HHmethod(double **A, int n){
    double **H, **Ab, **Q;

    H = getIdentity(n);
    Ab = A;

    for(int h=0;h<=n-2;h++){

        Q = houseHolder(getMatrixColumn(Ab, h, n), h, n);

        H = matrixByMatrix(H, Q, n, n, n, n);
        Ab = matrixByMatrix(matrixByMatrix(Q, Ab, n, n, n, n), Q, n, n, n, n);
    }
    setH(H);
    return Ab;
}

double* LibKarlos::getMatrixColumn(double** A, int h, int n){
    double *v;

    v = (double*)calloc((n),sizeof(double));

    for(int i=0;i<n;i++){
        v[i] = A[i][h];
    }

    return v;
}

double** LibKarlos::transposeMatrix(double **A, int n){
    double **A2, aux;

    A2 = (double**)malloc((n)*sizeof(double*));

    for(int i=0;i<n;i++)
        A2[i] = (double*)calloc((n),sizeof(double));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            A2[i][j] = A[j][i];
        }
    }

    return A2;
}

void LibKarlos::getQR(double** A, int n){
    double **Q, **Qij, **R;

    Q = getIdentity(n);

    for(int j=0;j<n-1;j++){
        for(int i=j+1;i<n;i++){
            Qij = buildQ(A[i][j], A[j][j], i, j, n);
            R = matrixByMatrix(transposeMatrix(Qij, n), A, n, n, n, n);
            Q = matrixByMatrix(Q, Qij, n, n, n, n);
            A = R;
        }
    }

    setR(R);
    setQ(Q);
}

double** LibKarlos::buildQ(double Aij, double Ajj, int i, int j, int n){
    double **Q, theta;

    Q = getIdentity(n);

    if(Ajj != 0){
        theta = atan(Aij/Ajj);
    }
    else{
        theta = M_PI/2;
    }

    Q[j][j] = cos(theta);
    Q[i][i] = cos(theta);
    Q[j][i] = -sin(theta);
    Q[i][j] = sin(theta);

    return Q;
}

double** LibKarlos::QRmethod(double **A, double e, int n){
    double **Q, **A1, **A2, norm=0;

    Q = getIdentity(n);

    A1 = (double**)malloc((n)*sizeof(double*));

    for(int i=0;i<n;i++)
        A1[i] = (double*)calloc((n),sizeof(double));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A1[i][j] = A[i][j];
        }
    }


    do{
        getQR(A1, n);

        Q = matrixByMatrix(Q, getQ(), n, n, n, n);

        A2 = matrixByMatrix(getR(), getQ(), n, n, n, n);
        norm = MatrixNorm(A2, n);
        A1 = A2;

        
    }while(fabs(norm) > e);
    setQ(Q);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fabs(A2[i][j]) < e)
               A2[i][j] = 0;
        }
    }

    return A2;
}

double LibKarlos::MatrixNorm(double **A, int n){
    double norm;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                norm += pow(A[i][j], 2);
            }
        }
    }

    norm = sqrt(norm);

    return norm;
}

double** LibKarlos::build_J(double aij, double ajj, double aii, int i, int j, int tam){
    double **J = getIdentity(tam);
    double theta;
    if (ajj - aii == 0)
        theta = M_PI/4;
    else
        theta = atan(2*aij/(ajj-aii))/2;

    J[j][j] = cos(theta);
    J[i][i] = cos(theta);
    J[i][j] = sin(theta);
    J[j][i] = -sin(theta);


    return J;
}

double LibKarlos::ColumnsNorm(double **A, int tam){
    double normC = 0;
    for(int i=0;i<tam;i++){
        normC += norm(A[i], tam);
    }

    return normC;
}

double LibKarlos::diagonalSum(double **A, int tam){
    double soma = 0;
    for(int i=0;i<tam;i++){
        soma += fabs(A[i][i]);
    }
    return soma;
}

double** LibKarlos::jacobiMethod(double **A, double e, int tam){
    int i,j;
    double **Jij, **Abarra, **Jijt, **J;
    double E, aux;
    this->e = e;
    Abarra = A;
    J = getIdentity(tam);

    do{
        for(j=0;j<tam-1;j++){
            for(i=j+1;i<tam;i++){
                Jij = build_J(Abarra[i][j],Abarra[j][j], Abarra[i][i], i, j,tam);
                Jijt = transposeMatrix(Jij,tam);
                Abarra = matrixByMatrix(Jijt,Abarra,tam,tam,tam,tam);
                Abarra = matrixByMatrix(Abarra,Jij,tam,tam,tam,tam);
                J = matrixByMatrix(J,Jij,tam,tam,tam,tam);
            }
        }
        aux = ColumnsNorm(Abarra, tam);
        
        E = diagonalSum(Abarra,tam);
        

        
    }while(fabs(aux-E)/aux>e);
    setJ(J);
    return Abarra;
}

// Setters e Getters
void LibKarlos::setR(double **R){
    this->R = R;
}

void LibKarlos::setQ(double **Q){
    this->Q = Q;
}

void LibKarlos::setJ(double **J){
    this->J = J;
}

void LibKarlos::setH(double **H){
    this->H = H;
}

double** LibKarlos::getR(){
    return this->R;
}

double** LibKarlos::getQ(){
    return this->Q;
}

double** LibKarlos::getJ(){
    return this->J;
}

double** LibKarlos::getH(){
    return this->H;
}

double** LibKarlos::getIdentity(int n){
    double **identity;
    identity = (double**)calloc((n),sizeof(double));
    for(int i=0;i<n;i++){
        identity[i] = (double*)calloc((n),sizeof(double));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                identity[i][j] = 1.0;
            else
                identity[i][j] = 0.0;
        }
    }
    return identity;
}


double* LibKarlos::getEigenValues(){
    return this->eigenValues;
}

double** LibKarlos::getEigenVectors(){
    return this->eigenVectors;
}

double LibKarlos::getEigenValue(){
    return this->eigenValue;
}
