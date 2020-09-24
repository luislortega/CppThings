/**
 * @Author: Luis Gerardo Leon Ortega
 * 
 * Tareas:
 * 
 * 1. Modifica la estructura racional que contemple funciones para la suma, multiplicación de racionales. [x]
 * 2. Escribir una función para racionales que simplifique la fracción. [x]
 * 
 * */
#include <stdio.h>

struct racional
{
private:
    int numerador;
    int denominador;

public:
    void imprimir();
    void asignar(int n, int d);
    void sumarRacionales(racional r1);
    void simplificar();
    int getMcd(int d, int n);
    int getNumerador();
    int getDenominador();
};

void racional::imprimir()
{
    if(numerador == denominador){
        printf("%d", numerador);
    }
    else{
        printf("%d/%d", numerador,denominador);
    }
    
};

void racional::asignar(int n, int d)
{
    numerador = n;
    denominador = d;
};

void racional::sumarRacionales(racional r2)
{
    numerador = (numerador * r2.getDenominador()) + (denominador * r2.getNumerador());
    denominador = denominador * r2.getDenominador();
};

void racional::simplificar(){
    int mcd = getMcd(numerador, denominador);
    numerador = numerador / mcd;
    denominador = denominador / mcd;
};

int racional::getMcd(int n, int d){
    return (n == 0) ? d : getMcd(d % n, n); 
}

int racional::getNumerador()
{
    return numerador;
};

int racional::getDenominador()
{
    return denominador;
};


int main()
{
    racional r, r2;
    r.asignar(1, 2);
    r2.asignar(1, 2);
    r.sumarRacionales(r2);
    r.simplificar();
    r.imprimir();
    
} ///:~

