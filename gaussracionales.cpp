/*
@author: luislortega

@description: La asignación de variables Racional deberá generarse de forma aleatoria. Será necesario crear una función para este proceso.
Todas las operaciones aritméticas deben mantener la representación de los Racionales (no es permitido usar flotantes para representar el Racional)
Las operaciones aritméticas puede suma, resta (suma negativa), multiplicación, división (inverso de multiplicación).
Es recomendable aplicar un procedimiento de simplificación, durante el proceso o al final, antes de presentar el resultado final.

@task:
1. Crear un vector de 6 racionales
2. La asignacion de los 3 primeros es aleatoria
 
    Ej:
    [1/2, 1/3, 1/4, 1, 0, 0]

3. Realizar operaciones (de racional) aritmeticas para transformar el vector

    Ej:
        de: [1/2, 1/3, 1/4, 1, 0, 0]
        a => [1, 0, 0, |__| , |__| , |__|]

        (|__|) => racionales resultantes de aplicar las operaciones aritmeticas para obtener 1,0,0 en las tres primeras posiciones

*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>

using namespace std;

struct racional
{
private:
    string representacion;

public:
    string getRepresentacion();
    void setRepresentacion(int, int);
    void setRepresentacionRandom();
    void setRepresentacionManual(int);
    void simplificarRepresentacion();
    int getMcd(int, int);
    size_t getVectorRepresentacion(vector<string> &, char const *);
    bool divisionDaEntero(string str);
};

string racional::getRepresentacion()
{
    return representacion;
};

void racional::setRepresentacion(int numerador, int denominador)
{
    representacion = to_string(numerador) + "/" + to_string(denominador);
};

void racional::setRepresentacionManual(int representacionNumerica)
{
    representacion = to_string(representacionNumerica);
};

void racional::setRepresentacionRandom()
{
    srand(time(0)); //Mi actual fecha para generar una semilla random.
    representacion = to_string(rand()) + "/" + to_string(rand());
};

void racional::simplificarRepresentacion()
{
    vector<string> valoresCadena;
    getVectorRepresentacion(valoresCadena, "/");
    int mcd = getMcd(stoi(valoresCadena[0]), stoi(valoresCadena[1]));

    if(stoi(valoresCadena[0]) == stoi(valoresCadena[1])){
        setRepresentacionManual(1);
    }else{
        if (divisionDaEntero( to_string(  (( (float)stoi(valoresCadena[0]) / (float)mcd) / ( (float)stoi(valoresCadena[1]) / (float) mcd)) ) )){
            setRepresentacionManual(((stoi(valoresCadena[0]) / mcd) / (stoi(valoresCadena[1]) / mcd)));
        }else{
            setRepresentacion(stoi(valoresCadena[0]) / mcd, stoi(valoresCadena[1]) / mcd);
        }
    }
};

bool racional::divisionDaEntero(string str)
{
    return (floor((float)stof(str)) == (float)stof(str)) ? true : false;
};

int racional::getMcd(int numerador, int denominador)
{
    return (numerador == 0) ? denominador : getMcd(denominador % numerador, numerador);
};

size_t racional::getVectorRepresentacion(vector<string> &cadenas, char const *caracter)
{
    size_t posicion = representacion.find(caracter);
    size_t posicionInicial = 0;
    cadenas.clear();
    while (posicion != string::npos)
    { //posicion negativa.
        cadenas.push_back(representacion.substr(posicionInicial, posicion - posicionInicial));
        posicionInicial = posicion + 1;
        posicion = representacion.find(caracter, posicionInicial);
    }
    cadenas.push_back(representacion.substr(posicionInicial, min(posicion, representacion.size()) - posicionInicial + 1));
    return cadenas.size();
}

int main()
{
    //Programa principal
    cout << "====== ZONA PRINCIPAL ========" << endl;

    vector<racional> vectorRacionales;

    racional r1,r2,r3,r4,r5,r6;

    r1.setRepresentacionRandom();
    r2.setRepresentacionRandom();
    r3.setRepresentacionRandom();
    r4.setRepresentacionManual(1);
    r5.setRepresentacionManual(0);
    r6.setRepresentacionManual(0);

    vectorRacionales.push_back(r1);
    vectorRacionales.push_back(r2);
    vectorRacionales.push_back(r3);
    vectorRacionales.push_back(r4);
    vectorRacionales.push_back(r5);
    vectorRacionales.push_back(r6);

    cout << vectorRacionales[0].getRepresentacion() << endl;
    cout << vectorRacionales[1].getRepresentacion() << endl;
    cout << vectorRacionales[2].getRepresentacion() << endl;
    cout << vectorRacionales[3].getRepresentacion() << endl;
    cout << vectorRacionales[4].getRepresentacion() << endl;
    cout << vectorRacionales[5].getRepresentacion() << endl;

    //Tests...
    cout << "====== ZONA DE TESTEOS ========" << endl;
    racional racional1, racional2;

    racional1.setRepresentacion(90, 9);
    racional2.setRepresentacionRandom();
    
    cout << racional1.getRepresentacion() << endl;
    cout << racional2.getRepresentacion() << endl;

    racional1.simplificarRepresentacion();
    racional2.simplificarRepresentacion();

    cout << racional1.getRepresentacion() << endl;
    cout << racional2.getRepresentacion() << endl;

}
