#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

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
