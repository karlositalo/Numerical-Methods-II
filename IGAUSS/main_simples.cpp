#include <iostream>
#include <math.h>

using namespace std;

double xs(double a, double b, double s) {

	return ((a + b) / 2) + ((b - a) / 2) * tanh(s);

}

double f(double x) {

	return sqrt(1.0 + (1.0 / x));

}

double g(double origina, double originb, double s) {

	return f(xs(origina, originb, s)) * (4.0 / (exp(2 * s) + 2 +
			(exp(-2 * s))));

}

double nc(double origina, double originb, double a, double b) {

	double h = (b - a) / 2.0;
	
	return (h / 3.0) * (g(origina, originb, a) + 4.0 *
			g(origina, originb, a + h) + g(origina, originb, b));

}

double integral(double origina, double originb, double a, double b,
				double epsilon) {
	
	double n = 1;
	double oldintegral;
	double step;
	double linf;
	double lsup;
	
	double integralv = nc(origina, originb, a, b);
	
	do {
		
		oldintegral = integralv;
		integralv = 0.0;
		
		n = n * 2;
		step = (b - a) / n;
		
		for (int i = 0; i < n; i++) {
		
			linf = a + i * step;
			lsup = linf + step;
			
			integralv += nc(origina, originb, linf, lsup);
		
		}
	
	} while (fabs(integralv - oldintegral) > epsilon);
	
	return integralv;

}

int main() {
	
	double a;
	double b;
	double linfg;
	double lsupg;
	
	cout << "Digite o valor de a: ";
	cin >> a;
	
	cout << "Digite o valor de b: ";
	cin >> b;
	
	linfg = a;
	lsupg = b;
	
	double integr = ((b - a) / 2) * integral(a, b, linfg, lsupg, 0.00001);
	double oldintegr;
	
	do {
	
		oldintegr = integr;
		
		linfg = linfg - 1;
		lsupg = lsupg + 1;
		
		integr = ((b - a) / 2) * integral(a, b, linfg, lsupg, 0.001);
		
	} while (fabs(integr - oldintegr) > 0.0001);
	
	cout << "O valor da integral é " << integr << endl;
	
	return 0;

}
