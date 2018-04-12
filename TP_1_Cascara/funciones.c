#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

float pedirFlotante(char mensaje[])
{
    float numero;

    printf("%s", mensaje);
    scanf("%f", &numero);

    return numero;
}

float calcularSuma(float sumandoA, float sumandoB)
{
    float resultado;
    resultado = sumandoA + sumandoB;

    return resultado;
}

float calcularResta(float minuendoA, float minuendoB)
{
    float resultado;
    resultado = minuendoA - minuendoB;

    return resultado;
}

float calcularCociente(float dividendo, float divisor)
{
    float resultado;
    resultado = dividendo / divisor;

    return resultado;
}

int validarCociente(float dividendo, float divisor)
{
    int resultado;

    if(divisor == 0)
    {
        if(dividendo == 0)
        {
            resultado = 2; //Indeterminacion
        }
        else
        {
            resultado = 1; //Infinito
        }
    }
    else
    {
        resultado = 0; //OK
    }

    return resultado;
}

float calcularProducto(float multiplicando, float multiplicador)
{
    float resultado;
    resultado = multiplicando * multiplicador;

    return resultado;
}

int calcularFactorial(float factor)
{
    float resultado = 1;
    int contador;

    if(factor == 0)
    {
        resultado = 1;
    }
    else
    {
        for(contador = factor; contador >= 1; contador--)
        {
            resultado = resultado * contador;
        }
    }

    return resultado;
}

int validarFactorial(float factor)
{
    int resultado;
    int factorEntero;

    if(factor < 0)
    {
        resultado = 2; //Numero negativo
    }
    else
    {
        factorEntero = validarEntero(factor);

        switch(factorEntero)
        {
        case 1:
            resultado = 1; //Numero decimal
            break;
        case 0:
            resultado = 0; //Numero entero
            break;
        default:
            printf("Caso no contemplado en la funcion validarEntero. Devolvio %d\n", factorEntero);
            resultado = 1; //Lo retorno como si fuera numero decimal.
            break;
        }
    }

    return resultado;
}

void limpiarPantalla()
{
    system("cls");
}

int validarEntero(float numero)
{
    int numeroEntero = (int)numero;
    int retorno;

    if(numero != numeroEntero)
    {
        retorno = 1; //No es entero
    }
    else
    {
        retorno = 0; //Es entero
    }

    return retorno;
}
