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

struct racional
{
private:
    char const *representacion;

public:
    char const *getRepresentacion();
    void setRepresentacion(int,int);
    void enteroaCadena(int,char*);
    void cadenaaEntero(int*); //no construido
    //Utilidades...
    void concatenarCadenas(char[],char[]);
    int tamanoCadena(char*);
};

char const *racional::getRepresentacion()
{
    return representacion;
};

void racional::setRepresentacion(int numerador, int denominador)
{
    char numeradorCadena[10];
    char separador[10] = "/";
    char denominadorCadena[10];

    enteroaCadena(numerador, numeradorCadena);
    enteroaCadena(denominador, denominadorCadena);

    //Concatenamos todo a numeradorCadena :) para convertirlo en la representacion char...
    concatenarCadenas(numeradorCadena, separador); 
    concatenarCadenas(numeradorCadena, denominadorCadena);

    representacion = numeradorCadena;
};

int racional::tamanoCadena(char *cadena){
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; ++i){
        contador = contador + 1;
    }
    return contador;
};

void racional::concatenarCadenas(char cadena1[], char cadena2[]){
    int tamanoCadena1, contadorContenido;
    tamanoCadena1 = tamanoCadena(cadena1);
    for (contadorContenido = 0; cadena2[contadorContenido] != '\0'; tamanoCadena1++, contadorContenido++)
    {
        cadena1[tamanoCadena1] = cadena2[contadorContenido];
    }
    cadena1[tamanoCadena1] = '\0';
};

void racional::enteroaCadena(int entero, char *posicionCadena)
{
    int n = entero;
    int i = 0;
    bool isNeg = n < 0;
    unsigned int n1 = isNeg ? -n : n;
    while (n1 != 0)
    {
        posicionCadena[i++] = n1 % 10 + '0';
        n1 = n1 / 10;
    }
    if (isNeg)
        posicionCadena[i++] = '-';

    posicionCadena[i] = '\0';
    for (int t = 0; t < i / 2; t++)
    {
        posicionCadena[t] ^= posicionCadena[i - t - 1];
        posicionCadena[i - t - 1] ^= posicionCadena[t];
        posicionCadena[t] ^= posicionCadena[i - t - 1];
    }
    if (n == 0)
    {
        posicionCadena[0] = '0';
        posicionCadena[1] = '\0';
    }
};

void inttochar(char *buf2);

int main()
{
    racional r1;
    char buffer[50];

    char const *buffer2;

    char algo[50];

    inttochar(algo);

    r1.setRepresentacion(1, 2);
    buffer2 = r1.getRepresentacion();

    buffer2 = algo;
}

void inttochar(char *buf2)
{
    int n = 124;
    char buffer[50];
    int i = 0;

    bool isNeg = n < 0;

    unsigned int n1 = isNeg ? -n : n;

    while (n1 != 0)
    {
        buf2[i++] = n1 % 10 + '0';
        n1 = n1 / 10;
    }

    if (isNeg)
        buf2[i++] = '-';

    buf2[i] = '\0';

    for (int t = 0; t < i / 2; t++)
    {
        buf2[t] ^= buf2[i - t - 1];
        buf2[i - t - 1] ^= buf2[t];
        buf2[t] ^= buf2[i - t - 1];
    }

    if (n == 0)
    {
        buf2[0] = '0';
        buf2[1] = '\0';
    }
}