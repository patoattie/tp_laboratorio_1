#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void muestraOrdenadoPorNombre(EPersona[]);
void muestraGraficoBarras(EPersona[]);

int main()
{
    char seguir='s';
    int opcion=0;

    //Declaro array donde guardo los datos de la estructura Persona
    EPersona listaPersonas[CANTIDAD];

    //Inicializo el flag de estado
    EPersona_init(listaPersonas);

    while(seguir=='s')
    {
        limpiarPantalla();

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                EPersona_alta(listaPersonas);
                break;
            case 2:
                EPersona_baja(listaPersonas);
                break;
            case 3:
                muestraOrdenadoPorNombre(listaPersonas);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion no contemplada, por favor vuelva a elegir");
                break;
        }

        if(seguir=='s')
        {
            printf("\n");
            pausarEjecucion();
        }
    }

    return 0;
}

void muestraOrdenadoPorNombre(EPersona lista[])
{
    EPersona temporario[CANTIDAD]; //Ordeno en un vector aparte
    int i;
    int posicionTemporario = 0;
    int muestraListado;

    EPersona_init(temporario); //Inicializo el vector temporario

    //Cargo en el vector temporario �nicamente los elementos del vector persona con estado OCUPADO
    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            temporario[posicionTemporario] = lista[i];
            posicionTemporario++;
        }
    }

    if(posicionTemporario > 0) //Hall� al menos una persona
    {
        ordenarVectorMenorMayor(temporario);
        muestraListado = EPersona_mostrarListado(temporario);

        if(muestraListado < 1)
        {
            printf("\nNo hay personas para ordenar por nombre");
        }
    }
    else
    {
        printf("\n*** NO HAY PERSONAS PARA MOSTRAR ***");
    }
}

void muestraGraficoBarras(EPersona lista[])
{
    /*
    Posicion 0 -> <18
    Posicion 1 -> >=18 && <=35
    Posicion 2 -> >35
    */
    int grupos[3] = {}; //Inicializo el vector en cero.
    int posicion;
    int i;
    int hayPersonas = 0;

    //Cuento las personas con estado OCUPADO de acuerdo a su edad.
    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            hayPersonas = 1; //Hall� al menos una persona

            if(lista[i].edad < 18)
            {
                posicion = 0;
            }
            else if(lista[i].edad >= 18 && lista[i].edad <= 35)
            {
                posicion = 1;
            }
            else //>35
            {
                posicion = 2;
            }

            grupos[posicion]++; //Voy contando seg�n rango de edad.
        }
    }

    if(hayPersonas == 1)
    {
        //Ordeno el vector resultante
        ordenarVectorMayorMenor(grupos);


    }
    else
    {
        printf("\n*** NO HAY PERSONAS PARA MOSTRAR ***");
    }


}
