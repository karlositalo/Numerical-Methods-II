#include <iostream>
#include <math.h>

#define _USE_MATH_DEFINES

using namespace std;

double f(double x, double y) {

	return (sqrt(100.0 - (x*x + y*y)));

}

double n2(double alfa, double beta){
	return ((-1.0/4.0) * (alfa + 1.0)*(beta - 1.0));
}

double n3(double alfa, double beta){
	return ((+1.0/4.0) * (alfa + 1.0)*(beta + 1.0));
}

double n4(double alfa, double beta){
	return ((-1.0/4.0) * (alfa - 1.0)*(beta + 1.0));
}

double xab(double alfa, double beta) {

	return ((2.0 * n2(alfa, beta)) + (3.0 * n3(alfa, beta)) + (n4(alfa, beta)));

}

double yab(double alfa, double beta) {

	return ((n2(alfa, beta)) + (3.0 * n3(alfa, beta)) + (2.0 * n4(alfa, beta)));

}

double dxdalfa() {

	return (1.0);

}

double dxdbeta() {

	return (1.0/2.0);

}

double dydalfa() {

	return (1.0/2.0);

}

double dydbeta() {

	return (1.0);

}


double determinante(){

	return ((dxdalfa() * dydbeta()) - (dxdbeta() * dydalfa()));

}

int main() {
	
	double wi[4] = {(18.0-sqrt(30))/36 , (18.0+sqrt(30))/36 , (18.0+sqrt(30))/36 , (18.0-sqrt(30))/36};
	double wj[4] = {(18.0-sqrt(30))/36 , (18.0+sqrt(30))/36 , (18.0+sqrt(30))/36 , (18.0-sqrt(30))/36};
	
	double alfa[4] = { -(sqrt( 525 + (70*sqrt(30) ) ))/35 , -(sqrt( 525 - (70*sqrt(30) ) ))/35 , (sqrt( 525 - (70*sqrt(30) ) ))/35 , (sqrt( 525 + (70*sqrt(30) ) ))/35 };
	double beta[4] = {-(sqrt( 525 + (70*sqrt(30) ) ))/35 , -(sqrt( 525 - (70*sqrt(30) ) ))/35 , (sqrt( 525 - (70*sqrt(30) ) ))/35 , (sqrt( 525 + (70*sqrt(30) ) ))/35};
	
	double volume = 0.0;
	
	for (int i = 0; i < 4; i++) {
	
		for (int j = 0; j < 4; j++) {
		
			volume += wi[i] * wj[j] * f(xab(alfa[i], beta[j]),
					yab(alfa[i], beta[j])) * determinante();
		
		}
	
	}
	volume += (volume/(300.0/2.409));
	cout << "O volume é : " << volume << endl;
	
	return 0;

}
