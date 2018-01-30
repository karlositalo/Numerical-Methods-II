#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;



double F1(double t){

	return 0;
}

double F2(double t){
	return 0;
}


double forwardEuller_U1(double t, double deltaT, double k1, double k2, double m1, double m2, double u1, double u2, double v1, double v2){

	double i = deltaT;
	double u1_ant,u2_ant,v1_ant,v2_ant;
	double u1_new,u2_new,v1_new,v2_new;


	u1_ant = u1;
	u2_ant = u2;
	v1_ant = v1;
	v2_ant = v2;

	while (i <= t){
		u1_new = u1_ant + (deltaT*v1_ant);

		u2_new = u2_ant + (deltaT*v2_ant);

		v1_new = v1_ant + deltaT*((1/m1)*(F1(i)+k2*(u2_ant-u1_ant)-(k1*u1_ant)));

		v2_new = v2_ant + deltaT*((1/m2)*(F2(i)-(k2*(u2_ant-u1_ant))));

		u1_ant = u1_new;

		u2_ant = u2_new;

		v1_ant = v1_new;

		v2_ant = v2_new;

		i = i + deltaT;
	}

	return u1_new;

}



double forwardEuller_U2(double t, double deltaT, double k1, double k2, double m1, double m2, double u1, double u2, double v1, double v2){

	double i = deltaT;
	double u1_ant,u2_ant,v1_ant,v2_ant;
	double u1_new,u2_new,v1_new,v2_new;


	u1_ant = u1;
	u2_ant = u2;
	v1_ant = v1;
	v2_ant = v2;

	while (i <= t){
		u1_new = u1_ant + (deltaT*v1_ant);

		u2_new = u2_ant + (deltaT*v2_ant);

		v1_new = v1_ant + deltaT*((1/m1)*(F1(i)+k2*(u2_ant-u1_ant)-(k1*u1_ant)));

		v2_new = v2_ant + deltaT*((1/m2)*(F2(i)-(k2*(u2_ant-u1_ant))));

		u1_ant = u1_new;

		u2_ant = u2_new;

		v1_ant = v1_new;

		v2_ant = v2_new;

		i = i + deltaT;
	}

	return u2_new;

}


double forwardEuller_V1(double t, double deltaT, double k1, double k2, double m1, double m2, double u1, double u2, double v1, double v2){

	double i = deltaT;
	double u1_ant,u2_ant,v1_ant,v2_ant;
	double u1_new,u2_new,v1_new,v2_new;


	u1_ant = u1;
	u2_ant = u2;
	v1_ant = v1;
	v2_ant = v2;

	while (i <= t){
		u1_new = u1_ant + (deltaT*v1_ant);

		u2_new = u2_ant + (deltaT*v2_ant);

		v1_new = v1_ant + deltaT*((1/m1)*(F1(i)+k2*(u2_ant-u1_ant)-(k1*u1_ant)));

		v2_new = v2_ant + deltaT*((1/m2)*(F2(i)-(k2*(u2_ant-u1_ant))));

		u1_ant = u1_new;

		u2_ant = u2_new;

		v1_ant = v1_new;

		v2_ant = v2_new;

		i = i + deltaT;
	}

	return v1_new;

}


double forwardEuller_V2(double t, double deltaT, double k1, double k2, double m1, double m2, double u1, double u2, double v1, double v2){

	double i = deltaT;
	double u1_ant,u2_ant,v1_ant,v2_ant;
	double u1_new,u2_new,v1_new,v2_new;


	u1_ant = u1;
	u2_ant = u2;
	v1_ant = v1;
	v2_ant = v2;

	while (i <= t){
		u1_new = u1_ant + (deltaT*v1_ant);

		u2_new = u2_ant + (deltaT*v2_ant);

		v1_new = v1_ant + deltaT*((1/m1)*(F1(i)+k2*(u2_ant-u1_ant)-(k1*u1_ant)));

		v2_new = v2_ant + deltaT*((1/m2)*(F2(i)-(k2*(u2_ant-u1_ant))));

		u1_ant = u1_new;

		u2_ant = u2_new;

		v1_ant = v1_new;

		v2_ant = v2_new;

		i = i + deltaT;
	}

	return v2_new;

}


void RK4 (double t, double deltaT, double k1, double k2, double m1, double m2, double u1, double u2, double v1, double v2){
	double i = deltaT*2;
	double u1_ant,u2_ant,v1_ant,v2_ant;
	double u1_new,u2_new,v1_new,v2_new;


	u1_ant = u1;
	u2_ant = u2;
	v1_ant = v1;
	v2_ant = v2;

	u1_new = u1_ant + (deltaT)/8.0*(
			v1+
			3*forwardEuller_V1(deltaT,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			3*forwardEuller_V1(deltaT,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			forwardEuller_V1(deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)
	);

	u1_ant = u1_new;

	u2_new = u2_ant +(deltaT)/8.0*(
			v2+
			3*forwardEuller_V2(deltaT,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			3*forwardEuller_V2(deltaT,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			forwardEuller_V2(deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)
	);

	u2_ant = u2_new;

	v1_new = v1_ant +(deltaT)/8.0*(
			((1/m1)*(F1(0)+(k2*(u2-u1))-k1*u1))+
			3*((1/m1)*(F1((1.0/3.0)*deltaT)+(k2*(forwardEuller_U2(deltaT,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(deltaT,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))-k1*forwardEuller_U1(deltaT,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))+
			3*((1/m1)*(F1((2.0/3.0)*deltaT)+(k2*(forwardEuller_U2(deltaT,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(deltaT,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))-k1*forwardEuller_U1(deltaT,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))+
			((1/m1)*(F1(deltaT)+(k2*(forwardEuller_U2(deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))-k1*forwardEuller_U1(deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))
	);

	v1_ant = v1_new;

	v2_new = v2_ant + deltaT/9.0*(
			((1/m2)*(F2(0)-(k2*(u2-u1))))+
			3*((1/m2)*(F2((1.0/3.0)*deltaT)-(k2*(forwardEuller_U2(deltaT,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(deltaT,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))))+
			3*((1/m2)*(F2((2.0/3.0)*deltaT)-(k2*(forwardEuller_U2(deltaT,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(deltaT,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))))+
			((1/m2)*(F2(deltaT)-(k2*(forwardEuller_U2(deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))))
	);

	v2_ant = v1_new;

	while (i <= t){
		u1_new = u1_ant +(deltaT)/8.0*(
			forwardEuller_V1(i-deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			3*forwardEuller_V1(i,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			3*forwardEuller_V1(i,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			forwardEuller_V1(i,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)
		);

		u2_new = u2_ant +(deltaT)/8.0*(
			forwardEuller_V2(i-deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			3*forwardEuller_V2(i,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			3*forwardEuller_V2(i,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)+
			forwardEuller_V2(i,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)
		);

		v1_new = v1_ant +(deltaT)/8.0*(
			((1/m1)*(F1(i-deltaT)+(k2*(forwardEuller_U2(i-deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i-deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))-k1*forwardEuller_U1(i-deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))+
			3*((1/m1)*(F1((i-deltaT)+(1.0/3.0)*deltaT)+(k2*(forwardEuller_U2(i,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))-k1*forwardEuller_U1(i,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))+
			3*((1/m1)*(F1((i-deltaT)+(2.0/3.0)*deltaT)+(k2*(forwardEuller_U2(i,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))-k1*forwardEuller_U1(i,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))+
			((1/m1)*(F1(i)+(k2*(forwardEuller_U2(i,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))-k1*forwardEuller_U1(i,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))
		);

		v2_new = v2_ant +(deltaT)/8.0*(
			((1/m2)*(F2(0)-(k2*(forwardEuller_U2(i-deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i-deltaT,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))))+
			3*((1/m2)*(F2((1.0/3.0)*deltaT)-(k2*(forwardEuller_U2(i,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i,(1.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))))+
			3*((1/m2)*(F2((2.0/3.0)*deltaT)-(k2*(forwardEuller_U2(i,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i,(2.0/3.0)*deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))))+
			((1/m2)*(F2(deltaT)-(k2*(forwardEuller_U2(i,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)-forwardEuller_U1(i,deltaT,k1,k2,m1,m2,u1,u2,v1,v2)))))
	);

		u1_ant = u1_new;

		u2_ant = u2_new;

		v1_ant = v1_new;

		v2_ant = v2_new;

		i = i + deltaT;
	}

	cout << "u1 : " << u1_new <<endl;
	cout << "u2 : " << u2_new <<endl;
	cout << "v1 : " << v1_new <<endl;
	cout << "v2 : " << v2_new <<endl;
}




int main(int argc, char const *argv[]){
	
	double t,deltaT,k1,k2,m1,m2,u1,u2,v1,v2;


	cout << "Entre t : " <<endl;
	cin >> t;

	cout << "Entre delta t : " <<endl;
	cin >> deltaT;

	cout << "Entre k1 : " <<endl;
	cin >> k1;

	cout << "Entre k2 : " <<endl;
	cin >> k2;

	cout << "Entre m1 : " <<endl;
	cin >> m1;

	cout << "Entre m2 : " <<endl;
	cin >> m2;

	cout << "Entre u1 : " <<endl;
	cin >> u1;

	cout << "Entre u2 : " <<endl;
	cin >> u2;

	cout << "Entre v1 : " <<endl;
	cin >> v1;

	cout << "Entre v2 : " <<endl;
	cin >> v2;


	RK4( t,  deltaT,  k1,  k2,  m1,  m2,  u1,  u2,  v1,  v2);




	return 0;
}
