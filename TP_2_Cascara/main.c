#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/** \brief Ordena el vector de personas por el campo nombre en forma ascendente, en un vector auxiliar
 *         para no alterar el vector original, invocando a la función ordenarVectorMenorMayor.
 *         Luego muestra el vector auxiliar ordenado por pantalla mediante la función EPersona_mostrarListado.
 *         Si no hay personas registradas muestra la advertencia por pantalla.
 * \param EPersona[] Vector de personas
 * \return void
 *
 */
void muestraOrdenadoPorNombre(EPersona[]);

/** \brief Dado el vector original como parámetro, se define un vector auxiliar con tres posiciones.
 *         Se recorre el vector original contando las personas cuyas edades:
 *         a) Son menores a 18 años y guarda la cuenta en la posición 0 auxiliar. (Columna 1 del gráfico)
 *         b) Están comprendidas entre 18 y 35 años inclusive guardando la cuenta en la posición 1 auxiliar. (Columna 2 del gráfico)
 *         c) Son mayores a 35 años y guarda la cuenta en la posición 2 auxiliar. (Columna 3 del gráfico)
 *         Luego utilizando la función buscarMaximo obtengo el mayor elemento del vector auxiliar.
 *         Tomando dicho máximo como punto de partida, en una estructura repetitiva implemento un contador reverso
 *         hasta el número 1 inclusive, y en cada iteración recorro en forma secuencial el vector auxiliar pregunto
 *         a) Si el elemento es mayor o igual al contador, imprimo un '*'
 *         b) Sino imprimo un ' ' (espacio en blanco).
 *         De esa forma se va armando el gráfico de barras.
 * \param EPersona[] Vector de personas
 * \return void
 *
 */
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
                muestraGraficoBarras(listaPersonas);
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

    //Cargo en el vector temporario únicamente los elementos del vector persona con estado OCUPADO
    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            temporario[posicionTemporario] = lista[i];
            posicionTemporario++;
        }
    }

    if(posicionTemporario > 0) //Hallé al menos una persona
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
    int columna[3] = {}; //Inicializo el vector en cero.
    int posicion;
    int i;
    int hayPersonas = 0;
    int nFila; //Guarda el numero de fila a imprimir
    char elementoGrafico[3];

    //Cuento las personas con estado OCUPADO de acuerdo a su edad.
    for(i = 0; i < CANTIDAD; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            hayPersonas = 1; //Hallé al menos una persona

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

            columna[posicion]++; //Voy contando según rango de edad.
        }
    }

    if(hayPersonas == 1)
    {
        /*
        Tomo como cantidad maxima a imprimir el maximo hallado para un rango de edad, representado por una columna del gráfico.
        Dicho rango siempre imprime un elemento en su correspondiente columna del gráfico.
        Los demás rango imprimirán siempre que su cantidad sea mayor o igual al numero de fila a imprimir
        */
        nFila = buscarMaximo(columna, 3);

        while(nFila > 0)
        {
            for(i = 0; i < 3; i++)
            {
                if(columna[i] >= nFila)
                {
                    elementoGrafico[i] = '*';
                }
                else
                {
                    elementoGrafico[i] = ' ';
                }

                printf("  %c  ", elementoGrafico[i]);
            }
            //Bajo una fila, corto cuando termino de imprimir la fila 1
            nFila--;
            printf("\n");
        }

        printf("---------------\n");
        printf(" <18 18-35 >35 ");
    }
    else
    {
        printf("\n*** NO HAY PERSONAS PARA MOSTRAR ***");
    }
}
