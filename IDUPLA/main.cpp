#include <iostream>
#include <math.h>

#define _USE_MATH_DEFINES

using namespace std;

double f(double x, double y) {

	return (2.0 * y * sin(x)) + (cos(x) * cos(x));

}

double c(double x) {

    return sin(x);

}

double d(double x) {

    return cos(x);

}

double xab(double a, double b, double alfa, double beta) {

	return ((a + b) / 2.0) + ((b - a) / 2.0) * alfa;

}

double yab(double a, double b, double alfa, double beta) {

	return ((c(xab(a, b, alfa, beta)) + d(xab(a, b, alfa, beta))) / 2.0) +
			((d(xab(a, b, alfa, beta)) - c(xab(a, b, alfa, beta))) / 2.0) *
			beta;

}

double dxdalfa(double a, double b) {

	return (b - a) / 2.0;

}

double dydbeta(double a, double b, double alfa, double beta) {

	return (d(xab(a, b, alfa, beta)) -
	        c(xab(a, b, alfa, beta))) / 2.0;

}

int main() {
	
	double a;
	double b;
	
	cout << "Digite o valor de a: ";
	cin >> a;
	
	cout << "Digite o valor de b: ";
	cin >> b;
	
	double wi[3] = {(5.0 / 9.0), (8.0 / 9.0), (5.0 / 9.0)};
	double wj[2] = {1.0, 1.0};
	
	double alfa[3] = {-sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0)};
	double beta[2] = {-sqrt(1.0 / 3.0), sqrt(1.0 / 3.0)};
	
	double volume = 0.0;
	
	for (int i = 0; i < 3; i++) {
	
		for (int j = 0; j < 2; j++) {
		
			volume += wi[i] * wj[j] * f(xab(a, b, alfa[i], beta[j]),
					yab(a, b, alfa[i], beta[j])) * dxdalfa(a, b) *
					dydbeta(a, b, alfa[i], beta[j]);
		
		}
	
	}
	
	cout << "O volume é : " << volume << endl;
	
	return 0;

}
