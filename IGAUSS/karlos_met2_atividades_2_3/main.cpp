#include <iostream>
#include <math.h>
#include "Funcao.hpp"
#include "Funcao_01.hpp"
#include "Funcao_02.hpp"
#include "Funcao_03.hpp"
#include "Funcao_04.hpp"
#include "Funcao_05.hpp"
#include "Integracao.hpp"
#include "NC_A_P0.hpp"
#include "NC_A_P1.hpp"
#include "NC_A_P2.hpp"
#include "NC_A_P3.hpp"
#include "NC_A_P4.hpp"
#include "NC_F_P1.hpp"
#include "NC_F_P2.hpp"
#include "NC_F_P3.hpp"
#include "NC_F_P4.hpp"
#include "GLE_P1.hpp"
#include "GLE_P2.hpp"
#include "GLE_P3.hpp"
#include "GLE_P4.hpp"
#include "GHE_P2.hpp"
#include "GHE_P3.hpp"
#include "GHE_P4.hpp"
#include "GLA_P2.hpp"
#include "GLA_P3.hpp"
#include "GLA_P4.hpp"
#include "GCHEB.hpp"
#include "EXPOSIMPLES.hpp"
#include "EXPODUPLA.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    
    int         tipoquadratura              =  0;
    int         nc_fechada_ou_aberta        =  0;
    int         grau_polinomio_substituicao = -1;
    int			num_pontos_polinomio		= -1;
    int         gauss_tipo                  =  0;
    int         particao_ou_precisao        =  0;
    int         numero_de_particoes         =  0;
    int         id_integrando               =  1;
    Funcao     *integrando                  =  0;
    Integracao *pintegrObj;
    
    double a        = -1.0;
    double b        =  1.0;
    double precisao =  0.0001;
    double integral;
    
    cout << "Bem-vindo ao programa de Integração numérica! \n\n";
    
    
    cout << "Escolha a função a ser integrada: \n";
    cout << "\t1 - x^2 \n";
    cout << "\t2 - x^3 \n";
    cout << "\t3 - cos(x) \n";
    cout << "\t4 - sin(x) \n";
    cout << "\t5 - sqrt(1 + 1/x) \n";
    cin  >> id_integrando;
    
    switch (id_integrando)
    {
        case 1:
            integrando = new Funcao_01;
            break;
        case 2:
            integrando = new Funcao_02;
            break;
        case 3:
            integrando = new Funcao_03;
            break;
        case 4:
            integrando = new Funcao_04;
            break;
        case 5:
            integrando = new Funcao_05;
    }

    
    while (tipoquadratura < 1 || tipoquadratura > 3)
    {
        cout << "Escolha o método de integração. \n\n";
        cout << "1 - Newton-Cotes. \n";
        cout << "2 - Quadratura de Gauss. \n";
        cout << "3 - Exponenciação. \n";
        cin  >> tipoquadratura;
    }
    
    if (tipoquadratura == 1)
    {
        // Quadratura de Newton-Cotes
        
        cout << "\n\nVocê escolheu quadratura de Newton-cotes \n\n";
        
        while (nc_fechada_ou_aberta < 1 || nc_fechada_ou_aberta > 2)
        {
            cout << "Escolha a filosofia adequada. \n";
            cout << "1 - Fórmulas fechadas. \n";
            cout << "2 - Fórmulas abertas.  \n";
            cin  >> nc_fechada_ou_aberta;
        }
        
        if (nc_fechada_ou_aberta == 1)
        {
            // N-C Fechada
            cout << "\n\nVocê escolheu quadratura de Newton-cotes fechada\n\n";
            
            while (grau_polinomio_substituicao < 1 || grau_polinomio_substituicao > 4)
            {
                cout << "\n\nEntre o grau do polinômio de substituição (1-4)\n\n";
                cin  >> grau_polinomio_substituicao;
            }
        }
        else
        {
            // N-C Aberta
            cout << "\n\nVocê escolheu quadratura de Newton-cotes aberta\n\n";
            
            while (grau_polinomio_substituicao < 0 || grau_polinomio_substituicao > 4)
            {
                cout << "\n\nEntre o grau do polinômio de substituição (0-4)\n\n";
                cin  >> grau_polinomio_substituicao;
            }
        }
        
        cout << "Entre o intervalo de integração (a, b): \n";
        cout << "a = ";
        cin  >>  a;
        cout << "\nb = ";
        cin  >> b;
        
        while(particao_ou_precisao < 1 || particao_ou_precisao > 2)
        {
            cout << "Você deseja particionar o intervalo de integração (a, b) ou quer definir uma precisão? \n";
            cout << "1 - Particionar.                     \n";
            cout << "2 - Definir a precisão do resultado. \n";
            cin  >>  particao_ou_precisao;
        }
        
        if (particao_ou_precisao == 1)
        {
            cout << "\n\nEntre o número de partições do intervalo (a,b) - número >= 1. \n";
            cin  >> numero_de_particoes;
        }
        else
        {
            cout << "\n\nEntre o valor da tolerância epslon (exemplo: 0.00001)\n";
            cin  >> precisao;
        }
        

        
        if (nc_fechada_ou_aberta == 1)
        {
            // N-C Fechada
            
            switch (grau_polinomio_substituicao)
            {
                case 1:
                    pintegrObj = new NC_F_P1(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                    
                case 2:
                    pintegrObj = new NC_F_P2(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                
                case 3:
                	pintegrObj = new NC_F_P3(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
              	
              	case 4:
              		pintegrObj = new NC_F_P4(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
            }
        }
        else
        {
            // N-C Aberta
            switch (grau_polinomio_substituicao)
            {
                case 0:
                    pintegrObj = new NC_A_P0(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                    
                case 1:
                    pintegrObj = new NC_A_P1(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                    
                case 2:
                    pintegrObj = new NC_A_P2(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                    
                case 3:
                	pintegrObj = new NC_A_P3(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
                	
               	case 4:
               		pintegrObj = new NC_A_P4(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
            }
        }

    }
    else if (tipoquadratura == 2)
    {
        // Quadratura de Gauss
        cout << "\n\nVocê escolheu quadratura de Gauss \n\n";
        
        while (gauss_tipo < 1 || gauss_tipo > 4)
        {
            cout << "Escolha a quadratura de gauss adequada. \n";
            cout << "1 - Gauss-Legendre.  \n";
            cout << "2 - Gauss-Hermite.   \n";
            cout << "3 - Gauss-Laguerre.  \n";
            cout << "4 - Gauss-Chebyshev. \n";
            cin  >> gauss_tipo;
        }
        
        if (gauss_tipo == 1) {
        
        	cout << "\n\nVocê escolheu quadratura de Gauss-Legendre\n\n";
            
            while (num_pontos_polinomio < 1 || num_pontos_polinomio > 4)
            {
                cout << "\n\nEntre o grau do polinômio de Legendre(1-4)\n\n";
                cin  >> num_pontos_polinomio;
            }
        
        } if (gauss_tipo == 2) {
        
            cout << "\n\nVocê escolheu quadratura de Gauss-Hermite\n\n";
            
            while (num_pontos_polinomio < 2 || num_pontos_polinomio > 4)
            {
                cout << "\n\nEntre o grau do polinômio de Hermite(2-4)\n\n";
                cin  >> num_pontos_polinomio;
            }
            
            switch (id_integrando) {
            
                case 1:
                    cout << "\nA integrar: e^(-x^2)x^2 de -inf a +inf\n\n";
                    break;
                
                case 2:
                    cout << "\nA integrar: e^(-x^2)x^3 de -inf a +inf\n\n";
                    break;
                    
                case 3:
                    cout << "\nA integrar: e^(-x^2)cos(x) de -inf a +inf\n\n";
                    break;
                    
                case 4:
                    cout << "\nA integrar: e^(-x^2)sen(x) de -inf a +inf\n\n";
                    break;
                    
                case 5:
                    cout << "\nA integrar: e^(-x^2)x^5 de -inf a +inf\n\n";
                    break;
            
            }
        
        } if (gauss_tipo == 3) {
        
            cout << "\n\nVocê escolheu quadratura de Gauss-Laguerre\n\n";
            
            while (num_pontos_polinomio < 2 || num_pontos_polinomio > 4)
            {
                cout << "\n\nEntre o grau do polinômio de Laguerre(2-4)\n\n";
                cin  >> num_pontos_polinomio;
            }
            
            switch (id_integrando) {
            
                case 1:
                    cout << "\nA integrar: e^(-x)x^2 de -inf a +inf\n\n";
                    break;
                
                case 2:
                    cout << "\nA integrar: e^(-x)x^3 de -inf a +inf\n\n";
                    break;
                    
                case 3:
                    cout << "\nA integrar: e^(-x)cos(x) de -inf a +inf\n\n";
                    break;
                    
                case 4:
                    cout << "\nA integrar: e^(-x)sen(x) de -inf a +inf\n\n";
                    break;
                    
                case 5:
                    cout << "\nA integrar: e^(-x)x^5 de -inf a +inf\n\n";
                    break;
            
            }
        
        } else {
        
            cout << "\n\nVocê escolheu quadratura de Gauss-Chebyshev\n\n";
            
            switch (id_integrando) {
            
                case 1:
                    cout << "\nA integrar: 1/(sqrt(1 - x^2))*x^2 de a a b\n\n";
                    break;
                
                case 2:
                    cout << "\nA integrar: 1/(sqrt(1 - x^2))*x^3 de a a b\n\n";
                    break;
                    
                case 3:
                    cout << "\nA integrar: 1/(sqrt(1 - x^2))*cos(x) de a a b\n\n";
                    break;
                    
                case 4:
                    cout << "\nA integrar: 1/(sqrt(1 - x^2))*sen(x) de a a b\n\n";
                    break;
                    
                case 5:
                    cout << "\nA integrar: 1/(sqrt(1 - x^2))*x^5 de a a b\n\n";
                    break;
            
            }
        
        }
        
        if (gauss_tipo != 2 && gauss_tipo != 3) {
        
            cout << "Entre o intervalo de integração (a, b): \n";
            cout << "a = ";
            cin  >>  a;
            cout << "\nb = ";
            cin  >> b;
        
        }
        
        while(particao_ou_precisao < 1 || particao_ou_precisao > 2)
        {
            cout << "Você deseja particionar o intervalo de integração (a, b) ou quer definir uma precisão? \n";
            cout << "1 - Particionar.                     \n";
            cout << "2 - Definir a precisão do resultado. \n";
            cin  >>  particao_ou_precisao;
        }
        
        if (particao_ou_precisao == 1)
        {
            cout << "\n\nEntre o número de partições do intervalo (a,b) - número >= 1. \n";
            cin  >> numero_de_particoes;
        }
        else
        {
            cout << "\n\nEntre o valor da tolerância epslon (exemplo: 0.00001)\n";
            cin  >> precisao;
        }
        
        if (gauss_tipo == 1) {
        
        	switch (num_pontos_polinomio) {
        	
        		case 1:
        			pintegrObj = new GLE_P1(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
                	
                case 2:
        			pintegrObj = new GLE_P2(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
                	
                case 3:
        			pintegrObj = new GLE_P3(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
                
                case 4:
        			pintegrObj = new GLE_P4(integrando, a, b, numero_de_particoes, precisao);
                	integral   = pintegrObj->integrar();
                	break;
        	
        	}
        
        } else if (gauss_tipo == 2) {
        
            switch (num_pontos_polinomio) {
            
                case 2:
                    pintegrObj  = new GHE_P2(integrando, a, b, numero_de_particoes, precisao);
                    integral    = pintegrObj->integrar();
                    break;
                    
                case 3:
                    pintegrObj  = new GHE_P3(integrando, a, b, numero_de_particoes, precisao);
                    integral    = pintegrObj->integrar();
                    break;
                    
                case 4:
                    pintegrObj  = new GHE_P4(integrando, a, b, numero_de_particoes, precisao);
                    integral    = pintegrObj->integrar();
                    break;
            
            }
        
        } else if (gauss_tipo == 3) {
            
            switch (num_pontos_polinomio) {
            
                case 2:
                    pintegrObj  = new GLA_P2(integrando, a, b, numero_de_particoes, precisao);
                    integral    = pintegrObj->integrar();
                    break;
                    
                case 3:
                    pintegrObj  = new GLA_P3(integrando, a, b, numero_de_particoes, precisao);
                    integral    = pintegrObj->integrar();
                    break;
                    
                case 4:
                    pintegrObj  = new GLA_P4(integrando, a, b, numero_de_particoes, precisao);
                    integral    = pintegrObj->integrar();
                    break;
            
            }
        
        } else {
        
            pintegrObj  = new GCHEB(integrando, a, b, numero_de_particoes, precisao);
            integral    = pintegrObj->integrar();
        
        }

    }
    else
    {
        
        cout << "\n\nVocê escolheu o método de Exponenciação\n\n";
        
        int tipo_expo = -1;
        
        while (tipo_expo != 1 && tipo_expo != 2) {
        
            cout << "Escolha o tipo de exponenciação. \n";
            cout << "1 - Exponenciação Simples.  \n";
            cout << "2 - Exponenciação Dupla.   \n";
            cin  >> tipo_expo;
        
        }
        
        cout << "\n\nEntre o valor da tolerância epsilon (exemplo: 0.00001)\n";
        cin  >> precisao;
        
        if (tipo_expo == 1) {
        
            pintegrObj  = new EXPOSIMPLES(integrando, precisao);
            integral    = pintegrObj->integrar();
        
        } else {
        
            pintegrObj  = new EXPODUPLA(integrando, precisao);
            integral    = pintegrObj->integrar();
        
        }
        
    }
    
    if (gauss_tipo != 2 && gauss_tipo != 3 && tipoquadratura != 3) {
        cout << "A integral da função escolhida, no intervalo (" << a << ", " << b << ") é : ";    
    } else {
        cout << "A integral da função escolhida é : ";
    }

    cout << integral <<"\n\n";
    
    return 0;
}

