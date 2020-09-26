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

using namespace std;

struct racional
{
private:
    string representacion;
public:
    string getRepresentacion();
    void setRepresentacion(int,int);
    size_t getVectorRepresentacion(vector<string>&, char const *);
};

string racional::getRepresentacion(){
    return representacion;
};

void racional::setRepresentacion(int numerador, int denominador){
    representacion = to_string(numerador)+"/"+to_string(denominador);
};

size_t racional::getVectorRepresentacion(vector<string> &cadenas, char const *caracter)
{
    size_t posicion = representacion.find(caracter);
    size_t  posicionInicial = 0;
     cadenas.clear();
    while( posicion != string::npos ) { //posicion negativa.
         cadenas.push_back( representacion.substr(  posicionInicial, posicion -  posicionInicial ) );
        posicionInicial = posicion + 1;
        posicion = representacion.find(caracter,  posicionInicial );
    }
    cadenas.push_back( representacion.substr(  posicionInicial, min( posicion, representacion.size() ) -  posicionInicial + 1 ) );
    return  cadenas.size();
}

int main()
{

    
    vector<string> v;
    racional racional1;
    
    racional1.setRepresentacion(1,2);
    racional1.getVectorRepresentacion(v, "/");

    cout << racional1.getRepresentacion() << '\n';
    cout << v[0] << '\n';

}
